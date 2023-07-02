
The choice of aggregate and merge functions in GNNs is crucial.

Different choices for the aggregate and merge functions can lead to different variants of GNN. 
1. the sum function for aggregate leads to the Graph Convolutional Network (GCN) 
2. concatenation function for the merge function leads to GraphSAGE.

The representational power of the GNN depends on the aggregate function used [5]. (sum > mean > max)
The image above shows the ranking of the expressive power of GNNs based on their aggregation function.

A GNN variant with maximal representation power would be one which has an injective aggregate function, like the Graph Isomorphism Network.

https://medium.com/stanford-cs224w/graphs-are-all-you-need-generating-multimodal-representations-for-vqa-744a8a1ad448

Xu, Keyulu, et al. “How powerful are graph neural networks?.” arXiv preprint arXiv:1810.00826 (2018)
