

# Multi-armed bandit

simplified version of MDP (markov decision process) without state

K = number of arms 

Bandit algo called optimal if it has regret = O(log T) where T = number of rounds to play

## Algorithms

1. greedy : linear regret
2. random  : linear regret
3. UCB upper confidence bound : add confidence bonus to estimated mean

## epsilon-greedy

## UCB algo

take account of each action's potential to be optimal

selected less would be more optimal

## Contextual bandit

use some context. this is intermediate between multi-armed bandit and full RL

# Bandit algorithms for website optimization book

## softmax algo

choose arms based of past reward rate of each arm

add exponential rescaling to allow negative rewards
(This naive exponential rescaling has the virtue of not behaving strangely if
you someone used negative numbers as rates of success, since the call to exp will turn
any negative numbers into positive numbers and insure that the negative numbers in
the denominator of these fractions can’t cancel out any positive numbers that may be
found in the denominator)

add temperature parameter to shift between fully deterministic and fully random
(the full Softmax algorithm is closely related to a concept called the Boltzmann distribution in physics, which is used
to describe how groups of particles behave.)

## Annealing softmax algo

softmax but explore less over time

(annealing is a process in which the blacksmith slowly decreases the temperature 
at which he works with molten melt so that it becomes more solid and less flexible)

## UCB algo

previous algorithms under-explore options whose initial experiences were not rewarding, even though they don’t have enough data to be confident about those arms

motive : gather more data before stopping exploration

1. UCB doesn’t use randomness at all. Unlike epsilon-Greedy or Softmax, it’s possible
to know exactly how UCB will behave in any given situation. This can make it easier
to reason about at times.
2. UCB doesn’t have any free parameters that you need to configure before you can
deploy it. This is a major improvement if you’re interested in running it in the wild,
because it means that you can start to use UCB without having a clear sense of what
you expect the world to behave like.


# Bandit problems (from Sutton Barto)

Bandit problems : reinforcement learning problem in which there is only a single state (i.e. non-associative)

suppose the bandit task were nonstationary, that is, the true values of the actions changed over time. In this case exploration is needed even in the deterministic case to make sure one of the nongreedy actions has not changed to become better than the greedy one

Non-stationary problems :  If reward probabilities change over time, then give more weight to recent rewards than to long-past rewards.  One of the most popular ways of doing this is to use a constant step-size parameter.  But convergence conditions need to be met by whatever update method is used.

Initial action values : Supply prior knowledge.  

UCB Upper confidence bound action selection method : actions with lower value estimates, or that have already been selected frequently, will be selected with decreasing frequency over time.

Contextual bandit : Associative search task : so called because it involves both trial-and-error learning to search for the best actions, and association of these actions with the situations in which they are best. Associative search tasks are often now called contextual bandits in the literature

One well-studied approach to balancing exploration and exploitation in k-armed bandit problems is to compute a special kind of action value called a Gittins index.   The Gittins-index approach is an instance of Bayesian methods

# Applications

## A/B testing

## Online shortest path

Daniel J. Russo, A Tutorial on Thompson Sampling
https://arxiv.org/pdf/1707.02038.pdf

correlated travel times

## Artwork personalization netflix contextual bandit

https://netflixtechblog.com/artwork-personalization-c589f074ad76

context is represented as feature vector provided as input to the model. 

* the titles they’ve played, 
* the genre of the titles, 
* interactions of the member with the specific title, 
* their country, 
* their language preferences, 
* the device that the member is using, 
* the time of day and the day of week. 

evaluate before deployment using offline algo called "replay" 
https://dl.acm.org/doi/10.1145/1935826.1935878

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

Multi-Armed Bandits: A Cartoon Introduction - DCBA #1
https://www.youtube.com/watch?v=bkw6hWvh_3k

# Todo

Aleksandrs Slivkins
https://arxiv.org/pdf/1904.07272.pdf

