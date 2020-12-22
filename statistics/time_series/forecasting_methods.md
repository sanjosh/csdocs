
# Overview

Classical

1. Arima
2. exp smoothing (holt winters)
3. Theta method of Assimakopoulos, Nikopoulos

ML based

1. Quantile regression forests
2. RNN
3. Gradient Boosting trees
4. Support vector regression
5. Gaussian Process Regresssion

# observations

Arima biased towards recent, Theta towards long-term

heirarchical forecasting : multiple timescales

heteroscedastic : handling errors that are not normally distributed

domain agnostic

## uber Danny Yuan

decompose using FFT, forecast on individual component and then run inverse 
but not easy to add new signals

instead encoder-decoder

InfoQ 2018
https://www.youtube.com/watch?v=VYpAodcdFfA

## uber Franziska Bell 

Best model depends on
1. data
2. correlation with explanatory variables
3. interpretability, computational complexity

Evaluation using Backtesting
1. Sliding window
2. Expanding window

Prediction interval

https://www.youtube.com/watch?v=bn8rVBuIcFg

publications

1. engineering uncertainty estimation in neural networks for time series prediction at uber
2. engineering extreme event forecasting at uber with RNN
3. omphalos, Uber's parallel and extreme extensible time series backtesting tool

## jeff yau

multivariate time series model

### VAR

VAR (system of linear eqn) only applies to stationary series

State space representation

non-stationary series can be transformed into stationary using diffeence of log, and if series not co-integrated, we can apply VAR

Got co-integrated series, use Vector error correction model

1. what are dynamic properties ? look at own lagged coefficients
2. do series interact ? look at cross lagged coefficients

find best model using AIC/BIC/HQIC

then do inverse transform to get original series

### Neural LSTM

1. stationarity is not a requirement
2. exogenous variables can be added
3. auto feature extraction

Flint time series for Spark

### kalman filter

VAR implementation

https://www.youtube.com/watch?v=i40Road82No

# Competitions

https://en.wikipedia.org/wiki/Makridakis_Competitions

# software

statsmodels

# TODO Theta model

https://www.sciencedirect.com/science/article/abs/pii/S0169207000000662

# References

1. https://eng.uber.com/forecasting-introduction/


