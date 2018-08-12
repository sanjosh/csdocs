
# Theory

## synchronization
1. async
2. semisync / quorum
3. sync

## Replication type
1. master-slave
2. master-master

# MySQL 

Replication methods
1. binlog - logfiles
2. GTID-based (no logfiles)

Synchronization
1. sync (MySQL cluster)
2. semisync
3. async

Replication format
1. Statement-Based replication. Execute SQL stmt on slave
2. Row-based replication. only changed rows. copy row to slave
3. Mixed-based replication 

http://dev.mysql.com/doc/refman/5.7/en/replication.html

* Master writes to binlog
* Slave has 2 threads
* IO thread puts data into relay_log 
* SQL thread : relay_log -> apply trans

https://www.percona.com/blog/2014/03/27/a-conversation-with-5-facebook-mysql-gurus/


# MongoDB

oplog - capped collection (circular buffer) stored in StorageEngine

src/mongo/db/repl

ops=insert/update/delete/db_cmd with bson

* local.startup_log
* local.system
* local.oplog

https://www.compose.io/articles/the-mongodb-oplog-and-node-js/

Also has journaling

http://daprlabs.com/blog/blog/2014/04/19/mongodb/


# TODO

Cassandra
Postgres
Pinot distributed OLAP like Druid
Toku
HBase
Bigtable
Voldemort key value store from Linkedin
Espresso doc store
Lucene
PacificA

https://engineering.linkedin.com/distributed-systems/log-what-every-software-engineer-should-know-about-real-time-datas-unifying

Elnozahy : Rollback recovery protocols in message passing systems
