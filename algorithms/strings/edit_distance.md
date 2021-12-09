
# Exact algorithms

Four types of algorithms 

## Dynamic programming 

1. Wagner-Fischer
2. Ukkonen banded search
3. Hirschberg

O(mn) time
O(mn) space

## NFA 

1. Ukkonen

## Bit parallelism

1. Parallelize the NFA
2. Parallelize the dynamic programming matrix

## Filtration

Filtration used to quickly rule out non-matching text.  Any filtration algo requires non-filtration algo for verification.

To find text at distance k from pattern, cut the pattern into k+1 approx equal length pieces, at least one of which must appear unchanged in text.  Use a multi-pattern algo to find the pieces.

### Hierarchical verifcation

Instead of splitting pattern into k+1 pieces, split it into binary tree.

# Approximate algorithms 

TODO

# Probabilistic algorithms

TODO

# Parallel algorithms

TODO

# Miscellaneous

1. Bitap (Baeza-Yates-Gonnet) : used in agrep

# Reference

1. Navarro. Flexible Pattern Matching in Strings

# libraries

fuzzwuzzy, gensim, difflib, jellyfish

