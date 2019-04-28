
# API types

1. sync
2. async (callback, future, async-await)
3. batch
4. streaming response

# Async API

1. callback
2. future
2. async await

# Batch API

1. separate the batch completion response from individual item error code
2. return separate list for success and error
3. support identifier for each item in batch to establish correspondence with batch response
4. return the max supported batch size

# Failure, Retry, idempotency

1. error code or exception ?
2. is exception propagated across network
3. idempotency

# use case specific

1. mobile friendly like GraphQL
2. allow batching/collapsing multiple calls for performance

# ADT/Grammar

1. support for strongly typed 
2. Fluent API 
3. CRUD
4. REST

# Versioning support

# Introspection support

