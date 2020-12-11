
# Regression 

Both are linear models
1. Linear  : outcome/dependent variable is numeric 
2. Logistic : dependent variable is categorical

https://www.quora.com/Whats-the-relationship-between-linear-and-logistic-regression-What-are-the-similarities-and-differences

Probability between [0, 1]
Odds = p/1-p = [0, +inf]
Log(odds) = Logit = to compress the range of odds

Logit func is referred to as link function which converts categorical dependent variable into continuous criterion

https://blog.clevertap.com/a-primer-on-logistic-regression-part-i/

Logistic can be 
1. binomial 
2. multinomial
3. ordinal

https://en.wikipedia.org/wiki/Logistic_regression

# Seven types of regression

https://www.analyticsvidhya.com/blog/2015/08/comprehensive-guide-regression/

# linear

## Lasso regression (regularization)

l1_penalty = sum j=0 to p abs(beta_j)

problem with linear regression is that estimated coefficients of the model can become large, making the model sensitive to inputs and possibly unstable. This is particularly true for problems with few observations (samples) or more samples (n) than input predictors (p) or variables (so-called p >> n problems).

change the loss function to include additional costs for a model that has large coefficients.

lasso_loss = loss + (lambda * l1_penalty)


https://machinelearningmastery.com/lasso-regression-with-python/

## Ridge/Tikhonov (regularization)

l2_penalty = sum j=0 to p beta_j^2

ridge_loss = loss + (lambda * l2_penalty)


# Logistic


https://machinelearningmastery.com/ridge-regression-with-python/
