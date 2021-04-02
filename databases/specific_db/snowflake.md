
# snowflake NSDI 20

key design goal is elasticity

## problems with traditional shared-nothing

1. mismatch between hardware & workload 

workload require 50 disk & 20 CPU => but require 25 VM

2. lack of elasticity : reshuffling

* adding new nodes requires reshuffling
* same nodes in query processing are also doing data reshuffling
* tight coupling between compute & storage - need independent scale

## workload characteristics

divesity of queries 

* read only queries are interactive
* write only are constant

characteristics of intermediate data
1. variation of 5 orders of magnitude

## design

users create virtual warehouse : each warehouse has set of VMs, with local SSD

## ephemeral store

cannot store intermittent data in S3; built ephemeral store 
1. store colocated with compute
2. use DRAM and SSD and final fallback is S3
3. also caches data
4. can do elasticity without data reshuffle

1. each file assigned to unique node
2. write through caching


## scheduling

1. pool of pre-warmed VMs used during scale-up
2. use lazy consistent hashing - wait until task needs data, and then pull from S3 into VM cache.
3. consistent hashing can cause imbalanced partitions; use work-stealing

do locality aware task scheduling

average resource utilization across warehouses shows uneven resource util
RAM is 20 perc, network Tx is 10 perc
because each has individual VM

how to improve util ?
1. have finer grained elasticity
2. move to resource shared model

initially, AWS did per-hour charging of VMs.   
now, introduced per-second charging so pre-warmed pool not effective

use statistical multiplexing

sharing cache between tenants :
1. no predetermined lifetime
2. co-existence with internal data
3. need private address space for tenants

## future work

1. elasticity at intra-query granularity :  resource consumption can vary significantly even within the lifetime of individual queries. 
2. use serverless from cloud provider

https://www.youtube.com/watch?v=4CYNxisz3d0&feature=emb_logo

https://github.com/resource-disaggregation/snowset

https://www.usenix.org/conference/nsdi20/presentation/vuppalapati
