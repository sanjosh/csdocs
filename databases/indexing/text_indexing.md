
# Text index

Searching text for a pattern can be optimized in two ways. 
1. By indexing the text using various data structures.   
2. By indexing the pattern using various algorithms.  

# Index the text itself

| type | Exact | Substring | Regex | Fuzzy | Typeahead |
| ---- | ----  | ---------| ---- | ---- | ----- |
| Hash table | Y | N | N | N | N |
| Prefix BTree | Y |Prefix only | N | N | Y |
| String BTree | Y | Y after augmentation | N | N | Y | 
| Trie | Y | Prefix | N | N | Y | 
| Ngram | reduce search space | reduce search space | reduce search space | N | N |
| Burkhard-Keller tree | N | N | N | Y | N |
| Suffix array/tree   | Y | Y | N | N | N |
| FST | Y |Expensive | Y | Y | Y | 

# Index the pattern 

| Algo | Objective | 
| ---- | -----     |
| Boyer Moore | Single pattern | 
| KMP | Single pattern | 
| Rabin Karp | Single pattern using rolling hash| 
| Aho Korasick | Build FST on multiple patterns | 
| Automata     | http://www.geeksforgeeks.org/searching-for-patterns-set-5-finite-automata/ |
| Automata on regex | google re2, thrax from openfst |
| Automata on levenshtein | fuzzy |
| Agrep (pattern is 32 or 64 symbols | fuzzy |

