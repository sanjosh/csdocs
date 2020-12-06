
# variational inference

problem : infer hidden structure from observed data

p(z | x) = p(x | z).p(z)/p(x) = p(z, x)/Integral p(z', x)

denominator is hard to compute

approx p by q(z|x) which is called variational distribution

Variational inference minimizes the KL divergence from the variational distribution to the posterior distribution. 
It maximizes the evidence lower bound (ELBO), a lower bound on the logarithm of the marginal probability of the 
observations log p(x)

ELBO is underlying reason why VAE work

steps
1. define probabilistic graphical model
2. use posterior inference algorithms

steps
1. use hidden variables to encode hidden structure in observed data; 
2. articulate the relationship between the hidden and observed variables with a factorized probability distribution
(i.e., a graphical model); 
3. use inference algorithms to estimate the posterior distribution, the
conditional distribution of the hidden structure given the observations.



```
solved with a coordinate ascent algorithm, iterating between re-analyzing every data 
point in the data set and re-estimating its hidden structure

This is inefficient for large data sets, however, because it requires a full pass 
through the data at each iteration
```

(Jordan 1999, Wainwright and Jordan 2008)

# Stochastic variational inference

apply complex bayesian models to massive data sets

(Hoffman, Stochastic Variational Inference, Journal of MLR)
