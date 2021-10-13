
NoSQL

* consistent hashing 
* virtual nodes
* CQL
* peer-to-peer distributed

Secondary index 
1. is also LSM
2. is also distributed ( each node stores index for data it holds)
3. stored in hidden column family

after delete or update in primary table, cassandra postpones index update - it invalidates index until read occurs

range query is optimized
1. query in rounds, increase number of nodes in each round
2. based on index selectivity

Also has materialized views which are global

# Fine-Grained Replicated State Machines for a Cluster Storage System

NSDI 2020

https://www.usenix.org/system/files/nsdi20-paper-liu-ming.pdf
