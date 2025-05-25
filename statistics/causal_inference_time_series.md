
# difference

Causality is constrained by temporal order: Causes must precede effects in time

# Approaches

## Grainger causality

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

```
import numpy as np
import pandas as pd
from tigramite import data_processing as pp
from tigramite.pcmci import PCMCI
from tigramite.independence_tests import ParCorr
import matplotlib.pyplot as plt

# Simulate time series data
np.random.seed(42)
T = 300  # Number of time steps
X = np.random.randn(T)
Z = 0.8 * X + 0.2 * np.random.randn(T)
Y = 0.5 * Z + 0.3 * np.random.randn(T)
data = np.column_stack([X, Y, Z])

# Wrap in Tigramite DataFrame
var_names = ['X', 'Y', 'Z']
dataframe = pp.DataFrame(data, var_names=var_names)

# Setup conditional independence test and run PCMCI
parcorr = ParCorr(significance='analytic')
pcmci = PCMCI(dataframe=dataframe, cond_ind_test=parcorr)
results = pcmci.run_pcmci(tau_max=2, pc_alpha=0.05)

# Plot the causal graph
pcmci.plot_graph(val_matrix=results['val_matrix'],
                 sig_matrix=results['p_matrix'],
                 alpha_level=0.05)

```


##  Dynamic Bayesian Networks (DBNs)

Extend Bayesian networks to model time dependencies.

See `pgmpy` package

## Nonlinear + Neural Methods

### Neural Granger Causality

learns nonlinear dependencies with LSTMs or attention

Highly accurate for nonlinear cases, but compute-intensive

see https://github.com/iancovert/Neural-GC

### TCDF

Temporal Causal Discovery Framework (interpretable convolutional networks)

see `TCDF` package


### NSC

Non-stationary causal discovery

 
# Scalability

1. Downsample your data (e.g. 1-minute intervals instead of 5 seconds)
2. Segment the data (e.g. run discovery on 1-month chunks)
3. Reduce variable space using feature selection or domain knowledge
4. Use parallel computing (especially for Granger or neural methods)
5. Limit max lag (e.g. 3–5 steps instead of dozens)

Run PCMCI from the tigramite package with downsampled data

Use Neural Granger on subsets of variables or compressed representations


#  Feature Engineering for Time Series:

Lags: Include lagged values of the treatment, outcome, and covariates as features (X, W, T) in your CausalForestDML model. For example, to estimate the effect of treatment at time t on outcome at time t+k, you might include T(t), Y(t-1), X(t), X(t-1).  This explicitly incorporates temporal dependencies.

Moving Averages, Differences, Trends: Create features that capture the dynamic behavior of the time series (e.g., moving averages, seasonal components, detrended values).

Stationarization: If applicable, transforming non-stationary series into stationary ones (e.g., differencing) can help meet the assumptions of underlying machine learning models used within DML.
