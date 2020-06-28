
# shortest path distance using node2vec

advantage is constant time computation

1. Using random walk, create node embedding such that embeddings on nearby nodes are similar.  This is like word2vec
2. identify landmork nodes (l)
3. run standard Shortest path algo to find distance of each node from landmark nodes.  this yields l x (n-l) training pairs


```
Knowledge of the distances to the landmarks, together with the triangle inequality, typically allows one to
compute approximate distance between any two nodes in O(l) time, where l is the number of landmarks.
```

## references

1. Rizi, Shortest Path Distance Approximation using Deep learning Techniques https://arxiv.org/pdf/2002.05257.pdf
2. Grover, node2vec: Scalable Feature Learning for Networks  https://arxiv.org/pdf/1607.00653.pdf



