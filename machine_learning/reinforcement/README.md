
# summary

RL model : 
1. needs observation space, action, reward
1. action space can be discrete or continuous
2. state can be discrete or continuous

treat env as black box - dont need to know semantics of observation returned by env

markov decision process assumption : 
1. only current state needed to take action
2. if markov assumption broken (e.g. video frames required to know speed), then concat past states

explore/exploit : 
1. use epsilon in Q-learning (vary like learning rate in NN)
2. add noise to weights in case of Policy Neural network, 
3. entropy bonus to penalize NN in case it emits that only one action is possible (probability vector)

how to decide which action in the sequence was responsible for the currently obtained reward ?  several schemes to decide reward measures and how many in the past to utilize

NN needs IID data for SGD : 
1. use of target network 
2. use of replay buffer 
3. Use of parallel environments

in ML, we update weights based on loss.  in policy RL, we update weights based on reward

Can we unroll Bellman equation for multiple steps : doesn't help beyond a point - causes instability

RL complexity : number of states, speed of response (for gaming), length of episodes

actor critic : combine value and policy 

bellman equation : not just reward but consider value of the state you are going into (recursive formulation)

Training stability

Sample efficiency

Multi-agent RL : can be collaborative or competitive

RL for combinatorial optimization 
1. no reward signal
2. need to reach most optimal solution rather than any solution
3. use of Monte Carlo tree search.

Other black box methods:
1. genetic algo
2. evolutionary algo

