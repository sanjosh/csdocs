
# UMAP

Rationale : A neighborhood graph based approach should capture manifold structure when doing dimension reduction. You can construct this graph using a simplicial complex.

Simplicial complexes are a means to construct topological spaces out of simple combinatorial components. This allows one to reduce the complexities of dealing with the continuous geometry of topological spaces to the task of relatively simple combinatorics and counting.

A k-simplex is a very simple way to build an k-dimensional object.
A simplicial complex is a set of simplices glued together along faces
An open cover is essentially just a family of sets whose union is the whole space
A Čech complex is a combinatorial way to convert the topology into a simplicial complex.
Vietoris-Rips complex, which is similar to the Čech complex but is entirely determined by the 0- and 1-simplices.

Given data samples as points in topological space
Create circles which represent open sets of the cover
The simplicial complex does a reasonable job of starting to capture the fundamental topology of the dataset
Most of the work is really done by the 0- and 1-simplices, which are easier to deal with computationally (it is just a graph, in the nodes and edges sense)

Build a dimension reduction algorithm by finding a low dimensional representation of the data that has a similar topological representation.
If we only want 0- and 1-simplices, then this is a graph layout problem
if we want to use spectral methods for graph layout, then this becomes Laplacian eigenmaps and Diffusion maps
If we want force-directed layouts, then this is MDS or Sammons mapping

Dilemma of deciding radius since the points from dataset are not uniformly distributed :
if radius of balls is too small, resulting simplicial complex splits into too many components
if radius of balls is too large, you get few high-dimensional complexes which do not capture manifold structure.

Solve the problem by assuming points are uniformly distributed : give each points its own distance function.
A unit ball about a point stretches to the k-th nearest neighbor of the point, where k is the sample size we are using to approximate the local sense of distance.
Choosing a distance k is very dataset dependent: one needs to look at the distribution of distances in the dataset to even begin to select a good value.
The local metric space can also be used to decide the weights on the edges of the graph

Dilemma of outliers : Some points in high dimensional spaces can be isolated
Need to ensure local connectivity. Every point should be connected to at least one other point

Dilemma of incompatible local metrics : Distance (b, a) is different from distance (a, b)
Make weight(a, b) = a + b - a.b (where a, b in [0, 1]) = probability that at least one edge exists

Find a low dimensional representation with the closest fuzzy topological structure.
Cross-entropy based on weight of edges in high and low-dimensional spaces

UMAP Algo:
Find a fuzzy topological representation: Use nearest neighbour descent algorithm of Dong, et al
Optimize low dimensional representation to have as close a fuzzy topological representation as measured by cross-entropy. Use stochastic gradient descent using objective function which is differentiable.

https://umap-learn.readthedocs.io/en/latest/how_umap_works.html
