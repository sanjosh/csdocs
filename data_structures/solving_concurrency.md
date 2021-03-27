
# Methods to resolve concurrency

Using shared mem :
1. locks or mutexes
2. wait-free algorithm

No shared mem :
1. hardware transaction memory
2. functional data structures
3. actor-based model

(from a Tarantool database presentation)

# Concurrent design patterns

* hazard pointers [Michael. Safe memory reclamation 2002]
* repeat offender problem [Herlihy Luchangco. Repeat Offender problem 2002]
* epoch based designs [Fraser. Practical Lock freedom 2004, King & Lehman. Concurent Binary Search tree 1980, Levandovski. Bw-tree, Mao Kohler. Cache Craftiness for fast multicore key-value storage, Tu Zheng Liskov, Speedy transactions]
* RCU

# CRDT 

1. operation based
2. state based

# Actor model

## problems

1. livelocks
2. non-determinism coming from waiting for multiple channels
3. use of buffered vs unbuffered channels

https://blog.acolyer.org/2019/05/17/understanding-real-world-concurrency-bugs-in-go/


