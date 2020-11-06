
# Alg geometric codes

Genus proportional to twistedness of curve

Hasse-Weil bound : high genus implies more rational points k

Riemann-Roch : small genus implies higher distance d 

as n->inf, we need k/n and d/n to increase

## All codes are alg geometric - Stichtenoth 

Given code C over Fq, one can find a function field F/Fq,   
a set of points of degree one,   
and a divisor G of F   
such that C <= C(G)

* Reed Solomon = code on line P1
* bicyclic = code on plane
* Generalized Reed Muller = code on affine space
* hermitian = code on curve

## Decoding algorithm (Skorobogatov-Vladut)

1. Calculate syndromes
2. Find error locator polynomial wrt syndromes
3. find error locations
4. calculate error values

