
https://www.youtube.com/watch?v=8age_72M_NE

QCon 2020 The Evolution of Distributed Systems on Kubernetes
Bilgin Ibryam 

# extension mechanisms

## Pod : 

give deployment guarantee : all on same node

give lifecycle guarantee : init containers which start sequentially and then run app container

## sidecar pattern 

cooperating containers

## operator pattern

reconciliation loop : drive desired state to actual state.   

e.g. write custom controller which reloads changed config file

# Knative

serverless for eventing

# Dapr

# envoy

Service mesh is adding support for more protocols such as MongoDB, ZooKeeper, MySQL, Redis, and the most recent one is Kafka.

envoy can do http caching, tap filter, webassembly









