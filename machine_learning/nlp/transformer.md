
# hugging face

Each of these parts can be used independently, depending on the task:

1. Encoder-only models: Good for tasks that require understanding of the input, such as sentence classification and named entity recognition.
1. Decoder-only models: Good for generative tasks such as text generation.
1. Encoder-decoder models or sequence-to-sequence models: Good for generative tasks that require an input, such as translation or summarization.

Encoder models use only the encoder of a Transformer model. At each stage, the attention layers can access all the words in the initial sentence. These models are often characterized as having “bi-directional” attention, and are often called auto-encoding models.

Encoder models are best suited for tasks requiring an understanding of the full sentence, such as sentence classification, named entity recognition (and more generally word classification), and extractive question answering.


Decoder models use only the decoder of a Transformer model. At each stage, for a given word the attention layers can only access the words positioned before it in the sentence. These models are often called auto-regressive models. These models are best suited for tasks involving text generation.




Sequence-to-sequence models are best suited for tasks revolving around generating new sentences depending on a given input, such as summarization, translation, or generative question answering.




https://huggingface.co/course/chapter1/4?fw=pt

# Transformer

encoder-decoder

1. For each word, create Query, Key and Value vectors. their dim is smaller than dim of embedding vector
2. score = dot product(query vector of current, key vector of every word)
3. multiply each value vector by softmax
4. sum up weighted value vectors

Output of encoder = Attention vectors K & V

## Transformer talk

Leo Dirac 

13 min : pseudo-code of attention  
20 min : why RELU better

https://www.youtube.com/watch?v=S27pHKBEp30

## Multi head attention (learn multiple things)

do attention 8 times with different Q, K, V matrices  

lets network learn 8 different semantic meanings : grammar, vocab, conjugation  

## Positional encoding (learn position; overcome bag of words problem)

https://jalammar.github.io/illustrated-transformer/

https://arxiv.org/abs/1706.03762

16 min : used Fourier; added word embedding and position embedding

this lets the model reason above position

https://www.youtube.com/watch?v=S27pHKBEp30

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


# How transformers workk

https://theaisummer.com/transformer/


# References

1. http://jalammar.github.io/illustrated-bert/
2.  https://news.ycombinator.com/item?id=18751469
3. https://thegradient.pub/nlp-imagenet/
