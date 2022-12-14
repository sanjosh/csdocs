
# metastable failures : bronson

```
In metastable failure, the extra unanticipated load activates a positive feedback loop 
that creates more load. 

This positive feedback loop is the sustaining effect that prevents the system 
from recovering when the initial trigger is resolved.
```

after glitch, system wastes time doing backlog processing for queries 
whose results will be discarded 


```
 A recurring pattern in our experience is that changes meant to improve the common case behavior 
 of a system tend to increase the strength of the sustaining effects. 

 Fast paths, caches, retries, failover, load balancing, and autoscaling all make the 
 failure state less resource-efficient relative to the normal state, which makes the 
 feedback loop worse.
```


http://charap.co/metastable-failures-in-distributed-systems/

https://brooker.co.za/blog/2021/05/24/metastable.html

Bronson, Metastable failures in distributed systems, HotOS 2021 
https://sigops.org/s/conferences/hotos/2021/papers/hotos21-s11-bronson.pdf


# Metastable Failures in the Wild : huang, et al

three states : stable, vulnerable, metastable

metastable failure state : the state of a permanent overload with an ultra-low goodput

Metastable failures are a class of system failures characterized by sustaining effects that keep systems in a degraded state and resist recovery. 

 other names : persistent congestion, overload, cascading failures, retry storms, death spirals

The problem is that in a complex, large-scale distributed system, we lack the ability 
to analyze the consequences of this decision to run in a vulnerable state under 
different conditions; e.g., 
1. what happens if load increases, 
2. or if the downstream latency increases, 
3. or if messages increase in size and serialization/deserialization starts to cost more CPU

triggers can be
1. buggy configuration 
2. code deployments
3. latent bugs

sustaining effects
1. load increase due to retries
2. expensive error handling
3. lock contention
4. performance degradation due to leader election churn

removing the trigger cannot fix the system

once in the metastable failure state, the system cannot 
recover all by itself as the sustaining effect keeps it
in the metastable failure state

how to recover
1. load shedding (throttle)
2. reboot to clear requests
3. policy changes (turn off feature)
4. increase system capacity

whether a system transitions from a vulnerable state into
a metastable failure state is determined by the 
1. current degree of vulnerability, 
2. the trigger magnitude, 
3. trigger duration


twitter : high queueing increases memory pressure and mark-and-sweep processing during GC, causing job slowdowns and thus higher queueing. 

look aside caching : caching server reboot, increased db server load, db times out, cache cannot be refilled

https://www.usenix.org/publications/loginonline/metastable-failures-wild
