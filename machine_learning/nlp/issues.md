
# Issues in NLP

how to handle 
1. out of vocab words : use n-grams
2. misspelled words
3. concat words : RNN
4. rare words : having common ngrams with frequent words will ensure good embedding
5. word sense disambiguation (WSD). Both CBOW and SG assume unique rep for each word
6. Data sparsity (unable to model all possible strings of words)
7. negation : do vs "don't" (sentence vec)
8. ordering of words : use sentence vec, RNN
9. punctuation : if dataset small, separate by space else let the network learn.

# Data sparsity

Guthrie, Closer look at skip-gram modeling
http://homepages.inf.ed.ac.uk/ballison/pdf/lrec_skipgrams.pdf

Solutions
1. smoothing
2. POS tags
3. syntactic categories
4. skipgrams

# perplexity

= 2^entropy
= effective number of neighbours

# Hyperparameters (in word2vec)

window size

# Problems with Classes

* Class imbalance problem : softmax
* Large num of classes : hierarchical softmax

# Space optimization

vector quantization of vectors to save space

# Reference
1. https://www.quora.com/Can-Word2Vec-be-used-for-Word-Sense-Disambiguation-WSD-If-yes-how
2. Bartunov, Adaptive skip-gram https://arxiv.org/pdf/1502.07257.pdf
3. Qiu, Proximity-Ambiguity Sensitive Skip-gram 
4. Neelakantan, Multi-sense Skip gram
