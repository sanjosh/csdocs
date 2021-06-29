
# difference with word2vec embeddings

word2vec are context-independent; learned representations are words

ELMo learns context-dependent vectors; it is character model which learns OOV words; learned representations are words

BERT is context dependent mode; learned representations are not words but subwords

ELMo uses LSTMS; BERT uses Transformer - an attention based model with positional encodings to represent word positions).

```
A practical implication of this difference is that we can use word2vec and Glove vectors trained on a large corpus directly 
for downstream tasks. All we need is the vectors for the words. There is no need for the model itself that was 
used to train these vectors.

However, in the case of ELMo and BERT, since they are context dependent, we need the model that was used to train the 
vectors even after training, since the models generate the vectors for a word based on context.

Having a fixed size vocabulary like BERT has a practical advantage of being able to load the vectors in a GPU regardless of corpus size
```

https://www.quora.com/What-are-the-main-differences-between-the-word-embeddings-of-ELMo-BERT-Word2vec-and-GloVe

# raw embeddings

They capture different forms of similarity — 
1. semantic (crown, throne, monarch, queen ), 
1. syntactic (he, she, they), 
1. word inflections (carry, carries, carrying), 
1. spelling( Mexico, México, Mexican ) 
1. phonetic similarity across languages

unsupervised entity tagging/linking

unsupervised harvesting of relationship triples

Pre-training BERT yields ~30,000 (28,996) vectors representing the words in BERT’s vocabulary 
(these vectors are stored in pytorch_model.bin file in Pytorch Transformers from Hugging Face)

```
Details of an example use of raw embeddings

If we have two terms (could be single words or phrases) and the goal is to identify what is common between these two terms we could

first pick sentences where each term appears alone in the sentences, and 
find the predicted neighbors for those terms using MLM head. 
An intersection of these descriptors serves as a signature of the meaning of those terms in isolation.

Pick sentences where both terms appear and predict the neighbors of those terms. 
This yields two signatures, one for each term, when they are in the context of each other.

We have four descriptor sets from above — descriptors for individual terms and for descriptors when both terms are used together.

Since all the descriptors harvested above are part of the vocabulary, we can examine these descriptors in the 
raw embedding space as an undirected graph where the connections between nodes are chosen based a threshold 
(threshold chosen based on the tail). Examining the descriptors tends to yields a signature that captures 
similarity in both spaces. Also the raw embedding space with a high threshold can be used to combine 
spelling variations in descriptors. This proves to be useful in the task of unsupervised harvesting of 
synonym candidates to a term.

```

https://github.com/ajitrajasekharan/bert_mask

https://handsonnlpmodelreview.quora.com/Examining-BERT-s-raw-embeddings-1

# prediction heads

MLM

Next sentence prediction


# visualizing

https://arxiv.org/pdf/1910.05276.pdf

https://exbert.net/

https://home.ttic.edu/~kgimpel/viz-bert/viz-bert.html
