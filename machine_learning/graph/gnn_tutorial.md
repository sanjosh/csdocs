
## Goal

learn state embedding which contains information on neighbourhood of each node

Just like a CNN aims to extract the most important information from the image to classify the image, 
a GCN passes a filter over the graph, looking for essential vertices and edges that can help classify nodes within the graph.

(https://missinglink.ai/guides/convolutional-neural-networks/graph-convolutional-networks/)


## concepts are same

* local connection : capture neighbourhood
* shared weights : 
* the use of multi-layer  : capture hierarchy of multi-scale features

Locality in
* images : CNN uses convolutional layer
* text : Transformer uses local context
* graph : adjacent nodes

Other mechanisms
* skip connection

types of networks
* auto-encoder
* generator
* attention
* convolution

properties
* universal approx
* receptive field
* VC dim

## Pooling

```
Images have a natural structure for pooling, for graphs we can use sub-graphs as the pools. 
DIFFPOOL provides a general solution for hierarchical pooling of nodes across a broad set of input graphs, and can be used in end-to-end training. 
It learns a cluster assignment matrix based on cluster node features and a coarsened adjacency matrix.
(kdnuggets article)
```




## Why not CNN or RNN for graphs ?

* graph nodes do not have specific order but CNN/RNN need order
* edges represent dependency between nodes but CNn/RNN just bundle it as "feature"

## Training data

data input is nodes 

## Input type

* directed graph
* graph with edge info
* heterogenous graph
* dynamic graph


## Message passing neural network

has 2 phases
1. message passing
2. readout

J. Gilmer, S. S. Schoenholz, P. F. Riley, O. Vinyals, and G. E. Dahl,
“Neural message passing for quantum chemistry,” arXiv preprint
arXiv:1704.01212, 2017.

# Types of GNN

```
In the domain of spatial GCNs there are two further main divisions. 
Recurrent-based methods apply the same graph convolution layer repeatedly over time until a stable fixed point is reached. 
Composition-based GCNs stack a number of convolutional layers, much like a classic CNN. 
A representative example here is Message-Passing Neural Networks.
(kdnuggets article)
```



## Graph convolutional network

graph convolution operation produces the normalized sum of neighbors' node features

## Graph attention network

GAT introduces the attention mechanism as a substitute for the statically normalized convolution operation.

attention enables variable sized input

more important nodes receive higher weight during neighbourhood aggregation

## Graph auto-encoder

Representation learning/embedding

* node2vec
* DeepWalk
* TADW
* LINE

## Graph generative networks

## Graph spatio-temporal networks

time dimension added

## gated graph neural network

# Applications

## link prediction

## node classification

## recommender systems

## Traveling salesman

## karate club problem / community detection 

LINE graph neural net (LGNN)
https://docs.dgl.ai/en/0.4.x/tutorials/models/



# references

Jie Zhou, Graph Neural Networks
https://arxiv.org/pdf/1812.08434.pdf

Zonghan Wu, A Comprehensive Survey on Graph Neural networks
https://arxiv.org/pdf/1901.00596.pdf

https://dsgiitr.com/blogs/gat/

https://arxiv.org/pdf/1710.10903.pdf

https://www.kdnuggets.com/2019/02/comprehensive-survey-graph-neural-networks.html

