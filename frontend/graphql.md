
# SDL

define types, queries and mutations


### introspection

Introspection is an optional feature, enabled by default during development, which allows clients (which are frequently developers, building an application) to automatically discover the types implemented within a GraphQL schema.

### design for front-end

GraphQL schemas are at their best when they are designed around the needs of client applications.

This is especially useful because GraphQL allows you to create associations between your data that don't exist in the underlying data, enabling you to move complex data manipulation logic out of your clients.

 you can design a schema that will allow your frontend to be as simple as possible, without limiting yourself to the exact shape of data that's in your underlying data sources.

### Mutation

 Unlike REST, where the behavior can be more ad-hoc, the Mutation type is designed with the expectation that there will be a response object. This ensures that the client receives the most current data without a subsequent round-trip re-query.


Multiple mutations may be sent in the same request, however they will be executed in the order they are provided (in series), in order to avoid race-conditions within the operation.

When different resources are modified, the client code can benefit from having updated fields returned from each type and the response format should support that.

Input types are a special type in GraphQL which allows an object to be passed as an argument to both queries and mutations and is helpful when simple scalar types aren't sufficient.

If only a portion of a mutation update succeeds, whether that is a partial update to a single document's fields or a failed update to an entire document, it's important to convey that information to the client to avoid stale local state on the client.

https://www.apollographql.com/docs/apollo-server/essentials/schema


