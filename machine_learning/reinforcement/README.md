
# summary

modeling : needs observation space, action, reward

treat env as black box - dont need to know semantics of observation returned by env

markov decision process assumption : only current state needed to take action

if markov assumption broken (e.g. video frames required to know speed), then concat past states

explore/exploit : use epsilon in Q-learning, add noise to weights in case of Policy Neural network, entropy bonus 

which action in the sequence got this reward ?  several schemes to decide reward measures and how many in the past to utilize

NN needs IID data for SGD : thats why target network and replay buffer introduced

in ML, update weights based on loss.  in policy RL, update weights based on reward

Unroll Bellman equation for multiple steps : doesn't help beyond a point - causes instability

RL complexity : number of states, speed of response (for gaming), length of episodes

actor critic : combine value and policy 

bellman equation : not just reward but consider value of the state you are going into (recursive formulation)

Training stability

Use of parallel environments

Sample efficiency

