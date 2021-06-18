# Intro

crypto = protocols, algorithms, primitives

# Boolean function

used for symmetric key crypto

three representations
1. Truth table
2. ANF
3. Walsh hadamard transform

## linear function

## affine function

linear cryptanalysis possible on affine function
 
## Balanced function

output has as many 0s and 1s 

need balanced to avoid correlation attack

## Bent function

maximally non-linear function

nonlinear = hamming distance between `function f` and set of affine functions

cannot approx by affine function

derivative of bent function is balanced function, hence cannot do differential cryptanalysis

### connection to graphs

and hadamard difference sets

bent function = strongly regular graph

https://www.sciencedirect.com/topics/computer-science/hadamard-matrix

## Walsh Hadamard transform

bent function have flat WHT spectrum

strict avalance criterion

https://en.wikipedia.org/wiki/Hadamard_transform

sympy.discrete.transforms.fwht

```
http://man.hubwiz.com/docset/SymPy.docset/Contents/Resources/Documents/_modules/sympy/discrete/transforms.html
```

## constructions

### Maiorana-McFarland

concatenation of affine functions


# Block cipher

1. Confusion : hide relation between cipher and key
2. diffusion : hide relation between cipher and plaintext

# P-box (permutation)

P-box provides diffusion


# S-box (substitution)

S-box provides confusion

its a lookup table

M x N box : where each output is boolean function of inputs

y(1) = f1(x1...xn)
y(m) = fm(x1...xn)

# Constructions

several rounds (repetitions) of weak block cipher = strong cipher

key schedule 
1. algo which derives key for each round
1. Key for each round = formed by selecting some N bits from the key

Always Mix the key and data : e.g. use XOR 

## Feistel

example : DES

why ? advantage that encryption and decryption are similar

## AES / Rijndael

1. byte shuffle and mixing provides diffusion
1. s-box provide confusion
1. XOR mixes key and data

## Twofish

S-boxes mutate : they are key-dependent

whitening : add key material to the data at start and end of cipher



# attacks

## parity attack

round can have even permutation or odd permutation

ideal block cipher only uses even permutation

## linear 

## differential

## known plaintext

plaintext and ciphertext are known

## chosen plaintext attack

plaintext is known

## chosen ciphertext attack

ciphertext is known

## related key attack

keys are related to each other

## weak keys

## timing attack

time taken depends on inputs, and you can figure out the key

# block cipher modes

what if your data is not equal to block size of cipher ?

## ECB

## CBC

How to choose C0 ? Initalization vector
1. Fixed IV
2. Counter IV
3. Random IV
4. Nonce-generated IV

## OFB Output feedback mode

## CTR mode


# summary

addition ? no, linear algebra
has to be reversible 
has to change with key : confusion
bit should not get stuck : diffusion
lookup table : key, plaintext -> ciphertext

# references

1. Ferguson, Cryptography engineering
2. https://www.umsl.edu/~siegelj/information_theory/projects/des.netau.net/Dataencryptionstandard.html
3. Amr Youssef, Boolean functions, https://www.fields.utoronto.ca/programs/scientific/07-08/cryptography/amr_youssef.pdf
4. T-79.5501 Cryptology  http://www.tcs.hut.fi/Studies/T-79.5501/2007SPR/lectures/boolean.pdf
