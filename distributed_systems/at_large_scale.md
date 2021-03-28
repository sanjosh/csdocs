
# phenomenon at large scale

| problem | solution space |
| ----  | ---- | 
| thundering herd | cache, randomize, power of two choices, coordinated cache fill, periodic refresh |
| noisy neighbour | quotas, bounded work, credits, admission control |
| tail latency | fast path, more RAM, more workers, optimize code, shift work to background |
| blast radius | replicate, cells, shuffle sharding |
| degradation | cache, partial, push and pull, fast rebuild  |

# solutions

1. prefer approximate over accurate, denormalize, eventual consistent
2. randomize, add jitter
3. stateless over stateful (e.g. periodic refresh, periodic disconnects to reconfigure, TTL)
4. fail safe : caching, partial results, push vs pull
5. cellular architecture and shuffle sharding
6. minimize modes of operation
7. do constant work at all load levels
8. balance push and pull (large fleet calling small fleet)
9. prefer async over sync
10. run anomaly detection at scale
