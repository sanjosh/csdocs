
# which action led to the reward ?

```

The idea of Bias-variance tradeoff appears when we compare Monte Carlo with TD learning. 
Remember that when we talk about bias and variance for these two methods, we are 
talking about the bias and variance of their target values.

Matthew Lai from DeepMind explained this with the concept of eligibility traces: 
given a reward, find which actions led to this reward. 

Unfortunately, it is often impossible to precisely determine the cause of our death. 
Thus, we use a simple heuristic: we believe that actions close to the reward 
(in timestep) are more likely causes of reward.

The Monte Carlo model uses the full trace: we look at all actions taken before the reward. 
Because we consider all actions, there will be a lot of noise. 
If we consider what actions the agent took in its entire lifetime, we will definitely find patterns, 
but most patterns will be coincidences, not actual patterns that can be generalized to future episodes. 
In other words, the Monte Carlo will overfit the episode.

On the other end, with the Temporal Difference model, the agent only looks at the 
action immediate before its death. In this case,the agent will most likely fail to find 
any pattern or generalization, since most actions have delayed rewards, so the last 
action was not the cause of its death. Therefore, the Temporal Difference model will underfit the episode.

Hence, middle ground...

We don’t want to only consider the last action, but we also don’t want to consider all actions made. so we consider 
n steps. This is called n-step bootstrapping.
```

https://www.endtoend.ai/blog/bias-variance-tradeoff-in-reinforcement-learning/
