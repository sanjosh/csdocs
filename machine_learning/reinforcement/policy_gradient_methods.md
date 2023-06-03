
# policy gradient

## Q-learning disadvantages

Deep Q-learning does not work large or continuous action spaces because it does Argmax over Q of all possible action

exploration is handled by adjusting probabilities

it suffers from perceptual aliasing : thinks two different states are the same in Q-table

## why policy gradient

estimate policy directly without value table

No explicit exploration (epsilon) needed; choose random weighted actions

it returns a matrix of probabilities for each action via softmax

Converges faster than Q-learning but needs more episodes

Need large replay buffer to avoid correlations

No target network needed (only one network)

## measuring quality of policy

in episodic, use average total return per episode

in continuous, use average reward per step

## Reinforce

(Simple Statistical Gradient-Following Algorithms for Connectionist Reinforcement Learning RONALD J. WILLIAMS)


## PPO

clipped loss


# References

https://www.youtube.com/watch?v=0c3r5EWeBvo&list=PLWzQK00nc192L7UMJyTmLXaHa3KcO0wBT&index=8

https://huggingface.co/learn/deep-rl-course/unit4/advantages-disadvantages?fw=pt

DeepMind x UCL RL Lecture Series - Policy-Gradient and Actor-Critic methods [9/13]
https://www.youtube.com/watch?v=y3oqOjHilio


