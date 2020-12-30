
# Optimal learning (black box optimization)

how to iterate through combinations efficiently to find global optima

other alternatives
1. grid search
2. random search
3. gradient descent (but require func is differentiable)
4. convex methods (but they assume underlying space is convex)
5. genetic algorithms  (but is exhaustive)


multi-armed bandit; 
1. find best slot machine 
1. maximize total rewards
1. unknown payout rate

example of advertising (click through rate)
1. find best advertiser
1. maximize clicks
1. where each click is success

exploration vs exploitation dilemma

Regret = best policy - current

amount of exploration increases with data

## policies
1. weighted random choice
1. epsilon-greedy
1. UCB
1. etc

## real world constraints

1. parallel sampling
1. arms expire (advertisement events no longer current)
1. payoff are noisy and non-binary
1. hardware constraints limit knowledge; batching
1. continuous - number of arms increase or become continuous

find best param to maximilize CTR = func(param) while sampling func as few times as possible.

derivative-free global optimization algorithm to evaluate black box

why heuristics dont work
1. there are dependent parameters
2. non-linear behaviour
3. thousands of combinations to iterate

## MOE (metric opt engine)

1. build gaussian process with points sampled
2. optimize covariance hyperparameters of GP
3. find points of highest expected improvement 
4. return optimal next point to sample

finding the Gaussian process model that best fits

1. max likelihood
2. cross validation
3. priors

overfit vs underfit : have to tune hyperparam of gaussian process

## acquisition function

Use the maximal location of the acquisition function to figure out where to sample next in the hyperparameter space. 
Acquisition functions play with the trade-off of exploiting a known maxima and exploring uncertain locations in the hyperparameter space. 
Different acquisition functions take different approaches to defining exploration and exploitation.

apply acquisition function (find point with highest expected improvement)

optimization criteria
1. expected improvement : points with high mean and reasonably high variance has to be sampled
2. knowledge gradient

intelligent sampling : no point in sampling a point which we already know is good

# reference

https://github.com/Yelp/MOE

Metric Optimization Engine (MOE); an open source, black box, Bayesian Global Optimization engine for optimal experimental design.
https://www.youtube.com/watch?v=CC6qvzWp9_A

Using Bayesian Optimization to Tune Machine Learning Models - MLconf SF 2016
https://www.youtube.com/watch?v=J6UcAdH54RE

https://optimallearning.princeton.edu

https://mlconf.com/blog/lets-talk-bayesian-optimization/

https://sigopt.com/blog/expected-improvement-vs-knowledge-gradient/

1. E. Brochu, V.M. Cora, N. de Freitas. A tutorial on Bayesian optimization of expensive cost functions, with application to active user modeling and hierarchical reinforcement learning. CoRR, abs/1012.2599, 2010.
2. P. Frazier. Bayesian Optimization. Recent Advances in Optimization and Modeling of Contemporary Problems, October 2018.
3. M. W. Hoffman, B. Shahriari. Modular mechanisms for bayesian optimization. In NIPS Workshop on Bayesian Optimization, 2014.
4. Y. Kim. Convolutional Neural Networks for Sentence Classification. In Proceedings of ACL 2014. June 2014.
5. I. Dewancker, M. McCourt, S.Clark, P. Hayes, A. Johnson, G. Ke. A Stratified Analysis of Bayesian Optimization Methods. arXiv:1612.04451. December 2016.
6. B. Shahriari, K. Swersky, Z. Wang, R. P. Adams, and N. de Freitas. Taking the human out of the loop: A review of Bayesian optimization. Proceedings of the IEEE, 104(1):148–175, Jan 2016.
