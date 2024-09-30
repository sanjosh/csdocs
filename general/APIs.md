
# google guidelines

https://google.aip.dev/

# adidas

https://adidas.gitbook.io/api-guidelines

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

1. Wes Bos. DotJs 2017 https://www.youtube.com/watch?v=9YkUCxvaLEk
2. https://hackernoon.com/javascript-promises-and-why-async-await-wins-the-battle-4fc9d15d509f
3. https://medium.com/@ThatGuyTinus/callbacks-vs-promises-vs-async-await-f65ed7c2b9b4
4. https://medium.com/front-end-weekly/callbacks-promises-and-async-await-ad4756e01d90

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

# Pagination (cursor problem)

requirements
1. is it stateless on server ?
2. can client control speed and fetch size ?
3. do newly added entries get fetched ?
4. separate pagination and filtering logic

## offset based (backend db is SQL which provides support)

offset is a relative number inside list of entries

since offset is relative, newly added entries can cause confusion 

## keyset pagination

find value from previous returned  page to decide next fetch

newly added entries are returned in order

## seek pagination (extension of keyset)

unique identifiers inside retrieval set are more stable

newly added entries are returned in order

use `fetch_after=NNN`

```
select where id > 20
```

## ref

https://www.moesif.com/blog/technical/api-design/REST-API-Design-Filtering-Sorting-and-Pagination/

# AWS pagination

return pagination token to client, which is null on end of iteration

auto-pagination

## sync pagination

use with stream, iterator, for loop

## async pagination (publish, subscribe)

A Publisher is a provider of a potentially unbounded number of sequenced elements, publishing them according to the demand received from its Subscriber(s).

A Subscriber MUST signal demand via Subscription.request(long n) to receive onNext signals.

The Reactive Streams API prescribes that all processing of elements (onNext) or termination signals (onError, onComplete) MUST NOT block the Publisher.

```
public interface Subscriber<T> {
    public void onSubscribe(Subscription s);
    public void onNext(T t);
    public void onError(Throwable t);
    public void onComplete();
}
```

http://www.reactive-streams.org/reactive-streams-1.0.0-javadoc/org/reactivestreams/Publisher.html

https://aws.amazon.com/blogs/developer/auto-pagination-feature-in-java-sdk-2-0/

# Reactive streams

https://github.com/reactive-streams/reactive-streams-jvm/blob/v1.0.2/README.md

# Elasticsearch pagination

## offset based (using from and size)

https://www.elastic.co/guide/en/elasticsearch/reference/current/paginate-search-results.html

## search after

use this for large result size with index state preservation

Using search_after requires multiple search requests with the same query and sort values.

use Point-in-time (PIT identifier)

use keep alive

https://www.elastic.co/guide/en/elasticsearch/reference/current/paginate-search-results.html

## scroll

returns scroll id cursor

sliced scroll :  By default the splitting is done on the shards



