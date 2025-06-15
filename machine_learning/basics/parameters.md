
# summary

```
input * weights = output
need activation function to make it non-linear
loss function = difference expected and actual
derivative of weights(params) wrt loss - SGD
backprop - subtract loss from weights to get new weights so loss goes down
optimizer used to update weights to speed up convergence
learning rate decides granularity of weight change
```

# batch size 

The batch size limits the number of samples to be shown to the network before a weight update can be performed

network with higher batch size is faster to train

keep it low for CPU-based training; higher for GPU

# dropout


# number of iterations

Number of iterations * batch size = entire training dataset

## early stopping

# epoch 

one epoch is when entire training dataset is passed ONCE forward and backward through neural network

# loss function


# loss values

train < val : overfitting
        
train > val : data leakage, 

both are high : model too simple

both low but noisy : data is random or not scaled

# curriculum Learning

Start with low variance synthetic data → increase variance slowly each epoch to stabilize early learning.


# learning rate

if the learning rate is too high, our loss will start jumping all over the place and never converge.

if the learning rate is too small, the model will take way too long to converge,

https://blog.nanonets.com/hyperparameter-optimization/


https://stats.stackexchange.com/questions/164876/tradeoff-batch-size-vs-number-of-iterations-to-train-a-neural-network

Leslie Smith paper on 1-cycle learning

# activation

data normalization, activation and loss func are important in determining accuracy

# optimizer

TODO how to embedding

TODO padding

optimizer just speeds up convergence
