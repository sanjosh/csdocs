
# Balancing Multi-Tenancy and Isolation at 4 Billion QPS

cache machine 
1. has IO thread
2. hits are fast in microseconds
3. misses are slow in milliseconds; 
4. there is work queue before worker handling misses
5. limited concurrency 3k workers

## fail quickly 

1. differentiate spikes from overload
1. queue length indicates bad health
2. how long ago did you process a request quickly

lower queue timeout on overload

## dont fail requests that can succeed

1. hard limits are bad
2. serve requests and then follow out-of-band
3. soft response to bad request (change queue delivery order; adjust queue timeouts; limit worker pool for bad queries)

## fail the right request

1. who is making request (inefficient app; batch job; viral product)
2. read or write hot spot; uncacheable pattern
3. where is the data held upstream

create tag : enumerate request features (who, what, where) to classify request

keep scoreboard : what fraction of machine capacity is devoted to a tag ?

anything suspicious is put into low priority queue and maybe timeout

queue is high performance - millions of things can be inserted and timed out

gather samples from healthy and unhealthy servers

```
Bayes : p(case | feature) = p(feature | case) * p(case) / p(feature)
```
epidemiology : case control studies 


Nathan Bronson
https://www.youtube.com/watch?v=dATHiDHS3Mo
