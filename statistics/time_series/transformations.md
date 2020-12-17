
# Forecasting  : principles and practice

## transformations and adjustments

* calendar adjustment
* population adjustment
* inflation adjustment
* mathematical transformations (log. power, box-cox 

## residuals

* must be uncorrelated, otherwise they indicate info left out of model
* must have zero mean

also good to have
* constant variance
* normally distributed

## forecast errors

* scale-dependent errors
* percentage errors
* scaled errors

## prediction interval (like confidence interval)

point forecast is useless without prediction interval

interval within which we expect y(t) to lie with a specified probability.

## how to select predictors

not recommended
1. scatterplot forecast variable against predictor 
2. do multiple linear regression with all predictors and drop those with big p-value.  statistical significance does not indicate predictive value.

need measure of predictive accuracy
1. adjusted R^2 and pick model with highest value
2. CV cross-validation on training data
3. AIC (akaike) and pick model with min AIC
4. BIC and pick model with min BIC


## decomposition methods

* X11
* SEATS
* STL

## hierarchical time series





https://otexts.com/fpp2/transformations.html

