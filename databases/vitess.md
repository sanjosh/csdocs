
# Vitess talk (youtube)

## Workload

* how much data per video and per user (static and dynamic)
* what is read-write ratio for youtube mysql ?
* number of distinct queries at youtube 
  1. programmatic or human 
  2. do analytical queries run on vitess as well?

## Mysql

* gtid based repl ?
* statement based or row-based
* innodb or rocksdb

## Proxy

* would it have been simpler to modify mysql server instead of building vitess front-end

* why not modify mysql proxy instead of vtablet or vtgate (mariadb has its own proxy - maxscale)

* subscribes to its own mysql server for cache invalidation (fb annotated binlog to update memcache)

* why not use mysql features ? its possible to kill queries in slow log

## Sharding 

* how to maintain foreign key constraints
* joins
* uneven distribution
* UDFs 
* does table need primary key ?

* replication lag for bulk ops 

* do u disable mysql buffer cache, given the row cache

* why is per conn cost 2 MB (cant u reduce buffers)

* vttablet query cache - why not use mysql query cache ? do you also cache negative results ?

* mysql query cost (does vttablet use query optimizer)
 - does it keep per-user limits ?

http://vitess.io/overview/#architecture

http://vitess.io/user-guide/sharding.html



# new planner

https://vitess.io/blog/2021-11-02-why-write-new-planner/
