
# Hash function Types
* Conventional (collision resistant)
* Crypto
* Locality sensitive (cluster similar items)
* Perfect  
* Universal

# Conventional

### Fine tuned for
* Integers
* Strings

### Construction primitives
* Division
* Byte shift using middle square
* Multiplicative
* Additive

### Statistical tests
* Avalanche diagram
* Chi-square test
* Bit and bucket histogram


### Examples
* Jenkins
* City
* Murmur
* Bernstein
* FNV

# Crypto

### Construction primitives

* Merkle-Damgard construction

# Locality sensitive

### Examples

* Nilsimsa (locality sensitive)
* Simhash
* Minhash (set similarity)

# Perfect

# Universal

### Construction primitives
* Matrix method
* Multiplicative
* Tabulation hashing

### Examples

* Zobrist Hash (gaming - generate unique game position)

#	Fuzzy hash

### Examples
* Context triggered piecewise hash
* Semantic hash (map docs to a code)
* Geometric hash (detect image transformation)
* PhotoDNA

# gradations of hashing

https://github.com/facebook/ThreatExchange/blob/master/hashing/hashing.pdf

* Exact hash : MD5, Sha-256
* Syntactic : PhotoDNA, dHash, aHash, pHash, PDQ
* Deeper Syntactic : GIST, SIFT
* Semantic : ML algo

# Semantic Hashing

Using Autoencoders (Goodfellow, Deep Learning Chap 14, Salakhutdinov and Hinton , 2007b , 2009b )

for textual input (Salakhutdinov and Hinton , 2007b , 2009b ) 

for images (Torralba et al., 2008 ; Weiss et al., 2008 ; Krizhevsky and Hinton , 2011 ).

# Misc

* Rolling hash


