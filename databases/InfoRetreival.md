
Calculating entropy of text.

http://simongog.github.io/lessons/2012/08/26/Calculating_H_k_in_linear_time/

-----------

Wildcard queries

1) Permuterm index : store rotations of term. 
```
    hello$, o$hell, lo$hel, llo$he, ello$h
   if search for h*o$ -> look for o$h* -> matches 2nd term above
```

2) k-gram index : Permuterm index stores too many rotations per term. Instead, store k-grams of a word 
```
(e.g. 3-grams of castle$ -> store $ca, cas, ast, stl, tle, le$)
```

Posting list points from k-gram to all terms having that k-gram

For wildcard query,
* first lookup k-gram index to find terms
* then lookup regular inverted index to find doc

----------------

Spelling correction of two types : isolated and context-sensitive

1. Edit distance
2. K-gram overlap

----------------

Phonetic correction:

* use Soundex algorithm
* reduce word to its sound
* vowels are interchangeable
* consonants with similar sounds are equivalent

----------------

Index <key=term, value=doc1(position), doc2>

Distributed index with sharding - by term or by docid

----------------

## Index compression

* Store dict as string
* do front coding for common prefixes
* Gap coding
* Variable length codes
* delta codes by Elias
* Gamma codess by Elias
* Golomb codes

----------------

Scoring

--------------

* Synonymous words
* Vector space model for document clustering
* Tf-Idf weights

--------------


References

1. Raghavan. Info Retreival
