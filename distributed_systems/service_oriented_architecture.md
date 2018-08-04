
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
