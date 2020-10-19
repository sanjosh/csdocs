

## Scope

Contains overview of FSAL implementation for version 2.4-Stable of Ganesha

Does not cover or support 

* pNFS
* Data server (fsal_dsh_ops) 
* extended attributes 
* quota functions

## Data structures exposed by Ganesha


Fsal_module
{
   List of exports
   List of object handles
   
   Fsal_ops m_ops [ module operations ]
}


Fsal_export
{
    List of exports from same FSAL
    up link to fsal module

    Fsal_up_vector
    export_ops
}

Fsal_object_handle
{
    Ptr to fsal_filesystem
    Ptr to fsal_module
    Fsal_obj_ops
    Pthread_rwlock on handle
    Fsid (filesystem id)
    Fileid (unique identifier of file)
    State_hdl ptr
}

Fsal_filesystem
{
   Ptr to Fsal_module
   fsid   
}

Fsal_obj_ops
{
}

Fsal_up_vector
{
}

Req_op_context 
{
    ptr to fsal_export
   Ptr to fsal_module
}

## MISC

fsal_staticfsinfo_t
Fsal_dev_t
Fsal_share [ ignore related to microsoft]
Fsal_status_t
Fsal_cookie_t : cookie used to remember position during reading of directory

Data structures for reading FSAL config file
Config_item
Config_block
config_file_t

## FSAL Commonlib

## Format of Ganesha Cache (FSAL_MDCACHE)

Mdcache_key  -> mdcache_fsal_obj_handle

## Global Objects inside FSAL

Dce_fsal_module is one per FSAL 
Dce_fsal_export is one per export

Dce_fsal_module 
{
    Fsal_module
    fsal_staticfsinfo
}

Dce_fsal_export
{
    Fsal_export
    Export path
    Root object handle
}

Dce_fsal_obj_handle
{
   Fsal_obj_handle
   Fsal_export
   <other>
}
Call flow

All FSAL operations are invoked from fsal_helper.c

## Module operations	(fsal_ops)

Call fsal_attach_export() and fsal_detach_export() 

### Create_Export (module handle) 

dce_exp = Allocate dce_fsal_export
fsal_export_init(dce_exp)
fsal_attach_export(module handle)

### Init_Config

display_fsinfo()

### Dump_config

### Unload

unregister_fsal()


## Export Operations (export_ops)

NOTE


Handle_digest : fsal object handle -> wire handle
Extract_handle : wire handle -> cache key
Handle_to_key : fsal_handle -> cache key

Therefore, 
handle_to_key(fsal obj handle) = extract_handle(handle_digest(fsal obj handle)

Get_name

Ignore

Unexport

ignore

Release[export] (fsal_export)

fsal_detach_export()
free_export_ops()
fsal_object_fini(export_handle->root_handle)

Lookup_path : path -> new fsal obj handle

Handle = allocate
fsal_object_handle_init(handle)
Extract_handle : wire handle -> cache key
Create_handle : wire handle -> new fsal obj handle
get_fs_dynamic _info (export handle, directory handle)
Fs_supports
Fs_supported_attrs

## Upcall operations for export (fsal_up_vector)


Invalidate (cache key)
Update (cache key)
lock_grant(cache key)
lock_avail(cache key)
layoutrecall(cache key)
Notify_device
delegrecall
invalidate_close

## Object handle Operations (fsal_obj_ops)

Call Fsal_obj_handle_init() and fsal_obj_handle_fini() when allocating and freeing object handle


## Directory operations
Lookup : path -> new fsal obj handle
Readdir
Create[file]
Mkdir
Mknod
Symlink
Unlink
Link [hard]
File Operations
Readlink
Test_access
Getattrs
Setattrs
Rename






## (IO operations)
Open
Reopen
Status
Read
Read_plus
Write
write_plus
Seek
Io_advise

Commit
Lock_op
Share_op [ignore - microsoft]
Close

## (Handle operations)
Handle_is
handle_cmp
Handle_digest  : fsal_handle -> wire_handle
Handle_to_key : fsal_handle -> cache_key
Get_ref
put_ref
Merge [duplicate obj handles]
Release[Object handle]



