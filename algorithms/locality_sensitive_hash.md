
# list

1. Simhash (Random projections)
2. MinHash
3. TLSH (digital forensics)
4. Nilsimsa (anti-spam)

# Minhash

## theory

characteristic matrix

To minhash a set represented by a column of the characteristic matrix, pick
a permutation of the rows. The minhash value of any column is the number of
the first row, in the permuted order, in which the column has a 1

Ullman http://infolab.stanford.edu/~ullman/mmds/ch3.pdf

h_min(Set S) = member x of S with minimum value of h(perm(x)) where h is hash func, perm is random permutation

Pr [h_min(S1) == h_min(S2)] = Jaccard(S1, S2) = | A intersect B | / | A union B |

## Why is it an unbiased estimator of Jaccard similarity ?

See theorem 1 of (Broder, On the resemblance and containment of documents)

## generating many hash function

One way to generate 200 hash values is to generate one hash value using a good hash algorithm and generate 
199 values cheaply by XORing the good hash value with 199 sets of random-looking bits having the same 
length as the good hash value (i.e. if your good hash is 32 bits, build a list of 199 32-bit pseudo 
random integers and XOR each good hash with each of the 199 random integers).

https://stackoverflow.com/a/19711615

## Accuracy (bill dimm)

Regarding how the accuracy depends on the number of hash functions, that comes from the Central Limit Theorem. 

If you compute the mean of a bunch of independent samples from the same probability distribution, the 
probability distribution of the mean itself will be normal (i.e. bell-shaped) if you take enough samples 
even if the probability distribution of the individual samples is far from normal. The standard deviation of 
the bell-shaped distribution for the mean is given by the standard deviation of the individual sample 
distribution divided by sqrt(N), where N is the number of samples.

For MinHash, you are taking the set of all unique shingles (between the two documents) and trying measure 
the fraction that are common to both documents, which is defined to be the document similarity. If the 
fraction is p, a randomly selected shingle has probability p of being a common shingle, and probability 
1-p of being a non-common shingle -- this is known as a Bernoulli distribution. The standard deviation of 
a Bernoulli distribution is `sqrt(p* (1-p))`. So, the average of N Bernoulli samples will have a normal 
(bell-shaped) distribution with standard deviation `sqrt(p*(1-p)/N)`. But, we don't know p -- that's what 
we are trying to measure. The largest possible value for the standard deviation occurs when p=0.5, so we 
know the standard deviation is at most 0.5/sqrt(N). To have 95% confidence that the true value is within 
our estimated range, the range should be plus or minus 2 standard deviations. So, a conservative estimate 
for the uncertainty in our result is plus or minus 1/sqrt(N).

If we take N=200, our result is plus or minus 1/sqrt(200) = 0.07. So, if 100 or our 200 sampled shingles 
are common to both documents we know that p is in the range 0.43 to 0.57. If p is close to 0 or 1 the error 
bar will actually be smaller than 0.07, but we don't know that will be the case when we pick N. If we took 
four times as many samples the error bar would only be cut in half due to the sqrt.

Useful references:
http://en.wikipedia.org/wiki/Central_limit_theorem
http://en.wikipedia.org/wiki/Bernoulli_distribution
http://en.wikipedia.org/wiki/68–95–99.7_rule

http://matthewcasperson.blogspot.com/2013/11/minhash-for-dummies.html

# Simhash Random projections

* N points  
* d dimensions  
* k hyperplanes  
* L repetitions  

Repeat the following procedure L times
1. Generate random hyperplanes h1, ... hk
2. To generate hash code ?
     Set k_th bit of hashcode = 0  if p.h_k < 0 where h_k is a hyperplane
                              = 1  if p.h_k > 0

Average points in a bucket = N/2^k

# Ref

https://www.youtube.com/watch?v=NJaJrVF__B4
