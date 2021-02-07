

# Federated learning

No need for centralized training data

1. Device downloads latest model
1. Train locally on user data
1. Sent model back to server
1. Server averages the model parameters
1. Server sends back updated global model

## Federated averaging algorithm

Not using SGD which requires low-latency, high-throughput connections to the training data

reduce upload communication costs to server up to another 100x by compressing updates using random rotations and quantization.

training on device happens only when the device is idle, plugged in, and on a free wireless connection, s

Secure Aggregation protocol that uses cryptographic techniques so a coordinating server can only decrypt the average update if 100s or 1000s of users have participated — 
no individual phone's update can be inspected before averaging.

https://arxiv.org/abs/1602.05629

https://ai.googleblog.com/2017/04/federated-learning-collaborative.html

## Practical Secure Aggregation for Privacy-Preserving Machine Learning

Goal : securely computing sums of vectors, which has 
1. a constant number of rounds, 
1. low communication overhead, 
1. robustness to failures, and 
1. requires only one server with limited trust.

different approaches
1. generic secure multi-party computation protocols, 
1. DC-nets, 
1. partially- or fully-homomorphic threshold encryption, 
1. pairwise masking

https://eprint.iacr.org/2017/281

