
# Parsers

1. dependency tree : has only terminal symbols
2. phrase structure/constituency tree : has non-terminals to represent phrases
3. link grammar
4. AMR (abstract meaning representation) parsing

# Syntactic Constituency parsing as sequence to sequence problem

Syntactic constituency parsing can be formulated as a sequence-to-sequence problem if we linearize the parse tree(depth first traversal).

We also found it useful to reverse the input sentences but not their parse trees, similarly to [1]

We also treat unknown words in a naive way: we map all words beyond our 90K vocabulary to a single UNK token. 

Use 3 LSTM layers


## Dataset

Treebanks for parser
https://en.wikipedia.org/wiki/Treebank

## Reference

1. Vinyals.  Grammar as a Foreign Language


