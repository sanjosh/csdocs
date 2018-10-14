
# Bayesian Product size recommendation (sembium)

True product size = s_j
True customer size = t_i

Given purchase history and return history of "i, j, fit/large/small"
1. s_i - t_j > b1 - its small
2. b1 < s_i - t_j < b2 - its fit
3. s_i - t_j < b2 - its large

Find s_i and t_j

Problems
1. cold start
2. sparse data => use bayesian
3. noisy data => use bayesian
4. dedup (multiple persona)

Use Bayesian PSIMS to get distribution for s_i & t_j instead of point estimate

estimate posterior distribution of latent size (s_i & t_j) variables

Steps
1. generative process  : generate priors s_i & t_j 
2. variational inference : find latent variables

Approx Inference : Alternative to Variational inference is Gibbs sampling

## Reference
1. Sembium Tekumalla et al.  Recommending Product Sizes to Customers. RecSys 17
2. Sembium Tekumalla et al.  Bayesian models for product size recommendation WWW 2018

# Decomposing Fit Semantics in Product Size recommendation (Misra)

TODO

## Reference
1. Misra et al. Decomposing Fit Semantics for Product Size Recommendation
in Metric Spaces.  RecSys 18

# Size Recommendation System for fashion (Abdulla)

TODO

## Reference
1. G Mohammed Abdulla and Sumit Borar. 2017. Size Recommendation System for
Fashion E-commerce. KDD Workshop on Machine Learning Meets Fashion (2017)


