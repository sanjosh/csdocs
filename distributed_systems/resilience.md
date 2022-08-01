
# principles

1. data plane does not depend on control plane of dependents
2. metrics pyramid : diagnostic (cpu, mem), operational (throughput, latency), business
3. blast radius

# randomness

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

# other

health check fails when system busy : use alternative signals of health, prioritize health check

timeout, exp backoff, retry cycle can cause the resource under contention to become idle; add jitter to backoff

Do AIMD for small number of correlated streams; AND exp backoff for large number of events

use shuffle sharding for multi-tenant shared resources

reduce blast radius or size of failure domain; cell is independently deployed subset of stack

brownout is when resp time is too slow to be useful.  if lock contention is high, or cpu util too high, then start load shedding - backpressure

stop wasting work; stop working if nobody listening; ask client to specify if its retry as well as deadline 

expose current pending jobs information to client

load balancing must be across failure domains

no fallback logic : always do the extra work (checks, logging, etc) that you would do on failure - that way, no extra load introduced on a failure

how to plan for software rollback 
1. protocol upgrade : do two phase deployment.  upgrade servers to talk both protocols.  
2. database upgrade : run mixed fleet (some servers old, some new)

how to propagate call timeouts thru chain of dependent services; timeout of parent request must be greater than child request; cancelation must propagate

handling thundering herd, bursts : high peak to average ratio

# Service

* mix of clients (latency sensitive vs throughput, high volume vs low volume)
* rate limit the clients and compartmentalize
* use client identifier to distinguish request
* use request identifier if its a retry 
* use request deadline to decide execution strategy
* internally, specify timeouts that are smaller than deadline
* reserve minimum resources per client
* record current resource usage and throttle
* expose hard limits via API 
* expose current resource usage via API
* provide estimated ETA during submit
* send paginated response
* error must be retryable with retry interval, throttling, non-retryable
* provide partial result if possible
* provide sync/async/batch API
* for call from high volume to low volume, use request&response queue

# Client

* use cache in case of failure
* use backoff and jitter
* generate unique request identifier to enable retry
* propagate timeout as deadline

# Database

* fixed insert and query times
* connection pool
* curb database growth
* impose timeout on queries

# Queues

* be bounded to throttle
* allow custom retreival like lifo in case of brownout
* allow priority
* allow expiration via TTL
* allow cancelationf from publisher
* versioning, in case older expired message is read
* break down tasks to process partially

# TODO

1. Ford, et al. Availability in Globally Distributed Storage Systems. Google Inc
2. Session State : Beyond Soft state (NSDI 04)
