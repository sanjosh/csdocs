
# Bertology paper

Pretraining uses two self-supervised tasks: 
1. masked language modeling (MLM, prediction of randomly masked input tokens) and 
2. next sentence prediction (NSP, predicting if two input sentences are adjacent to each other)

In fine-tuning for downstream applications, one or more fully-connected layers are
typically added on top of the final encoder layer.

each word in the input is first tokenized into wordpieces (Wu et al., 2016), and 
then three embedding layers (token, position, and segment) are combined to obtain 
a fixed-length vector. 

Special token [CLS] is used for classification predictions, and [SEP] separates input segments.

## finding what it encodes

using
1. fill-in-the-gap probes of MLM, 
2. analysis of self-attention weights, and 
3. probing classifiers with different BERT representations as inputs.

## syntax

BERT representations are hierarchical rather than linear,

BERT embeddings encode information about parts of speech, syntactic chunks
and role

syntactic structure not directly encoded in self-attention weights, but can be recovered from token representations

BERT takes subject-predicate agreement into account while performing cloze task

does not understand negation, insensitive to malformed inputs

predictions not altered by shuffled word order 


## semantic

BERT encodes information about entity types, relations, semantic roles, and proto-roles

struggles with numbers (due to wordpiece tokenization)

brittle with named entity replacement

## world knowledge

struggles with pragmatic and role-based inference

abstract attributes, visual properties

for some relation types, it can generalize

In order to retrieve BERT’s knowledge, we need good template sentence

BERT cannot reason (houses are bigger than people)



# BERT for long sentences

1. reduce text length by summarization
1. combine by pooling
1. Longformer
1. Extract the keywords using unsupervised extraction methods like YAKE, RAKE, KeyBERT.
1. TF-iDF + SVD/PCA/UMAP

https://pakodas.substack.com/p/semantic-search-on-documents

https://stackoverflow.com/questions/58636587/how-to-use-bert-for-long-text-classification
