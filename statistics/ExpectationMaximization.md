
# Expectation Maximization algo

1. Expectation-step : estimate missing data based on observed data and current estimate of model parameters
2. Maximization-step : maximize likelihood func after assuming missing data are known the estimate of missing data from E-step is used

* [StackExchange](http://stats.stackexchange.com/questions/72774/numerical-example-to-understand-expectation-maximization)
* [Weiss, EM tutorial]

Given a set of points for a mixture of 2 distributions, how to find individual distribution ?

```
E-step : each point can belong to any of 2 distributions
        calculate residuals for each datapoint
        calculate 2 weights for each datapoint,
        after running them thru a softmin func

M-step : fit the points to each distribution
         estimate parameters for each distribution
         using (weight * each point)
```

* [EM tutorial paper by Do and Batzoglou]
* [Stackoverflow](http://stackoverflow.com/questions/11808074/what-is-an-intuitive-explanation-of-expectation-maximization-technique)
