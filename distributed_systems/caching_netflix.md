
# Caching at netflix - scott mansfield

EVCache

distributed sharded replicated key value
based on memcached
topology aware

why optimize for AWS : unstable regions, zones fail, instances disappear, lossy network

Three levels (L1/L2)
1. Local Cache
2. EVCache remote
3. Prana Sidecar

Cache can be filled in background by offline services

cross region cache replication via Kafka

Cache warming pulls data from Kafka and pushes to new cache

## Moneta

## reference

https://www.youtube.com/watch?v=Rzdxgx3RC0Q
