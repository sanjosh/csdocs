
# conformal prediction

## adaptive conformal


# bayesian

# gaussian

# quantile regression

(chatgpt)

In quantile regression, you train models to estimate conditional quantiles:


```
import lightgbm as lgb

# Train lower quantile (e.g., 10th percentile)
model_lower = lgb.LGBMRegressor(objective='quantile', alpha=0.1)
model_lower.fit(X_train, y_train)

# Train upper quantile (e.g., 90th percentile)
model_upper = lgb.LGBMRegressor(objective='quantile', alpha=0.9)
model_upper.fit(X_train, y_train)

# Predict for a new point (e.g., with feature "hour" = 8 AM)
x_new = X_new  # e.g., input features including hour
lower = model_lower.predict(x_new)
upper = model_upper.predict(x_new)

```

This gives you an interval [lower, upper] that reflects the feature-conditioned distribution of the target — exactly like what adaptive conformal prediction aims for.



# residual model

(chatgpt)

building a separate model to predict residuals is a powerful way to capture heteroscedasticity and create adaptive conformal prediction intervals.

We want to predict the expected magnitude of error (or the residual) of the main model using the same input features. This allows us to scale the conformal quantile for different situations (e.g., high uncertainty in the morning).

## train base model

```
from xgboost import XGBRegressor

base_model = XGBRegressor()
base_model.fit(X_train, y_train)

y_cal_pred = base_model.predict(X_cal)
residuals = np.abs(y_cal - y_cal_pred)

```

## train residual model

This model learns patterns in the residuals, which may depend on input features like time of day, seasonality, etc.



```
error_model = XGBRegressor()
error_model.fit(X_cal, residuals)

```

## Scale Errors and Compute Normalized Quantile

We’ll normalize the calibration residuals by their predicted error estimates from the residual model. 

This gives us a scaled set of errors:


```
predicted_errors_cal = error_model.predict(X_cal)
normalized_residuals = residuals / predicted_errors_cal

# Compute quantile of the normalized residuals
alpha = 0.1
q = np.quantile(normalized_residuals, 1 - alpha)

```

## predict with adaptive intervals

```
X_new = ...  # new data point(s)
y_pred = base_model.predict(X_new)
pred_error = error_model.predict(X_new)

interval = q * pred_error

lower = y_pred - interval
upper = y_pred + interval

```

This method adaptively scales the prediction interval based on the expected uncertainty at each input. If the error model predicts higher variance (e.g., in the morning), the interval will expand accordingly.



# bootstrapping

y = B0 + B1.x + e

we want to estimate confidence interval on regression coefficient B1

(chatgpt)

```
import numpy as np
from sklearn.linear_model import LinearRegression

# Simulated data
np.random.seed(42)
x = np.random.uniform(0, 10, 100)
y = 3 * x + 5 + np.random.normal(0, 2, 100)
x = x.reshape(-1, 1)

# Step 1: Fit the original model
model = LinearRegression().fit(x, y)
y_pred = model.predict(x)
residuals = y - y_pred

# Step 2-6: Residual bootstrapping
boot_slopes = []
n_boot = 1000
for _ in range(n_boot):
    resampled_residuals = np.random.choice(residuals, size=len(residuals), replace=True)
    y_boot = y_pred + resampled_residuals
    boot_model = LinearRegression().fit(x, y_boot)
    boot_slopes.append(boot_model.coef_[0])

# Step 7: Confidence interval from percentiles
lower = np.percentile(boot_slopes, 2.5)
upper = np.percentile(boot_slopes, 97.5)

print(f"Bootstrapped 95% CI for slope: ({lower:.3f}, {upper:.3f})")
```
