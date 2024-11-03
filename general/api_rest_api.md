

# REST API design pitfalls - Victor Rentea

https://www.youtube.com/watch?v=CNlLWCvazcQ


## archunit

https://www.baeldung.com/java-archunit-intro

## postel law

## breaking changes

change route

change property name, type, required params, 

change response format, throw new errors

remove support for some request type

add validators to input to make it more constrained

increase response time

## openapi-diff

https://github.com/OpenAPITools/openapi-diff

## pact.io

https://pact.io/

## do not expose domain model (customer) in api

1. security risk
2. cannot change domain model
3. only expose DTO data transfer objects

separate contract from implementation

## bulk fetch - only expose get-one-by-id

POST bulk-fetch with body = ids list

HTTP GET can have body since 2021

## proxying responses

## do not reuse the same DTO in get and create (do CQRS)

false overlap 

## error handling

1. which are retryable
2. dont leak unauthorized reason











