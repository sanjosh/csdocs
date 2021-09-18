

# The Bayesian Learning Rule

https://arxiv.org/abs/2107.04562

Mohammad Emtiyaz Khan, Håvard Rue

We show that many machine-learning algorithms are specific instances of 
a single algorithm called the Bayesian learning rule. 

The rule, derived from Bayesian principles, yields a wide-range of algorithms from fields such as optimization, deep learning, and graphical models. This includes classical algorithms such as ridge regression, Newton's method, and Kalman filter, as well as modern deep-learning algorithms such as stochastic-gradient descent, RMSprop, and Dropout. The key idea in deriving such algorithms is to approximate the posterior using candidate distributions estimated by using natural gradients. Different candidate distributions result in different algorithms and further approximations to natural gradients give rise to variants of those algorithms. 

Our work not only unifies, generalizes, and improves existing algorithms, but also helps us design new ones.

You need to make two decisions: first, the form of the post. approx. and second, the natgrad approx.

The main message is that many algorithm, that have "stood-the-test-of-time", can all be seen as solving a two-step scheme where
1. A Bayesian objective is optimized to find posterior approximations
2. Natural-gradient descent is used for optimization (Bayesian learning rule)

## ridge regression, 

## Newton’s method, 

## Kalman filter, 

## stochastic-gradient descent, 

## RMSprop, 

## Dropout


# Continual lifelong learning with neural networks: A review



Parisi, German I., et al. "Continual lifelong learning with neural networks: A review." Neural Networks (2019)

# ref

https://team-approx-bayes.github.io/
