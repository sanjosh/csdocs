
# Problems and solutions

| problem | solution |
| ------  | ------   |
| oscillations/jitter | resource reservation |
| unbounded queues | throttling |
| fragmentation | bespoke allocators, garbage collection |
| contention | dedicated threads, lock-free data structures |
| random IO | caching |
| excessive interrupt | polling (as in linux net drivers) |
| stale data | invalidation on write, TTL |


