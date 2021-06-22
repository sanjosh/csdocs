# Intro

crypto = protocols, algorithms, primitives

# Boolean function

used for symmetric key crypto

three representations
1. Truth table
2. ANF
3. Walsh hadamard transform
4. graphs

## Walsh Hadamard transform

like fourier transform for discrete

Walsh coefficient can be atmost +/- exp(2, n)

strict avalance criterion

sequency is like frequency

https://en.wikipedia.org/wiki/Hadamard_transform

sympy.discrete.transforms.fwht

```
http://man.hubwiz.com/docset/SymPy.docset/Contents/Resources/Documents/_modules/sympy/discrete/transforms.html
```


## linear function

For 2-variable, there are 8 linear and affine
(00, 01, 10, 11)
0000
0101 -
0011 -
0110

1111 -
1010
1100
1001

there are 4 bent (0001, 0010, 0100, 1000)
every bent func in 2-ary has hamming weight of 1


For n binary variables, the total number of affine Boolean function is exp(2, n+1) out of which exp(2, n) are linear
The 16 affine Boolean functions for 3-variable are 0, 60, 90, 102, 150, 170, 204, 240, 15, 51, 85, 105, 153, 165, 195, 255
Out of which first eight are linear

For n = 4, there are 896 bent functions
(Climent, On the construction of bent functions of n + 2 variables from bent functions of n variables)

(Rout, Classification of Boolean Functions where Affine Functions are Uniformly Distributed)
https://arxiv.org/pdf/1303.3527.pdf

## affine function

linear cryptanalysis possible on affine function
 
## Balanced function

output has as many 0s and 1s 

need balanced to avoid correlation attack

## Bent function

maximally non-linear function

nonlinear = hamming distance between `function f` and set of affine functions

cannot be approximated by affine function

bent function have flat WHT spectrum ; absolute value of all Walsh coefficients is exp(2, n/2)

derivative of bent function is balanced function, hence cannot do differential cryptanalysis


### connection to graphs

as well connection to hadamard difference sets

bent function = strongly regular graph where e=d

https://www.sciencedirect.com/topics/computer-science/hadamard-matrix

## constructions

hard to find bent functions as variables increase.  need heuristic constructions

construct higher from lower

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

substitution, transposition, key mixing

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

## linear cryptanalysis

linear expression of plaintext + ciphertext + key occurs with low/high probability

introduced by Matsui at EUROCRYPT ’93

## differential cryptanalysis

Biham and Shamir at CRYPTO ’90 

specific output difference occurs for specific input difference with high probability (not 50 perc)

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
5. https://math.stackexchange.com/questions/415152/is-it-possible-to-derive-all-the-other-boolean-functions-by-taking-other-primiti
6. why xor is linear https://www.quora.com/Reason-why-XOR-is-a-linear-operation-but-ordinary-addition-isn-t
7. xor linear  https://crypto.stackexchange.com/questions/12634/reason-why-xor-is-a-linear-operation-but-ordinary-addition-isn-t
8. tokareva.  http://math.nsc.ru/~tokareva/
8. walsh transform https://in.mathworks.com/help/signal/ug/discrete-walsh-hadamard-transform.html
9. Mukhopadhyay http://cse.iitkgp.ac.in/~debdeep/courses_iitkgp/Crypto/slides/SBox.pdf
10. Heys.  Tutorial Linear and differential cryptanalysis
11. Mister, Adams. Practical S-box design 
12. Nyberg.  Perfect S-boxes
13. https://share.cocalc.com/share/2bb232d71b6e841b65867d04f1009ea1d65d7c18/useful_articles_for_designing_s-box%20/Cheung_Jennifer.pdf
14. Carlisle Adams.  Good S-boxes easy to find https://link.springer.com/content/pdf/10.1007/0-387-34805-0_56.pdf
15. Sasao.  Logic functions for cryptography - A tutorial
16. Universitetet i Bergen, Institutt for informatikk, Bergen, Norway. Online database of Boolean functions according to bentness, degree, correlation immunity, propagation criterion
http://www.selmer.uib.no/odbf/search.html
