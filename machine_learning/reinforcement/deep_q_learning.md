
# Deep Q-learning

Replace Q-lookup table by neural network

attempts to estimate Q values

backprop the MSE(predicted, actual returns)

choose action with highest Q value

SGD requires training data to be IID but state transitions are highly correlated.     
Hence introduce replay buffer (list of state, action, reward, new_state).    
Randomly sample batches to train on from this buffer  
new data kicks off old data  

Use 2 separate networks : Q(s, a) and Q^(a, s)
Every N steps, copy weights from Q to Q^  

in video game, past does matter.  So Markov property violated.  
solution : stack several recent frames together

## references

https://www.youtube.com/watch?v=pST6caY3mu8&list=PLWzQK00nc192L7UMJyTmLXaHa3KcO0wBT&index=7
