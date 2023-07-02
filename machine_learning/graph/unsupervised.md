
# Petar Velickovic

https://petar-v.com/talks/ACDL-UnsupGraph.pdf


## Random Walk (link prediction is special case)

hold out some edges, obtain node embeddings, optimize GNN to predict edges

### GraphSAGE Hamilton et al., NIPS 2017) 

DeepWalk needs whole graph to be available to learn embedding of node

GraphSAGE works on dynamic graphs (nodes added at runtime) - hence the name "inductive"

three parts : context construction, information aggregation, and loss function

aggregator function is learned : When the aggregator weights are learned, the embedding of an unseen node can be generated from its features and neighborhood.

GraphSAGE owes its inductivity to its aggregator functions. We can define various aggregators that are either parametric or nonparametric


Note: GraphSage is intended for use on large graphs (>100,000) nodes. The overhead of subsampling will start to outweigh its benefits on smaller graphs.

https://github.com/williamleif/GraphSAGE

https://towardsdatascience.com/an-intuitive-explanation-of-graphsage-6df9437ee64f


## Mutual Information maximization 

Deep Infomax

Deep InfoMax follows examples like Mutual Information Neural Estimation known as MINE.

Mutual information is just like a divergence or a difference between two different distributions, one is the joint distribution between two variables and the other is the product of marginals. 
The joint distribution is the probability that these two things co-occur and the product of marginals is their probabilities that they occur independently of each other.

https://medium.com/machine-intelligence-and-deep-learning-lab/deep-infomax-explanation-of-mutual-information-maximization-99cf98170138

Hjelm; Learning Deep Representations by Mutual Information Estimation and Maximization.

A natural way to capture similarities is optimising mutual information.
Attempt to simultaneously optimise for all pairs of nodes
The model will “discover” which pairs can be best compressed.


## Latent graph inference (neural relational inference)

derive interaction graph from observed dynamics

Use a downstream task to drive graph construction:
1. First, infer the graph (encoder network)
2. Then, use the graph to make predictions (decoder network)


