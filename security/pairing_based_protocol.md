
# Pairings based protocol

1. Discrete log problem : given P and Q, find x such that Q = xP.
1. Diffie Hellman problem : given P, aP, bP - find K = abP

Diffie-Hellman used to construct two-party one-round key agreement protocol

Can there be a three-party one-round key agreement protocol? Yes, use Bilinear mapping (Joux)

1. Bilinear Diffie-Hellman problem : given P, aP, bP, cP, abP, acP, bcP : find K = abcP

Applications

## Joux’s key agreement protocol, 

## Boneh-LynnShacham short signature scheme, 

Unlike ElGamal, this uses a single group element

## Boneh-Franklin identity-based encryption scheme.

## reference

Menezes, An Introduction to Pairing-Based Cryptography

https://crypto.stackexchange.com/questions/12357/advantages-of-bilinear-map

## TODO

Galbraith, “Pairings”, Ch. IX of I. Blake, G. Seroussi and N. Smart, eds., Advances in 
Elliptic Curve Cryptography, Cambridge University Press, 2005.

Paterson, “Cryptography from pairings”, Ch. X of I. Blake, G. Seroussi and N. Smart,
eds., Advances in Elliptic Curve Cryptography, Cambridge University Press, 2005.

