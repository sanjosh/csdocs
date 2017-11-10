
* Earlier work : _External Memory model of Aggarwal & Vitter 1988_
* Need to know blocksize B and cachesize M

Cache oblivious started by *Frigo Leiserson Prokop Ramachandran 1999*
* Design algorithms without knowing B and M
* Should work well across multiple memory hierarchies
* Such algorithms cannot issue block-read/purge requests - page replacement strategy is unknown.  Fetch triggered automaticaly by request.
* Assume ideal cache - page replacement optimal, cache is fully associative

*(from Erik Demaine paper)*

------------

Frigo defined reductions to convert ideal-cache algo to realistic-cache algo such that running time degrades by constant factor

1. Number of memory transfers depend polynomially on cache size M. In other words, LRU or FIFO is as good as optimal replacement upto const factor.
2. Convert full associative cache to 1-way associative.  Use 2-universal hash functions.
3. Tall cache assumption : number of blocks M/B > block size B.

--------------

Strategy 
* redesign algo and data structure to avoid cache misses 
* most cache oblivious algos use divide and conquer until problem fits in cache

---------------

Matrix multiplication in cache oblivious model

* Store matrix to be multiplied not in row-major or column-major but as submatrices A11, A12, A21, A22 in consecutive segments in arbit order.
* Each block is read/written at most once
* Same technique applied to LU factorization, matrix transpose and FFT

-------------

Sorting

* External Memory model which achieves best bound is an (M/B)-way mergesort
* For cache-oblivious model, Frigo defined funnelsort and adaptation of the existing distribution sort.

-------------

Cache oblivious Data structures
1. Van Emde Boas Layout of Tree
2. Unrolled Linked List
3. COLA - Cache Oblivious Lookahead array
4. Fractional cascading

-------------

Funnel heap

------------

Fractional Cascading paper of Chazelle

* http://en.wikipedia.org/wiki/Fractional_cascading
* http://blog.ezyang.com/2012/03/you-could-have-invented-fractional-cascading/
* http://blog.ezyang.com/2012/02/visualizing-range-trees/

-------------

Insert-query tradeoff can be modeled as a ball-shuffling problems ( Dan Mor slides)
