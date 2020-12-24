

## functional 

* with functional, decryption keys can reveal some partial information about the plaintext 
* with Homomorphic, you can compute arbitrary functions on encrypted data without decrypting that data

## identity based encryption

## attribute based encryption

## Inner product functional encryption (IPFE) 

multiple variants of IPFE 
1. multi-clients, 
2. multi-inputs, 
3. decentralized, 
4. function hiding

given
* Master public key mpk
* evaluation key z_y
* vector a
* vector y

proc
1. use mpk to encrypt "a"
2. use z_y to compute inner product "a.y" using (y, mpk(a)) - without knowing "a".

## searchable PKE

# ref

https://research.kudelskisecurity.com/2019/11/25/forget-homomorphic-encryption-here-comes-functional-encryption/

https://en.wikipedia.org/wiki/Functional_encryption

Boneh, Functional encryption https://eprint.iacr.org/2010/543.pdf

FENTEC project
