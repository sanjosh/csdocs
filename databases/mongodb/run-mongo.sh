$ scons -j20 --dbg=on --opt=off CPPPATH=/usr/local/include LIBPATH=/usr/local/lib

$ more mongo.conf 
 systemLog:
   destination: file
     path: mongo.log
       logAppend: true

       storage:
         dbPath : /mnt/data/db

$ gdb --args ./mongod --config mongo.conf --storageEngine rocksdb
