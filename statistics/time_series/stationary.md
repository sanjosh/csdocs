
# definition

no trend, no seasonality

constant mean, variance and auto-correlation

a stationary time series will have no predictable patterns in the long-term. 

Time plots will show the series to be roughly horizontal (although some cyclic behaviour is possible), with constant variance.

if {y_t} is stationary, then for all s, distribution {y_t, ..., y_t+s} does not depend on t

if the cycle is aperiodic, series is stationary because timing of cycles is not predictable

https://otexts.com/fpp2/stationarity.html

# why stationary important for ARMA (not ARIMA)
 
https://stats.stackexchange.com/questions/19715/why-does-a-time-series-have-to-be-stationary

# how to check stationarity 

1. summary statistics
2. unit root tests

## summary statistics

partition time series, compute mean and variance of each partition, and check if difference is statistically significant

look at histogram

https://machinelearningmastery.com/time-series-data-stationary-python/

## Kwiatkowski-Phillips-Schmidt-Shin (KPSS) test

## Dickey-Fuller test for Time Series Stationarity using Python

bhavesh bhatt

if ADF statistic < critical value(5 perc), then reject null hypothesis and say time series is stationary

run linear regression of "difference of consecutive" wrt original time series
the t-statistic of this is the ADF

statsmodels.adfuller(X)

https://www.youtube.com/watch?v=warCSvy1DMk

## Trend and Seasonality from scratch

1. fit a second degree polynomial to find trend
2. detrended = subtract trend from time series 
3. seasonal = group detrended by month and get mean

https://github.com/bhattbhavesh91/time-series-decomposition-from-scratch/blob/master/time-series-decomposition-from-scratch.ipynb

https://www.youtube.com/watch?v=6iVJPG9RQXQ

# convert non-stationary to stationary

1. first difference
1. second difference
1. take log or square root to remove non-constant variance
1. seasonal difference : y1(t) = y(t) - y(t-m)


# multivariate

## Johansen’s test for multivariate time series.

