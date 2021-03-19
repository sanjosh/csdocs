
# SOA patterns

https://afedyanin.wordpress.com/pages/soa-patterns/
https://www.amazon.co.uk/SOA-Patterns-Arnon-Rotem-Gal-Oz/dp/1933988266/

# Why SOA

* services can scale independently

# Practical problems/Phenomenon in SOA

## services get defined by team structure
* mitigation : use inverse conway maneuver
 
## data service gets defined, becomes intermediary, which increases coupling
* this is done in order to follow the principle "Service must encapsulate DB"
* mitigation : split entities along with services; use workflows or append-only stores. Domain drive design(Evans).

## every service generates its own identifiers to be independent
* forced to keep mappings between identifiers

## Json document is passed between services
* document has many sections, each section can only be written by one service, but many services can read a section.
* due to lack of global picture, the code which interprets a doc section gets duplicated
* reduces insulation from changes in upstream services (e.g. relationships between entities)
* over time, makes it difficult to add new features or change existing (adds a flag in API, extend an enum in many places)
* mitigation : tie the code with the doc, and version both

## hidden dimensions were not thought of earlier
* these become hard-coded in every service 
* gradually, they assume importance and become first-class services

## CRUD tends to couple readers and writers, who sit on different pipelines
* mitigation : command query separation (CQRS instead of CRUD)

## Every service talks to every other service
* mitigation : introduce layering of services (platform, entity, business logic, presentation, orchestration)
* mitigation : and introduce discovery service to find instance of a service 

## Orchestrator increases coupling
* mitigation : use choreography

## No resilience to failure - pack of cards which collapses
* one service goes down, everything is blocked
* mitigation : service must be able to work in degraded mode if dependency is down
* mitigation : service must support bulk APIs to enable catch-up on backlog after recovery
* mitigation : service must explicitly encode dynamic fallback strategies
* See hystrix

## fixed bandwidth systems - not adaptive
* hard-coded constants in code and config file
* mitigation : dynamic discovery and download of tuning parameters
* flip side is oscillations could get introduced 
 

# Best practices

https://github.com/katopz/best-practices/blob/master/best-practices-for-building-a-microservice-architecture.md

# Conf

strange loop
Goto
atscale


# Anti-patterns

* hardcoded endpoints
* wrong cuts
* cyclic dependency
* API versioning
* shared persistence
* ESB usage (enterprise service bus)
* legacy org
* local logging
* megaservice
* inapprop service intimacy
* no api gateway
* shared lib
* too many tech
* lack of microservice skeleton
* focus on latest tech
* too many microservices
* common ownership
* no devops tools
* non-homogenous adoption

Microservices Anti-Patterns: A Taxonomy
Taibi, Lenarduzzi, Pahl
https://arxiv.org/pdf/1908.04101.pdf

# Uber

Domains, Layers, Gateways, Extensions

https://eng.uber.com/microservice-architecture/
