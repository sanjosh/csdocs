
# Algorithms to build MRC (miss ratio curve) 

temporal locality

working set size = cache size (where MRC curve shows knee of steep drop)

# reuse distance

```
compute reuse distances : use a balanced tree to track the most recent references to each block 

employ a hash table for fast lookups into this tree.
```

# miss ratio curves

1. Y axis = miss ratio
1. X axis = cache size

1. high miss ratio at low cache size : working set too small
1. low miss ratio at large cache size : working set too large


miss ratio curve goes down cache size increases

# cache hit ratio curve

inverse of miss ratio (above)

more intuitive to plot

curve must go up as cache size increases

# Counter stacks

(Wires, OSDI 2014)

key idea : compute reuse distance is same as counting distinct elements

1. difference in change between adjacent counters = repeated reference
1. location of difference stores the reuse distance


sublinear space : reduce asymptotic space complexity below M (size of data)

hyperloglog 

1. Every d references and every s seconds, starts a new counter to record the number of distinct data accessed from the current time. 
1. on every request, set all counters 
1. During the execution, the number of active counters keeps growing. 
2. periodically writes the results of active counters to the disk. 
2. The data in the disk is used to compute the reuse distance distribution and construct MRC. 
2. Pruning : To reduce the number of live counters, delete a younger counter whenever its value is as least (1−δ) times the older counter’s value. 

By controlling δ, balance between accuracy and number of counters.


# SHARDS

constant space

1. compute reuse for block if hash(location) mod P < T
1. sampling rate R = T/P
1. each sample represents 1/R locations
1. if found, insert into distance tree
1. if threshold lowered, subset inclusion property maintained

count associated with reuse distance histogram need to be adjusted as well to account for sampling.

approximation algorithm that employs uniform randomized spatial sampling, 

track references to representative locations selected dynamically based on their hash values

# Kinetic modeling (AET = average eviction time)

composable model - can combine the model of multiple caches 





# References

1. Hu.  Kinetic Modeling of Data Eviction in Cache.  Usenix 2016
2. Waldspurger.  Efficient MRC Construction with Shards.  FAST 2015
3. ALan Smith.  Disk Cache - Miss ratio analysis. http://www.dataram.com/blog/?p=112
