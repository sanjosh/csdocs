
# Conditional Random fields

1. define many feature functions : how likely is current word an adjective ?

F : (sentence, word pos, current word label, prev word label) -> score

2. assign weight to each feature functions

3. transform scores into probabilities by exp and normalize

4. train CRF using gradient descent

5. predict label using dynamic programming algo 

http://blog.echen.me/2012/01/03/introduction-to-conditional-random-fields/

```
Conditional random fields can be viewed as simplified versions of higher-order, conditional Boltzmann machines in which the hidden units have been eliminated. This makes the learning problem convex, but removes the ability to learn new features (Hinton, Boltzmann machines)
```

# Sutton and McCallum


http://homepages.inf.ed.ac.uk/csutton/publications/crftut-fnt.pdf

# applications

## named entity recognition

```
In HMM, your tag of the current word is dependent only on the tag of the previous word. 
And the current word is dependent on the current tag only. 

No such constraints for CRF, which makes it more flexible and powerful.
```
https://spoonshot.com/blog/2018/03/10/name-entity-recognition-using-crf/

# packages

pycrf

sklearn-crfsuite

# TODO

Xiao Li SigIR 2009 Extracting Structured Information from User Queries with Semi-Supervised Conditional Random Fields https://www.microsoft.com/en-us/research/publication/extracting-structured-information-from-user-queries-with-semi-supervised-conditional-random-fields/
