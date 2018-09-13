
# Google BigTable

* sparse distributed persistent multi-dim sorted map
* map indexed by row key, column key and timestamp
* timestamp can be assigned by bigtable or user
* client can specify how many versions of cell to keep

* tablet location stored in B+-tree like structure (3-level hierarchy)
* chubby file -> root tablet -> metadata tablet -> user table

* client can group multiple column families into locality group
* separate SSTable generated for each locality group

* SSTable has two caches : scan cache of recent key, value
* sstable has bloom filter

two pass compression 
1. compress long strings in large window, 
2. then repetitions in small window

* keep single commit log per tablet server (across all tablets)
* complicates recovery - sort the log file 
* block cache of sstable blocks

