
# Haystack

Graph retriever that uses a pre-trained Bart model to translate natural language questions given in text form to queries in SPARQL format.  
The generated SPARQL query is executed on a knowledge graph

BART is a denoising autoencoder that maps a corrupted document to the original document it was derived from. 
It is implemented as a sequence-to-sequence model with a bidirectional encoder over corrupted text and a left-to-right autoregressive decoder.

https://arxiv.org/pdf/1910.13461.pdf


# Xser


three-phase process. 
1. It first creates a dependency representation of the phrase using a directed acyclic graph. 
2. disambiguates resources related to the phrases recognised in the question 
3. builds the final query. 

One interesting insight is that the query graph structure is generated directly from the 
DAG connections. The graph is generated using two machine leaning (ML) algorithms: 
1. one to capture four types of phrases in the target sentence and 
1. one to build the DAG. 

The first algorithm is a structured perceptron with Viterbi decoding algorithm to solve a 
sequence labelling problem of identifying entities, relations, categories and variables. 

The second algorithm is a transition-based parser to estimate the best operation in 
each step of the graph creation. 

In both approaches lexical and semantic features are used, in addition to specific ones, 
such as NER and structure-related features

Kun Xu, Answering natural language questions via phrasal semantic parsing

# TBSL 


translate the question in two steps. 

The first one analyzes the question structure to generate SPARQL templates with slots to be filled with resources. 

The second one searches and disambiguate the resources that best fit the phrases detected in the first phase.

The query building part starts with the question being processed with a POS tagger. 

Then, based on the tags, the question is parsed, generating syntactic and semantic representations. 
Representation of domain-independent lexicon mapping expressions is used, composed by expressions such as all, 
where, minimum and no. 

With these representations, a set of hand-made rules is applied to generate domain-independent templates. 

Later on in the process, these templates are ranked based on how the disambiguated resources are related in the target KB.

Christina Unger, Lorenz B¨uhmann, Jens Lehmann, Axel-Cyrille Ngonga Ngomo,
Daniel Gerber, and Philipp Cimiano. Template-based question answering over
rdf data.

# SINA

clean the user question

use HMM to disambiguate resources.  The emission and transition parameters were defined using bootstrapping

the question building part starts with a set of resources, which can be classes, properties or instances.

maps all superclasses of instances and all domain and range types of properties. This information is 
used to assemble an incomplete query graph (IQG), which can be disconnected if nodes are from different 
vocabularies. In this IQG, all input classes and instances are instantiated as nodes and all properties as edges.
If an input property cannot connect two nodes of the IQG, then new nodes are created so that the property can be created. 

uses an adaptation of the minimal spanning tree algorithm to connect the disconnected components of the IQG

Saeedeh Shekarpour, Edgard Marx, Axel-Cyrille Ngonga Ngomo, and Soren Auer. Sina: 
Semantic interpretation of user queries for question answering on interlinked data.


# SQG (sparql query generator)


query generator receives a list of candidate resources for each entity, class or property instead of already disambiguated resources. 

it has a query ranking system, which selects the most probable query graph according to the user intentions.

So, the SPARQL graph generator works in two steps: 
1. generation of walks in the KG, which corresponds to SPARQL queries, 
2. and assortment of candidate walks.

instead of assembling more than one QG, SQG assembles one subgraph of the KG and, then, generates graph walks that correspond to queries. 

These candidates are fed into the ranking system. 

The assumption is that the structure of the NL question should be similar to the candidate walk structure. 
In order to measure this similarity, cosine function is applied over two vector representations of two trees. 

The first one is a dependency tree of the NL question and the second one is a tree generated from each
candidate walk. These vectors are produced using a Child-Sum Tree-LSTM network, whose architecture is 
adapted to have trees as inputs

tested two classifiers, namely logistic regression and naive Bayes, over TF-IDF sentence representations 
to predict three classes: count, boolean and list questions

Hamid Zafar, Giulio Napolitano, and Jens Lehmann. Formal query generation for question answering over knowledge bases

# MSQG (modification of SQG)

Learning to build SPARQL queries from natural language questions 

## question type classifier 

decide type of aggregation required

## graphs generator 

output candidate graphs 

## similarity evaluator 

compare natura question against candidate graphs.  use BERT to avoid this dependency parsing process

## query constructor 

build query based on previous components

https://www.ic.unicamp.br/~reltech/PFG/2019/PFG-19-33.pdf
