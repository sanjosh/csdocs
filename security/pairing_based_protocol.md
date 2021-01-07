
# Bilinear maps OR pairings 

Allow for three-party protocols

before pairings
1. Discrete log problem : given P and Q, find x such that Q = xP.
1. Diffie Hellman problem : given P, aP, bP - find K = abP

Diffie-Hellman was used to construct two-party one-round key agreement protocol

Can there be a three-party one-round key agreement protocol? Yes, use Bilinear mapping (Joux)

1. Bilinear Diffie-Hellman problem : given P, aP, bP, cP, abP, acP, bcP : find K = abcP

# examples of pairings

## Weil pairing

## Tate pairings 

## simplest

e(X, Y) = g^XY mod p

https://stackoverflow.com/questions/5293873/need-information-on-bilinear-maps


# Applications

## Joux’s key agreement protocol, 

Given 
1. Group G of prime order q
2. mapping e : G x G -> G2
3. g = generator of G

1. Alice picks a and transmits g^a
1. Bob picks b and transmits g^b
1. Carol picks c and transmits g^c

1. Alice computes e(g^b, g^c)^a = g^(abc)
1. Bob computes e(g^a, g^c)^a = g^(abc)
1. Carol computes e(g^b, g^a)^a = g^(abc)


Bilinear Mapping "e" helps because it let you get g^bc from g^b and g^c
and regular exp obtains g^abc from g^bc and g^a

But man-in-middle observer cannot do the same.
* cannot use "e" to get g^abc from g^a, g^b, g^c
* because e(g^a, e(g^b, g^c)) = e(g^a, g'^bc) is not g'abc


## Boneh-LynnShacham short signature scheme, 

Unlike ElGamal, this uses a single group element

## Boneh-Franklin identity-based encryption scheme.

## reference

1. Menezes, An Introduction to Pairing-Based Cryptography
1. https://crypto.stackexchange.com/questions/12357/advantages-of-bilinear-map
1. John Bethencourt. Introduction to bilinear maps https://people.csail.mit.edu/alinush/6.857-spring-2015/papers/bilinear-maps.pdf
1. https://www.researchgate.net/post/Can-anyone-give-the-numerical-example-for-Bilinear-Pairing-Based-Cryptography-to-understand-the-concept-of-bilinear-pair
1. Ben Lynn.  Implementation of pairing based cryptosystem ON THE IMPLEMENTATION OF PAIRING-BASED CRYPTOSYSTEMS
1. McCullagh. Thesis Cryptographic applications of bilinear maps 
1. https://crypto.stackexchange.com/questions/27355/simple-example-to-describe-bilinear-mapping
1. https://stackoverflow.com/questions/5293873/need-information-on-bilinear-maps
1. https://math.stackexchange.com/questions/1380004/simple-example-for-bilinear-mapping


## TODO

Galbraith, “Pairings”, Ch. IX of I. Blake, G. Seroussi and N. Smart, eds., Advances in 
Elliptic Curve Cryptography, Cambridge University Press, 2005.

Paterson, “Cryptography from pairings”, Ch. X of I. Blake, G. Seroussi and N. Smart,
eds., Advances in Elliptic Curve Cryptography, Cambridge University Press, 2005.

