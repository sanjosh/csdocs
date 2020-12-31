
# Intro

One of the main attractions of the Gaussian process framework is
precisely that it unites a sophisticated and consistent view with computational
tractability.

A Gaussian process is a generalization of the Gaussian probability distribution. 
Whereas a probability distribution describes random variables which are 
scalars or vectors (for multivariate distributions), a stochastic process governs 
the properties of functions.

non-parametric

1. mean
2. pointwise variance
3. covariance (between random variables which constitute GP)

Slower variation is achieved by simply adjusting parameters of the
covariance function. The problem of learning in Gaussian processes is exactly
the problem of finding suitable properties for the covariance function

two views of Gaussian process
1. function space view : distribution over functions
2. weight space view 

# Regression

Kernel trick : If an algorithm is defined solely in terms of inner products in input space
then it can be lifted into feature space by replacing occurrences of those inner
products by k(x, x')

## weight space view

Basis Functions : project input space into some high-dimensional feature space
where inputs become linearly separable.

## function space view

A Gaussian process is defined as a collection of random variables.

A Gaussian process is completely specified by its mean function and covariance function.

f(x) = GP(m(x), k(x, x'))

In non-Bayesian paradigms, the model is typically trained by minimizing the empirical risk (or loss). 

In contrast, in the Bayesian setting there is a clear separation between the 
likelihood function (used for training, in addition to the prior) and the loss function. 
The likelihood function describes how the noisy measurements are assumed to deviate 
from the underlying noise-free function. 
The loss function, on the other hand, captures the consequences of making a specific choice, 
given an actual true state. 
The likelihood and loss function need not have anything in common

GP in geostatistics is called Kriging

# Classification

the solution of classification problems using Gaussian processes is rather more demanding than for the regression problems 

This is because we assumed in the previous chapter that the
likelihood function was Gaussian; a Gaussian process prior combined with a
Gaussian likelihood gives rise to a posterior Gaussian process over functions,
and everything remains analytically tractable. 

For classification models, where the targets are discrete class labels, 
the Gaussian likelihood is inappropriate, we need approximate methods.

logistic regression is generalized to Gaussian process classification (GPC)

likelihood is non-Gaussian but the posterior process can be approximated by a GP.

## Generative model for classification

## Discriminative model for classification

## binary classification

place a GP prior over the latent function f (x) and then “squash” this through the logistic function to obtain a prior on

## approx methods

need to use either 
1. analytic approximations of integrals
2. solutions based on Monte Carlo sampling

### Laplace approx for GPC

### Expectation propagation algorithm

# Covariance function

* Kernel : function k of two arguments mapping a pair of inputs x, x' into R 
* Given inputs points {x[k] | k = 1..n}, Gram matrix has entries K(i,j) = k(x[i], x[j])
* if kernel k is a covariance function, then Gram matrix is Covariance matrix 

## stationary

## dot product

## examples of covariance function

### constant

### linear

### polynomial

### squared exponential : linear regression 

### Matern

### exponential

### rational quadratic

## new kernels from old

* sum of 2 kernels = kernel
* multiplication of 2 kernels = kernel
* rescaling
* convolution
* direct sum
* tensor product


## kernel decomposition (mercer's theorem)


# Model selection

# Relationships between GPs and other models

# Theoretical perspectives

# Approximation methods for large datasets

One issue with Gaussian process prediction methods is that their basic com-
plexity is O(n^3), due to the inversion of a n×n matrix. For large datasets this is
prohibitive (in both time and space) and so a number of approximation methods
have been developed,

# Further issues and conclusions


