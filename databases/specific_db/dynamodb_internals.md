
# DynamoDB under the hood

PutItem replicates to one other node before returning, but the other is lazy

GetItem is eventual consistent because it is allowed to hit any RequestRouter

Paxos

## Request routers 

mediate all requests

RR talk to Authentication system

## Partition metadata system

RR talk to Partition metadata system

## Storage nodes 

1. have SSD
2. Each node has BTree and replication log
3. split across AZ


## Auto-admin 

1. ensures partition metadata system is up-to-date
2. partition repair
3. table provisioning
4. split partition

## Secondary index

Log propagator updates index

write amplification : One table update can cause New Put & Old Delete in index

there are multiple indices, each replicated, so many nodes can get updated due to one update

## RCU

Token bucket


## Hotspots - use an adaptive capacity multiplier

PID controller decides multiplier : 

1. inputs = consumed capacity, provisioned capacity, throttling rate, current multiplier
1. output = new multipler

PID controller sees consumed is greater than provisioned and resets multipler back to 1 

## Auto-scaling

Sets 2 alarms for read, 2 alarms for write, one for provisioned and one for consumed value

can scale tables down

## Provisioning summary

1. imbalance in time => solution was partition bursting
2. imbalance in key space => solution was adaptive capacity
3. changing workload => solution was auto-scale

## Backup and restore

move btree scan & replication log to S3

on-demand backup

## Streams

no duplicates

Stream is in order by key, but may not be across keys (due to partitions)

in other words, partition key is maintained

latencies = 10s of ms

## Global tables

external service to dynamodb

global tables go through request router.  need IAM replication role enabled.

stream reader forwards to RepOut which talks to RepIn in all other regions.  
does not get circular loop

Pic at 48 min

last writer wins if key updated in 2 regions

## reference

AWS re:Invent 2018 DAT 321 DynamoDB under the hood

https://www.youtube.com/watch?v=yvBR71D0nAQ&feature=youtu.be
