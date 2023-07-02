
# Neural relational inference


your task is to figure out the interplay of components in a complex dynamical system

in this dataset, the goal is to predict whether or not any two balls are connected by a spring in an unsupervised manner. 
In both the multi-simulation encoder and single-simulation GNN architectures, springs are first hypothesized to exist between every two balls (fully connected graph).
The model then learns the likelihood of these hypotheses, hence predicting a weighted adjacency matrix indicating the probability of each edge. 

we present a more generalized formulation, briefly, that incorporates features of both nodes and edges.

https://medium.com/stanford-cs224w/how-to-analyze-interacting-systems-using-graph-neural-networks-940da9f9c013

https://arxiv.org/abs/1802.04687
Neural Relational Inference for Interacting Systems
Thomas Kipf, Ethan Fetaya, Kuan-Chieh Wang, Max Welling, Richard Zemel

https://colab.research.google.com/drive/1rSr0j-oof3dh-yb6BzZsz5bUVTCoq2EQ?usp=sharing

https://github.com/ethanfetaya/NRI
