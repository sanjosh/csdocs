
# Transformer

encoder-decoder

1. For each word, create Query, Key and Value vectors. their dim is smaller than dim of embedding vector
2. score = dot product(query vector of current, key vector of every word)
3. multiply each value vector by softmax
4. sum up weighted value vectors

Output of encoder = Attention vectors K & V

## Multi head attention

## Positional encoding

https://jalammar.github.io/illustrated-transformer/

https://arxiv.org/abs/1706.03762


# ELMO

1. Contextual word embedding
2. two layer bidirectional LSTM

# ULM-Fit

transfer learning

"A language model is an NLP model which learns to predict the next word in a sentence."

1. train a language model 
2. take this pretrained model’s encoder and combine it with a custom head model
3. do the good old fine tuning using discriminative learning rates in multiple stages carefully.

https://medium.com/mlreview/understanding-building-blocks-of-ulmfit-818d3775325b

http://nlp.fast.ai/classification/2018/05/15/introducting-ulmfit.html

# OpenAI transformer

1. only decoder from transformer
2. use input transformations to learn different tasks
3. Entailment input is "premise" + "hypothesis"
4. Sentence similarity is "text2+text1" and "text1+text2" fed in parallel

# BERT

1. Use encoders from transformer
2. Use WordPieces as input tokens instead of words
3. Masks

# References

1. http://jalammar.github.io/illustrated-bert/
2.  https://news.ycombinator.com/item?id=18751469
3. https://thegradient.pub/nlp-imagenet/
