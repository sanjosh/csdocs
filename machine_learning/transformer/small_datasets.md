
# Optimizing Deeper Transformers on Small Datasets

https://arxiv.org/abs/2012.15355

## DT-Fixup

Data-dependent Transformer Fixed-update initialization schem

weight initialization scheme called T-Fixup for the vanilla transformer 

fully eliminates the need for layer normalization and learning rate warmup, and stabilizes the training to avoid harmful plateaus of poor generalization.

requires the inputs x to be Gaussian randomly initialized embeddings with variance d^(−1/2) where d is the embedding dimension

# Improving Transformer Optimization Through Better Initialization (T-Fixup)

ICML 2020

1. Transformer training can break down without learning rate warmup
2. requirement for warmup comes from a combined effect of high variance in the Adam optimizer and backpropagation through layer normalization
3. derive weight initialization scheme.  It requires the inputs x to be Gaussian randomly initialized embeddings with variance d^(−1/2) where d is the embedding dimension

