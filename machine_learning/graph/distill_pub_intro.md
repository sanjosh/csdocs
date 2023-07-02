
Distill pub https://distill.pub/2021/gnn-intro/

# Analogies

## Graph level task

This is analogous to image classification problems with MNIST and CIFAR, where we want to associate a label to an entire image. With text, a similar problem is sentiment analysis where we want to identify the mood or emotion of an entire sentence at once.

## Node level task

Following the image analogy, node-level prediction problems are analogous to image segmentation, where we are trying to label the role of each pixel in an image. With text, a similar task would be predicting the parts-of-speech of each word in a sentence (e.g. noun, verb, adverb, etc).

## Edge level task

# Pooling

collect information from edges and give them to nodes for prediction, or vice-versa.

We can do this by pooling. 

If we only have node-level features, and need to predict a binary global property, we need to gather all available node information together and aggregate them. This is similar to Global Average Pooling layers in CNNs

# Message passing

neighboring nodes or edges exchange information and influence each other’s updated embeddings.

Just as pooling can be applied to either nodes or edges, message passing can occur between either nodes or edges.

message passing and convolution are operations to aggregate and process the information of an element’s neighbors in order to update the element’s value. In graphs, the element is a node, and in images, the element is a pixel

Which graph attributes we update and in which order we update them is one design decision when constructing GNNs. We could choose whether to update node embeddings before edge embeddings, or the other way around. This is an open area of research with a variety of solutions– for example we could update in a ‘weave’ fashion [21] where we have four updated representations that get combined into new node and edge representations: node to node (linear), edge to edge (linear), node to edge (edge layer), edge to node (node layer)

# Master node

Nodes far away may not be able to efficiently transfer information, if task depends on information between nodes farthest

In this case, introduce master node which acts as bridge between all nodes

# Inductive bias

When building a model to solve a problem on a specific kind of data, we want to specialize our models to leverage the characteristics of that data.

For images, use convolutions, which are translation invariant. 

For text, the order of the tokens is highly important, so recurrent neural networks process data sequentially

For graph, model should preserve explicit relationships between entities (adjacency matrix) and preserve graph symmetries (permutation invariance).

