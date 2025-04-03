
# bayesian structural time series

https://en.wikipedia.org/wiki/Bayesian_structural_time_series

All ARIMA models can be written as structural time series models


# spike and slabs prior

https://en.wikipedia.org/wiki/Spike-and-slab_regression

```
Another advantage of Bayesian structural models is the ability to use spike-and-slab priors.
This provides a powerful way of reducing a large set of correlated variables into a parsimonious model,
while also imposing prior beliefs on the model.
Furthermore, by using priors on the regressor coefficients,
the model incorporates uncertainties of the coefficient estimates when producing the credible interval for the forecasts.
```

https://jasonlian.github.io/Rmarkdown/Tutorial_for_BSTS.html#13_bayesian_variable_selection

# kalman is bayesian

```
The Kalman Filter and its variants are Bayesian inference on a time series.

You have a hidden state x_t, x_t+1,.. and observations y_t, y_t+1.. .
There is a model for the evolution of the hidden state (e.g. physics of an asteroid moving through space)
and
a model for the observations given the hidden state (how an image of the asteroid is produced given its position and velocity).
There is also a prior for the hidden state, which comes from the previous time step.
```

https://www.reddit.com/r/statistics/comments/12c5azg/use_cases_for_bayesian_time_series_q/

# structural time series (not bayesian, AKA state space models)

unobserved variable is called "state space"

A structural time series in particular posits a particular form for these relationships, that these functions between states and observations, and between states and previous states are linear subject to Gaussian noise.

https://embecosm.com/2021/12/18/forget-arima-going-bayesian-with-time-series-analysis/


# going bayesian



https://embecosm.com/2021/12/18/forget-arima-going-bayesian-with-time-series-analysis/

code for it
https://github.com/WillRogerJones/BayesianTimeSeries

# why bsts

```
BSTS is more transparent because its representation does not rely on differencing, lags and moving averages.
You can visually inspect the underlying components of the model.
It handles uncertainty in a better way because you can quantify the posterior uncertainty of the individual components, control the variance of the components, and impose prior beliefs on the model.
Last, but not least, any ARIMA model can be recast as a structural model. Generally, we can write a Bayesian structural model like this:
```

https://jasonlian.github.io/Rmarkdown/Tutorial_for_BSTS.html

```
When building Bayesian models we get a distribution and not a single answer.
Thus, the bsts package returns results (e.g., forecasts and components) as matrices or arrays where the first dimension holds the MCMC iterations.

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

# four ways to add bayesian

## Bayesian ARIMA

## Bayesian Structural Time Series (BSTS)

Bayesian Structural Time Series (BSTS) models decompose time series data into distinct components, incorporating trend components for long-term patterns, seasonal elements for cyclical behavior, external regressors for additional variables, and anomaly detection capabilities


## Bayesian Dynamic Linear Models (BDLMs)

Bayesian Dynamic Linear Models (BDLMs) extend state-space models through Bayesian inference, proving particularly valuable when relationships between variables evolve over time. 

use pymc 

## Bayesian Neural Networks (BNNs).

Bayesian Neural Networks (BNNs) merge neural network architecture with Bayesian principles. 

https://medium.com/@kylejones_47003/bayesian-time-series-analysis-in-python-bsts-bdlm-bnn-b-arima-1ca74d6cc3de

# packages

R package bsts

PyBSTS

https://github.com/wwrechard/pydlm

tensorflow probability
https://blog.tensorflow.org/2019/03/structural-time-series-modeling-in.html

Steven L. Scott and Hal Varian
https://www.inderscienceonline.com/doi/abs/10.1504/IJMMNO.2014.059942
