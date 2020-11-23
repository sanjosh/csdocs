
# Phoebe : defining caching tiers

## three factors in caching

The data allocation policy basically controls the data flow and 
determines admissions of various data, such as read-only, write-only, or both; 

the high accuracy of data hotness recognition can prevent cache pollution
from unnecessary data, improving cache performance via locality protection; 

the data eviction policy decides which data block to evict when the 
cache is full, thus indirectly increasing the effective cache capacity.

## past

For a given data access trace, the reuse distance of a data
block is defined as the number of accesses between the cur-
rent access and the consecutive next access to the same data
block, measuring the data access locality

belady optimal algorithm (1966) : evict block with longest reuse distance

# this paper

stay priority : represent the relative importance of each data block.
stay priority has time-lagging property 

Nine features to extract reuse information

uses deep deterministic policy gradient (DDPG) + actor critic

the agent attempts to learn an optimal policy of assigning stay priorities 
to data blocks such that the overall hit rate is maximized;

Given the state, assign a stay priority value which becomes the action 

Environment decides if block is to be evicted based on assigned stay priority

The cache hit or miss in the next time step is regarded as the immediate reward

The state encodes the locality information from a past fixed-length sequence of accesses 

# intelligent prefetching work

perceptron Wang and Luo 2017 Data Cache Prefetching with Perceptron Learning

perceptron Bhatia 2019 Perceptron-based prefetch filtering.

the contextual bandits model in RL 
Peled, L.; Mannor, S.; Weiser, U.; and Etsion, Y. 2015. Semantic locality and context-based prefetching using reinforcement learning.

regression problem (Zeng and Guo 2017) Long short term memory based hardware prefetcher: A case study. 

classification problem (Hashemi 2018) Learning Memory Access Patterns.

Markov decision process (MDP) with side information (Somuyiwa, György, and Gündüz 2018),
A reinforcement-learning approach to proactive caching in wireless networks

multi-armed bandit (Blasco and Gündüz 2014; Chang et al. 2018)   
Blasco Learning-based optimization of cache content in a small cell base station.   
Chang Learn to cache: Machine learning for network edge caching in the big data era  

Q-learning (Sadeghi, Wang, and Giannakis 2019; Sadeghi et al. 2020).  
Reinforcement Learning for Caching with Space-Time Popularity Dynamics  
Deep reinforcement learning for adaptive caching in hierarchical content delivery networks  

# applying machine learning for system optimizations

## Song et al. 2020 Learning Relaxed Belady for Content Distribution Network Caching

## Dean 2017 Machine Learning for Systems and Systems for Machine Learning.

## Lecuyer Harvesting Randomness to Optimize Distributed Systems

develop a non-invasive methodology for harvesting this randomness to enable efficient offpolicy evaluation

many system decisions can be cast as contextual bandits


## Spiral : self-tuning 

reactive cache use-case

system provides the result of the query and a subscription to that result. 
Whenever an external event affects the query, it automatically sends the updated result to the client.
this relieves the client of the burden of polling, and reduces load on the web front-end service that computes query results.

Along with the original result, the cache receives a list of objects and associations 
that were touched while computing the result. It then begins monitoring a stream of 
database updates to any objects or associations the query accessed.

there is an enormous volume of database updates, but only a tiny fraction of them affect the output the query.

After reexecuting a query, it is easy to determine whether the observed updates 
were spam or ham by simply comparing the new query result with the old query result. 
This mechanism was used to provide feedback to Spiral, allowing it to create a classifier for updates.

Spiral collects this feedback from all reactive cache servers and uses it to train 
a classifier for every distinct query type. These classifiers are periodically 
pushed to the cache servers.

The data sent to the server is sampled with a counter-bias to avoid percolating 
class imbalance biases in the samples. For example, if over a period of time we 
receive 1,000 times more negative examples than positive ones, we need only log 
1 in 1,000 negative examples to the server, while also indicating that it has a weight of 1,000. 


Bychkovsky et al. 2018;     Spiral: Self-tuning services via real-time machine learning.
https://engineering.fb.com/2018/06/28/data-infrastructure/spiral-self-tuning-services-via-real-time-machine-learning/
