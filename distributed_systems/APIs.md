
# API types

1. sync
2. async (callback, future, async-await)
3. batch
4. streaming request and/or response

# Invocation domain

1. Network 
2. In-process

# Async API

1. callback
2. future
3. async await

## issues
1. chaining
2. error handling

## References

1. https://www.youtube.com/watch?v=9YkUCxvaLEk
2. https://hackernoon.com/javascript-promises-and-why-async-await-wins-the-battle-4fc9d15d509f


# Batch API

1. separate the batch completion response from individual item error code
2. return separate list for success and error
3. support identifier for each item in batch to establish correspondence with batch response
4. return the max supported batch size

# Failure, Retry, idempotency

1. error code or exception ?
2. is exception propagated across network
3. idempotency token or client generated identifier
4. dont log and throw
5. catch specific first
6. wrap exception without consuming it


# use case specific

1. mobile friendly like GraphQL
2. allow chaining or batching multiple calls for network performance

# ADT/Grammar of the API

1. support for strongly typed 
2. Fluent API 
3. CRUD
4. REST
5. Functional

## Functional API

options to support multiple use-cases
1. multiple API function
2. pass config struct
3. variadic arguments
4. functional - customize by applying functions on the new object, instead of config param

satisfies
1. sensible defaults
2. is highly configurable
3. can grow over time
4. self documenting
5. safe for newcomers
6. and never requires nil or an empty value to keep the compiler happy

https://dave.cheney.net/2014/10/17/functional-options-for-friendly-apis

https://commandcenter.blogspot.com/2014/01/self-referential-functions-and-design.html

# API Versioning support

# Introspection support

# Security

1. Authentication
2. authorization

# Examples

1. gRPC
2. Thrift
3. GraphQL
4. REST

