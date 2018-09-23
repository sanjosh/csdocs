
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

Algorithms 
* logistic regression (excel SUMPRODUCT)
* neural net
* decision tree
* boosted decison tree
* random forest

Tools
* Knime

# Reference

1. https://github.com/dataspring/DeDuplication
2. http://aseigneurin.github.io/2016/02/22/record-inkage-a-real-use-case-with-spark-ml.html
3. https://datascience.stackexchange.com/questions/22587/algorithms-for-aggregating-duplicate-identities-based-on-non-numerical-data
4. https://dedupe.io/developers/library/en/latest/How-it-works.html
5. https://stats.stackexchange.com/questions/90997/state-of-the-art-in-deduplication
6. https://medium.com/district-data-labs/basics-of-entity-resolution-with-python-and-dedupe-bc87440b64d4
7. https://stackoverflow.com/questions/43366705/how-to-apply-machine-learning-to-fuzzy-matching

