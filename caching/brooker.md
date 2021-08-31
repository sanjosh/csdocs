
# good caches are part of feedback loops which reduce load

latency increases with concurrency; concurrency increases with latency

congestive collapse

cache is empty => db requests fail => cannot fill cache

load testing does not test bad patterns

caches are based on assumptions of locality of cache

CPU caches are immune from this problem because slowness caused by empty caches slows down your interaction

