
# Methods to resolve concurrency

Using shared mem :
1. locks or mutexes
2. wait-free algorithm

No shared mem :
1. hardware transaction memory
2. functional data structures
3. actor-based model

*(from a Tarantool database presentation)*


# Concurrent design patterns

* hazard pointers [Michael. Safe memory reclamation 2002]
* repeat offender problem [Herlihy Luchangco. Repeat Offender problem 2002]
* epoch based designs [Fraser. Practical Lock freedom 2004, King & Lehman. Concurent Binary Search tree 1980, Levandovski. Bw-tree, Mao Kohler. Cache Craftiness for fast multicore key-value storage, Tu Zheng Liskov, Speedy transactions]
* RCU

