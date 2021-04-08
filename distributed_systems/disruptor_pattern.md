
# Martin Thompson - mechanical sympathy

## earlier attempts

1. SEDA
2. Actor

## queues are a problem

"queuing of events between stages in the pipeline was dominating the costs.  We found that queues also introduced latency and high levels of jitter. "

balancing producer and consumer rate

locks on queues; CAS on queues - both problematic

## solution

```
A more conventional approach might use a Producer Queue and a Consumer Queue, 
each using locks as concurrency mechanisms. 

In practice, what happens with producer and consumer queues is that the queues 
are either completely empty or completely full most of the time, which causes 
lock contention and wasted clock cycles. 

The disruptor alleviates this, in part, by having all of the producers and 
consumers use the same queue mechanism, coordinating with each other by watching 
the sequence counters rather than using locking mechanisms.
```
https://softwareengineering.stackexchange.com/questions/244826/can-someone-explain-in-simple-terms-what-is-the-disruptor-pattern

data should be written by only one thread

like Phasers in Java 7 - Fork Join pool
https://docs.oracle.com/javase/8/docs/api/java/util/concurrent/Phaser.html

preallocated bounded data structure like a ring buffer - no garbage collection

this creates batching effect where consumers can process ring buffer

# Ref


http://lmax-exchange.github.io/disruptor/files/Disruptor-1.0.pdf



