

## Kernals

Kernels are widely used in machine learning, for example in support vector machines [5]. The reason for this is that they allow similarity measures that go far beyond the standard euclidean distance (L2L2-distance). Many of these kernels conceptually embed the input points into a higher dimensional space in which they then measure the similarity



## Gaussian process

Stochastic process can lead to different paths. Each path is a realization.
Each realization defines a position 'd' at time 't. Thus every realization is a function f(t) = d
Stochastic process can be defined as a random distribution over functions
We can sample a realization of a function from a stochastic process

Thus a stochastic process can be interpreted as a random distribution over functions.

Gaussian Process is a distribution over a function, where distribution is defined by Mean m(x) and Positive Definite Covariance function k(x, x')

f(x) ~ GP(m(x),k(x,x′))

we can use them to build regression models
We treat Gaussian process as a prior defined by kernel function.
Then create a posterior distribution based on data.

https://peterroelants.github.io/posts/gaussian-process-tutorial/

## Gaussian process

Linear regression : find function f such that y = f(x) + ϵ
find parameters A, B such that y = A + Bx + ϵ

Bayesian Linear regression : find distribution over parameters A, B that gets updated whenever new data points are observed

Gaussian Process is non-parametric : finds a distribution over the possible functions f(x) that are consistent with the observed data.

We don't want all the functions, but only those whose x value falls in some domain
Within that domain, we want smooth functions (i.e. use covariance matrix to ensure closeness in input space maps to closeness in output space)

This covariance matrix, along with a mean function to output the expected value of f(x) defines a Gaussian Process.

A GP defines a prior over functions, which can be converted into a posterior over functions once we have seen some data. Although it might seem difficult to represent a distrubtion over a function, it turns out that we only need to be able to define a distribution over the function’s values at a finite, but arbitrary, set of points, say x1, ..., xn

https://katbailey.github.io/post/gaussian-processes-for-dummies/

# Ref

Gaussian Processes for Machine Learning by Rasmussen and Williams.

Book Gaussian process for machine learning http://www.gaussianprocess.org/gpml/chapters/RW4.pdf

https://www.cs.toronto.edu/~duvenaud/cookbook/

https://distill.pub/2019/visual-exploration-gaussian-processes/
