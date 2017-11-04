
# Four array layouts
1. Sorted
2. Eytzinger (special case of Btree with B=1)
3. B-tree
4. van Emde Boas layout (vEB)  - cache oblivious

Brodal found for searching
1. For arrays smaller than cache size, sorted and Eytzinger fastest, then Btree, then vEB.
2. For arrays larger than cache size, Btree layout fastest, then vEB, Eytzinger and sorted.

Optimizations
* Intel SSE instruction that do three comparisons in parallel can be used to traverse two levls of binary tree.
* Explicit Prefetch instructions for loading memory into CPU cache.
* Predicated instructions (e.g. conditional move as opposed to conditional jump) do not break instruction pipeline.  This forms the basis for a Branch-free binary search.

Measure binary search cost across parameters
* Total Array size fits in L1, L2, L3 cache and beyond
* Different processors
* Multiple threads
* Size of item in array

# References
1. Khuong, Morin.  Array Layouts for Comparison-Based Searching.  ACM Journal of Experimental Algorithmics, Vol. 22, No. 1, Article 1.3
