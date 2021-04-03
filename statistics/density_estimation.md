
# Density estimation

Two ways to do density estimation
1. MLE (frequentist)
2. MAP (bayesian)

for joint distribution, latent variables have to be discovered - EM algo

Parametric is when distribution is assumed or known

# parametric vs non-parametric

Non-parametric
1. Parzen windows
   estimate likelihood = `P(x | Cj)`

2. Nearest neighbours
   do posterior estimation = `P(Cj | x)`

```
Given p(x) = (k/n) / V
where V = volume of region R
and k = number of samples inside R
and n = total number of samples

In Parzen, fix volume V and determine k - number of pts inside V
In nearest neighbour, fix k and determine V that contains k
good rule of thumb is to choose k = sqroot(n)
```

There are multiple approaches to approximate a model or a function to fit a
given data set. The list includes 

1. Splines
2. Least square regression
3. Levenberg-Marquardt
4. K-nearest neighbors
5. Histogram
6. Polynomial interpolation
7. Logistic regression
8. Neural Networks
9. Tensor products
... and many more


# MAP vs MLE



```
From the vantage point of Bayesian inference, MLE is a special case of maximum a posteriori estimation (MAP) that assumes a uniform prior distribution of the parameters. In frequentist inference, MLE is a special case of an extremum estimator, with the objective function being the likelihood.
```

https://en.wikipedia.org/wiki/Maximum_likelihood_estimation

D = (x1, .. xn)

Assume joint distribution p(D, Theta)

Theta_MAP = arg_max p (theta | posterior distribution)

Theta_MLE = arg_max p (data | theta )

Advantages:
* Use MAP if prior is known (bayesian)
* MAP with flat priors = MLE
* MAP avoid overfitting
* tends to look like MLE as n -> inf

Disadvantages
* no representation of uncertainty since its point estimate
* Not invariant under reparametrization

## references

https://www.youtube.com/watch?v=kkhdIriddSI&list=PLD0F06AA0D2E8FFBA&index=31

https://wiseodd.github.io/techblog/2017/01/01/mle-vs-map/

https://stats.stackexchange.com/questions/95898/mle-vs-map-estimation-when-to-use-which
