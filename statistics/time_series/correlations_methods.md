


### 1. Vector Autoregression (VAR): The Structural Approach

A VAR model builds an equation for every variable based on the lagged history of *all* variables in the system.

define a system where today's Demand ($D_t$) is predicted by yesterday's Demand ($D_{t-1}$), yesterday's Supply ($S_{t-1}$), and yesterday's Price ($P_{t-1}$). 

At the exact same time, today's Supply ($S_t$) is predicted by that exact same shared history.

VAR models explicitly calculate the **Covariance Matrix** of these residuals. 

apply a Cholesky decomposition to this residual matrix to generate correlated shock scenarios for future forecasting.

### 2. Copulas: The "Super Glue" for Complex Dependencies

If you are using machine learning models (like XGBoost or ARIMA) to forecast Demand and Supply independently, but you want to bind their probabilities together, you use **Copulas**.

1. You build the best possible XGBoost model just for Demand.
2. You build the best possible XGBoost model just for Supply.
3. You use a Copula function to act as "mathematical super glue." It binds the probability distributions of their outputs together.
 
Cholesky matrix assumes linear, uniform correlation. Copulas can model **tail dependence**. 

In a market, Demand and Supply might not be highly correlated on normal days, but during an extreme shock (a "tail event" like a city-wide blackout), their correlation goes to 1.0. 

Copulas capture these non-linear, extreme-event correlations perfectly.

### 3. Dynamic Conditional Correlation (DCC-GARCH)

In real markets, correlation is not a static number. The correlation between a downtown area and a suburb, or between riders and drivers, changes depending on the time of day or the volatility of the market.

DCC models (often paired with GARCH, which models volatility clustering) treat the correlation matrix itself as a time series. The correlation coefficient is allowed to dynamically evolve step-by-step based on recent shocks.

If a sudden political protest shuts down a major highway, a static model will fail to recognize that the correlation between Supply in Region A and Region B just fundamentally changed. 

A DCC model will immediately adapt, updating the correlation matrix for the next time step to reflect the newly entangled volatility.

