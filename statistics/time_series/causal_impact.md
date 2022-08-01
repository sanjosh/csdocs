
# Causal Impact

How to measure impact of market intervention (new product launch)

three sources of information available for constructing an adequate synthetic control.
1. time-series behaviour of the response itself, prior to the intervention
2. behaviour of other time series that were predictive of the target series prior to the intervention
3. available prior knowledge about the model parameters, as elicited, for example, by previous studies

combine the three preceding sources of information using a state-space time-series model, where one component of state is a linear regression on the contemporaneous predictors

regression component which allows constructing a synthetic control based on a combination of markets that were not treated

Subtracting the predicted from the observed response during the post-intervention period gives a semiparametric Bayesian posterior distribution for the causal effect

https://github.com/google/CausalImpact

# air shipping amazon

https://www.amazon.science/publications/aspire-air-shipping-recommendation-for-e-commerce-products-via-causal-inference-framework

# lib

https://github.com/py-why/dowhy

https://pypi.org/project/pycausalimpact/
