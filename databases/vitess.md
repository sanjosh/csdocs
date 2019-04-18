
read replica
write sharding
disaster recovery

DR adds maintenance tasks
query mediator - protect from toxic queries
make it appear as one db

proxy server called vttablet 
1. connection pooling
2. row cache (besides mysql buffer cache)
3. query de-duplication
4. blacklist query
5. limit list of queries
6. stats module

topology mgr - lock server (master failover)

vtk - collective whole - use topology

sharding is a noSQL concept

in Relational, you have primary keys, secondary indexes - unique & non-unique, foreign keys

In vitess, every row is range sharded by keyspace id 
it is not physical column
you can define multiple mapping func; its pluggable

how to have auto-incr => use sequence

vitess supports cross-shard index.  there is backing table - even that can be sharded to avoid contention.

support 2pc 

support message queues

support row based replication

online schema swap

able to co-locate and co-shard 2 tables

what if table has foreign key to another table which is sharded differently

vttablet
1. conn pooling
2. results reuse
3. sql parser, row rewriter
4. rowcache 

# SCALE 

some reads can be stale; some need fresh

replicas cannot keep up with write TPS

with sharding - CONS : bad joins, fat client, cross-shard index

# References

1. 2017 Percona - https://www.youtube.com/watch?v=57al_MMGr-Q
2. 2014 @Scale https://www.youtube.com/watch?v=5yDO-tmIoXY


