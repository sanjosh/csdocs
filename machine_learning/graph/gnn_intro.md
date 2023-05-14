
# Deepfindr youtube

https://www.youtube.com/watch?v=fOctJB4kVlM&list=PLV8yxwGOxvvoNkzPfCx2i8an--Tkt7O8Z&index=1

problems
1. node label prediction
2. link prediction (find edge label)
3. graph level prediction (is this molecule suitable for a drug)

need permutation invariance : cannot use adjacency matrix as input since its sensitive to change in vertex order

graphs are non-euclidean : hence its called geometric deep learning

for node prediction, use node embedding to predict label of a particular node (i.e. find similar nodes)

for graph prediction, combine node embeddings or pool them (i.e. similar graphs have similar embeddings)

message passing layer : convolution - combine node and edge info into node embedding

graph convolution : (like convolution on image) is used to create embedding for node.   use kernel 

each message passing layer increases information from adjacent nodes (widening circle)

each message passing adds a layer to the GNN

number of MP layers is a hyperparameter; depends on size of graph and complexity of problem

oversmoothing : excessive layers - dont learn anything new - all node embeddings became similar - see paranorm

node state update in (k+1) is performed using aggregate + update

many different variations proposed for doing update and aggregate (e.g. GRU, Attention, sum of normalized, etc)


## notebook

```
We apply three convolutional layers, which means we learn the information about 3 neighbor hops. After that we apply a pooling layer to combine the information of the individual nodes, as we want to perform graph-level prediction.

Always keep in mind that different learning problems (node, edge or graph prediction) require different GNN architectures.
```

For node-level prediction you will often encounter masks.  
You need masks because may not all nodes available during training or prediction.  So you mask out others

For graph-level predictions on the other hand you need to combine the node embeddings
1. mean pooling
2. max pooling
3. or graph-level pooling which reduces graph size)
```

## grpah level predictions (pooling)

add super/virtual/dummy node which gets messages from all nodes but doesnt return anything back.  this super node can be used as graph representation

differentiable pooling

top-k pooling




