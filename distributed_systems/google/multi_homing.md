
# Multi-homing at Google

```
Multi-homed systems run live in multiple datacenters all the time, adaptively moving load between datacenters, with the ability to handle outages of any scale completely transparently.  Most of our systems (e.g. Photon, F1, Mesa) now support multi-homing as a fundamental design property.  
...
Our current approach is to build natively multihomed systems. Such systems run hot in multiple datacenters all the time, and adaptively move load between datacenters, with the ability to handle outages of any scale completely transparently [1]
```

F1 is a distributed RDBMS
Photon is a streaming engine
Mesa is a data warehouse

Consistency in streaming means => exactly once, monotonic increasing events.

## Classes of failures in distributed system:
1. machine : software, hardware, power at rack or datacenter level.
2. network connectivity problems : network partitions, reduced bandwidth, increased latency, unreliable connections, asymmetric connectivity, and unexplained flakiness.
3. underlying infra : layers like distributed fs, db, comm services.

## Availability tiers
1. single homed systems (single datacenter)
2. failover based systems (primary secondary datacenter)
3. multi-homed move workload adaptively between datacenters

## Challenges in building Multi-homed 

### Global state. 

network latency between datacenters is tens of milliseconds.  
updating global state synchronously is time consuming.  
hence some form of batching needed WAN bandwidth more expensive than local.  
hence size of global state must be minimized.  
use global state for metadata instead of data.

### Checkpoints

checkpoints are expensive, esp of global state.  
minimize checkpoints.  
only checkpoint at endpoints of the cluster.  
keep small checkpoints selectively at particular nodes

### Repeatable input

ensure same input available at all datacenters.   
ensure secondary inputs (lookups into db) are repeatable.   
otherwise result of lookup must be stored as part of checkpoint.   
Or push non-deterministic lookups towards end of pipeline. 

### Exactly once output. 

have idempotent output.  
if not, use 2PC

### Resource cost

Failover with 2 sites costs 3x resources (catch up cost is high)
Multihomed with 3 sites costs 1.7x resources.

# References

1. Gupta Shute, Google's Data Infra for Ads (https://storage.googleapis.com/pub-tools-public-publication-data/pdf/44686.pdf)
