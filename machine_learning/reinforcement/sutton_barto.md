
policy
reward
value function

reinforcement learning uses formal theory of markov decision process

trial-and-error
The most important feature distinguishing reinforcement learning from other types of learning is that
it uses training information that evaluates the actions taken rather than instructs by giving correct
actions

Evolutionary Genetic Algorithms change policy only after game.  They do not use value functions to aid search in space of policies.
Reinforcement (esp. value-function learning methods) change policy during game using value functions.

convergence of several fields
dynamical systems
optimal control solved using dynamic programming and value functions
discrete version of optimal control is called markov decision process
optimization theory
statistics
neurodynamic programming of Bertsekas
approximate dynamic programming of Powell

reinforcement learning uses neural networks to generalize and learn from past experience

use of parametrized approximators to address curse of dimensionality

model of env is present ?

explore-exploit dilemma

relation to game theory ? (Szita 2012)

MDP solutions
policy iteration method

Tabular solution methods:

state and action spaces are small enough for the approximate value functions to be represented as arrays, or tables.
in this case, it is possible to find optimal value function and optimal policy.
for larger problems, only approx methods and solutions are possible.

bandit problems : have single state

Solving finite Markov decision problems:
Dynamic programming methods are well developed mathematically, but require a complete and accurate model of the environment. 
Monte Carlo methods don’t require a model and are conceptually simple, but are not well suited for step-by-step incremental computation. 
temporal-difference methods require no model and are fully incremental, but are more complex to analyze.

MDPs are a mathematically idealized form of the reinforcement learning problem for which precise
theoretical statements can be made

discounting 

pole balancing

episodic tasks vs continuing tasks

A fundamental property of value functions used throughout reinforcement learning and dynamic pro-
gramming is that they satisfy recursive relationships similar to that which we have already established
for the return (3.9).

Bellman equation expresses a relationship between the value of a state and the values of its successor states.

The value function is the unique solution to its Bellman equation. We show in subsequent chapters how this Bellman equation forms the basis of a number of ways to compute, approximate, and learn value function .

backup diagram

Bellman optimality equation

model-based 
1. dynamic programming and heuristic search
2. rely on planning as their primary component, 

model-free 
1. Monte Carlo and temporal-difference methods. 
2. rely on learning

# Dynamic programming methods

DP solves the problem only when model is known
But Dynamic programming provides basis for understanding solution methods
DP ideas can also be applied to continuous spaces after quantizing.

The key idea of DP, and of reinforcement learning generally, is the use of value functions to organize
and structure the search for good policies.

DP algorithms are obtained by turning Bellman equations such as these into assignments, that is, into update rules for improving approximations of the desired value functions

Just as there are four primary value functions (v π , v ∗ , q π , and q ∗ ),
there are four corresponding Bellman equations and four corresponding expected update

policy evaluation(prediction): compute state-value function for arbitrary policy 

Iterative policy evaluation

## Policy iteration
two simultaneous, interacting processes, 
1. Policy evaluation : one making the value function consistent with the current policy 
2. Policy improvement : the other making the policy greedy with respect to the current value function 

## Value iteration
1. a single iteration of policy evaluation is performed in between each policy improvement

## Asynchronous Dynamic Programming 

select which states to update
1. evaluation and improvement processes are interleaved at an even finer grain.

## Generalized Policy Iteration 
1. allow policy evaluation and policy improvement interact finer level

Making the policy greedy with respect to the value function typically makes the value function incorrect for the
changed policy, and making the value function consistent with the policy typically causes that policy
no longer to be greedy. In the long run, however, these two processes interact to find a single joint
solution: the optimal value function and an optimal policy.

Bertsekas and Tsitsiklis (1989) Jacobi-style and Gauss-Seidel style

## Complexity

worst case time to find an optimal policy is polynomial in the number of states and actions. 
If n and k denote the number of states and actions, this means that a DP method takes a number of computational
operations that is less than some polynomial function of n and k.

Linear programming have better worst-case guarantee but they become impractical at much smaller number of states (by a factor of 100)

# monte carlo methods

does not assume complete knowledge of environment
but uses experience of environment

Monte Carlo methods solve based on averaging sample returns. 
To ensure that well-defined returns are available, define only for episodic tasks. 
That is, we assume experience is divided into episodes, and that all episodes eventually terminate no matter what actions are selected.
Value estimate and policy are changed only after episode ends

Monte Carlo : 
1. the estimates for each state are independent. 
2. not harmed by violation of Markov
3. learn value functions from sample returns with the MDP.

DP
1. estimate for one state builds upon the estimate of any other state
2. harmed by violation of Markov
3. computed value functions from knowledge of the MDP


computational expense of estimating the value of a single state is independent of the number of states.

If a model is not available, its useful to estimate action values (the values of state– action pairs) rather than state values. 
With a model, state values alone are sufficient to determine a policy

## Monte carlo control


## Monte carlo exploring starts

## On-policy Monte carlo 

On-policy methods attempt to evaluate or improve the policy that is used to make decisions
off-policy methods evaluate or improve a policy different from that used to generate the data

## Off policy learning

How to learn about the optimal policy while behaving according to an exploratory policy

use two policies, 
1. target policy : one that is learned about and that becomes the optimal policy, 
2. behaviour policy : one that is more exploratory and is used to generate behavior. 

Almost all off-policy methods utilize importance sampling, a general technique for estimating expected
values under one distribution given samples from another.

## Off-policy Monte carlo control

Importance sampling
1. Discounting-aware
2. weighted
3. per-reward


# Temporal difference learning

is combo of Monte carlo and DP

## Policy evaluation

Markov reward process : MDP without actions

## Policy iteration

## Sarsa on-policy TD control

## Q-learning (off-policy TD control)

## Double learning


## n-step algo

## TD(Lambda) algo


## RTDP 

Real-time dynamic programming, or RTDP, is an on-policy trajectory-sampling version of DP’s value-
iteration algorithm.
