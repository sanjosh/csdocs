
# shuffling waiters to improve locking

The key idea of shuffling is to re-order the queue of threads waiting to acquire the lock in accordance with some pre-established policy. 
For best performance, this work is done off the critical path, by the waiter threads. 
Using shuffling, we demonstrate how to achieve NUMA-awareness and implement an efficient parking/wake-up strategy, without any auxiliary data structure, mostly off the critical path. 

https://dl.acm.org/doi/10.1145/3341301.3359629
Scalable and practical locking with shuffling
Sanidhya Kashyap
