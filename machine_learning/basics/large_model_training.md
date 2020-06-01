
# Gradient averaging

When training big neural networks, it can happen that the biggest mini-batch size you can afford is one. In such cases training can get very inefficient and even not converge due to very noisy gradients. Gradient averaging is a technique allowing to increase the effective mini-batch size arbitralily despite GPU memory constraints. The key idea is to separate gradients computation from applying them. 

https://gchlebus.github.io/2018/06/05/gradient-averaging.html

https://medium.com/huggingface/training-larger-batches-practical-tips-on-1-gpu-multi-gpu-distributed-setups-ec88c3e51255

# Gradient checkpointing

# DataParallel

# Distributed
