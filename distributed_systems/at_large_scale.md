
# phenomenon at large scale

| problem | solution space |
| ----  | ---- | 
| thundering herd | cache, randomize, power of two choices, coordinated cache fill, periodic refresh |
| brownout | retry throttle, timeouts, caching, fail fast, circuit breaker |
| fail due to unpredictable limits | use cells, admission control, fast restart |
| noisy neighbour | quotas, bounded work, credits, admission control |
| tail latency | fast path, more RAM, more workers, optimize code, shift work to background |
| blast radius | replicate, cells, shuffle sharding |
| partial degradation | cache, partial, push and pull, fast restart |
| automation breakdown | limit the number of changes, monitor anomalies |
| stale data, TOCTOU, throughput dilution, wobbling state | replica coordination, decide ground truth |
| correlated workloads create spikes | statistical multiplexing |

# solutions

1. prefer approximate over accurate, eventual consistent (sketches)
1. denormalize 
2. randomize, add jitter
3. stateless over stateful 
3. short-term state : leases, periodic disconnects or periodic refresh, TTL
4. fail safe : caching, partial results, push vs pull
5. cellular architecture and shuffle sharding
6. minimize modes of operation
7. do constant work at all load levels
8. balance push and pull (large fleet calling small fleet)
9. prefer async or batching over sync
10. run anomaly detection at scale
11. changing scales : design for varying time scales of data (e.g. data vs metadata)
12. connection pools
12. latency budget : RAM > SSD > HDD
13. throughput budget : per machine capacity, per db node capacity
14. source of ground truth must be constant; if it changes, throw away old decisions
15. statistical multiplexing to create uncorrelated workloads on same machine & avoid spikes

## summary

1. decouple stable from dynamic (what will change over time)
1. async over sync
1. stateless over stateful
1. approximate over accurate
1. push vs pull

base entities of the domain
layers of data changing over time

separate data plane and control plane 

tail latency : fast path has to be unconditional (no GC, no allocation)

thundering herd : caching, rate limit

uneven load : randomize to decorrelate

multi-tenant

failure 
1. reduce wasted work : request has TTL, cancelation, timeout
1. just reboot : time taken to rebuild from scratch, avoid complex logic on failure, 
1. fail fast, cache, use short-term state, do partial processing
1. blast radius : cells, have predictable zones of operation, quotas

compatibility  :backward and forward

reduce manual touchpoints

security

graceful recovery after failure : pending work, new requests

protocol upgrade : first everyone must read new protocol, then write new
