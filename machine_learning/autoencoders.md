
# Autoencoder

example of Feedforward network. 

Learn imperfectly.  Used for dimensionality reduction or feature lerning. Learn structure of manifold

```
h = f(x); r = g(h)
f is encoder
g is decoder
```

training via
1. minibatch gradient descent
2. recirculation

Minimize loss func L(x, g(f(x)))

## why useful

purpose is not to learn identity func

autoencoder useful because hidden dimension h can take useful properties, when h is constrained to have smaller dim than x

autoencoders fail to learn anything useful 
1. if the encoder and decoder are given too much capacity.
2. if h has same or greater dim as x

## linear and non-linear

When the decoder is linear and L is the mean squared error, an undercomplete
autoencoder learns to span the same subspace as PCA.  Autoencoder learns principal subspace of training data.

Autoencoders with nonlinear encoder functions f and nonlinear decoder func-
tions g can thus learn a more powerful nonlinear generalization of PCA.

## regularized autoencoder

regularized autoencoders use a loss function that encourages the model to have other properties besides the ability to copy its input to its output

## sparse autoencoder

training criterion involves a sparsity penalty

## denoising autoencoder

Learn L(x, g(f(x'))) where x' is corrupted copy of x

Denoising autoencoders must undo this corruption rather than simply copying their input.  They are an example of how overcomplete, high-capacity models may be used as autoencoders so long as care is taken to prevent them from learning the identity function.

## Variational Autoencoders

Carl Doersch.  tutorial on variational autoencoders
https://arxiv.org/pdf/1606.05908.pdf

## Deep encoder and decoder

Depth can exponentially reduce the computational cost of representing some
functions. Depth can also exponentially decrease the amount of training data
needed to learn some functions

## stochastic encoder and decoder

encoding and decoding func are not simple; involve noise injection

## contractive autoencoder

denoising autoencoders make the reconstruction function resist small but finite-sized perturbations of the input, while contractive autoencoders make the feature extraction function resist infinitesimal perturbations of the input.

## Applications

### Semantic hashing

if we train the dimensionality reduction algorithm to produce a code that is low- dimensional and binary , then we can store all database entries in a hash table mapping binary code vectors to entries.

This hash table allows us to perform information retrieval by returning all database entries that have the same binary code as the query. We can also search over slightly less similar entries very efficiently, just by flipping individual bits from the encoding of the query. This approach to information retrieval via dimensionality reduction and binarization is called semantic hashing

# Reference

1. Goodfellow.  Deep Learning Chap 14
