
Maurice Herlihy (1991) ranks atomic operations by their consensus numbers, as follows:

1.  ∞: memory-to-memory move and swap, augmented queue, compare-and-swap, fetch-and-cons, sticky byte, load-link/store-conditional (LL/SC)[1]
2.   2n - 2: n-register assignment
3.   2: test-and-set, swap, fetch-and-add, queue, stack
4.   1: atomic read and atomic write

It is impossible to implement an operation that requires a given consensus number with only operations with a lower consensus number, no matter how many of such operations one uses.[2]

http://en.wikipedia.org/wiki/Read-modify-write

Maurice Herlihy (1991) proved that test-and-set has a finite consensus number, in contrast to the compare-and-swap operation. The test-and-set operation can solve the wait-free consensus problem for no more than two concurrent processes.[1] However, more than two decades before Herlihy's proof, IBM had already replaced Test-and-set by Compare-and-swap, which is a more general solution to this problem.

http://en.wikipedia.org/wiki/Test-and-set

http://en.wikipedia.org/wiki/Compare-and-swap

http://en.wikipedia.org/wiki/Load-link/store-conditional

A non-blocking algorithm is 
1. lock-free if there is guaranteed system-wide progress regardless of scheduling; 
2. wait-free if there is also guaranteed per-thread progress.

In modern usage, therefore, an algorithm is non-blocking if the suspension of one or more threads will not stop the potential progress of the remaining threads. They are designed to avoid requiring a critical section. 

Locks cause deadlocks, livelocks, priority inversion, coarse-grained locking

Additionally, some non-blocking data structures are weak enough to be implemented without special atomic primitives. These exceptions include:

1. single-reader single-writer ring buffer FIFO
2. Read-copy-update with a single writer and any number of readers. (The readers are wait-free; the writer is usually lock-free, until it needs to reclaim memory).
3. Read-copy-update with multiple writers and any number of readers. (The readers are wait-free; multiple writers generally serialize with a lock and are not obstruction-free).

Until 2011, wait-free algorithms were rare, both in research and in practice. However, in 2011 Kogan and Petrank[12] presented a wait-free queue building on the CAS primitive, generally available on common hardware. Their construction expands the lock-free queue of Michael and Scott,[13] which is an efficient queue often used in practice. A follow-up paper by Kogan and Petrank[14] provided a methodology for making wait-free algorithms fast and used this methodology to make the wait-free queue practically as fast as its lock-free counterpart.

In general, a lock-free algorithm can run in four phases: completing one's own operation, assisting an obstructing operation, aborting an obstructing operation, and waiting. Completing one's own operation is complicated by the possibility of concurrent assistance and abortion, but is invariably the fastest path to completion.

http://en.wikipedia.org/wiki/Non-blocking_algorithm

http://en.wikipedia.org/wiki/Memory_barrier


