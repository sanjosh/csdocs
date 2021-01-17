
# property-preserving encryption

Introduced Pandey and Rouselakis

## order preserving (OPE)

possible to compare 2 ciphertext

Agrawal, R., Kiernan, J., Srikant, R., Xu, Y.: Order-preserving encryption for numeric data. In: SIGMOD, pp. 563–574 (2004)

used for range queries, sorting queries, searching queries

indistinguishability under an ordered chosen plaintext attack

examples
1. Cryptdb
1. SkyHigh networks

## order revealing (ORE)

generalizes order preserving

ciphertexts are numeric-valued, and the ordering of the underlying plaintexts is determined by numerically comparing the ciphertexts

Boneh, D., Lewi, K., Raykova, M., Sahai, A., Zhandry, M., Zimmerman, J.: Semantically secure order-revealing encryption: multi-input functional encryption without obfuscation

# searchable symmetric encryption

# oblivious RAMs

http://esl.cs.brown.edu/blog/how-to-search-on-encrypted-data-oblivious-rams-part-4/

# secure two-party computation

# searchable symmetric

Tony Arcieri
https://www.youtube.com/watch?t=545&v=LhSB98nZllk&feature=youtu.be

# differential privacy

# functional encryption

PEKS

# homomorphic encryption

## partially homomorphic

only one operation, either addition or multiplication, can be performed an unlimited number of times on the ciphertext.

add or multiply two ciphertext

## somewhat homomorphic

supports select operation (either addition or multiplication) up to a certain complexity, but these operations can only be performed a set number of times.

## fully homomorphic

arbitrary computation on ciphertext


### limitations

1. support for multiple users. need separate database per user.
2. large and complex algorithms homomorphically.  ratio of compute time for encrypted versus clear is high


# ref

https://www.venafi.com/blog/homomorphic-encryption-what-it-and-how-it-used

