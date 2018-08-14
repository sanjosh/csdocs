
# Succinct data structures

How to index and search compressed data ?

## Theoretical models

Two theoretical models to study lower bounds on data structures:

1. Cell probe model : total space used and total number of probes performed on memory - while computation is free
2. Index model : additional restriction that obj must be stored in raw form together with a small index

## Various problems:

* Rank/Select problem : 
    rank(k) = find number of 1 bits in [0,k] -popcount
    select = 

* Balanced parenthesis problem
* Binary relation representation
* Problem of computing permutation and its inverse

## Succinct versions of

1. FM-index : stands for full text in minute space 
2. Wavelet trees
3. RRR (Raman Raman Rao) 

## References

https://news.ycombinator.com/item?id=7079427

http://simongog.github.io/ - SDSL library (STL like)

http://pizzachili.dcc.uchile.cl/

http://cstheory.stackexchange.com/questions/8710/where-can-i-find-a-copy-of-guy-jacobsons-thesis-succinct-static-data-structure

http://cstheory.stackexchange.com/questions/11261/need-a-good-overview-for-succinct-data-structure-algorithms?rq=1

https://news.ycombinator.com/item?id=3650657
