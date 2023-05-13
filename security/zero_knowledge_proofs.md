
# how to log in without sending password

key properties between prover and verifier
1. completeness : honest prover will always pass test
2. soundness : malicious prover will fail test with high probability
3. zero knowledge : if prover is honest, verifier will learn nothing from protocol

every problem in NP has a zero knowledge proof



sumcheck protocol

## secure remote password protocol

## discrete log problem

```
tell (g)^x mod p = 1 without revealing x
```

x is your password

how to prove you know `x` without sending it to verified 

```
generate random number r
calculate C = (g)^r (mod p)
send C to verifier

verifier asks you what is (x+r)
w = (x+r) mod p
send w to verifier
Fermat's little theorem allows verifier to see that that (y.C mod p) = (g)^w (mod p)

verifier is not allowed to ask for r
```


## ref

https://www.youtube.com/watch?v=cI5lkif-V1c

