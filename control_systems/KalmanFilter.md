
Kalman is Optimal estimator = minimize MSE if noise is Gaussian

if noise not Gaussian, then Kalman is linear

state variables X(k) have mean and variance

capture correlation between input/state variables using covariance matrix

```
F(k) = prediction matrix to update next state based on current
     = depends on system being modeled
X(k)  = F(k) * X(k-1)

Cov(x) = E
Cov(Ax) = A.E.A_tranpose

Therefore
Cov(X(k)) = E(k) = Cov(F(k) * E(k-1)) = F(k).E(k-1).F(k)_tranpose

E(k) = F(k).E(k-1).F(k)_transpose
```

##  to merge

https://github.com/rlabbe/Kalman-and-Bayesian-Filters-in-Python

ind a estimate between prediction & measurement

update the gain as well since it signifies change in 2 (noisy) measurement 

https://en.wikipedia.org/wiki/Alpha_beta_filter(g_h filter)

Least Squares filter, 

Benedict-Bordner filter

1. Multiple data points are more accurate than one data point, so throw nothing away no matter how inaccurate it is.
2. Always choose a number part way between two data points to create a more accurate estimate.
3. Predict the next measurement and rate of change based on the current estimate and how much we think it will change.
4. The new estimate is then chosen as part way between the prediction and next measurement scaled by how accurate each is.

