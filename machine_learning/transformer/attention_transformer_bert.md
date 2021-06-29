
# Attention

A(K, V, Q) = softmax(Q.K_transpose).V

query = input word 
key = other words

query = what you want to look for 
key = what you can compare to 
value = info you can retrieve 

```
The key/value/query concepts come from retrieval systems. 
For example, when you type a query to search for some video on Youtube, 
the search engine will map your query against a set of keys (video title, description, etc.) 
associated with candidate videos in the database, then present you the best matched videos (values).
```

https://stats.stackexchange.com/questions/421935/what-exactly-are-keys-queries-and-values-in-attention-mechanisms

# Attention Kaiser

Attention is all you need; Attentional Neural Network Models | Łukasz Kaiser | Masterclass

at time 16 min

https://youtu.be/rBCqOTEfxvg?t=961

https://www.youtube.com/watch?v=rBCqOTEfxvg

# transformer

https://theaisummer.com/transformer/ (mike tamir)

# transformer

Value is selected based on similarity between key & value

https://www.youtube.com/watch?v=XSSTuhyAmnI

## why not seq-to-seq

two RNN : encoder and decoder

trouble with seq-to-seq is that only information decoder receives is the last encoder hidden state

instead, lets give decoded a vector representation for every encoder time step

## what is attention

Attention is an interface between the encoder and decoder that provides the decoder with information from every encoder hidden state

two types of attention : global and local

Global attention 

Attention assigns a score to each word in encoder.  Weighted sum of encoder scores = context vector

High attention score means decoder is going to be heavily influenced by this encoder hidden state 
Multiply each softmaxed encoder state with its softmax score = alignment vector 
Sum of alignment vectors = context vector 

Feed context vector to decoder 

Attention works because of backprop 

During inference, the input to each decoder time step t is the `*predicted output*` from decoder time step t-1. 
During training, the input to each decoder time step t is our `*ground truth output*` from decoder time step t-1. 

https://towardsdatascience.com/attn-illustrated-attention-5ec4ad276ee3

## Self-attention

every input must have 3 representations : key, query and value

Multiple each input by weights for key, query and value.

For each input 

1. Using score function, multiply (query vector of input 1) x (key vector of all input)  = attention score.  
     The alignment score function can be = dot product attention, scaled dot product, additive/concat
2. Take softmax across all attention scores
3. Multiply softmax scores x value scores  = weighed values
4. Output 1 = sum of weighted values =  Query representation of Input 1 interacting with all keys

https://towardsdatascience.com/illustrated-self-attention-2d627e33b20a

The self attention layers in the decoder operate in a slightly different way than the one in the encoder:

In the decoder, the self-attention layer is only allowed to attend to earlier positions in the output sequence. 
This is done by masking future positions (setting them to -inf) before the softmax step in the self-attention calculation.

The “Encoder-Decoder Attention” layer works just like multiheaded self-attention, except it creates 
its Queries matrix from the layer below it, and takes the Keys and Values matrix from the output of the encoder stack.

## difference between attention and self-attention

## multi-headed attention

with multi-headed attention we have not only one, but multiple sets of Query/Key/Value weight matrices (the Transformer uses eight attention heads, so we end up with eight sets for each encoder/decoder)

http://jalammar.github.io/illustrated-transformer/

# Transformer

deal with long-term dependencies better than LSTM

key property of the Transformer : word in each position flows through its own path in the encoder. 
There are dependencies between these paths in the self-attention layer. 
The feed-forward layer does not have those dependencies, however, and thus the various paths can 
be executed in parallel while flowing through the feed-forward layer.

positional encoding is added  

position vector cannot use relative position otherwise sentences which are longer than training set will not translate; instead add sin() and cos() to simulate frequencies

residual connection  
layer normalization 

http://jalammar.github.io/illustrated-transformer/

# BERT

BERT is basically encoder part of Transformer

# Evolution

## Word2Vec, GloVe

Word embeddings

## ELMo 

created contextualized word embeddings 

## ULM-FiT 

introduced language model (predict next word) and transfer learning

## OpenAI transformer 

used decoder of Transformer to create Language Model

introduced input transformations to handle different types of tasks

but it was not bidirectional

## BERT - Use encoder of Transformer

Masked Language model : mask out 15 percent of the words

BERT can also generate contextualized word embeddings

http://jalammar.github.io/illustrated-bert/

# attention talk by lukasz kaiser

## convolution vs self-attention 

Wavenet built using convolution
corresponding model for translation called Bytenet which is referencing by position 

self-attention is like a weighted average

image models still prefer convolution

## attention

for translation, we need referencing by context - hence attention

Three ways of attention
1. Encoder decoder attention (attends to input to modify output) 
2. encoder self-attention (attends everywhere)
3. decoder self-attention (masked attention which is based only on words before)

coreference resolution - Winograd schema

## multi-model

convolutional encoder   
transformer decode  
use mixture of experts  

## tensor2tensor library

transformer 
multimodel  
slicenet 
NeuralGPU 
bytenet 
Xception 


# Reference

1. Yannic Kilcher.  https://www.youtube.com/watch?v=iDulhoQ2pro
2. Vaswani.  Attention is all you need.  https://arxiv.org/abs/1706.03762
3. https://nlp.seas.harvard.edu/2018/04/03/attention.html
4. raimi karim https://towardsdatascience.com/attn-illustrated-attention-5ec4ad276ee3
5. raimi karim https://towardsdatascience.com/illustrated-self-attention-2d627e33b20a


