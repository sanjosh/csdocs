
# AVL

# Red-Black

# Scapegoat

# splay
1. recently accessed elements

# Segment Tree
1. intermediate nodes store aggregate over leaves
2. query points

# Interval Tree
1. query interval intersects

# Van-Emde Boas tree
1. data comes from limited set {1..u}
2. constant height tree
3. min, max, pred, succ ops in log.log.u

# Fenwick tree/Binary Indexed tree
1. prefix sums 
2. intermediate nodes based on powers of two

# Heap
1. not fully sorted

# Treap
1. heap on one key, sorted on another key
2. structure of treap is independent of insertion order

# Fractal tree

https://en.wikipedia.org/wiki/Fractal_tree_index

# Applications

* if balanced & search more frequent, use AVL
* if balanced & insert-delete more frequent, use red-black
* if no need for fully sorted, then heap
* if data comes from limited set {1..u}, then Van emde boas tree
* if aggregation required, then segment tree 
* if prefix sums required, then Fenwick

## segment tree vs fenwick tree

1. segment tree can do anything that BIT can do 
2. BIT requires half the mem
3. segment tree ops have larger constant factor

from
https://www.quora.com/How-does-one-decide-when-to-use-a-Segment-Tree-or-Fenwick-Tree
