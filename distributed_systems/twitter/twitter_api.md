
# rebuilding twitter api

```
https://youtu.be/axFSaH_-IMw
```

history
1. 2005 ruby rails
2. 2012 woodstar (jvm)
3. 2014 macaws (14 http microservices jvm)
4. 2017 graphql
4. 2020 public API v2 

four clients : web, iOS, Android, public API

using graphQL server to serve them

both similar
1. twitter clients query data and render UI
1. twitter API query data and render json

platform components
1. resource fields  : will create user and tweet resources
2. selection components defines how to find resources : e.g. tweet lookup by id or search

allows teams to independently own components or functions of above

Strato data catalog keeps managed columns

services powered by thrift

search has pagination : query, max results, next token

twitter graphQL system requires all queries to be submitted at build time so it can optimize them;

these persistent queries are then assigned an operation id which is used during operation

monitoring : SLO dashboard


