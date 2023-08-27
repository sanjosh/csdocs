
# bayesian strucural time series

https://en.wikipedia.org/wiki/Bayesian_structural_time_series

All ARIMA models can be written as structural time series models


# structural time series (not bayesian, AKA state space models)

unobserved variable is called "state space"


# why bsts

```
BSTS is more transparent because its representation does not rely on differencing, lags and moving averages. You can visually inspect the underlying components of the model. It handles uncertainty in a better way because you can quantify the posterior uncertainty of the individual components, control the variance of the components, and impose prior beliefs on the model. Last, but not least, any ARIMA model can be recast as a structural model. Generally, we can write a Bayesian structural model like this:
```

https://jasonlian.github.io/Rmarkdown/Tutorial_for_BSTS.html

```
When building Bayesian models we get a distribution and not a single answer. Thus, the bsts package returns results (e.g., forecasts and components) as matrices or arrays where the first dimension holds the MCMC iterations.

```

https://multithreaded.stitchfix.com/blog/2016/04/21/forget-arima/


# structural time series

The key challenge with time series data is the missing values and absence of confounders - makes them special

https://gowrishankar.info/blog/structural-time-series-models-why-we-call-it-structural-a-bayesian-scheme-for-time-series-forecasting/


## counterfactual 

```
Causal effect = E[ Y | x = 1] - E[Y | x = 0]
```

Causal effect is the magnitude by which Y is changed by unit change in X 

https://gowrishankar.info/blog/is-covid-crisis-lead-to-prosperity-causal-inference-from-a-counterfactual-world-using-facebook-prophet/


# packages

R package bsts

https://github.com/wwrechard/pydlm

tensorflow probability
https://blog.tensorflow.org/2019/03/structural-time-series-modeling-in.html

Steven L. Scott and Hal Varian
https://www.inderscienceonline.com/doi/abs/10.1504/IJMMNO.2014.059942
