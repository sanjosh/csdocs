
# Aerospike

## Partition

Compute digest = ripemd160(primary_key)
digest is partitioned into 4096 non-overlapping partitions

## Indexing

collocate index and data
index only kept in shared memory
Index is rebuilt after crash
use rb-tree for primary, B-tree for secondary - all are in RAM

## Systems

threads are bound to cpu socket, not core
to reduce context switch, all work for network request done by same thread
Use of jemalloc arena xtensions
use of partitioned single-threaded data structures
Use of cooperative scheduling
job management framework 

                            -> work queue -> worker threads
   [job queue] -> generator -> work queue -> worker threads
                            -> work queue -> worker threads

## Storage

SSD is used in raw mode
SSD block is never overwritten 
like log structured filesystem with continuous background defrag thread

## Backup

use of shadow device - write to local store and EBS 

