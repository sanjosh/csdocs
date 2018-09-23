
# open loop queueing system

P-K Pollaczek-Khinchine formula

mean queueing delay = U/(1-U) * linear fn(mean svc time) * quadratic fn(svc time variability)

this produces hockey stick

how to improve mean response time (reactive)
1. set max queue length
2. client side backoff
3. Controlled delay (CoDel) - allow short bursts, prevent standing queues.
4. process requests in adaptive LIFO because oldest requests are likely to timeout - dont waste work by processing them.

proactive ways to improve mean resp time - based on formula above
1. decrease svc time by optimizing code
2. decrease svc time variability by batching requests

# closed loop queueing system

fixed num of clients

low util regime - resp time stays about same
high util regime - resp time grows linearly with N
NO hockey stick here

# take-away

do not model open system with closed.

# cluster of servers

why cluster of N servers does not scale 
* contention penalty (serialization) increases linearly with N
* crosstalk penalty (synchronization) increases quadratic with N

how to improve scalability
* smarter aggregation
* smarter partitioning
* better load balancing
* fine grained locking
* MVCC

universal scalability law



# Reference
Kavya Joshi applied performance theory
https://www.youtube.com/watch?v=M5r-IVxP-WI
