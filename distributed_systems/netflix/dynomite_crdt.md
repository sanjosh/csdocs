
# Dynomite datastore using CRDT

this is a way to make Redis highly available (multi master)

open-source distributed datastore primarily backed by Redis

We can have 
1. no quorums, 
1. quorums within a single region, 
1. quorums across regions

Each ring is basically a full copy of the data.  Each ring is contained within one rack or Amazon availability zone.

Anti-entropy
1. last writer wins
1. vector clock
1. CRDT

CRDT properties
1. commutative axb = bxa
2. idempotent
3. associative ax(bxc) = (axb)xc

CRDT ops
1. update 
1. merge

## PNNCounter

each replica has a PNCounter : positive and negative counter

sum = pos + neg

## LWW-Element set

used for register, hash map , sorted sets

keep two things:
1. add set : latest update timestamp for keys
1. remove set : timestamps at which keys were removed

remove set can grow forever : 
1. delete if all replicas agree.
2. maintain remove set as sorted set

## Implementation

redis allows lua scripts, single thread operation (atomic)

do background repairs :
1. dont go through all; maintain list of recently written keys

delta state CRDT : maintain list of recent mutations and ship it (command vs state replication)

https://www.infoq.com/presentations/netflix-crdt-entropy/

https://www.youtube.com/watch?v=JirCwLXlH_c
