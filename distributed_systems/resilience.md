
* adding randomness can increase entropy.
* predictable systems are easy to operate
* therefore, be unique but consistent - seed all randomness based on one seed

randomize memory layouts within a system
1. jvm heap size randomization (explore CMS GC)
2. use random seeded hash func to change collision pattern
3. randomize array resizing, tree, etc

reduce correlation between independent servers/agents
1. vary the limits on queues, timeouts, disk vol sizes
2. add jitter to periodic tasks

timeout, exp backoff, retry cycle can cause the resource under contention to become idle; add jitter to backoff

Do AIMD for small number of correlated streams; AND exp backoff for large number of events

use shuffle sharding for multi-tenant shared resources

brownout is when resp time is too slow to be useful.  if lock contention is high, or cpu util too high, then start load shedding - backpressure

stop wasting work; stop working if nobody listening; ask client to specify time bound along with work; 

load balancing must be across failure domains

no fallback logic : always do the extra work (checks, logging, etc) that you would do on failure - that way, no extra load introduced on a failure

how to plan for software rollback 
1. protocol upgrade : do two phase deployment.  upgrade servers to talk both protocols.  
2. database upgrade : run mixed fleet (some servers old, some new)

how to propagate call timeouts thru chain of dependent services 

handling thundering herd, bursts : high peak to average ratio

# TODO
1. Ford, et al. Availability in Globally Distributed Storage Systems. Google Inc
2. Session State : Beyond Soft state (NSDI 04)
