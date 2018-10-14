
# Conditional Random fields

1. define many feature functions : how likely is current word an adjective ?
F : (sentence, word pos, current word label, prev word label) -> score

2. assign weight to each feature functions

3. transform scores into probabilities by exp and normalize

4. train CRF using gradient descent

5. predict label using dynamic programming algo 

http://blog.echen.me/2012/01/03/introduction-to-conditional-random-fields/

# TODO

Xiao Li SigIR 2009 Extracting Structured Information from User Queries with Semi-Supervised Conditional Random Fields https://www.microsoft.com/en-us/research/publication/extracting-structured-information-from-user-queries-with-semi-supervised-conditional-random-fields/
