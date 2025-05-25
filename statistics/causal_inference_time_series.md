
# difference

Causality is constrained by temporal order: Causes must precede effects in time

# Approaches

## grainger causality

If past values of X help predict future values of Y, then X "Granger-causes" Y.

Assumes linearity and no unobserved confounders

see `statsmodels`

## VAR 

Use a Vector Autoregression (VAR) model to summarize time-lagged dependencies.

Then apply causal discovery methods (e.g., PC, LiNGAM) to the coefficients or residuals.

Example:

Fit VAR:

```
X(t) = A1.X(t-1) + A2.X(t-2) + ... + An
```
Analyze structure of At or residual dependencies
​
## Temporal PC / PCMCI (PC = Peter-Clark algo)

uses conditional independence testing across lags and corrects for autocorrelation.

Handles high-dimensional time series

Can detect both lagged and contemporaneous effects

see `tigramite` package


##  Dynamic Bayesian Networks (DBNs)

Extend Bayesian networks to model time dependencies.


## Nonlinear + Neural Methods

Neural Granger Causality: learns nonlinear dependencies with LSTMs or attention

TCDF: Temporal Causal Discovery Framework (interpretable convolutional networks)

NSC: Non-stationary causal discovery

see `TCDF` package
 
