
# metastable failures

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
