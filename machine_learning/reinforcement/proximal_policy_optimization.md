
invented to improve stability of SGD

instead of using gradient of log prob of the action taken, it uses ratio between new and old policy scaled by advantages


# Proximal Policy Optimization.

1. builds on actor-critic
2. has sampling efficiency
3. minimal hyperparameter tuning

Upgrades

1. Generalized Advantage estimation  (GAE)
2. Surrogate policy loss function
3. Mini-batch updates


## GAE algorithm

new way to calculate returns which reduces variance

## surrogate policy loss

ratio of new probabilities/old probabilities

# References

1. https://www.youtube.com/watch?v=5P7I-xPq8u8
2. https://www.youtube.com/watch?v=WxQfQW48A4A&list=PLWzQK00nc192L7UMJyTmLXaHa3KcO0wBT&index=11
3. https://openai.com/blog/openai-baselines-ppo/
4.  Maxim Lapan, Deep reinforcement learning
