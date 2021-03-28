
# phenomenon at large scale

1. thundering herd : randomize, power of two
2. noisy neighbour : quotas, bounded work
3. tail latency : more RAM, more workers, optimize code, shift the work
4. blast radius : cells
5. degradation : fail safe

# solutions

1. approximate over accurate, denormalize, eventual consistent
2. randomize
3. stateless over stateful (e.g. periodic disconnects to reconfigure, TTL)
4. fail safe : caching, partial results, push vs pull
5. cellular architecture and shuffle sharding
6. minimize modes of operation; do constant work at all load levels
7. push versus pull
8. async over sync
9. anomaly detection at scale
