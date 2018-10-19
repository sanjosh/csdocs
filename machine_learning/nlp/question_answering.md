
# Question answering systems

Read text, read question, then revisit all pages in the book

# Augmented RNN with memory
1. Memory network : Western & fb
2. Neural turing machine : deepmind
3. Dynamic memory network : richard socher
4. Stack-augmented RNN : fb

At any point in time, Controller can read/write from Memory Bank

if you don't read all memory bank, then algo is hard to train since it is not differentiable, 

# Augment RNN with operations (addition/mult/sin)

Given context and question, generate an answer
e.g. Building was built in 2010, collapsed in 2012.  How many years did building last

Can neural net do addition ?
Yes, Push numbers into stack

(Quoc Le, Sequence to Sequence Deep Learning, https://www.youtube.com/watch?v=G5RY_SUJih4)

# Reference

1. Chris Olah blog.  Attention and Augmented Recurrent neural networks

