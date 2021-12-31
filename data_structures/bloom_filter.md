
# Bloom filters

# Original

Hash functions need to be independent and uniformly distributed

Parameters
Filter size (number of bits)
Number of hash functions to use

False positive error rate = F(size of filter, number of inserted element, number of hash functions)

Code reference

https://github.com/adobe/chromium/blob/master/chrome/browser/safe_browsing/bloom_filter.cc
rocksdb
Serialization support

# Quotient filter

Support deletion

# Cuckoo filter

Permit deletion

# Spectral Bloom filter

support estimates of frequencies
Replace bit vector with a vector of M counters.

# Attenuated Bloom filter

Keep arrays of Bloom filters to store shortest path distance information

# Bloomier filter

associate values with a subset of the domain elements
Must know entire set S upon creation

https://github.com/egrim/java-bloomier-filter

https://arxiv.org/abs/0807.0928

Slide 90 onwards
http://cs.unc.edu/~fabian/courses/CS600.624/slides/bloomslides.pdf

# Counting Bloom filter

Support deletion
Each entry is not a bit but a counter

# Count-Min sketches

track counts associated with items,

Same as Counting Bloom filter.  However, they are used differently and therefore sized differently: a count-min sketch typically has a sublinear number of cells, related to the desired approximation quality of the sketch, while a counting Bloom filter is more typically sized to match the number of elements in the set.


# Blocked Bloom filter


An array of small Bloom filters, each fitting in one CPU cache line. Each item is stored in only one of these small Bloom filters determined by hash partitioning

# Multistage filters 

track counts associated with items

the memory needs to scale inversely with the threshold percentage and directly with the oversampling factor

 C. Estan and G. Varghese, New directions in traffic measurement and accounting: Focusing on the elephants, ignoring the mice
Approximate concurrent state machines 

track the dynamically changing state of a changing set of items.
return false positives, false negatives, or a “don’t know” response


F. Bonomi, M. Mitzenmacher, R. Panigrahy, S. Singh, and G. Varghese, Beyond Bloom filters: From approximate membership checks to approximate state machines, Proc 2006 ACM SIGCOMM, 2006, pp. 315–326.

# Retouched bloom filter

retouched Bloom filters trade off false positives and false negatives

# Golomb-Compressed Sequence 

stores all items’ fingerprints in a sorted list.

# D-Left counting bloom filter

Use D-left hashing

# Compressed Bloom filter

Optimized for network transmission

Count min sketch

Space code bloom filter

Measure approx size of traffic flows

Use Maximum Likelihood Estimation (MLE) or Mean Value Estimation (MVE) to estimate multiplicity of y

# Hierarchical Bloom filter

Support substring matching

Block based Filter (BBF) : Break string into blocks.   Hash each block
During query, query using various offsets upto the block size

What is hashed ?

* Block digest  : hash (content)
* Offset digest : hash(content + offset)
* Payload digest : hash (content + offset + IP)

A Hierarchical Bloom filter (HBF) is simply a collection of BBFs for geometrically increasing block sizes

# Adaptive Range filter

Adaptive Range Filters for Cold Data:
Karolina Alexiou Systems Group, ETH Zurich Zurich, Switzerland kalexiou@student.ethz.ch Donald Kossmann∗ Systems Group, ETH Zurich Zurich, Switzerland donaldk@ethz.ch Per-˚Ake Larson

https://www.microsoft.com/en-us/research/wp-content/uploads/2013/09/p1714-kossmann.pdf

# ribbon filter

http://rocksdb.org/blog/2021/12/29/ribbon-filter.html

https://arxiv.org/abs/2103.02515

# False positives : elimination techniques

Keep a small number of troublesome false positives

# Applications

Inner product of two bloom filter arrays = measure of similarity
To halve the size of the filter, just OR the first and second halves together. When hashing to do a lookup, the highest order bit can be masked.
A Bloom filter that represents the union of two sets can be obtained by taking the OR of the two bit vectors of the original Bloom filters.




