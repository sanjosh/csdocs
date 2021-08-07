
# ZippyDB

https://engineering.fb.com/2021/08/06/core-data/zippydb/

1. uses RocksDB
1. data replication library called Data Shuttle.
1. ShardManager
1. config service Zookeeper

ZippyDB deployed in Tiers

each shard replicated across regions.  Mix of sync and async Within a shard, 
1. a subset of replicas are configured to be a part of the Paxos quorum group, also known as global scope, where data is synchronously replicated using Multi-Paxos 
2. The remaining replicas, if any, are configured as followers. These are similar to learners in Paxos terminology and receive data asynchronously.

Stickiness : In addition to the sync or async replication strategy, applications also have the option to provide “hints” to the service 
about the regions in which the replicas of a shard must be placed.

API
1. get
2. put
3. delete
4. range iter
5. test and set
6. TTL

two levels of shard
1. p-shard is Server side shard
2. u-shard is client side microshard
3. allows transparent resharding

two kinds of mappings from μshards to physical shards: 
1. compact mapping  : when mapping is fairly static and changes only when shard size grows
2. Akkio mapping : mapping is managed by service

configurable consistency and durability levels

most popular consistency levels are 
1. eventual, 
2. read-your-writes, 
3. strong.

Conditional write is implemented using “server-side transactions”.  API for use cases based on some common preconditions such as 
1. key_present, 
2. key_not_present, 
3. value_matches_or_key_not_present.


https://engineering.fb.com/2015/06/22/core-data/inside-data-scale-2015/

https://www.youtube.com/watch?v=ZRP7z0HnClc

