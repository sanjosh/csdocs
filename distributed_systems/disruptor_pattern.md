
# Martin Thompson - mechanical sympathy

## earlier attempts

1. SEDA
2. Actor

## queues are a problem

"queuing of events between stages in the pipeline was dominating the costs.  We found that queues also introduced latency and high levels of jitter. "

balancing producer and consumer rate

locks on queues; CAS on queues - both problematic

## solution

data should be written by only one thread

like Phasers in Java 7 - Fork Join pool
https://docs.oracle.com/javase/8/docs/api/java/util/concurrent/Phaser.html

preallocated bounded data structure like a ring buffer - no garbage collection

this creates batching effect where consumers can process ring buffer

# Ref


http://lmax-exchange.github.io/disruptor/files/Disruptor-1.0.pdf



