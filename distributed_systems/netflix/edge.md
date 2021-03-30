
# evolution of edge

https://www.youtube.com/watch?v=k01PHa5YDpQ

https://www.infoq.com/presentations/netflix-edge-gateway

NCCP stands for Netflix Content Control Protocol

API gateway becomes monolith

API gateway needs to split to handle discovery, search, playback

two ways to do it; we do both
1. client-side orchestration (discovery to one, playback to another - separate Domain)
2. API gateway side orchestration (route to different services)

two different cases : streaming + content engineering

## POP

TCP + TLS handshake can take 400 ms 

added POP 

client goes to POP where SSL terminated, then private highway (multiple protocol) to data center

# Scaling Patterns for Netflix's Edge

https://www.youtube.com/watch?v=6twDj1cojyg

https://www.infoq.com/presentations/netflix-edge-scalability-patterns/

## Melnitz

L7 proxy : if cookie expired, go to account service

weird activity - want the account to log it out, but not hit the DB

focus on first eight hours after account registry : set of customerIds

use bloom filter to check new customer 

## Mantis

4 PB per day of logs

event stream processing

Mantis query language MQL inserts matching filter into all agents running on host

## Passport

Service plan is required per request.  It gets queried by every service

Instead, inject it into request.

## Device types

need to group the client devices for telemetry

everyone queried DTS service (device types) - then added pub-sub

its not realtime data

so instead, you embed it into jar file and eliminate service

## sharding

MSL = message security layer like TLS

encrypt, key exchange, authN

moved MSL out of service; improved GC time


