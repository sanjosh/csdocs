
## Gaussian process (krasser)

Non-parametric method

instead of inferring distribution over parameters, GP can be used to infer distribution over functions

http://krasserm.github.io/2018/03/19/gaussian-processes/


## Gaussian process (cmu bagnell)

gaussian distribution over functions

bayesian linear regression is special case of GP with linear kernel

A Gaussian process is a random stochastic process where correlation is introduced between neighboring samples

### how to specify

specified by mean and kernel/covariance matrix

covariance matrix has larger values for points that are closer to each other, and smaller values for points further apart.

kernel must be positive semidefinite.  examples are squared exp, laplace

### how to plot

1. define mean and kernel
2. sample inputs
3. compute kernel E
4. sample from multivariate Gaussian N(0, E)
5. plot samples

### how to update GP or compute posterior

first find joint distribution

Use conditioning rules to compute posterior mean and conditional distribution

### computational complexity

much more costlier compared to bayesian linear regression

http://www.cs.cmu.edu/~16831-f14/notes/F14/16831_lecture22_venkat_koval_parashar.pdf


## Kernels

Kernels are widely used in machine learning, for example in support vector machines [5]. The reason for this is that they allow similarity measures that go far beyond the standard euclidean distance (L2L2-distance). Many of these kernels conceptually embed the input points into a higher dimensional space in which they then measure the similarity


## Gaussian process (roelants)

Stochastic process can lead to different paths. Each path is a realization.
Each realization defines a position 'd' at time 't. Thus every realization is a function f(t) = d
Stochastic process can be defined as a random distribution over functions
We can sample a realization of a function from a stochastic process

Thus a stochastic process can be interpreted as a random distribution over functions.

Gaussian Process is a distribution over a function, 
where distribution is defined by Mean m(x) and Positive Definite Covariance function k(x, x')

f(x) ~ GP(m(x),k(x,x′))

we can use them to build regression models
We treat Gaussian process as a prior defined by kernel function.
Then create a posterior distribution based on data.

https://peterroelants.github.io/posts/gaussian-process-tutorial/

## Gaussian process (bailey)

Linear regression : find function f such that y = f(x) + ϵ
find parameters A, B such that y = A + Bx + ϵ

Bayesian Linear regression : find distribution over parameters A, B that gets updated whenever new data points are observed

Gaussian Process is non-parametric : finds a distribution over the possible functions f(x) that are consistent with the observed data.

We don't want all the functions, but only those whose x value falls in some domain
Within that domain, we want smooth functions (i.e. use covariance matrix to ensure closeness in input space maps to closeness in output space)

This covariance matrix, along with a mean function to output the expected value of f(x) defines a Gaussian Process.

A GP defines a prior over functions, which can be converted into a posterior over functions once we have seen some data. Although it might seem difficult to represent a distrubtion over a function, it turns out that we only need to be able to define a distribution over the function’s values at a finite, but arbitrary, set of points, say x1, ..., xn

https://katbailey.github.io/post/gaussian-processes-for-dummies/

## Ref

Gaussian Processes for Machine Learning by Rasmussen and Williams.

Book Gaussian process for machine learning http://www.gaussianprocess.org/gpml/chapters/RW4.pdf

https://www.cs.toronto.edu/~duvenaud/cookbook/

https://distill.pub/2019/visual-exploration-gaussian-processes/

# MathematicalMonk


https://www.youtube.com/watch?v=vU6AiEYED9E&list=PLD0F06AA0D2E8FFBA&index=150

## examples of gaussian processes

1. Brownian motion
2. Squared exp
3. ornstein-ulhenbeck
4. A periodic gaussian process
5. A Symmetric gaussian process 

https://www.youtube.com/watch?v=clMbOOz6yR0&list=PLD0F06AA0D2E8FFBA&index=152

https://www.youtube.com/watch?v=e7as_wY0hUI&list=PLD0F06AA0D2E8FFBA&index=153

# COmputational

https://scikit-learn.org/stable/modules/classes.html?highlight=gaussian#module-sklearn.gaussian_process

https://scikit-learn.org/stable/modules/gaussian_process.html#gp-kernels

https://sheffieldml.github.io/GPy/

https://github.com/cornellius-gp/gpytorch

https://github.com/fonnesbeck/gp_regression

https://github.com/dfm/gp

https://george.readthedocs.io/en/latest/

https://github.com/krasserm/bayesian-machine-learning
