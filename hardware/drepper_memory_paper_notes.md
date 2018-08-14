
* mlock the mem
* fix the mem leak
* instrument with machine-level perf counters
* cpu affinity
* calculate working set (12G Virtual address space vs 800M resident - how much swapping)
* do we have NUMA?
* how much bus bandwidth is being taken?
* gcc optimizations
* kernel params
* run proc at higher priority
* set sched to noop

define a queuing model for system - eqn for cache miss

```
T_exec = Num[ (1-Fmem)T_proc + (Fmem)(G_hit.T_cache + (1-G_hit)T_miss)]
Fmem = fraction of N that access mem

cache_miss_ratio = (100 * cache_misses)/(L2 cache fills + L2 requests)
```

----------

# Drepper - Programmer memory paper

page 11:

running RAM at more freq requires more power - hence fewer devices can be driven in parallel because signals get distorted

this limits amount of RAM on motherboard 

1. One soln is add memory controller per CPU - i.e. NUMA
2. another soln is use of serial bus which can be driver at higher freq.  this soln is seen at all levels
	* FB-DRAM is serial equiv of parallel  memory bus
	* PCI Express is serial equiv of PCI/AGP
	* SATA is serial equiv of PATA

advantage of serial: reduced pin count, higher freq, full duplex

----------

* L1
* L2
* RAM
* SSD
* HDD

* CPU : 3 Ghz 
* L1/L2 cache
* RAM/Front side bus : 1 Ghz 
* South bridge:  lower freq 
* IO : still lower freq & higher size

as we go down the caches and away from CPU
1. freq is lowered
2. cache block size increases
3. total mem size increases
4.  contention becomes virtualized (cpu contention, process contention, IO card contention, inter-machine contention)

bus snooping as an idea
1. ARP snooping
2. frontside bus snooping for cache misses

------------

Is video RAM part of main mem or separate?

------------

* working set size
* ratio of cache to next layer of mem
* granularity of cache increases
* cache miss ratio
* cpu stall

------------

page 28 : why 4 CPUs are the limit - L3 cache is not enuf to store working set of more than 4 CPUs  - no speedup obtained beyond

--------------

* cachegrind
* oprofile
* massif
* pagein tool
* /proc/<pid>/stat - 10-14 fields are page faults
* /proc/<pid>/numa_maps
* /sys/devices/ - has cpu topology
