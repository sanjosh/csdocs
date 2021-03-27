
# scaling slack

```
https://www.youtube.com/watch?v=_M-oHxknfnI
```

Workspace
1. channels
2. users
3. bots
4. messages

long lived connections

(4 min) diagram

1. message proxy (edge terminating SSL proxy websocket over WAN to data center) -> message server
1. PHP webapp -> Job queue + MySQL

CLient/server flow
1. At Login, download full workspace model
2. establish websocket to message proxy
3. push updates to websocket 
4. API calls for channel history, message edit, create channel

workspace sharding
1. assign workspace to DB and message server shard 
2. metadata lookup for each API request

could manually add servers 

DBs run in active/active

what was Good about previous
1. Updates appear instantly (user experience good)
2. Full data model in memory
3. All operations are workspace-scoped (server debugging easy)
4. can horizontally scale

Changes required
1. increasing scale (2x DAU users, 3x connections)
2. product model changed (not workspace anymore, new enterprise model added, shared channel between companies)

## recurring issues

1. large org - metadata download slow
2. thundering herd : connection time load much greater than steady state
3. hot spots - db
4. herd of pets- manual ops not possible anymore
5. cross workspace channels : changed partitioning assumptions

Solutions to above problem

### thin client (flannel edge cache)

handle boot download

### fine-grained db sharding (vitess)

no longer channel or user-sharded

moved sharding knowledge from php code to vitess

vitess 
1. per table sharding policy
2. auto expand workflow
3. failover

### message server sharding

single message server would handle a channel - no longer possible

1. Gateway server :  Websocket termination.  Subscribes to multiple channels in channel server 
1. Channel server : pub sub fanout with 5 min buffering
1. Presence server : 
1. Message Server : for reminders, google calendar integration
1. Admin server  : cluster management and routing

## discovery mesh

consul

## deprecation challenges

## performance

* simple caching
* add client-side jitter
* eliminate unnecessary queries 

# Infrastructure engineering at slack

## presence server

initially broadcast all changes to all users - not scalable

80 perc of all websocket traffic was presence info

so transition from broadcast to pub/sub 

# How slack works

https://www.youtube.com/watch?v=WE9c9AZe-DY


https://www.youtube.com/watch?v=yHBwoZh1Mxg
