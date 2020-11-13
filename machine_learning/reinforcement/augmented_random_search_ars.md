
# ARS

ARS is enhanced version of Basic random search

Building block is perceptron.  No deep learning

input is sensor, output is motors

number of weights = (num inputs) x (num outputs)

## method of finite differences

1. clone two versions of weights
2. Add/subtract random noise `delta` from both versions of weights 
3. collect positive and negztive reward
4. weight += (learning_rate(positive_reward - negative_reward) * delta


# References

1. Colin Skow

https://www.youtube.com/watch?v=2P2Dj5PX5cg&list=PLWzQK00nc192L7UMJyTmLXaHa3KcO0wBT&index=6
