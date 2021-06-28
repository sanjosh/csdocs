
In general dimension reduction is limited by the packing bound

# Survey of dimension reduction techniques

## linear vs non-linear

We distinguish two major types of dimension reduction methods: linear and non-linear. Linear techniques
result in each of the k ≤ p components of the new variable being a linear combination of the original variables

## need for higher-order linear

For normal variables (with mean zero), the covariance matrix contains all the information about
the data. Second-order methods are relatively simple to code, as they require classical matrix manipulations.

However, many datasets of interest are not realizations from Gaussian distributions. For those cases, higher-
order dimension reduction methods, using information not contained in the covariance matrix, are more
appropriate. Such a linear higher-order method, projection pursuit is reviewed in Section 4. Section 5
summarizes another higher-order linear method called independent component analysis.

##  TODO - PCA

Principal Component Analysis: A Natural Approach to Data Exploration
https://dl.acm.org/doi/10.1145/3447755

## PCA (linear)

second order method based on covariance matrix

aka singular value decomposition (SVD), the Karhunen-Loève transform, the Hotelling transform, and the empirical orthogonal function (EOF) method.

For many datasets, the first several PCs explain most of the variance, so that the rest can be disregarded with minimal loss of information.

first standardize each variable to have mean zero and standard deviation one.

eigenvalue decomposition : total variation is equal to the sum of the eigenvalues of the covariance matrix,


## Factor analysis


### Principal factor analysis

### max likelihood factor analysis

## projection pursuit

Projection pursuit (PP) is a linear method that, unlike PCA and FA, can incorporate higher than second-
order information, and thus is useful for non-Gaussian datasets. It is more computationally intensive than
second-order methods.

Optimize based on a projection index

## independent component analysis

ICA is a higher-order method that seeks linear projections, not necessarily orthogonal to each other, that
are as nearly statistically independent as possible.

statistical independence requires that the multivariate probability density function factorizes,

While PCA seeks uncorrelated variables, ICA seeks independent variables.

goal of ICA is not necessarily dimension reduction.

ICA has been applied to many different problems, including exploratory data analysis, blind source
separation, blind deconvolution, and feature extraction. In the feature extraction context, the columns of
the matrix A represent features in the data, and the components s i give the coefficient of the ith feature in
the data. Several authors used ICA to extract meaningful features from natural images

Multi-unit and single-unit objective functions

mutual information is always non-negative, and is zero if and only if the variables are statistically independent

## Non-linear PCA

non-linear objective function, but the resulting components are still linear combinations of the original variables.

## Random projections

S = R.X 

* where X in R^p, 
* columns of R are realizations of independent and identically distributed (i.i.d.) zero-mean normal variables, scaled to have unit length
* S in R^k
* and k << p

if the similarity between two vectors is measured by their inner product (giving the cosine of their angle
for unit-length vectors), [33] showed that if the dimension of the reduced space d is large, random projection
matrices preserve the similarity measure: on the average, the distortion of the inner products is zero, and
its variance is at most the inverse of twice d

## Non-linear methods

### Non-linear independent component analysis

### principal curves

Principal curves are smooth curves that pass through the “middle” of multidimensional data sets [18, 40, 7].
Linear principal curves are in fact principal components, while non-linear principal curves generalize the
concept

### multidimensional scaling

Popular distance measures include the Euclidean distance (L 2 norm), the manhattan distance (L 1 , absolute norm), and the maximum norm. 

Results of MDS are indeterminate with respect to translation, rotation, and reflection.

MDS methods that incorporate the given distances δ ij into their calculations are called metric
methods, while the ones that only use the rank ordering of the distances are called non-metric methods.

An alternative to MDS is FastMap [12], a computationally efficient algorithm that maps high-dimensional
data into lower-dimensional spaces, while preserving distances between objects.

https://en.wikipedia.org/wiki/Multidimensional_scaling

### topologically continuous maps

* Kohonen self-organizing

### neural nets

Many, traditional and more recent, linear and non-linear, dimension reduction techniques can be implemented using neural networks
with different architectures and learning algorithms

K.I. Diamantaras and S.-Y. Kung. Principal Component Neural Networks. Theory and Applicatins.
John Wiley & Sons, New York, Londin, Sydney, 1996.

M.A. Carreira-Perpinan. A review of dimension reduction techniques. Technical report CS-96-09,
Department of Computer Science, University of Sheffield, 1997.

### vector quantization

### genetic and evolutionary algorithms

### regression

Dimension reduction methods related to regression include projection pursuit regression [20, 7], gener-
alized linear [42, 10] and additive [19] models, neural network models, and sliced inverse regression and
principal hessian directions

### Gaussian process

uses a Gaussian process to learn a low-dimensional representation of (potentially) high-dimensional data. 

In the typical setting of Gaussian process regression, where we are given inputs X and outputs y, 
we choose a kernel and learn hyperparameters that best describe the mapping from X to y. 

In the GPLVM, we are not given X: we are only given y. So we need to learn X along with the kernel hyperparameters

http://pyro.ai/examples/gplvm.html

## References

Imola K. Fodor, A survey of dimension reduction techniques, 202

# Johnson-Lindenstrauss lemma 

it works for smaller points in hi-dim space : 

for n points in R^d, exists linear map that preserves isometry 
    f : R^d _. R^k

* where k is logarithmic in n and independent of d
* where k > 4.(1/eps_factor).log(n)

Map can be found in randomized poly time

Can be adapted to Online algo (muthukrishnan)

[Ref](https://afonsobandeira.wordpress.com/2013/09/13/the-johnson-lindenstrauss-lemma/)


# Diffusion maps

https://en.wikipedia.org/wiki/Diffusion_map


# t-Distributed Stochesic Neighbour Embedding (t-SNE)

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


