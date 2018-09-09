

# Anna: A KVS For Any Scale

Chenggang Wu , Jose M. Faleiro Yihan Lin , Joseph M. Hellerstein 

## source code

https://github.com/cw75/tiered-storage

## summary

1. in-memory key store
2. lazy updates epoch based
3. use of lattice merge/crdt
4. shared-nothing, per-core, async message passing
5. only point lookups (no secondary index, range scan)

# Requirements

different type of KVs
1. global like dynamodb
2. local like Redis, rocksdb

Design a KV that can run well at any scale
1. shard key space across nodes and across cpu cores
2. multi-master replication
3. wait-free execution
4. unified support for wide range of coordination-free consistency models

# Design

1. coordinator free actors, each with private mem and thread tied to CPU core
2. for wait-free execution => only send lazy updates
3. for replica consistency => use lattice composition

## programming model

actor model with addition of monotonic programming (e.g Bloom distributed prog lang, CRDT)

## lattice composition

two ways to maintain consistency in replicated systems
1. State machine replication
2. lattice composition

Other Replicated systems use State machine replication for maintaining strong consistency.  This creates total order using Paxos/Raft this fundamentally limits the throughput of each replica-set. 

Anna uses lattice composition to maintain the consistency of replicated state.  Lattices are resilient to message re-ordering and duplication, allowing Anna to employ asynchronous multi-master replication without need for any waiting.

```
while lattice composition cannot include the strongest forms of consistency such as linearizability or serializability, they include relatively strong levels including causality and read-committed transactions.

Lattices avoid inconsistency and guarantee replica convergence via their ACI properties, which make them resilient to message reordering and duplication
```

epoch-based key exchange to lazily propagate changes to other masters

consistent hashing to partition key space

## consistency model

Anna leverages ACI(associative, commutative, idempotent) properties to achieve a rich set of consistency guarantees

## delete implementation

DELETE is implemented as a special PUT request with an empty value field. Actors free the heap memory of a key/value pair only when the DELETE’s timestamp dominates the key’s current timestamp. To completely free the memory for a key, each actor maintains a vector clock that keeps track of the latestheard timestamps of all actors, which is kept up-to-date during multicast. Actors free the memory for a key only when the minimum timestamp within the vector-clock becomes greater than the DELETE’s timestamp.  

# group membership

When a new actor joins the cluster, 
1. it first broadcasts its id to all existing actors. 
2. Each existing actor, after receiving the id, updates its local copy of the consistent hash ring and determines the set of key-value pairs that should be managed by the new actor. 
3. It then sends these key-value pairs to the new actor and deletes them from its local KVS replica. 
4. If the pre-existing actor receives queries involving keys that it is no longer responsible for, it redirects these requests to the new actor. 
5. After the new actor receives key-value pairs from all existing actors, it multicasts its id to all client proxies. 
6. Upon receiving the id, client proxies update the consistent hash ring so that relevant requests can be routed to the new actor.

When an actor is chosen to leave the cluster, 
1. it first determines the set of key-value pairs every other actor should be responsible for due to its departure. 
2. It then sends them to other actors along with its intention to leave the cluster.  
3. Other actors ingest the key-value pairs and remove the leaving actor from the consistent hash ring. 
4. The leaving actor then broadcasts to all client proxies to let them update the consistent hash ring and retry relevant requests to proper actors.
