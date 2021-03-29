
# streaming million likes per second (instant messaging)

it also distributes comments, typing indicators, presence


## delivery pipe

client -> likes backend (publisher) -> real time delivery backend (subscriber) -> client

send to client with Long poll with SSE (EventSource)

## thousands of connections 

use Akka connection management, Akka actor and mailbox

each actor manages one persistent connection

Akka supervisor actor

## multiple live videos

viewer client tells delivery which video is being watched

subscription table is kept in-memory.  

Map : live video -> connectionId

## Sharding (Dispatcher sits above real-time delivery nodes)

real-time dispatcher sends likes to frontend machines

keeps table : topic -> frontend host

## Dispatcher is bottleneck

add multiple dispatchers 

subscription table is not in memory and kept in KV store; this helps failover

## Flow

subscription flow
1. subscription request from client
1. updates subscription table in frontend node
2. frontend node sends subscription request to dispatcher which updates KV store

publish flow
1. updates likes backend
2. send to dispatcher
3. send to frontend nodes

## multiple data centers

dispatcher checks local KV

cross-DC publish to all peer-nodes

number of connections per machine : 100K

dispatcher node has to publish only to frontend nodes

max events/sec which dispatcher can accept = 5K

end-to-end latency : 75 ms (one key value lookup)

no persistence ?

scales because horizontal scale

## questions

fallback for SSE ? websockets get blocked by firewall but not SSE

how to sync the likes when video streams are delayed : 

consistency guarantee ?  None, we go for speed

why not Kafka ? each frontend server needs to subscribe to all videos 

slow clients can cause memory exhaustion ?  frontend is fire-and-forget

## ref

https://www.youtube.com/watch?v=yqc3PPmHvrA

Streaming a Million Likes/Second: Real-Time Interactions on Live Video

https://www.infoq.com/presentations/linkedin-play-akka-distributed-systems

# Presence problem : noisy 

periodic heartbeats for bad network

trigger

when you come online, 
1. check presence of your contacts 
2. then subscribe to changes
3. notify you are online
4. setup heartbeat and start timer



https://engineering.linkedin.com/blog/2018/01/now-you-see-me--now-you-dont--linkedins-real-time-presence-platf

# Samza Aeon: latency insights for asynchronous 

https://engineering.linkedin.com/blog/2018/04/samza-aeon--latency-insights-for-asynchronous-one-way-flows
