
# SysML - machine learning distributed training

Every neural networks library on the market can be categorised based on four key elements:
1. Operations on tensors (e.g. computational graphs vs. eager execution)
2. automatic gradient calculation (e.g. higher order gradients)
3. The ability to speed up the code on GPUs, distributed systems, etc
4. The availability of high-level modules to build and train neural networks. 

Keras = 4

Autograd = 2

# TODO

swift, tangent from google

## autodiff in ML survey

https://www.youtube.com/watch?v=wG_nF1awSSY
https://arxiv.org/abs/1502.05767

# Summary of ML eng

what goes on inside the neural network ? a circuit/graph with tensors, activations, weights

Training and Inference

what happens during training - memory, CPU, GPU

challenges in distributed training

inference on the edge

inference on the browser

# Autograd

how to implement autodiff ? (Roger Grosse)

## step 1 tracing computation to build graph.  

tensorflow tells user to specify graph while pytorch traces computation in forward pass

## step 2 implement vector-Jacobian product for each primitive op

jacobian matrix is matrix of partial derivatives

## step 3 implement backprop itself

do message passing between nodes

https://github.com/mattjj/autodidact
http://www.cs.toronto.edu/~rgrosse/courses/csc421_2019/readings/L06%20Automatic%20Differentiation.pdf

# XLA



# Auto differentiation in Stan

https://arxiv.org/abs/1509.07164

# Flax


# Haiku

# Trax

Trax includes basic models (like ResNet, LSTM, Transformer) and RL algorithms (like REINFORCE, A2C, PPO). 

It is also actively used for research and includes new models like the Reformer and new RL algorithms like AWR. 

Trax has bindings to a large number of deep learning datasets, including Tensor2Tensor and TensorFlow datasets.

# Rlax

reinforcement learning

# Neural tangents

high-level neural network API for specifying complex, hierarchical, neural networks of both finite and infinite width

Infinite (in width or channel count) neural networks are Gaussian Processes (GPs) with a kernel function determined by their architecture

# Tensorflow

# Keras

# Pytorch

# Misc


### From thesis maclaurin

Composite function

Evaluation of Jacobian starting from the left, we call “reverse accumulation mode” (AKA backprop)
evaluation starting from the right, we call “forward accumulation mode”:

Reverse mode is therefore the more efficient way to evaluate the gradient of a vector-to-scalar function

```
Forward mode differentiation is therefore a factor of D (where x ∈ R D) slower than reverse-mode differentiation, and reverse-mode differentiation is only a small constant factor slower than evaluating the composite function itself. It should be noted that reverse mode differentiation has one major drawback: since we must do a complete forward pass to compute the intermediate values before applying the JVPs on the reverse pass, we need to store all the intermediate values in memory.
```

How to get the computation graph ? three ways 
* User specifies nodes of graph, as done in Theano
* source code inspection : have to build interpreter
* monitor function execution : 

VJP and JVP 

Maclaurin, Modeling, Inference and Optimization with Composable Differentiable Procedures, 2016 Harvard

https://dougalmaclaurin.com/phd-thesis.pdf

Also Rumelhart
Pearlmutter and Siskind

## Numpy

Array data structure 
ndarray - two of them can share memory


dtype

Pauli Virtanen
http://scipy-lectures.org/advanced/advanced_numpy/

## scipy

## scikit-learn

## BLAS

## Horovod

## matplotlib

## opencv

## Cython

# Hardware

## TPU

## GPU

# Demystifying parallel and distributed deep learning

## supervised learning

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
2. Model parallelism
3. Layer parallelism (pipelining)

As for layer partitioning, there are several advantages for a multi-processor pipeline over both data and model parallelism: 
1. there is no need to store all parameters on all processors during forward evaluation and backpropagation (as with model parallelism); 
2. there is a fixed number of communication points between processors (at layer boundaries), and the source and destination processors are always known. Moreover, since the processors always compute the same layers, the weights can remain cached to decrease memory round-trips.   

Two disadvantages of pipelining are however, are that data (samples) have to arrive at a specific rate in order to fully utilize the system, and that latency proportional to the number of processors is incurred

## Data parallel

1. Run multiple copies of the training script and each copy
   * reads a chunk of the data
   * runs it through the model
   * computes model updates (gradients)
2. Average gradients among those multiple copies
3. Update the model
4. Repeat (from Step 1a)

All-Reduce

Horovod

https://eng.uber.com/horovod/

## Model parallelism

Model parallelism divides a model into multiple partitions and performs the corresponding forward and backward computation across devices, i.e., 
the computation for each input datasample is partitioned and executed on multiple devices. 

Model parallelism can work in two ways:
1. via vertical partitioning [3, 4], and 
2. via horizontal partitioning [5, 6]. 

Vertical partitioning splits the model by partitioning the total layers in the DL model across multiple GPUs, 
and uses pipelined micro-batches to avoid GPU stalls. 

Horizontal partitioning on the other hand,splits individual DL layers across multiple-GPUs by parallelizing 
the underlying computation such as matrix-multiplication, or the element-wise operation.

https://arxiv.org/pdf/1910.02054.pdf


### Distribution schemes for deep learning can be categorized along three axes: 

1. model consistency, 
2. parameter distribution, and 
3. training distributionun

### supervised learning

GAN & auto-encoder

# Reinforcement learning

training algo are like DeepQ learning and A3C

https://arxiv.org/pdf/1802.09941.pdf

# ZeRO: Memory Optimization Towards Training

A Trillion Parameter Models

Microsoft paper on splitting optimizer state

data parallelism replicates the entire model states across all data parallel process resulting in redundant memory consumption;

while model parallelism partitions these states to obtain high memory efficiency, but often result in too fine-grained computation and expensive communication that is less scaling efficient.  

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

https://syncedreview.com/2020/12/14/a-brief-history-of-deep-learning-frameworks/
