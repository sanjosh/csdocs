
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


