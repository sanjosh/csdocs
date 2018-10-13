
http://blog.echen.me/2012/01/03/introduction-to-conditional-random-fields/

1. define many feature functions : how likely is current word an adjective ?
F : (sentence, word pos, current word label, prev word label) -> score

2. assign weight to each feature functions

3. transform scores into probabilities by exp and normalize

4. train CRF using gradient descent

5. predict label using dynamic programming algo 
