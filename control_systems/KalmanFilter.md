
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

