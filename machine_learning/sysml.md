
# SysML - machine learning distributed training

Every neural networks library on the market can be categorised based on four key elements:
Operations on tensors (e.g. computational graphs vs. eager execution);automatic gradient calculation (e.g. higher order gradients);The ability to speed up the code on GPUs, distributed systems, etc;The availability of high-level modules to build and train neural networks. 
Keras = 4
Autograd = 2
TODOtrax, jax, swift, tangent from google

# Summary of ML eng

what goes on inside the neural network ? a circuit/graph with tensors, activations, weights
Training and Inference
what happens during training - memory, CPU, GPU
challenges in distributed training
inference on the edge
inference on the browser



# Jax

Jax - (like Autograd 2.0)

JAX uses XLA for array-level program optimization and code generation

The acronym JAX stands for “just after execution”, since to compile a function we first monitor its execution once in Python.

https://mlsys.org/Conferences/2019/doc/2018/146.pdf
# Flax

# Stax

# Haiku

# Rlax

reinforcement learning
Neural tangentsTensorflowKerasPytorch

# Misc

## Autograd

JAX is built atop the same tracing library used within Autograd, which, being designed for self-closure, recognizes its own operations as primitives.

## From thesis maclaurin

Composite function

Evaluation of Jacobian starting from the left, we call “reverse accumulation mode” (AKA backprop)
evaluation starting from the right, we call “forward accumulation mode”:

Reverse mode is therefore the more efficient way to evaluate the gradient of a vector-to-scalar function

"Forward mode differentiation is therefore a factor of D (where x ∈ R D) slower than reverse-mode differentiation, and reverse-mode differentiation is only a small constant factor slower than evaluating the composite function itself. It should be noted that reverse mode differentiation has one major drawback: since we must do a complete forward pass to compute the intermediate values before applying the JVPs on the reverse pass, we need to store all the intermediate values in memory.

How to get the computation graph ? three ways 
User specifies nodes of graph, as done in Theanosource code inspection : have to build interpretermonitor function execution : 
VJP and JVP 

Maclaurin, Modeling, Inference and Optimization with Composable Differentiable Procedures, 2016 Harvard

https://dougalmaclaurin.com/phd-thesis.pdf

Also Rumelhart
Pearlmutter and Siskind

# Numpy

Array data structure 
ndarray - two of them can share memory


dtype

Pauli Virtanen
http://scipy-lectures.org/advanced/advanced_numpy/
scipyscikit-learn

# BLAS

# Horovod

# matplotlib

# opencv

# Cython

# Hardware

TPU

GPU

# Demystifying parallel and distributed deep learning

supervised learning
learning a composite function whose form is decided by activations and weights
regression vs classification

loss function has to be differentiable
compute gradient with respect to input and weights using backprop
weight update rule (learning rate)

minibatch size : tradeoff between performance and validation error
Minibatch depends on RAM

multiple forward and backward passes

parallel analysis using Work-Depth model

parallelize the convolution using Toeplitz matrix (im2col)

fully connected layers
maxpool
RNN

CPU & GPU : see CUDNN and MKL-DNN libraries

memory footprint
communication bandwidth
SGD has to converge

Three prominent partitioning strategies:
1. Data parallelism (input samples)
1. Model parallelism
1. Layer parallelism (pipelining)

As for layer partitioning, there are several advantages for a multi-processor pipeline over both data and model parallelism: (a) there is no need to store all parameters on all processors during forward evaluation and backpropagation (as with model parallelism); 
(b) there is a fixed number of communication points between processors (at layer boundaries), and the source and destination processors are always known. Moreover, since the processors always compute the same layers, the weights can remain cached to decrease memory round-trips.   

Two disadvantages of pipelining are however, are that data (samples) have to arrive at a specific rate in order to fully utilize the system, and that latency proportional to the number of processors is incurred

Data parallel
Run multiple copies of the training script and each copy:a) reads a chunk of the datab) runs it through the modelc) computes model updates (gradients)Average gradients among those multiple copiesUpdate the modelRepeat (from Step 1a)
All-Reduce

# Horovod

https://eng.uber.com/horovod/

# Model parallelism

Model parallelism divides a model into multiple partitions and performs the correspondingforward and backward computation across devices, i.e., the computation for each input datasample is partitioned and executed on multiple devices. Model parallelism can work in two ways:i) via vertical partitioning [3, 4], and ii) via horizontal partitioning [5, 6]. Vertical partitioningsplits the model by partitioning the total layers in the DL model across multiple GPUs, anduses pipelined micro-batches to avoid GPU stalls. Horizontal partitioning on the other hand,splits individual DL layers across multiple-GPUs by parallelizing the underlying computationsuch as matrix-multiplication, or the element-wise operation.

https://arxiv.org/pdf/1910.02054.pdf


# Distribution schemes for deep learning can be categorized along three axes: 

model consistency, parameter distribution, and training distributionunsupervised learning
GAN & auto-encoder

# Reinforcement learning
training algo are like DeepQ learning and A3C

https://arxiv.org/pdf/1802.09941.pdf

# Challenges in training large models

# ZeRO: Memory Optimization Towards Training

A Trillion Parameter Models

Microsoft paper on splitting optimizer state

data parallelism replicates theentire model states across all data parallel process resulting in redundant memory consumption;while model parallelism partitions these states to obtain high memory efficiency, but often result in too fine-grained computation and expensive communication that is less scaling efficient.  

Furthermore, both of these approaches maintain all the model states required over the entiretraining process statically, even though not all model states are required all the time duringthe training

We find that the majority of the memory is occupied by 
the optimizer states (such as momentum and variances in Adam), gradients, andparameters, which we refer to as OGP states of a model (or model states in short).

https://arxiv.org/pdf/1910.02054.pdf

# Alexa Radiate

# Amazon published paper on MxNet

# TODO

https://github.com/bharathgs/Awesome-Distributed-Deep-Learning

Mayer Jacobsen Scalable Deep LEarning https://arxiv.org/pdf/1903.11314.pdf

Hegde Usmani Parallel and Distributed Deep Learning https://stanford.edu/~rezab/classes/cme323/S16/projects_reports/hedge_usmani.pdf
