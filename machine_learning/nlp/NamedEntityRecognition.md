
# Biomedical NER (David Campos, Sérgio Matos and José Luís Oliveira)

The extracted information is stored in structured knowledge resources, such as Swiss-Prot [1] and GenBank

Challenges
1. two entities share same head nouns
2. multiple ways to spell same entity
3. ambiguous abbreviations

Chemical names can be divided into two classes [38]: 
1. a closed (finite) class for trivial names, 
1. an open (infinite) class for names following strictly defined nomenclatures (e.g. IUPAC names).

Approaches

## rule-based

## dictionary based

species recognition is already efficiently performed by dictionary-based solutions: LINNAEUS [12] and OrganismTagger [11]

Two different types of dictionaries are commonly used: 
1. target entity names (match tokens with dictionaries with a complete set of names of the target entity name), and 
2. trigger names (match names that may indicate the presence of biomedical names in the surrounding tokens).

## ML-based

Entity recognized by
1. orthographic
2. linguistic : mix of uppercase and lowercase, presence of symbols
3. morphological : suffix and prefix, n-grams, word shape patterns

CRF
1. CRF better than HMM - conditional nature relaxes independence assumptions
1. CRF better than MEMM - avoid label bias
1. CRF better than SVM - less time to train

semi-supervised solutions
1. Semi-CRFs [29, 30], 
2. Semi-SVMs [31], 
3. ASO [32] 
4. FCG [33].

## Ensemble methods

## references

https://www.intechopen.com/books/theory-and-applications-for-advanced-text-mining/biomedical-named-entity-recognition-a-survey-of-machine-learning-tools

# TODO

categories
http://stackoverflow.com/questions/4216648/facebook-pages-authoritative-list-of-categories

https://gist.github.com/shlomibabluki/6333174

https://nlpforhackers.io/named-entity-extraction/

https://github.com/acrosson/nlp/blob/master/information-extraction.py

Stanford NER
https://nlp.stanford.edu/software/CRF-NER.html


https://streamhacker.com/2018/04/04/advances-deep-learning-natural-language-processing/

Levenshtein in NLTK
https://streamhacker.com/2011/10/31/fuzzy-string-matching-python/

https://stackoverflow.com/questions/29275614/using-my-own-corpus-instead-of-movie-reviews-corpus-for-classification-in-nltk
