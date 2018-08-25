
# Faster : Concurrent Key value store (Microsoft)

## objectives

make common case fast
1. optimize point ops
2. optimize update ops (blind AND read-modify-write)
3. concurrent
4. support larger than RAM
5. NOT range scan (workaround : keep histogram of key ranges)

## user interface

dynamic codegen for updates, read, upsert, delete

## epochs

* epoch based synchronization
* shared atomic counter called "epoch" E
* each thread has thread-local version of E
* shared epoch table with one cache line per thread
* epoch `c` is safe if all threads have local E_t > c
* global actions (drain list) are invoked when epoch is safe
* examples of actions are GC, index resize, page flush, checkpoint

## Hash index

* each bucket is 64 byte cache aligned.  Allows latch-free ops using CAS
* Each bucket has 7 8-byte "bucket entries" and one 8-byte entry for overflow bucket ptr.
* Each bucket entry has {15-bit tag, tentative bit, 48-bit address}

## insert

```
Faster uses a latch-free two-phase insert algorithm that leverages the tentative bit entry. A thread finds an empty slot and inserts the record with the tentative bit set. Entries with a set tentative bit are deemed invisible to concurrent reads and updates. We then re-scan the bucket (note that it already exists in our cache) to check if there is another tentative entry for the same tag; if yes, we back off and retry. Otherwise, we reset the tentative bit to finalize the insert.
```

## hybrid log

* log spans disk and RAM, tail is in RAM
* addressed by 48-bit logical address
* log divided into 3 sections {stable, read-only, mutable}
* mutable log can be in-place updated; rest required RCU
* leverage epochs to handle eviction of pages from RAM to disk

## fuzzy checkpoint

* Record the tail-offset of the HybridLog before starting (t_1 ) and after completing (t_2 ) 
* During recovery, we scan through the records between t_1 and t_2 on the HybridLog in order, and update the recovered fuzzy index wherever necessary. 
* The resulting index is a consistent hash index that corresponds to HybridLog until t_2.

## Resizing the hash index

Shrinking/Resizing occurs in 3 phases
1. prepare
2. resize : copy buckets to new index
3. stable

Hash index divided into n contiguous chunks

Shared pin array of n counters, used during resizing to indicate number of threads which are updating buckets in a given chunk.


# Garbage collection

todo

# TODO

Intel TBB Hash Map

