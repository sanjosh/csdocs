
# Policy gradient method

Deep Q-learning does not work large or continuous action spaces because it does Argmax over Q of all possible action

instead, return a matrix of probabilities for each action via softmax

exploration is handled by adjusting probabilities

## REINFORCE algo

No explicit exploration needed; choose random weighted actions

Converges faster than Q-learning but needs more episodes

Need large replay buffer to avoid correlations

No target network needed (only one network)


# References

https://www.youtube.com/watch?v=0c3r5EWeBvo&list=PLWzQK00nc192L7UMJyTmLXaHa3KcO0wBT&index=8


