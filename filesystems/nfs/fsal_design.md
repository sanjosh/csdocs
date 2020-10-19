

This document has following sections
1. Requirements to be fulfilled by a FSAL
2. Designing the wire handle for DCE FSAL
3. Designing for Crash-consistency
4. Locking needed for Multi-threaded operation
5. Changes required for Multiple NFS servers manipulating shared MotherNFS filesystem
6. New approach to rename
7. Complete DCE FSAL WORKFLOW (now outdated - see Sec 5 & 6)

Two more misc sections at end
Open Problems
Logging

--------------------------------------------------------------------------

1. Requirements to be fulfilled by a FSAL
General notes on Ganesha workflows and handles

There are three objects : wire handle, fsal handle and cache key

Ganesha Server maintains its own cache from {cache_key} to {fsal_handle}
NFS client talks to Ganesha using wire handles 

wire_handle <--> cache_key <--> fsal_handle

There are four functions which interconnect them
1. fsal_handle => cache_key using handle_ops.handle_to_key()
   used to find key to use while inserting in Ganesha cache
2. fsal_handle => wire_handle using handle_ops.handle_to_digest()
   used to return wire handle of new object to NFS client
3. wire_handle => cache_key using export_ops.extract_handle()
   used to find cache key given incoming wire handle
4. wire_handle => fsal_handle using export_ops.create_handle()
   used to find fsal object which was not found in cache
   but for which wire handle was previously returned

NFS client first obtains the wire handle for root of filesystem
This is done in export_ops.lookup_path()

If NFS client does not have a wire handle for an existing file
whose name was discovered during directory traversal, then the FSAL 
will get call to 
   export_ops.lookup(dir_handle, file)
to get a wire handle for this unknown file.

Later, NFS client will operate on the file using this wire handle

Given a wire handle read from the network socket
1. First Ganesha tries to find if wire handle is in its cache
   convert wire handle to cache key 
   cache_key = export_ops.extract_handle(wire_handle) 
2. if cache_key not in cache
      convert wire handle to fsal handle
      fsal_handle = export_ops.create_handle(wire_handle)
      new_cache_key = handle_ops.handle_to_key(fsal_handle)
      insert {new_cache_key} => {fsal_handle} into cache
3. call specific operation on fsal_handle using handle_ops.<some_func>()

If the NFS client is creating a new object (mkdir/symlink/create), it 
does not have a wire handle for it.  In this case, it makes a call 
using wire handle of parent directory.  Then Ganesha returns the 
wire handle of the new object using
   wire_handle = handle_ops.handle_to_digest(fsal_handle)

----------------------------------------------------------------------------

Designing the wire handle for DCE FSAL

Given a wire handle coming from a client, the FSAL needs to find the if the 
wire handle is valid and which file it points to.

There are two possible designs for the wire handle

1. wire_handle = {inode number + sequence number}.  
   The inode number is given by the underlying filesystem.
   The sequence number is a continuously increasing number, similar to the 
   way the NFS kernel uses the inode generation number.
   This requires storing one map from {inode number} => {filename}
   The map from filename to inode number is given by stat() call.

2. wire_handle = {guid, which is a random number}.
   This requires storing two maps
   Other from {guid} => {filename}
   Other from {filename} => {guid} (this comes for free in proposal 1).

For now, we will go with proposal 1.

To find which file the wire handle points to, the wire handle must contain
the inode number of the file.

To find if the handle is valid, we need a sequence number in the wirehandle
and a current sequence number associated with the inode.  If they dont
match, we return a stale handle to the NFS client, after which the client
will call lookup(filename) to create a fresh wire handle.

Therefore, we need these two reverse maps in the FSAL to correctly identify a
file given a wire handle:
1) inode => filename : since POSIX won't tell us that
2) inode => seqnum : to correctly identify stale wire handles

The {inode => filename} map could be kept transient.  We could walk the filesystem 
after ganesha restarts on an existing filesystem and rebuild this map.  
But we also need to keep an inode => seqnum mapping and that needs to be
persistent (as explained next).  Therefore, the inode => filename map can
also be kept persistent along with inode to seqnum map.

INODE_NUMBER REUSE
The underlying filesystem could allocate the same inode number to the same filename after 
a sequence of creates and deletes.  In this case, the old wire handle with the 
(inode number + sequence) might be able to successfully read the new file.
This should not be allowed because the file is new even though the name
and inode number are same.

To prevent this bug, we need to check if sequence number in the wirehandle matches
the sequence number in the inode

The question is how to associate a seqnum with inode so that following
sequence of conversions work when

   wire_handle -> ganesha cache key -> fsal_handle -> inode -> filename

The second question is : Does the inode => seqnum map need to be persistent ?

When ganesha restarts after a transient failure, it may receive a wirehandle 
obtained before crash, using which it must be able to operate on existing file.  
If Ganesha did not store the {inode=>seqnum} mapping persistently, then all
previous wire handles would become invalid.  This will increase startup cost 
and cause a thundering herd.

Therefore, inode => seqnum maps needs to be persistent.

For a persistent map, these proposals were discussed

Alternatives :

1) Use extended attributes (xattr) to store the sequence number with the file.  
   Xattr is a fringe feature which may or may not work.
2) use ioctl() to get inode generation number stored in the underlying
   filesystem.  
   http://stackoverflow.com/questions/20052912/how-do-i-get-the-generation-number-of-an-inode-in-linux
   This doesnt work when the underlying filesystem is itself over NFS 
   (as will be the case).
3. Use the path_to_handle(3), open_by_handle(3) and other related calls
   which were designed for userspace NFS servers and are currently used
   by the VFS FSAL.  These do not work when the underlying filesystem is NFS.
4) use creation time of inode.  This wont work, because the creation time gets
   updated after creation when you do chown, chmod.
5) keep a file whose name is the inode number and has data={seqnum, filename}
6) use mysql to store mapping from inode_number => seqnum, filename.

Right now, we are going with proposal 5.  Later, we will move to proposal 6 (mysql).

This map from inode number -> {seqnum, filename} will be called "inodemap" 
for the rest of this document.

To address the stale wire handle problems, we are always going to look up the
inode => (seqnum, filename) mapping and allow an operation only if inode.seqnum 
matches wire_handle.seqnum.  When retreiving inode.seqnum, we will also fetch
the filename for the inode number.  Therefore, it makes no sense any longer to
store the filename in the fsal_obj_handle.  This should be removed.

---------------------------------------------------------------------

Designing for Crash-consistency

The NFS Ganesha server process can crash in between an FSAL operation.
How should the DCE FSAL handle recovery from such crashes.

The DCE FSAL stores information in two places : inodemap and filesystem.

All operations which update both these locations need to be designed 
to ensure that a ganesha process crash inside them does not create
inconsistent state between the inodemap entry and the actual file.
Any operation which reads from one place must cross-check and/or correct
the data obtained from the other place.

The following operations do multi-step updates and should be made crash-consistent:
1) create or mkdir : create file and create inodemap entry
2) unlink : delete file and delete inodemap entry
3) rename : rename files and updates the inodemap entry to contain new filename

The following operations are used to obtain fsal handles given file names. 
1) lookup(directoy, file)
2) readdir(directory)
They map filename -> inode -> fsal_handle -> wire handle
They should be modified to detect and fix any inconsistency between inodemap and 
the filesystem.

The following operations use existing file handles to operate on files
1) dce_getattr
2) dce_setattr
3) dce_open
4) dce_close 

If the inodemap entry does not exist, these operations will return a stale handle 
error code after which the Ganesha upper layer or NFS client will discard the
fsal handle or wire handle and call dce_lookup() to obtain a new handle.  
During the call to dce_lookup(), any inconsistency can be detected and fixed.

If the filename in the inodemap does not match the filename, should this be
checked in the getattr/setattr/open/close functions ?  This situation only
occurs if the Ganesha process crashes in the middle of a rename (or if there
is some serious unknown corruption).  In this case, the dce_rename() will
first be retried before a call to getattr/setattr/open/close.  Therefore
the filename mismatch check will not be done in these functions.

**************************

dce_create() can only create inodemap entry after creating file, because until 
then it doesn't know inode number.  (It is possible to do the other way round
by using "mkstemp" and "mkdtemp" to a create a temporary file, gets it inode
number to create inodemap entry, and then move the temporary file to actual
filename.  This approach is not pursued because it would complicate the 
recovery logic discussed below. )

Theefore, this is how create/mkdir should work

dce_create()
{
    1. mkdir/creat
      --- GANESHA PROCESS can CRASH here ---
    2. insert inodemap entry
}

**************************

unlink/remove should work in reverse; it should remove the inodemap entry 
before deleting file, otherwise we have the following bug

Thread T1 deletes the file which frees the inode number to the filesystem
Thread T2 creates new dir/file and get that freed inode number 
Thread T2 may write to the inode-map file for that inode
Thread T1 now wakes up and deletes the same inode-map file (BUG)

Therefore, this is how file delete [dce_unlink()] should work

dce_unlink() AKA file or directory delete
{ 
    1. remove inodemap entry
      --- GANESHA PROCESS can CRASH here ---
    2. delete file/dir
}

There are four states possible given the filesystem & inodemap entries:

    file : inodemap  : implies
     Y   : Y  : this is an error in create, but good in delete
     Y   : N  : crash occurred half-way during create/delete
     N   : Y  : not possible by current logic
     N   : N  : this is an error in delete, but good in create

**************************

dce_rename() or file rename

It was observed with NFSv3 that if the NFS server crashes in the middle
of a rename, the NFS client retries the rename() operation. (Dont know
about NFSv4).

Say the operation was 
    rename(src_dir/src_file -> dest_dir/dest_file).

When Ganesha server again receives rename(src_dir/src_file, dest_dir/dest_file) after
a crash, its cache is empty.  The cache rename function first calls the 
FSAL lookup() to fetch new fsal handles for both source and destination files.

If the dce_lookup() operation correctly detects and recovers from any 
inconsistency left by partial rename, then the new rename will succeed.

To ensure this, it was discovered during testing that the 
a) dce_lookup(src_dir, src_file) must always succeed irrespective of the crash in dce_rename() 
b) dce_lookup(dest_dir, dest_file) may return ENOENT or success.

It seems to make sense to increment the sequence number for the inode after a
rename.  During testing, this increment was found to invalidate wire handles 
and it broke existing semantics of NFS clients which retry operations after 
a crash.  Therefore, dce_rename() will not increment sequence number.

**************************

dce_lookup(dir, filename)  or dce_read_dirents(dir)

How should it work if the inodemap entry does not exist or if the
filename in the inodemap does not match the actual filename.

Alternatives for handling missing inodemap entry
1) It can create the inodemap entry but with what sequence number ?
2) It can delete the actual filename

Alternatives for filename in inodemap mismatch with actual filename
1) Update inodemap.filename = name of actual file
2) Update name of actual file = inodemap.filename

In order to choose the alternatives, the nature of the inconsistencies
need to be detailed. This is discussed next...

**************************

There are two source of information regarding files in the DCE FSAL 
(a) the filesystem which has actual files and 
(b) the inodemap

To reason about crash consistency, we shall adopt the following PRINCIPLE:

    The source of truth is always the filesystem.
    In other words, the inodemap contains derived data.

Therefore, any multistep operation must first modify the inodemap before
modifying on the filesystem.  It means after a crash, the filesystem data 
must be relied to update the inodemap entry and NOT the other way round.

The logical choices for each function follow from this principle :

1) during create, the file is created before inodemap entry
   if we crash between these two operations, there will be a file with
   a missing inodemap entry which should be deleted after crash.
   This accurately reflects the intended operation before crash.

2) during unlink, the file is deleted after the inodemap entry.
   if we crash between these two operations, there will be a file with
   a missing inodemap entry which should be deleted after crash.

3) during rename, the inodemap entry for source file must be updated to 
   contain the destination name before the Unix rename(src, dest) system call 
   is invoked on the filesystem.

   dce_rename(src, dest) 
   {
      1. if (dest exists) delete inodemap entry for dest if it exists
      --- GANESHA PROCESS can CRASH here ---
      2. update inodemap entry for src file to contain dest filename
      --- GANESHA PROCESS can CRASH here ---
      3. make Unix rename(src, dest) system call
   }

   if we crash after step 1, then after recovery, the destination file will 
   be deleted in lookup() or readdir() since its inodemap entry does not exist.  
   This will allow the rename() to be retried successfully, where source file
   is moved to non-existent destination.

   If we crash after step 2, then after recovery, there will be a mismatch. 
   The inodemap entry will contain the the destination filename while
   the filesystem still contains the source filename.  
   Since the destination filename does not exist, the FSAL during lookup()
   or readdir() must update the inodemap entry to contain the source filename.
   Once this is done, the rename() operation can be retried successfully
   by the NFS client.

4) during lookup(dir, file) or readdir(dir), 

   (a) if we detect a partially created file with missing inodemap entry, 
       it means we crashed during dce_create, dce_mkdir, dce_unlink or 
       in dce_rename() after step (2).
       Such a partially created file must be deleted.

   (b) if we detect a file whose inodemap entry contains another name,
       it means we crashed during dce_rename() before calling Unix rename().
       We must update the inodemap entry to contain the file name seen
       in the filesystem.  This will ROLLBACK the partial rename().

       dce_lookup(dir, filename) or dce_readdir(dir)
       {
          inode_of_file = stat(filename)
          filename_in_inode = inodemap[inode_of_file]
          if inodemap entry doesnt exist
          {
             delete filename 
          }
          else if (filename_in_inode != filename)
          {
             inodemap[inode_of_file] = filename
          }
       }
       

This is how various FSAL operations should work to ensure recoverability 
after a crash.

dce_create/mkdir()
{
  create file or dir
  create inodemap entry
}

dce_unlink()
{
  remove inodemap entry
  remove file
}

dce_rename(src, dest)
{
   remove inodemap entry for dest
   inodemap entry[src file] = destination file
   invoke Unix rename(src, dest)
}

dce_lookup(dir, filename_in_dir)
{
   inode_of_file = stat(filename_in_dir)
   filename_in_inode = inodemap[inode_of_file]
   if (inodemap entry does not exist)
   {
       // crash occurred during delete or create
       // or after step 1 of rename
       delete filename_in_dir
   }
   else if (filename_in_inode != filename_in_dir)
   {
      if (filename_in_inode exists in filesystem)
         unknown error
      else
         // crash occurred after step 2 of rename
         // update inodemap to be consistent with filesystem
         inodemap[inode_of_file] = filename_in_dir
   }
}

dce_read_dirents(dir)
{
   for each file in readdir
   {
       // apply same logic as in dce_lookup() 
       filename_in_inode = inodemap[inode_of_file]
       if (inodemap entry does not exist)
       {
           // crash occurred in delete or create 
           // or after step 1 of rename
           delete filename
       }
       else if (filename_in_inode != filename)
       {
          if (filename_in_inode exists in filesystem)
             unknown error
          else
             // crash occurred after step 2 of rename
             // update inodemap to be consistent with filesystem
             inodemap[inode_of_file] = filename
       }
   }
}

-----------------------------------------------------------------------

Locking needed for Multi-threaded operation

With each fsal object handle in the cache, Ganesha NFS keeps three read-write
locks.

struct cache_entry_t
{
   struct fsal_obj_handle *obj_handle;
   ...
   pthread_rwlock attr_lock - protect cached attributes of a file
   ...
   pthread_rwlock content_lock - protect changes to avl_tree which stores files in a directory
   ...
   pthread_rwlock state_lock - state_list or lock_list (for NFSv4 state, it seems)
}


These are the locks taken during or after each operation

FSAL function : Lock taken (Mode)

access : attr_lock (Write)
getattr : attr_lock (Write)

setattr : if size is being set, take content_lock (Write) 

lookup : content_lock on parent directory (Read)
readdir : content lock on directory (Read)
create : after create on fsal, take content_lock on parent directory (Write)
unlink : after unlink on fsal, take content_lock on parent directory (Write)
rename : after rename on fsal, take content lock on both parent directory (Write)

open : content_lock (Write)
close : content_lock (Write)
read :  content_lock (Read)
write : content_lock (Read)
status : content_lock (Read)
commit : content_lock (Read)

Based on the above analysis (limited to 2.1 and can change in 2.4), there 
are two functions which read directory : dce_read_dirents() and dce_lookup() 
and there are three functions which modify directory : dce_create(), 
dce_unlink() and dce_rename().

Since these operations are invoked by the upper layer without holding the
directory "content_lock", it introduces race conditions inside FSAL_DCE
between the directory readers and writers.

Race condition between dce_read_dirents() and dce_rename()

  Thread T1                         Thread T2
 dce_rename(old, new)             dce_read_dirents(dir)

 (events listed in increasing time order)
 T1.1 update inodemap file.filename = new
                             T2.1:readdir() finds old name
                             T2.2:calls dce_check_consistency()
                             T2.3:doesnt find old filename so it thinks
                                  it was due to crash in previous epoch
                                  then updates inodemap file to contain old name
 T1.1 calls syscall rename(old, new)

Now we have a case where directory contains new filename but the corresponding
inodemap file contains old filename.

This problem ONLY occurs for operations which call dce_check_consistency(),
This function was introduced to handle crash consistency, and it achieves
this by reverting the filename set in the inodemap file to the 
actual filename in the directory.

To prevent such race conditions, dce_rename(), dce_create(), dce_unlink() will 
take a write lock on the directory handle and dce_read_dirents() and dce_lookup() will take a read lock on the directory handle.

* Use of fcntl locks

 In our configuration, multiple ESX servers share the same filesystem (Mother nfs)
 To prevent dce_check_consistency() on one NFS server from interfering with
 dce_rename() on another server, we use fcntl locks on 
 /mnt/persist-data/<exportid>/consistency.lck.

 Also, the ESX servers create ".lck" files to guard against split brain.
 In dce_create, dce_unlink or dce_rename, we take write locks to prevent
 the servers from overwriting the common ".lck" files.

-----------------------------------------------------------------------

SECTION 5. Changes required for Multiple NFS servers manipulating shared MotherNFS filesystem

Multiple NFS servers can manipulate the shared filesystem (MotherNFS).
In particular, VMWare creates some directories like "iorm.sf" and ".vSphere-HA"
which are manipulated by multiple VMWare servers.  Any NFS server can 
crash during the creation, deleton or renaming of a file, leaving 
behind an orphan file without its corresponding inodemap entry.

Since an NFS server can crash anytime, every NFS server must do a 
consistency check on the directory not just at startup but during
every readdir().

Since MotherNFS is a shared filesystem, an NFS server cannot rely on 
per-process locks alone.

File-level locks (fcntl) over NFS can be a headache so must be avoided.

The solution then is to create hidden temporary files during dce_create(), 
dce_unlink(), dce_mkdir() and dce_rename() which signify intermediate
states.  These temporary files will be hidden by dce_read_dirents() from 
any NFS server.  Their handle will never be requested during a dce_lookup()
We shall use unique suffixes for these temporary files [".create", ".delete" and 
".rename" ] to enable easier debugging.

dce_create(file1)
{
    tmpfd = create "file1.create"
    ino = inode number(tmpfd)
    ----CREATE_CRASH_1
    create inodemap file "ino.txt" with {name=file1}
    ----CREATE_CRASH_2
    mv "file1.create" "file1"
}

The above logic gives rise to following inconsistencies 
CREATE_CRASH1 : file1.create exists without corresponding inodemap file
    delete file1.create
CREATE_CRASH2 : file1.create exists but inodemap points to name=file1
    delete file1.create and inodemap

dce_rename(old_file, new_file)
{
   if (new_file) exists
      dce_unlink(new_file) (crash within dce_unlink handled in that function)
   mv "old_file" "old_file.rename"
   ---RENAME_CRASH_1
   set old_file_inodemap.name = new_file (using im_update)
   ---RENAME_CRASH_2
   mv "old_file.rename" "new_file"
}

The above logic gives rise to 2 inconsistencies which will be tackled
later in dce_check_consistency()
RENAME_CRASH_1 : old_file.rename exists but inodemap points to name=old_file
   move old_file.rename to old_file
RENAME_CRASH_2 : old_file.rename exists but inodemap points to name=new_file
   set inodemap.name = old_file (not new_file)
   move old_file.rename to old_file
 
dce_unlink(file1)
{
   mv "file1" "file1.delete"
   ---DELETE_CRASH_1
   delete inodemap file of "file1"
   ---DELETE_CRASH_2
   delete "file1.delete"
}

The above logic gives rise to 2 inconsistencies which will be tackled
later in dce_check_consistency()
DELETE_CRASH_1 : file1.delete exists but inodemap.name = file1
DELETE_CRASH_2 : file1.delete exists without corresponding inodemap file

dce_read_dirents()
{
   for each file
   {
      if file suffix is ".create/delete/rename"
      {
        skip it - do not return this filename to upper layer
        call dce_check_consistency() if file is older than 15 min which
        assumes that NFS server which was manipulating the file has died
      }
      else its a regular file
      {
        dce_check_consistency()  - merely check if inodemap file exists
      }
   }
}

dce_lookup(filename)
{
  since readdir() has not returned a file with suffix "create/delete/rename"
  a filename with such a suffix should not be seen here.
  Flag an error if that happens.
}

Consistency checking function which is called from dce_read_dirents() 
or dce_lookup() has to handle following 8 cases

(1) the inodemap.name is different from actual filename
  and file.suffix is 
  "create" => case CREATE_CRASH_2
      delete both inodemap and file
  "delete" => case DELETE_CRASH_1
      delete both inodemap and file
  "rename" => case RENAME_CRASH_1 or RENAME_CRASH_2
     (SEE CODE FOR CORRECT LOGIC)
      lets rollback the incomplete rename()
      mv "file1.rename" "file1" 
      set file_inodemap.name = file1
  normal => not possible
 
(2) the inodemap entry does not exist
  and file.suffix is 
  "create" => case CREATE_CRASH_1
      delete the file
  "delete" => case DELETE_CRASH_2
      delete the file
  "rename" => cannot happen
  normal   => cannot happen

dce_check_consistency(dir_hdl, filename)
{
   im = get inodemap(filename)
   if (im doesnt exist)
   {
     if filename suffix is "create" or "delete"
       delete file
     else 
       error
   }
   else if filename not equals im.name
   {
        if file suffix is "create/delete"
          delete file and im
        else if file suffix is "rename"
          mv filename.rename filename
        else 
          mv filename im.name
   }
}

NOTES:

1) ovsp_isflat() checks for particular suffixes.  Must ensure that function
dce_delete_file() is not called for suffixes.
Otherwise it will clash with new suffix "create/delete/rename" introduced here.

-----------------------------------------------------------------------

 SECTION 6 : New approach to dce_rename()
    It was found previous approach to rename does nto work
    WHen the Ganesha server restarts after a crash, if the
    NFS client is hanging, it resends the rename request.
    At this point, it expects either the new or old file
    to exist.
    
    In the previous approach, neither existed.
    It is necessary to atomically move "old" to "new"
    so either one of them exists.
    
    Therefore, in this approach, the inodemap file
    is enhanced with "new_fname" field in json.
    dce_rename(old_file, new_file) has 3 steps
    {
      inodemap.new_fname = "new_file"
      ---CRASH_1
      rename(old_file, new_file)
      -- CRASH 2
      inodemap.fname = "new_file", and clear new_fname
    }
    
    If we crash at point 1, we reset inodemap.fname = old
    if we crash at point 2, we reset inodemap.fname = new
    Either is done based on the file which exists in the FS



-----------------------------------------------------------------------

==============

OPEN PROBLEMS

1) Address the 2 FIXME comments in handle.c; 
2) Check crash-consistent logic works with SIMF
3) Rename directory bug ; If you move a directory, then you need to substitute 
the new directory name in each file under that directory. 

================

LOGGING

If "-L" is not passed, Ganesha defaults to logging all messages to syslog

logrotate can be used to rotate log files. this has to be changed
from daily run to hourly run or evern shorter.

sending SIGUSR1 to ganesha increases debug level (see call to ArmSignal)
sending SIGUSR2 to ganesha decreases debug level 

Use create_log_facility() to install additional logger.  
Use enable_log_facility() to enable it.  All messages are now sent to all enabled loggers.
Use set_default_log_facility() to make your logger the default.


