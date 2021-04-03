
# Alex Smola course

## Attention 

Attention is (key, value) pairs which are used to transfer state between encoder and decoder

https://www.youtube.com/watch?v=ivSNHf62-Sw

## Transformers

use sin(some_exp of i/j) and cos to encode position(i, j) : fourier basis

multi-head attention : database with multiple queries

RNN are sequential but transformers process everything in parallel like convolutions

https://www.youtube.com/watch?v=xf5gKdd7mBw

## BERT

Why transformers
1. Word2Vec ignores sequential information; 
2. language model looks only in one direction

masked language model : mask 15 perc of tokens (fill in the blanks)

BERT returns feature vector with context information for each token

different fine-tuning tasks can use different set of vectors
1. sentence classification
2. NER
3. Q&A

https://www.youtube.com/watch?v=5KRwXdiQoEI

