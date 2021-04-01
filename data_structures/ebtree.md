
# Elastic binary tree (HAProxy)

handle 10K connections with minimal latency

Willy Tarreau

1. run active tasks
1. check suspended tasks and wake them

Three layers between which connection moves
1. IO scheduler has connections
1. (move to) task scheduler has run queue
1. (move to) timer has wait queue

requirement for scheduler
1. fast tree descent and search
1. lookup by mask or prefix
1. insert and deletes
1. read sorted
1. priorities
1. duplicates

Prefix tree/Radix tree
1. can be unbalanced

towards solution
1. simplify memory management
1. reduce impact of imbalance

in a regular binary tree, you need to allocate intermediary nodes to attach leaves,

With ebtrees, each structure is both a node and a leaf, and thanks to some pointer manipulation, both of them can be used separately.

leads to O(1) deletion

https://fossies.org/linux/haproxy/include/import/ebtree.h
