
# AppSync/GraphQL notes


UX requires data in format that is different from how it is stored in datasource 
Declarative Data fetching

# Overview

## Compare REST vs GraphQL


https://blog.pusher.com/rest-versus-graphql/
https://dzone.com/articles/rethinking-rest-practices-an-introduction-to-graph

GraphQL defines shape of response rather than exact fields

**1. Ask for what you need, get exactly that**
 Send a GraphQL query to your API and get exactly what you need, nothing more and nothing less. GraphQL queries always return predictable results. Apps using GraphQL are fast and stable because they control the data they get, not the server.
**2. Get many resources in a single request**
 GraphQL queries access not just the properties of one resource but also smoothly follow references between them. While typical REST APIs require loading from multiple URLs, GraphQL APIs get all the data your app needs in a single request. Apps using GraphQL can be quick even on slow mobile network connections.
**3. Describe what's possible with a type system**
 GraphQL APIs are organized in terms of types and fields, not endpoints. Access the full capabilities of your data from a single endpoint. GraphQL uses types to ensure Apps only ask for what’s possible and provide clear and helpful errors. Apps can use types to avoid writing manual parsing code.
**4. Evolve your API without versions**
 Add new fields and types to your GraphQL API without impacting existing queries. Aging fields can be deprecated and hidden from tools. By using a single evolving version, GraphQL APIs give apps continuous access to new features and encourage cleaner, more maintainable server code.
**5. Bring your own data and code**
 GraphQL creates a uniform API across your entire application without being limited by a specific storage engine. Write GraphQL APIs that leverage your existing data and code with GraphQL engines available in many languages. You provide functions for each field in the type system, and GraphQL calls them with optimal concurrency.


## GraphQL advantages


**Return partial data **: every field is nullable by default.  If a particular fetch fails, that field will be returned as null in the response.

GraphQL supports entities and relations while REST has endpoints; we have to think afresh (Project/Workstream/Jobs).

GraphQL exposes single endpoint and executes complex queries; REST requires client to call multiple endpoints

**No API Versioning required** : GraphQL only returns the data that's explicitly requested, so client can continue fetching based on older version.

Subscriptions are part of the API

Aggregations are part of the API

Offline usage : Amplify mobile


## AppSync vs Amazon GraphQL

GraphQL is available in serverless or hosted

AppSync is Serverless

Amazon GraphQL is a wrapper which can integrate with existing service running Horizonte, ARest, Coral

You can also deploy custom GraphQL server (Apollo)

## AppSync features

Delta Sync : separate ddb table

Caching : AWS AppSync hosts Amazon ElastiCache Redis instances in the AppSync service accounts, in the same AWS Region as your AppSync API. 


# GraphQL specifics

## Schema

### Derive from Node interface


If you derive from Node, you can include it in the Query
https://atheros.ai/blog/graphql-interfaces-and-unions-how-to-design-graphql-schema

https://relay.dev/graphql/connections.htm


### Add custom types where required

 

> * Rule #10: Use custom scalar types when you're exposing something with specific semantic value.*

> *Rule #11: Use enums for fields which can only take a specific set of values.*


```
https://github.com/Shopify/graphql-design-tutorial/blob/master/TUTORIAL.md
```


## Query



### Cursor-based pagination

```
https://graphql.org/learn/pagination/
```

Use Relay standard to define cursor fields 

add cursorId in query and response

```
https://relay.dev/graphql/connections.htm
```


### Use nested objects in response


> *, but this is a major anti-pattern in GraphQL. Instead of providing an ID, and forcing the client to do another round-trip to get any information on the object, we should just include the object directly into the graph - that's what GraphQL is for after all...As a general rule, the only ID fields in your design should be the IDs of the object itself. Any time you have some other ID field, it should probably be an object reference instead.*

https://github.com/Shopify/graphql-design-tutorial/blob/master/TUTORIAL.md


### 

### Use fragment in query

define common set of fields in multiple queries

https://atheros.ai/blog/how-to-query-your-schema-with-graphql-fragments

## Mutation

### add clientMutationId in mutation to support idempotency


One of the stranger parts of the Relay mutation spec is the parameter `clientMutationId`, which shows up in both input and output types for mutations.

 It allows our server to, for instance, cache the response for each client based on the `clientMutationId` they sent

The Relay spec also requires sending the same `clientMutationId` back to the client in the output of the mutation.

https://relay.dev/graphql/connections.htm

https://blog.logrocket.com/robust-graphql-mutations-the-relay-way/

### Return affected objects 



> Returning affected objects as a result of mutations...This allows us to update the state on the frontend accordingly and keep things consistent. 


https://atheros.ai/blog/graphql-best-practices-for-graphql-schema-design

https://www.apollographql.com/blog/designing-graphql-mutations-e09de826ed97/

### Use a unique output type for each mutation.  


For example, if you have a mutation called `CreateUser`, its output type would be called `CreateUserPayload`.


### Use a single, unique input-type for each mutation

```
mutation CreatePost(input: CreatePostInput!): CreatePostPayload!
```

https://blog.logrocket.com/robust-graphql-mutations-the-relay-way/


### Use a verb for mutation names

## Subscription

### To subscribe to updates not done through GraphQL, use local resolver

*you can setup this behavior yourself using DynamoDB streams and lambda. To do so you can add a new field (for example named publishMessage) with a local resolver (i.e. a resolver targeting a NONE datasource) attached. You can then also subscribe to that mutation in your onCreateMessage subscription*

https://docs.aws.amazon.com/appsync/latest/devguide/tutorial-local-resolvers.html

## Interface and union


**Interface** 


**Union**


> The **union type** is great if you do not want to constrain yourself to validating children types. We just want to represent multiple types that do not need to have any fields in common. Let's say we want to implement a query for searching within our schema. However, there is the constraint that we can only search for **Planet** and **Galaxy**. We want to abstract these two types and access them as one "searchable" entity without enforcing any other properties on them. This is a great use case for using Union type.

> https://atheros.ai/blog/graphql-interfaces-and-unions-how-to-design-graphql-schema


https://github.com/graphql/graphql-spec/issues/236

## Directives

schema-type

query-type

*The possible applications of directive syntax are numerous: enforcing access permissions, formatting date strings, auto-generating resolver functions for a particular backend API, marking strings for internationalization, synthesizing globally unique object identifiers, specifying caching behavior, skipping or including or deprecating fields, and just about anything else you can imagine.*
https://www.graphql-tools.com/docs/schema-directives/

## Resolvers & VTL

Unit
Pipeline
Local : Resolvers with None data resource

**VTL language to do validation, transformation, filtering**
*A resolver includes a code snippet (also referred to as a **mapping template**) defined in a templating language Velocity (VTL). Mapping templates are a way of telling AppSync how to translate an incoming GraphQL request into instructions for the data source, and how to translate the response from that data source back into a GraphQL response.*

VTL can add custom logic

https://docs.aws.amazon.com/appsync/latest/devguide/resolver-mapping-template-reference-programming-guide.html

### Do not put business logic in resolver


### **Performance problem : N+1 fetches solved using DataLoader**


https://github.com/graphql/dataloader
https://github.com/graphql-java/java-dataloader

Does Caching and Batching
Dataloader requires as input a batchFunction : array of ids → array of Promises
Works on single tick of event loop

https://www.youtube.com/watch?v=OQTnXNCDywA&feature=youtu.be

https://secure.phabricator.com/book/phabcontrib/article/n_plus_one/

### How to integrate DataLoader into AppSync


DataLoader is already built into AppSync
Use BatchInvoke in Lambda but it has limit of max 5 items !!

https://medium.com/@onufrienkos/how-to-create-appsync-dataloader-b6b1c5e5178c

https://github.com/aws/aws-appsync-community/issues/51

https://docs.aws.amazon.com/appsync/latest/devguide/tutorial-lambda-resolvers.html


## Error handling 

* If GraphQL gives you `results.data`, it is not an error, so don’t throw it on the client.
* If the viewer should see the error, return the error as a field in the response payload. If it’s a query, make a response payload.
* Replace any remaining GraphQL `errors` with a generic message, but don’t throw it on the client and don’t expect the UI to always be able to handle it.


https://itnext.io/the-definitive-guide-to-handling-graphql-errors-e0c58b52b5e1

*Rule #22: Mutations should provide user/business-level errors via a `userErrors` field on the mutation payload. The top-level query errors entry is reserved for client and server-level errors.*

https://github.com/Shopify/graphql-design-tutorial/blob/master/TUTORIAL.md

### Lambda resolver errors 

 If an error is thrown from the Lambda function, AWS AppSync fails to resolve the current field. Only the error message returned from Lambda will be set in the response.

*For batched invocations, raising an error from the Lambda function flags an entire batch as failed. This might be acceptable for specific scenarios where an irrecoverable error occurs, such as, a failed connection to a data store. However, in cases where some items in the batch succeed and some others fail, it’s possible to return both errors and valid data.... you could choose to return a list of `Response` objects where each object has optional data, errorMessage, and errorType fields. *

https://docs.aws.amazon.com/appsync/latest/devguide/tutorial-lambda-resolvers.html

### **Beware of non-nullable fields in response**


Upon encountering an exception while resolving a field that is non-nullable, the exception works its way up the parent chain until a nullable field is found


## Best practices

https://graphql.org/learn/best-practices/

Use consistent identifiers for better caching
https://graphql.org/learn/global-object-identification/

https://towardsdatascience.com/graphql-best-practices-3fda586538c4

## AppSync limitations

https://medium.com/@dadc/aws-appsync-the-unexpected-a430ff7180a3

max query timeout = 30 sec
max items in VTL = 1000
Batch Invoke = 5 items
Lambda response size = 1 MB

## GraphQL in microservice architecture

Use RPC - third option
https://medium.com/@mena.meseha/practice-of-graphql-in-microservice-architecture-e8f2d698f93b


## GraphQL client

https://relay.dev/


## Examples of GraphQL schema


github has exported a GraphQL API to their domain model
https://github.blog/2016-09-14-the-github-graphql-api/

https://github.com/APIs-guru/graphql-apis

## Other references

https://github.com/dabit3/awesome-aws-appsync

https://www.graphql-tools.com/docs/introduction

