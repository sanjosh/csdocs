
# Reactor pattern 

doug schmidt

# Async Event handling framework

Various alternatives
1. libevent/libevent2 : not MT-safe
2. libev : MT-safe but level-triggered; can cause thundering herd.
3. libuv : edge-triggered 
4. boost asio
5. epoll : all above use epoll, signalfd, timerfd, eventfd

# Numa awareness

1. NIC interrupts to CPU core
2. per-core memory allocator
3. Block device driver has per-core queue
4. Threads are bound to CPU core.
5. Support for NUMA awareness from underlying libraries 

## references

1. WiredTiger advises disabling numa zone reclamation policy 

http://source.wiredtiger.com/2.2.0/tune_zone_reclaim.html
https://queue.acm.org/detail.cfm?id=2513149

2. Carrefour indicates that non-uniform access overhead has come down to about 30 percent.   It kicks in only when there is congestion in memory controllers.  (http://cacm.acm.org/magazines/2015/12/194641-challenges-of-memory-management-on-modern-numa-systems/abstract)

# Coroutines

1. libcoro

# Async Disk IO

1. use iosubmit(2)
2. libeio
3. libuv

# Networking server / C10K problem

Alternatives
1. thread per client connection
2. shared threadpool 
3. SEDA (Staged event driven architecture)

## References

1. “Comparing the performance of web server architectures” http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.141.5192
2. blog post “Retrospective on SEDA” http://matt-welsh.blogspot.in/2010/07/retrospective-on-seda.html

# Examples

## Folly + Wangle from Facebook

1. Wangle derived from Netty.
2. Uses libevent internally
3. Executor service
4. Pipelining available in Wangle 

## Seastar

1. Starts dedicated thread to issue disk I/O from internal queue. This makes it appear to calling thread as if I/O is async.  
2. Divides RAM on startup and instantiates tcmalloc-type memory allocators for every NUMA node.  
3. Defines per-core Reactor, which has a thread for epoll() and another thread to monitor the task queue.  
4. Defines per-core mutexes (rwlock)


