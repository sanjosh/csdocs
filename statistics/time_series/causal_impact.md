
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

# misc

counterfactual

imputation

data generation process


# Inferring the effect of an event using CausalImpact by Kay Brodersen

https://www.youtube.com/watch?v=GTgZfCltMm8

what is the effect of product launch

use other time series which are correlated by outcome of interest but not affected by product launch (e.g. web searches of competitors or weather or economy)

synthetic control estimators : train model in pre-period; apply inference in post-period

uses bayesian structural time series as base model

## How to prevent or detect Spurious correlations

Back-test the method in the past

## Application - ROI analysis

## how many predictive time series do you need 

5 to 20 empirically 

## can it analyse multiple events that overlap in time

## statistical power - confidence intervals


# Bayesian structural time series


# Microsoft library dowhy

https://github.com/py-why/dowhy





