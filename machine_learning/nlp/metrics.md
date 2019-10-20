
## Entropy

## Cross Entropy


P = empirical distribution of language
Q = learnt by model from sample text

Therefore, the cross entropy of Q with respect to P is the sum of the following two values:

the average number of bits needed to encode any possible outcome of P using the code optimized for P [which is - entropy of P].
the number of extra bits required to encode any possible outcome of P using the code optimized for Q.


## Perplexity

Consider a language model with an entropy of three bits, in which each bit encodes two possible outcomes of equal probability. This means that when predicting the next symbol, that language model has to choose among 2^3 = 8 possible options. Thus, we can argue that this language model has a perplexity of 8.

## BPC

https://thegradient.pub/understanding-evaluation-metrics-for-language-models/
