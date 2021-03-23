
# sklearn model size

1. max_depth of trees has to be specified instead of None
1. min_samples_split
1. min_samples_leaf
1. max_leaf_nodes
1. clf.feature_importances

pickle protocol has to be highest

https://datascience.stackexchange.com/questions/8358/prohibitive-size-of-random-forest-when-saved-to-disk

https://stackoverflow.com/questions/34997134/random-forest-tuning-tree-depth-and-number-of-trees

https://github.com/scikit-learn/scikit-learn/issues/6276

## post pruning

https://github.com/scikit-learn/scikit-learn/issues/6557

# ngram compression (hashing trick)

HashingVectorizer : does not store strings

https://stackoverflow.com/questions/24005762/understanding-the-ngram-range-argument-in-a-countvectorizer-in-sklearn

featureHasher if you already have bigrams
https://scikit-learn.org/stable/modules/generated/sklearn.feature_extraction.FeatureHasher.html

https://radimrehurek.com/gensim/corpora/hashdictionary.html

https://blog.scrapinghub.com/2014/03/26/optimizing-memory-usage-of-scikit-learn-models-using-succinct-tries

ngrams of a word - fastText
https://radimrehurek.com/gensim/models/utils_any2vec.html

https://gist.github.com/generall/68fddb87ae1845d6f54c958ed3d0addb?short_path=8d81180

gensim Phraser

Perfect Hash

https://datascience.stackexchange.com/questions/22250/what-is-the-difference-between-a-hashing-vectorizer-and-a-tfidf-vectorizer

Disco : perfect hash

# Neural nets


EfficientNet

https://arxiv.org/abs/1905.11946

Extreme language model compression

https://arxiv.org/abs/1909.11687

Work in model compression for NLP applications falls broadly into four categories:

    1. matrix approximation,
    1. parameter pruning/sharing,
    1. weight quantization
    1. Knowledge distillation (small footprint student model borrows knowledge from larger teacher model)


the FLOPS of a regular convolution op is proportional to d,w2,r2, i.e., doubling network depth will double FLOPS, but doubling network width or resolu-tion will increase FLOPS by four times.

## quantization

binary quantization

quantization on FPGA to arbitrary bits

loss of accuracy in mat mul with smaller bits
