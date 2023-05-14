
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

We apply three convolutional layers, which means we learn the information about 3 neighbor hops. After that we apply a pooling layer to combine the information of the individual nodes, as we want to perform graph-level prediction.

Always keep in mind that different learning problems (node, edge or graph prediction) require different GNN architectures.

For node-level prediction you will often encounter masks.  
You need masks because may not all nodes available during training or prediction.  So you mask out others

For graph-level predictions on the other hand you need to combine the node embeddings
1. mean pooling
2. max pooling
3. or graph-level pooling which reduces graph size)


## graph level predictions (pooling)

add super/virtual/dummy node which gets messages from all nodes but doesnt return anything back.  this super node can be used as graph representation

differentiable pooling

top-k pooling

if data imbalance (positive and negative), use weighted cross-entropy

## VAE 

reconstruction + regularization loss

decoder problem : graph reconstruction problems (graph-level info is lost) :
1. decoder may predict different number of nodes
2. we lose node ordering 
3. graphs of different sizes - FCN output nodes have to change based on size of graph

use max pool matching for 1 and 2, fixed max graph size for 3

have canonical ordering for (2)

https://www.youtube.com/watch?v=F45X7e6QS4E&list=PLV8yxwGOxvvoNkzPfCx2i8an--Tkt7O8Z&index=13

## explainability 

1. instance level predictions 
2. model level predictions (harder because you have to learn decision boundary)

methods for instance level
1. gradients/features : backprop 
2. perturb (remove parts of graph)
3. decomposition prediction into input space (layer by layer, input is reached)
4. surrogate : fit simpler model in local area

for model level
1. generation 

look at computation graph for a node

maximize mutual information : indicates how much influence a subgraph has on overall computation graph

instead of going over all subgraphs, use a constant mask to get certain subset of subgraphs

DiG (Dive into Graphs) implements explainer methods

## Twitch 



## libraries

### pytorch geometric

### deep graph library (DGL)

backend agnostic : works for pytorch, tensorflow, mxnet

can add custom info to nodes, edge


### Spektral

keras and tensorflow

for node and graph level predictions

## Graph Nets (deepmind)

tensorflow and sonnet

lower level library

no pooling layers

no datasets

### DeepChem for chemical GNN

### DiveIntoGraphs 

### deepsnap

transfer learning

## temporal graphs

1. static temporal
2. dynamic temporal

steps
1. first calculate spatial embedding of each node by sending graph at each step thru GNN
2. then send them to temporal model to create spatio-temporal embedding of each node

Dynamic graphs : what if node or edges change over time ?  there is a paper on it

### pytorch geometric temporal library


### traffic forecasting

time series forecasting in GNN : labels become features for next step

tensorflow overview of time series forecasting
https://www.tensorflow.org/tutorials/structured_data/time_series
https://www.tensorflow.org/tutorials/structured_data/time_series

## fraud detection

fraud of fake commenters : adjacency matrix of page-comments is anomalous

credit card transactions : nodes are buyer, amount, email, shipping address

GNN can learn complex structural patterns

what if nodes are heterogenous ? need message passing

## fake news detection

confirmation bias - user retweets an article

not fact checking

gossipcop dataset

node attributes : profile date created, followers, location

## recommender systems

1. content based filtering
2. collaborative filtering (similarity between user) - matrix completion problem - use matrix factorization

in GNN, collab filtering becomes bipartite graph

use graph auto-encoder to reconstruct graph

then use link prediction - predict edge probabilities (possible new edges)

PinSAGE (Pinterest) : 

how to do sequential recommendation of purchases ?  paper Dynamic GNN for sequential recommendation

## causality 

shawhin talebi

pearl structural causality model (SCM)

hierarchy 
1. counterfactual
2. intervention
3. association

paper "relating gnn to structural causal models" velickovic

## unsupervised GNN training

predominant approach is self-supervised

variants of SSL on graphs
1. autoencoder
2. task generation - precalculated tasks (task is to predict descriptors like node degree - forces model to produce embeddings which learn structure)
3. contrastive : task is to maximize similarity between pairs, augmentation of positive pairs, use negative sampling within batch

augmentation ( attr masking, attr shuffling)



## Converting table (csv) to graph data

identify nodes, edge, node features, labels

use DataLoader in pytorch geometric

for temporal
```
The more or less difficult part with temporal graph datasets, is to define a stepsize for the temporal snapshots. In the dataset above we have random trips from one location to another, without a pre-defined discrete interval. An easy approach is for example to define X minute intervals and build a graph out of all trips that happened (ended) in this timeframe
```

Static Graph Temporal Signal
```
This is simply a graph that always stays the same and only the label information changes. Common examples are road networks (the nodes/edges do not suddently disappear in a long-range time horizon) or electricity networks.
```

Dynamic Graph Temporal/Static Signal
```
The more difficult graph type is a dynamic graph (with regards to nodes/edges). This typically happens in social networks, that quickly grow/shrink over time, but also transaction systems like crypto networks. Previously I mentioned that the node ordering is implicitly defined by the node feature matrix - but what if this matrix changes.
```
