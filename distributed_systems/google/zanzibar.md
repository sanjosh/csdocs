
# Zanzibar: Google’s Consistent, Global Authorization System

## requirement

respect causal ordering of user actions and thus provide external consistency amid changes to access control lists and object contents
1. it respects the order in which ACL changes are committed to the underlying data store. 
2. it can ensure that authorization checks are based on ACL data no older than a client-specified change.

a simple data model with a powerful configuration language. 

## distributed scaling

When a check request arrives to Zanzibar, the work to evaluate the check may fan out to multiple
servers, for example when a group contains both individual members and other groups

The ACL data does not lend itself to geographic partitioning because authorization checks for any object can come from anywhere in the world. 
Therefore, Zanzibar replicates all ACL data in tens of geographically distributed data centers and distributes load 
across thousands of servers around the world.

handles hot spots on normalized data by caching final and intermediate results, and by deduplicating simultaneous requests. 

It also applies techniques such as hedging requests and optimizing computations on deeply nested sets with limited denormalization

Zanzibar responds to more than 95% of authorization checks within 10 milliseconds and has maintained more
than 99.999% availability for the last 3 years.

## cache hot spots

To handle the “cache stampede” problem [3], where concurrent requests create flash hot spots before the cache is
populated with results, we maintain a lock table on each server to track outstanding reads and checks. 
Among requests sharing the same cache key only one request will begin processing; the rest block until the cache is populated

To handle hot forwarding keys, we cache results at both the caller and the callee of internal RPCs, effectively
forming cache trees. 

We also use Slicer [12] to help distribute hot keys to multiple servers.

We avoid reusing results evaluated from a different snapshot by encoding snapshot timestamps in cache keys. 

We choose evaluation timestamps rounded up to a coarse granularity, such as one or ten seconds, while respecting staleness
constraints from request zookies. This timestamp quantization allows the vast majority of recent checks and reads to be
evaluated at the same timestamps and to share cache results

## new enemy problem

Preventing the “new enemy” problem requires Zanzibar to understand and respect the causal ordering between ACL or
content updates, including updates on different ACLs or objects and those coordinated via channels invisible to Zanzibar. 
Hence Zanzibar must provide two key consistency properties: 
1. external consistency [18] and 
2. snapshot reads with bounded staleness.

## spanner used

we store ACLs in the Spanner global database system [15]. Spanner’s TrueTime mechanism assigns each ACL 
write a microsecond-resolution timestamp, such that the timestamps of writes reflect the causal ordering
between writes, and thereby provide external consistency

one could try to always evaluate at the latest snapshot such that the check result reflects all ACL writes up to the
check call. However, such evaluation would require global data synchronization with high-latency round 
trips and limited availability 

## protocol

we design the following protocol to allow most checks to be evaluated on already replicated data 
with cooperation from Zanzibar clients
1. A Zanzibar client requests an opaque consistency token called a zookie for each content version, via a 
contentchange ACL check (§2.4.4) when the content modification is about to be saved
2. The client sends this zookie in subsequent ACL check requests to ensure that the check snapshot

## zookie

A concept used throughout these API methods is that of a zookie. A zookie is an opaque byte sequence encoding a
globally meaningful timestamp that reflects an ACL write, a client content version, or a read snapshot. Zookies in ACL 
read and check requests specify staleness bounds for snapshot reads, thus providing one of Zanzibar’s core consistency
properties.

## language 

Defining our data model around tuples, instead of per-object ACLs, allows us to unify the concepts of ACLs and
groups and to support efficient reads and incremental updates,

The language allows clients to define arbitrary relations between users and objects, such as owner, editor, commenter, and
viewer. 

It includes set-algebraic operators such as intersection and union for specifying potentially complex access
control policies in terms of those user-object relations

ACLs can thus refer to other ACLs, for example to specify that the set of users who can comment on a video consists 
of the users who have been granted viewing rights on that specific video along with those with viewing permissions on the video channel.

Zanzibar evaluates ACL checks by converting check requests to boolean expressions.

To minimize check latency, we evaluate all leaf nodes of the boolean expression tree concurrently

### userset rewrite rules

we let clients define object-agnostic relationships via userset rewrite rules in relation configs.

## watch API

Some clients maintain secondary indices of relation tuples in Zanzibar. They can do so with our Watch API. A watch
request specifies one or more namespaces and a zookie representing the time to start watching

watchservers are a specialized server type that respond to Watch requests. They tail the changelog and serve a stream 
of namespace changes to clients in near real time.

## indexing

Leopard is an indexing system used to optimize operations on large and deeply nested sets. 
It reads periodic snapshots of ACL data and watches for changes between snapshots

Recursive pointer chasing during check evaluation has difficulty maintaining low latency with groups that are deeply
nested or have a large number of child groups. For selected namespaces that exhibit such structure, 
Zanzibar handles checks using Leopard, a specialized index that supports efficient set computation

## probability test on stale data

Each server tracks the frequency of such out-of-zone reads for data at a default staleness as well as for fresher
and staler data, and uses these frequencies to compute a binomial proportion confidence interval 
of the probability that any given piece of data is available locally at each staleness.

Upon collecting enough data, the server checks to see if each staleness value has a sufficiently low probability 
of incurring an out-of-zone read, and thus will be low-latency. If so, it updates the default staleness bound 
to the lowest “safe” value. If no known staleness values are safe, we use a twoproportion z-test to see 
if increasing the default will be a statistically significant amount safer. In that case, we increase 
the default value in the hopes of improving latency

## noisy neighbour

measures the cost of each RPC in terms of generic cpu-seconds, a hardware-agnostic metric. Each client has
a global limit on maximum CPU usage per second; its RPCs will be throttled if it exceeds the limit and there is 
no spare capacity in the overall system

Each Zanzibar server also limits the total number of outstanding RPCs to control its memory usage. Likewise it limits the number of oustanding RPCs per client.

Zanzibar further limits the maximum number of concurrent reads per (object, client) and per client on each Spanner
server. This ensures that no single object or client can monopolize a Spanner server

Finally, we use different lock table keys for requests from
different clients to prevent any throttling that Spanner applies
to one client from affecting other clients

## tail latency

hedging


To determine the appropriate hedging delay threshold, each server maintains a delay estimator that dynamically
computes an Nth percentile latency based on recent measurements. This mechanism allows us to limit the additional
traffic incurred by hedging to a small fraction of total traffic.


