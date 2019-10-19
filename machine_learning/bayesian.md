
# Linear Regression (bayesian)

instead of thinking about the line minimizing a cost, think about it as maximizing the likelihood of the observed data.

likelihood=p(y1|x1,θ) * p(y2|x2,θ) * p(yn|xn,θ)

We want to find values of θ that maximize this result.

minimizing the residual sum of squares is equivalent to maximizing the likelihood of the data.

https://katbailey.github.io/post/from-both-sides-now-the-math-of-linear-regression/

## Ref

https://github.com/CamDavidsonPilon/Probabilistic-Programming-and-Bayesian-Methods-for-Hackers

http://blog.christianperone.com/2019/01/mle/

http://krasserm.github.io/2018/03/21/bayesian-optimization/

https://github.com/krasserm/bayesian-machine-learning

https://www.cs.ubc.ca/~nando/540-2013/lectures.html

An Introduction to Statistical Learning by James, Witten, Hastie and Tibshirani

Gaussian Processes for Machine Learning by Rasmussen and Williams.

Cameron Davidson-Pilon’s Probabilistic Programming & Bayesian Methods for Hackers is a fantastic introduction to Markov Chain Monte Carlo and the PyMC Python library

Kevin Murphy’s textbook Machine Learning: A Probabilistic Perspective.

## tools

https://github.com/pymc-devs/pymc

https://github.com/probml/pmtk3

