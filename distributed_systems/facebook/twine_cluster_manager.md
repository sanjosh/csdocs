
# Twine unified cluster manager

tupperware ?

use power-efficient small machines outfit with a single 18-core CPU and 64GB RAM

using small machines led to 18% savings in power and 17% savings in total cost of ownership

1. migration : support hardware refresh, kernel upgrade, job resizing, power capping, hardware failure
2. unified : manage all data centers in a region
3. collaborative : support workload-specific customization (e.g. stateful service )
4. entitlement quota system

## Rebalancing

```
The addition or removal of machines and workload evolution may result in hotspots in CPU,
power, or network. ReBalancer runs asynchronously and continuously to improve upon the 
allocator’s allocation decisions by swapping machines across entitlements or 
moving tasks across machines.  ReBalancer uses a constraint solver to perform 
these time-consuming global optimizations
```

## allocator to find free machines

The allocator maintains an in-memory index of all machines and their 
properties to support hard requirement queries, 
such as “all Skylake machines with available CPU ≥ 2RRU and available memory ≥ 5GB"


## host customization for better performance

We resolved the conflict between host-level customization
and sharing machines in a common pool via host profiles,
a framework to control host-level customizations on entitlements.

Supported host profile settings include 
1. kernel versions, 
2. sysctls (e.g., hugepages and kernel scheduler settings), 
3. cgroupv2 (e.g., CPU controller), 
4. storage (e.g., XFS or brtfs), 
5. NIC settings, 
6. CPU Turbo Boost, and 
7. hardware prefetch.


## application level scheduling

1. stateful
2. batch
3. ML
4. Stream
5. video processing


## small machines

 some services initially did not fit the limited 64GB in our small machines. 

 To address this, we used several common software architectural changes:

1. Shard a service so that each instance consumes less memory.  Use Shard Manager platform 
2. Exploit data locality to move in-memory data to an external database and use the smaller memory as a cache. 
3. Exploit data locality to provide tiered memory on top of 64GB RAM and TBs of local flash. 

For example, when migrating TAO [7], our social graph cache, from big
machines to small machines, CacheLib [5] transparently provided tiered 
memory to improve cache hit ratio and reduce load on the external 
database by about 30%.


## autoscaling metric

We rely on Autoscaling to free up underutilized machines. 

Active Last Minute (ALM) is the number of people who use our online products within a one-minute interval.

The load of many services correlates with ALM


## scale - manage million machines

Two principles help Twine scale to one million machines and beyond: 
1. sharding as opposed to federation, 
2. separation of concerns

Sharding of the Twine schedulers done based on entitlements

* the largest scheduler shard manages ≈170K machines; 
* the largest entitlement uses ≈60K machines; 
* the largest job has ≈15K tasks

We avoid Kubernetes’ centralized architecture where all components interact through 
one central API server and share one persistent store

Sharded components include the front end, scheduler, allocator, Resource Broker, Health Check Service, and Sidekick.

Further, each stateful Twine component (front end, scheduler, allocator, and RB) has its own separate persistent store for metadata.

Separation of allocation and optimization responsibilities
helps the allocator scale. The allocator makes quick decisions
when starting tasks, whereas ReBalancer asynchronously runs
a constraint solver to perform time-consuming global optimizations 
such as balancing CPU, network, and power.

Separation of responsibilities between Twine and
application-level schedulers helps Twine scale further.
Application-level schedulers handle many fine-grained resource 
allocation and lifecycle operations without involving Twine.

## sharding vs federation

Other cluster management systems scale out by deploying one 
isolated control plane per cluster and operate many siloed clusters. 
They preallocate machines to a cluster; once a job starts in a cluster, 
it stays with the cluster

To avoid stranded capacity, we can introduce mobility by moving either jobs or machines. 

1. Kubernetes moves a job across multiple static clusters, 
2. Twine dynamically moves machines in and out of entitlements 

Federation Manager to perform complex coordination for a job whose metadata and
management operations are split among multiple distributed Cluster Managers

Twine is simpler because a job is exclusively managed by one scheduler
shard, and Resource Broker provides a simple interface to manage the 
shared regional pool of machines.

## mitigating SPOF for control plane failure

1. all components are sharded
1. all components are replicated
1. tasks keep running
1. rate limit destructive operations
1. network redundancy

Twine is able to bootstrap itself : all Twine components run as Twine jobs

Twine dependencies are also Twine jobs


## power capping

See Dynamo: Facebook’s Data Center-Wide Power Management System

https://research.fb.com/wp-content/uploads/2016/11/dynamo_facebook_s_data_center-wide_power_management_system.pdf


## reference


https://www.usenix.org/system/files/osdi20-tang.pdf

