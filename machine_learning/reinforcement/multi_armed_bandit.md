

# Multi-armed bandit

simplified version of MDP (markov decision process) without state

K = number of arms 

Bandit algo called optimal if it has regret = O(log T) where T = number of rounds to play

# Algorithms

1. greedy : linear regret
2. random  : linear regret
3. UCB upper confidence bound : add confidence bonus to estimated mean

## epsilon-greedy

## UCB algo

take account of each action's potential to be optimal

selected less would be more optimal

# Contextual bandit

use some context. this is intermediate between multi-armed bandit and full RL

# Applications

## A/B testing

## Online shortest path

Daniel J. Russo, A Tutorial on Thompson Sampling
https://arxiv.org/pdf/1707.02038.pdf

correlated travel times


## Recommendation

solve cold-start with MixNeigh

Caron Bhagat, Mixing bandits: a recipe for improved cold-start recommendations in a social network
https://dl.acm.org/doi/abs/10.1145/2501025.2501029?download=true

## Learning to rank (top K)

Cascading bandits 

Branislav Kveton, Csaba Szepesvari, Zheng Wen, Azin Ashkan
Cascading Bandits: Learning to Rank in the Cascade Model
https://arxiv.org/abs/1502.02763

# Ref

https://lilianweng.github.io/lil-log/2018/01/23/the-multi-armed-bandit-problem-and-its-solutions.html

https://en.wikipedia.org/wiki/Multi-armed_bandit
