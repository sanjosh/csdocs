
# Question answering systems

Read text, read question, then revisit all pages in the book

## Open-domain QA

### Retrieval-based QA

retrieve potentially relevant documents from a knowledge corpus, and use a reading comprehension system to extract answers

1. retrieval is done using bag of words, or MIPS index

## Fact verification

### Generation based QA

sequence prediction task: simply encode the question, and then decode the answer token-by-token based on the encoding

# systems/papers

## Augmented RNN with memory

1. Memory network : Western & fb
2. Neural turing machine : deepmind
3. Dynamic memory network : richard socher
4. Stack-augmented RNN : fb

At any point in time, Controller can read/write from Memory Bank

if you don't read all memory bank, then algo is hard to train since it is not differentiable, 

## Augment RNN with operations (addition/mult/sin)

Given context and question, generate an answer
e.g. Building was built in 2010, collapsed in 2012.  How many years did building last

Can neural net do addition ?
Yes, Push numbers into stack

(Quoc Le, Sequence to Sequence Deep Learning, https://www.youtube.com/watch?v=G5RY_SUJih4)

## MemNN

## Dynamic Memory network

### Reference

1. Chris Olah blog.  Attention and Augmented Recurrent neural networks
2. babl  https://youtu.be/oGk1v1jQITw?t=3741 (Socher, Deep learning bay area 2016)


## Realm by Google

traditional NN store knowledge implicitly inside the parameters; storage space limited by model size

retrieve-then-predict
1. knowledge retriever model
2. knowledge-augmented encoder model

useful For open-domain QA

train the retriever using a performance-based signal from unsupervised text:

a retrieval that improves the language model’s perplexity should be rewarded, while an uninformative retrieval should be penalized

during training, MIPS index is refreshed using model parameters

https://ai.googleblog.com/2020/08/realm-integrating-retrieval-into.html

https://arxiv.org/abs/2002.08909

## Retrieval augmented generation by Facebook

https://research.fb.com/publications/retrieval-augmented-generation-for-knowledge-intensive-nlp-tasks/

1. parametric memory is a pre-trained seq2seq model 
2. non-parametric memory is a dense vector index of Wikipedia, accessed with a pre-trained neural retrieve

jointly train the retriever and generator components without any direct supervision on what document should be retrieve

