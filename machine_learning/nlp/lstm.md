
# RNN 

RNN can learn short-term but not long-term dependencies because of vanishing gradient problem[2].

training an RNN on a long sequence of words can cause the gradient to vanish (when the gradient is small) or to explode (when the gradient is large) during backpropagation.

Basically, the backpropagation algorithm multiplies the gradients along the computational graph of the neural network in reverse direction. Hence, when the eigenvalue of the hidden state matrix is large or small, the gradient becomes unstable.[4]

see also [5]

RNN can simulate computer program...If training vanilla neural nets is optimization over functions, training recurrent nets is optimization over programs. [karpathy blog]

The interesting part of backpropagation in RNN is that backpropagation occurs from right to left. Since the parameters are updated from final time steps to initial time steps, this is termed as backpropagation through time. [from "towards data science"]

# LSTM 

can capture long range dependencies

the forget gate and the output activation function to be its most critical components[3].

We discovered that the input gate is important, that the output gate is unimportant, and that the forget gate is extremely significant on all problems except language modelling.[2]

LSTM with n memory cells has a hidden state of dimension 2n[2].


# LSTM Variations

## Peephole connections

## Coupled forget and input gates

## GRU

has 2 gates instead of 3. trains faster.


## Depth gated RNN

## Clockwork RNN

# Complex LSTM 

## Bidirectional

Bidirectional LSTMs are supported in Keras via the Bidirectional layer wrapper.

## Multilayer

stack vs multidim

## Tree LSTM

```
Tree-LSTMs outperform all existing systems and strong LSTM baselines on two tasks: predicting the semantic relatedness of two sentences (SemEval 2014, Task 1) and sentiment classification (Stanford Sentiment Treebank).
```

(see also skip-thought vectors for semantic relatedness task)

## Zoneout

* Like dropout in CNN
* zoneout trains a psuedo-ensemble (collection of child models spawned from parent model)
* zoneout as per-unit stochastic depth.
* zoneout helps propagate gradients

See [8]

# Training algorithm

## Teacher forcing

improve model skill and stability

[9, 12]

## Professor forcing

teacher forcing 
* train an Open loop generator using ground truth
* maximum likelihood principle
* problem is that it accumulates errors
* does not generalize well to sequences which are longer than training set.

In professor forcing
* Two generators with shared parameters : open loop (teacher forcing) and closed loop (free running)
* Uses adversarial framework with Discriminator
* Distributions of hidden states are forced to come closer by Discriminator
* Optimize closed loop to fool classifier
* Optimize open loop with teacher forcing

[11]

## Curriculum learning

## Scheduled sampling

[10]

# TODO

Beam search
Stack/Queue/Deque 

# Reference

1. https://colah.github.io/posts/2015-08-Understanding-LSTMs/
2. Jozefowicz. An Empirical Exploration of Recurrent Network Architectures
3. Greff. LSTM Search space odyssey
4. https://www.oreilly.com/ideas/build-a-recurrent-neural-network-using-apache-mxnet
5. Pascanu. On the difficulty of training recurrent neural networks
6. Tai. Improved semantic representations from Tree LSTM.  https://arxiv.org/abs/1503.00075
7. https://www.quora.com/What-is-the-difference-between-stacked-LSTMs-and-multidimensional-LSTMs
8. Tegan Maharaj. Zoneout.  (MILA) http://videolectures.net/deeplearning2016_maharaj_zoneout/
9. A Learning Algorithm for Continually Running Fully Recurrent Neural Networks, 1989.
10. Scheduled Sampling for Sequence Prediction with Recurrent Neural Networks, 2015.
11. Anirudh Goyal. Professor Forcing: A New Algorithm for Training Recurrent Networks, 2016.
12. Section 10.2.1, Teacher Forcing and Networks with Output Recurrence, Deep Learning, 2016.
