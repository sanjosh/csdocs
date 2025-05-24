
## AIC and BIC
AIC and BIC find model which explains the data well with as few parameters as necessary


## MLE Extensions & Comparisons
What’s the difference between MLE and MAP (Maximum A Posteriori)?
```
MAP incorporates prior
```

How does MLE compare to Bayesian estimation?
```
Bayesian estimates full posterior distribution

MLE is a special case of Bayesian estimation with a uniform (flat) prior (or ignoring the prior).

The MAP estimate is the mode of the posterior.

Bayesian estimation gives you more than just a point estimate — it provides uncertainty and full probabilistic modeling.
```

When does MLE fail or become biased?

Can MLE be used with censored or missing data?

How does regularization relate to MLE?

## Model Selection & Evaluation
What are AIC and BIC, and how do they relate to MLE?

How do I choose between two models using MLE?

What is overfitting, and how does MLE relate to it?

How do likelihood ratio tests work?

## Distribution-Specific MLEs
Can you derive MLEs for other distributions like Exponential, Bernoulli, or Beta?

How do you estimate parameters in a multinomial or categorical distribution using MLE?

## Practical & Computational
How do I implement MLE in Python or R for my dataset?

What’s the role of optimization algorithms in computing MLEs?

What happens if the likelihood has multiple maxima (non-convex)?

How do I estimate MLE numerically for complex likelihoods?

## Applications in Machine Learning
How is MLE used in logistic regression or linear regression?

How does MLE connect to loss functions in machine learning?
```
Optimization in machine learning usually involves minimizing a loss function.
Instead of maximizing likelihood, we minimize the negative log-likelihood (NLL)
Loss functions in many ML models are just the negative log-likelihoods from probabilistic models, making MLE the statistical foundation of these optimization objectives.


```

What role does MLE play in neural networks and deep learning?
