
# perplexity

* 2^entropy
* effective number of neighbours

lower is better

lower perplexity = higher probability

In machine learning, the term perplexity has three closely related meanings. 
1. Perplexity is a measure of how easy a probability distribution is to predict. 
2. Perplexity is a measure of how variable a prediction model is. 
3. Perplexity is a measure of prediction error. The third meaning of perplexity is calculated slightly differently but all three have the same fundamental idea.

Models with lower perplexity have probability values that are more varied, and so the model is making “stronger predictions” in a sense.
```

## References

1. https://jamesmccaffrey.wordpress.com/2016/08/16/what-is-machine-learning-perplexity/

# Perplexity

perplexity must be evaluated relative to vocab size, context length

context length is inversely proportional to cross-entropy

Given empirical distribution P

and distribution Q learned by neural model

cross entropy(p, q) = H(P) empirical distribution + kl_divergence(p || q)

cross entropy loss >= H(P)

H(P) <= Log(|V|) = log(num of unique words) = word level entropy

perplexity of SOTA neural models still less than n-gram models


## references

1. https://thegradient.pub/understanding-evaluation-metrics-for-language-models/
