
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

Arima is biased towards recent; Theta towards long-term

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

# ensemble

1. preprocessing : fill missing values interpolation zeileis.  handle heteroscedascity with box-cox
2. ensemble of arima, STL, theta, ETS, TBATS, neural net, random walk, seasonal naive, mean, linear regression with seasonal components
3. prefer models which detect long-term trend : use change point detection of verbesselt and then drop models like ARIMA which have short-term memory and overfit on recent changes
4. combine forecasts of individual models using Inverse mean square forecast error 

theta assimakopoulus and nikolopoulos does not handle seasonal

time series data may not fit in memory

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

# TODO neurips 2020

https://github.com/AIStream-Peelout/flow-forecast

https://towardsdatascience.com/breakthroughs-in-time-series-forecasting-at-neurips-2020-1dc1b9b6d99d

Spectral Temporal Graph Neural Network for Multivariate Time-series Forecasting
 using Graph Neural Networks to model the interactions between multivariate time series. Spectral Temporal Graph Neural Network (STGNN)

# TODO

1. Makridakis M3 competition 
2. Clemen.  Combining forecasts
2. Hyndman Khandakar Automatic time series forecasting
2. Granger, Joyeux.   Long memory time series models and fractional differencing
2. Menezes, Bunn.  use of combined forecasts
2. Zeileis Grothendieck.  zoo S3 infrastructure for regular and irregular time series
2. Grupe Cleveland calendar effects
2. Provost, Kolluri.  Scaling up inductive algorithms
2. Atiya Amir, Robert.  Combination of long term and short term forecasts
2. Verbesselt.  Detecting trend and seasonal changes

# References

1. https://eng.uber.com/forecasting-introduction/


