
# Text Similarity - Shaurya Roy

Dimensions of similarity
1. Content (topics)
2. Structure within text (interconnection)
3. Style (grammar, lex, usage)

Problems
1. paraphrase detection
2. text entailment recognition ; given texts T and H, will human reading T infer H ?
3. plagiarism
4. normalization
5. evaluation of NLP tasks

Granularity of similarity
1. word - lexical
2. word to text : compositional or non-comp (wordnet)
3. text sequences : idioms, quotation.

Distributional hypothesis : (infrequent non-generic?) words that occur in similar context have similar meaning.

Word2vec 

semantic similarity vector space : Skipgram, CBOW, Glove, FastText

fuzzwuzzy, gensim, difflib, jellyfish

Supervised text similarity
1. classical : SVM, random forest, ensemble
2. neural : outperforms classical.  Sequential models RNN, GRU, LSTM better for text.

Attention based similarity models

# Followup
1. Gomma and Fahmy, Survey of text similarity, 2013

