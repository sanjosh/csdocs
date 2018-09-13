
# aerospike

* 160_digest = ripemd160(primary_key)
* digest is partitioned into 4096 non-overlapping partitions

* collocate index and data
* index only kept in shared memory
* index rebuilt after crash
* (use rb-tree for primary, B-tree for secondary - all in mem)

* threads are bound to cpu socket, not core
* to reduce context switch, all work for network request done by same thread
* use jemalloc extensions
* use of partitioned single-threaded data structures
* cooperative scheduling
* job management - 

```

                            -> work queue -> worker threads
   [job queue] -> generator -> work queue -> worker threads
                            -> work queue -> worker threads

```

* SSD is used in raw mode
* SSD block is never overwritten 
* like log structured filesystem with continuous background defrag
* use of shadow device - write to local store and EBS 
