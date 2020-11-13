
# Actor critic

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

# references


https://www.youtube.com/watch?v=O5BlozCJBSE&list=PLWzQK00nc192L7UMJyTmLXaHa3KcO0wBT&index=9

