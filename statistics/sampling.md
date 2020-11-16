
# Importance sampling

Importance sampling is a technique to estimate properties of a particular distribution, by samples
from a different distribution, to lower the variance of the estimation, or when sampling from the
distribution of interest is difficult.

(Li, Deep reinforcement learning)

# thompson sampling / probability matching / posterior sampling 

How to choose between k choices, each with success probability Theta_k which is initially unknown.

* first proposed in 1933; now widely applied
* revived in (Chapelle and Li, 2011; Scott, 2010).
* goal is to intelligently balance explore and exploit in 2-armed bandit problems (clinical trials)

Dithering : randomly perturb action selected by greedy algo (e.g. epsilon-greedy exploration)

Thompson sampling does better at Dithering than epsilon-greedy

Thompson chooses estimate which "represents a statistically plausible success probability rather than a statistically plausible observation"

It draws a random sample from distribution rather than picking Expectation E

when dealing with problems that are not amenable to efficient Bayesian inference  
four approaches to approximate posterior sampling: 
1. Gibbs sampling, 
2. Langevin Monte Carlo, 
2. sampling from a Laplace approximation, and 
3.  the bootstrap. Such methods are called for


(Russo, A Tutorial on Thompson Sampling)
https://arxiv.org/pdf/1707.02038.pdf

https://github.com/sanjosh/ts_tutorial

## tutorial


NYC tutorial Lydia Gu
https://www.youtube.com/watch?v=aWKeSvnTalE

# Stratified sampling

