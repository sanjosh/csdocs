
# why Lyft invented Envoy

AWS external ELB -> haproxy/nsq -> AWS internal ELB

problems
* multiple languages and frameworks
* multiple protocols : HTTP, gRPC, REST
* black box load balancers - logs in S3
* lack of consistent observability (stats, logging, trace)
* no retry, circuit breaker, rate limit, timeouts
* minimal authN and authZ

Sidecar proxy alongside every host 

## envoy

Library based approach vs out-of-process approach 

Envoy chose second - language agnostic

Self contained proxy : L3/L4 filter TCP

* written for HTTP/2
* does active/passive health check (ping and monitor traffic)
* advanced load balancing
* also used as edge proxy (normally people use nginx as edge, haproxy as middle proxy)
* envoy has thin clients

## Envoy manager xDS (like istio)

* not require config file on every server
* listener discovery service
* cluster discovery service

## question

serverless with envoy ?

https://www.youtube.com/watch?v=55yi4MMVBi4
