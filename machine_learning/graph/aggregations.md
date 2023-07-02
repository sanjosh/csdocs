
# Aggregations

The choice of aggregate and merge functions in GNNs is crucial.

Different choices for the aggregate and merge functions can lead to different variants of GNN.

```
the sum function for aggregate leads to the Graph Convolutional Network (GCN)

concatenation function for the merge function leads to GraphSAGE.

The representational power of the GNN depends on the aggregate function used [5]. (sum > mean > max)
```

The image (in link below) shows the ranking of the expressive power of GNNs based on their aggregation function.

A GNN variant with maximal representation power would be one which has an injective aggregate function, like the Graph Isomorphism Network.

https://medium.com/stanford-cs224w/graphs-are-all-you-need-generating-multimodal-representations-for-vqa-744a8a1ad448

Xu, Keyulu, et al. “How powerful are graph neural networks?.” arXiv preprint arXiv:1810.00826 (2018)

```
mean aggregation captures the distribution (or proportions) of elements

max aggregation proves to be advantageous to identify representative elements

sum aggregation enables the learning of structural graph properties (Xu et al. (2018))

multiple aggregations (Corso et al. (2020), Tailor et al. (2021))

learnable aggregations (Li et al. (2020)) 
```
https://pytorch-geometric.readthedocs.io/en/latest/modules/nn.html#convolutional-layers


```
The mean operation can be useful when nodes have a highly-variable number of neighbors or you need a normalized view of the features of a local neighborhood.

The max operation can be useful when you want to highlight single salient features in local neighborhoods.

Sum provides a balance between these two, by providing a snapshot of the local distribution of features, but because it is not normalized, can also highlight outliers
```

https://distill.pub/2021/gnn-intro/
