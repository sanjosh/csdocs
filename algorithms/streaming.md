

# Data streams : Muthukrishnan 

##  set reconcilation problem (find missing numbers)

subset reconcilation problem

## Missing mass problem


## Models

1. Time series model  A: [1..N] -> R^2
2. cash register model : stream of increments to A[j]
3. turnstile model : stream of updates to A[j]

## foundation

### Sampling

1. Find number of distinct items in cash register model
2. find quantiles in cash register
3. find frequent items in cash register

### random projections/Sketches

Generated using random variables

Indyk Stable Distributions, Pseudorandom Generators, Embeddings, and Data Stream Computation
```
any linear combination of a set of samples from a p-stable distribution must itself
be a sample from the same distribution, scaled by the p-norm of the weight vector.

inner product of u with sequence r of n i.i.d. random variables drawn from p-stable distribution 
has magnitude proportion to |u|_p

this enables construction of compact representation of vector u (space-saving)

one can use pseudorandom generators to reduce number of random bits
```

Cormode and Indyk, Stable Distributions in Streaming Computations
http://dimacs.rutgers.edu/~graham/pubs/papers/stablechapter.pdf
```
we get the intuition for why stable distributions are helpful in computing Lp norms 
and Lp distances: by maintaining the inner product of variables from α-stable distributions 
with a vector being presented in the stream, we get a variable S which is distributed 
as a stable distribution scaled by the Lp norm of the stream, where p = α. 

Maintaining this inner product as the vector undergoes updates is straightforward: given an update
(i, c), we simply add Xi·c to S
```

Sketches of different stable distributions can estimate various Lp norms on data stream

1. Using Lp sketches, estimate number of distinct elements in Turnstile
2. Using L1 sketches, estimate quantiles in Turnstile
2. Using L1 sketches + algo, track frequent items, wavelets, histograms in Turnstile
4. Using L2 sketches, estimate self-join size - inner product

## Basic algo techniques

### group testing

### Tree method

### robust approximation

### exponential histograms

Datar

https://www.cs.upc.edu/~gavalda/DataStreamSeminar/files/Lecture6.pdf

## How to construct lower bounds

## Streaming Models

### Permutation streaming

### windowed streaming

### synchronized streaming


