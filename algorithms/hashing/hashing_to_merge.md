
# Conventional hash

## Properties

Diffusion

http://ticki.github.io/blog/designing-a-good-non-cryptographic-hash-function/

Confusion

## Construction

```
uint Hash(string s)
{
 uint hash = 0;
 foreach (char c in s)
 {
 hash = mix_with(hash) + combine(c)
 }
 return hash;
} 
```

## Mixing step

The input to the function is the current internal state and the output of the function becomes the new internal state.

Collisions are guaranteed not to happen if the mixing function is reversible, 

.... If the function is not reversible, it implies that there are at least two inputs that result in the same output.

## Combining step

https://burtleburtle.net/bob/hash/examhash.html

https://www.drdobbs.com/database/algorithm-alley/184410284

https://papa.bretmulvey.com/post/124027987928/hash-functions

https://papa.bretmulvey.com/post/124028832958/hash-functions-continued

http://www.partow.net/programming/hashfunctions/

## types

Integer

String

Bob Jenkins https://burtleburtle.net/bob/hash/doobs.html


## Tests

Avalanche

Chi-square

Is it fair ?

If it couldn't happen very often by chance then it is called statistically significant.

https://mste.illinois.edu/patel/chisquare/intro.html

https://en.wikipedia.org/wiki/Chi-squared_test

funnels https://burtleburtle.net/bob/hash/funnels.html

SmHasher https://github.com/aappleby/smhasher

https://github.com/aappleby/smhasher/blob/master/src/AvalancheTest.h#L2-L7

## Performance

practical 32-bit, 64-bit

## language

Java Hash (hashCode)
https://www.javamex.com/tutorials/collections/hash_function_guidelines.shtml

Python hash
https://github.com/python/cpython/blob/v3.6.5/Objects/dictobject.c#L132

## Variants

Know all the keys beforehand ? Perfect hashing
