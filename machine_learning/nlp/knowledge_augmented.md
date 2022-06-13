
https://www.youtube.com/watch?v=y68RJVfGoto&list=PLoROMvodv4rOSH4v6133s9LFPRHjEmbmJ&index=15

# Lecture 15 - Add Knowledge to Language Models

Stanford CS224N NLP with Deep Learning | Winter 2021 | 

techniques
1. use pretrained embedding
2. use external memory
3. modify training data

http://web.stanford.edu/class/cs224n/slides/cs224n-2022-lecture-knowledge.pdf

## add entity embeddings

for that, you have to do entity linking : 

1. TransE - knowledge graph embedding methods
2. Wikipedia2Vec : word entity co-occurence
3. BLINK - use transformer

How do we incorporate pretrained entity embeddings when they're from a different embedding space than the language model?
Learn a fusion layer that combines word info and entity info

what about relation embedding ?

### ERNIE: Enhanced Language Representation with Informative Entities (ACL 2019)


### QAGNN/GreaseLM: Reasoning with Language Model and Knowledge Graph

Key idea: when adding entity embeddings to language model, dynamically update them together with neighbor or related entities in knowledge graph as well as text

Text is encoded by a language model, knowledge graph (KG) is encoded by a graph neural network (GNN), and they
are fused together for multiple rounds.

structured reasoning is better : By grounding language model to knowledge graph, models learn to perform structured reasoning 

can handle negation

## add external memory

Cons of entity embedding methods : if the KB is modified, you may need to re-train the entity embeddings and model

### KGLM

Key idea: condition the language model on a knowledge graph (KG) when predicting next word

Method: Build a local knowledge graph as you iterate over this sequence

why use local KG : local signals are stronger

what about queries that require more than one step in KG : 

three cases
1. new entity
2. related entity
3. not an entity

Modifying the KG has a direct change in the LM predictions

### kNN-LM



## modify training data

Mask or corrupt the data to introduce additional training tasks that require factual knowledge.

WKLM

ERNIE

salient span masking (Guu ICML 2020)


## testing LM

LAMA library from facebook
https://github.com/facebookresearch/LAMA


## better prompts

Problem: LMs may know the fact, but fail on completion tasks (LAMA) due to the query phrasing

## Other

Retrieval-augmented language models [More details in Kelvin Guu’s lecture!]
• REALM, Guu et al., ICML 2020
• RAG, Lewis et al., NeurIPS 2020
• Retro, Borgeaud et al., 2022

Modifying knowledge in language models [More details in Eric Mitchell’s lecture!]
• Fast Model Editing at Scale, Mitchell et al., 2021

More knowledge-aware pretraining for language models
• KEPLER, Wang et al., TACL 2020


#  Lecture 15 - Guu 

http://web.stanford.edu/class/cs224n/slides/cs224n-2022-lecture15-guu.pdf

Transformer feed-forward layers are key-value memories (Geva et al, 2021)

modify memory Meng et al, 2022: apply a rank-1 update.

WARNING: this is a new research area, and conclusions may change soon!

slide 43 : memory retrieval methods

## external tool 

LaMDA Thoppilan 2022 + search engine, 

WebGPT

## neural retriever

ORQA Lee 2019

REALM Guu 2020

