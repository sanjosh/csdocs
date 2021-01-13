
# Deduplication

AKA record linkage, dedup, entity resolution, conflation

can it be done without labeled data ?

Need normalizers and comparators for each column
* normalizers for incomplete or corrupted data
* use weighted Jaccard distance to find intersection in tokens of words 
* use edit distance for strings
* word2vec to find nearest semantic match
* custom compare for numerics, latitude-longitudes
* siamese net for image match
* locality sensitive hashing
* phrase embeddings : encoder-decoder network of RNN
* image captioning : joint embeddings


## factor graphs

# Tools

## Knime

## recordlinkage python


# papers

## named entity disambiguation 

Pasca Bunescu, Using Encyclopedic Knowledge for Named Entity Disambiguation, https://www.cs.utexas.edu/~ml/papers/encyc-eacl-06.pdf


## Named entity disambiguation with knowledge graph (oracle)

1. Build graph from DBPedia (Property graph and Redirects graph)
2. Graph embedding : Encode vertex as vector - similar vertex has similar embedding
3. Deepwalk to create embedding
4. Inference : find candidate vertices based on string match

https://blogs.oracle.com/datascience/named-entity-disambiguation-with-knowledge-graphs-v2-v2

Parravicini, Patra, Fast and Accurate Entity Linking via Graph Embedding
https://dl.acm.org/doi/10.1145/3327964.3328499

https://www2.slideshare.net/necstlab/fast-and-accurate-entity-linking-via-graph-embedding

## entity disambiguation with freebase

Zheng, Entity Disambiguation with Freebase

https://static.googleusercontent.com/media/research.google.com/en//pubs/archive/38389.pdf

## cross-document coreference

factor graph

https://ai.googleblog.com/2013/03/learning-from-big-data-40-million.html

Singh, Large-Scale Cross-Document Coreference Using Distributed Inference and Hierarchical Models

# Reference

1. https://github.com/dataspring/DeDuplication
2. http://aseigneurin.github.io/2016/02/22/record-inkage-a-real-use-case-with-spark-ml.html
3. https://datascience.stackexchange.com/questions/22587/algorithms-for-aggregating-duplicate-identities-based-on-non-numerical-data
4. https://dedupe.io/developers/library/en/latest/How-it-works.html
5. https://stats.stackexchange.com/questions/90997/state-of-the-art-in-deduplication
6. https://medium.com/district-data-labs/basics-of-entity-resolution-with-python-and-dedupe-bc87440b64d4
7. https://stackoverflow.com/questions/43366705/how-to-apply-machine-learning-to-fuzzy-matching

