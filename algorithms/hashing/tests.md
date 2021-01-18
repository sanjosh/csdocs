
# Tests

## bit histogram

do all output bits change randomly ?

graph of P(bit=1) on Y-axis versus each output bit on X axis

ideal is that all bits are at P(X=1) = 0.5

## bucket histogram (behaviour with different number of buckets)

for varying modulus

graph of items per bucket (y-axis) vs number of buckets (x-axis)

ideal is uniform distribution - line

## statistical goodness (The chi-square test)

determine if an observed probability distribution is the same as an expected (and known) distribution. 

Is the number of items per bucket is distributed uniformly randomly ?

* Number of items = M
* number of buckets = N
* expected number of items in bucket E_i = M/N
* Observed O_i = 

chi^2=  Sum (i = 0, N-1) (O_i - E_i)^2/E_i

compare this with chi-square distribution with N degree of freedom

p-value

# Ref

Steven Pigeon


https://hbfs.wordpress.com/2015/09/29/hash-functions-part-i/

https://hbfs.wordpress.com/2015/10/06/the-anatomy-of-hash-functions-hash-functions-part-ii/

https://hbfs.wordpress.com/2015/10/13/testing-hash-functions-hash-functions-part-iii/

https://hbfs.wordpress.com/2015/10/20/three-bad-functions-hash-functions-part-iv/

https://hbfs.wordpress.com/2015/10/27/three-somewhat-better-functions-hash-functions-part-v/

https://hbfs.wordpress.com/2015/11/17/and-a-good-one-hash-functions-part-vi/

https://hbfs.wordpress.com/2008/08/12/bit-blenders-move-bits-around-quite-a-bit/

https://hbfs.wordpress.com/2011/11/08/mild-obfuscation/
