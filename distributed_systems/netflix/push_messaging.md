
https://www.youtube.com/watch?v=6w6E_B55p0E

# Zuul Push

a scalable push notification service that handles millions of "always-on" persistent connections from all the Netflix apps running.

use Websocket or SSE 

Clients connect to Zuul Push servers at edge

Auth policy : Cookie or JWT

Push registry 
1. maintain which client is connected to which Push server
2. low read latency
3. record expiry TTL (since clean disconnect not possible)
4. sharding

Push server registry uses Dynomite (Redis + sharding + quorum + cross region repl)

Push library : send (clientId, message)

message goes to Push message queue 
1. use Kafka
2. priority queues

Message processor 
1. lookup registry
2. may require cross-region delivery
3. message queue -> push server
4. If no connection in registry, drop the message (fire and forget)
5. use Mantis

Push server : 
1. handles millions of connections (nonblocking async io, C10K)
1. use Netty

operational
1. long lived stable connections are terrible for quick deploy 
2. disconnecy during deploy can cause thundering herd
3. tear down connections periodically (auto-close)
4. randomize connection lifetime
5. ask client to close its connection (to avoid TIME_WAIT resource hog on server)
6. handle misbehaving clients which don't close

optimize push server
1. most connections were idle 
2. have many small servers instead of few large
3. auto-scale based on number of open connections
4. ELB cannot proxy WebSockets (workaround : run ELB as TCP load balancer)


