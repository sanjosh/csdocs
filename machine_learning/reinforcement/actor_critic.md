
# actor critic - 2

Actor = Decides policy ; Critic = outputs the value of the state

```
The actor network receives observation (state) as the input and outputs a list of probabilities, with one probability per action. These probabilities form a distribution, and the action can then be chosen by sampling from this distribution.


To represent the state value function, the critic network also receives the state as the input and outputs a single number representing the estimated state value of that state.
```

https://www.endtoend.ai/tutorial/s4tf-ppo/

# Actor critic - 1

two outputs - policy head (actor) and value head (critic)

entropy bonus

## asynchronous actor-critic (A3C)

policy gradients are online method, so we must use training data obtained using current policy

To keep data IID, we need large buffer

Solution : Run many env in parallel to obtain large training data

## continuous action space actor-critic

1. policy head will output mean and std deviation
2. policy loss is neg log probability of a normal distribution
3. entropy bonus uses normal distribution equation

## references


https://www.youtube.com/watch?v=O5BlozCJBSE&list=PLWzQK00nc192L7UMJyTmLXaHa3KcO0wBT&index=9

