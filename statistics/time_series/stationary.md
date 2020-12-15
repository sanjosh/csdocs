
# how to check stationarity

mean is zero, std deviation is zero and seasonality is constant

1. do global vs local tests
2. augmented dickey-fuller test (ADF)

## Dickey-Fuller test for Time Series Stationarity using Python

bhavesh bhatt

if ADF statistic < critical value(5 perc), then reject null hypothesis and say time series is stationary

run linear regression of "difference of consecutive" wrt original time series
the t-statistic of this is the ADF

statsmodels.adfuller(X)

https://www.youtube.com/watch?v=warCSvy1DMk

## Johansen’s test for multivariate time series.

## Trend and Seasonality from scratch

1. fit a second degree polynomial to find trend
2. detrended = subtract trend from time series 
3. seasonal = group detrended by month and get mean

https://github.com/bhattbhavesh91/time-series-decomposition-from-scratch/blob/master/time-series-decomposition-from-scratch.ipynb

https://www.youtube.com/watch?v=6iVJPG9RQXQ
