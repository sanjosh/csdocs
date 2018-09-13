
# RethinkDB

JSON

* Simple
* Compound
* Multi-index : document/row can be indexed using multiple values
* Expression index 

Tailable cursor / push-based model to find changes:

BTree

* range sharding of primary key
* shards have to be rebalanced if inserts become uneven
* only one doc can be updated atomically
* reads takes snapshot of Btree
* storage engine is log structured like BtrFS
* incremental fully concurrent GC on disk
* database itself becomes log
* disadvantage - large amount of data becomes obsolete in heavy insert/update
* workload
* disadvantage - eliminates data locality

http://www.cs.toronto.edu/~ryanjohn/teaching/csc2531-f12/rethinkdb-whitepaper.pdf

* uses coroutines

https://github.com/rethinkdb/rethinkdb/blob/next/src/btree/secondary_operations.hpp
