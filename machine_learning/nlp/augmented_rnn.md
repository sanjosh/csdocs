
# Augmented RNN (Greffenstette)

Talk at deep learning school 2016

Computational (Chomsky) hierarchy
1. FSM (regular lang) : memory is finite
2. Pushdown automata (context free lang) : operations are limited
3. Turing machine (computable func) :  FSM + tape + back/front operations

RNN good because
1. RNN fit variable width problems
2. unfold to feedforward nets with shared weights
3. can capture long(ish) dependencies

Natural language is at least context free (need at least a PDA)

RNN can express/approx Turing machine

But expressivity is NOT learnability
1. RNN does not control Turing tape
2. Max likelihood objective produces Model which is close to training distribution.
3. RNN act as both controller & memory
4. need more memory for dependency tracking of higher order

RNN are more like approx to FSM

Think of RNN as API rather than model (prev state, next state) with differentiable constraint.  

Then create arbitrary nesting of Recurrent Cells (stack, queue, deque).

Split controller and memory

Create Neural PDA

# Recurrent Neural Networks and Models of Computation (Grefensttete)

talk at Turing institute 2018
https://www.youtube.com/watch?v=OWZ3mtzpn7g

Language modeling as task of maximize joint Probability
P(t1, t2, t3) = P(t3 | t1, t2). P(t2 | t1)

LSTM make good local language model

Fail at Topical consistency, Relational consistency 

Transduction bottleneck in sequence to sequence model
1. Non adaptive capacity
2. target sequence model dominates training
3. gradient starved encoder (gradient from decoder does not flow to encoder)
4. Fixed size

Augmentations
1. Attention as Read only memory - Early fusion or late fusion
2. Register memory as RAM : neural turing machine; memory networks
3. Neural stack 

These augmentation come closer to PDA

# Memory networks (Weston)

Hard attention memory network by Weston, Chopra, Bordes ICLR 2015

1. hard attention
2. needed supervision on attention

# End to end Memory networks

Question answering task

Propose mem net MemN2N
1. Read mem with soft attention
2. perform multiple lookups on mem
3. end to end training with backprop

* memory module : has unordered set of vectors
* controller module : internal state

to record sentence, take sum of word vectors and embed as memory vector

to enforce temporal structure, add time embedding vector

https://github.com/facebook/MemNN

# Sukhbaatar, Szlam, Weston, Fergus. End-To-End Memory Networks 2015

https://www.youtube.com/watch?v=ZwvWY9Yy76Q

# RNNsearch (Bahdanau)

Bahdanau 2015

# Dynamic memory networks (Kumar)

Richard Socher
Bay Area Deep Learning school
https://youtu.be/oGk1v1jQITw?t=2791

Can all NLP problems be seen as Question Answering tasks ?

1. sentiment analysis (sst) : tree lstm (Tai 2015)
2. question answering (babl) : supervised MemNN (Weston 2015)
3. pos tagging : bidirectional LSTM-CRF (huang 2015)

Dynamic Memory networks : generic architecture for all kinds of QA
1. Episodic Memory 
2. Semantic Memory
3. Input Module
4. Answer Module
5. Question Module

GRU is basic block; word2vec used for representation

# Teaching machines to read and comprehend - Hermann 2015

# Attentive reader (Hermann 2015)

# Stacks Queues and Double Ended Queues (Grefenstette NIPS 2015)

# Stacks Lists (Joulin Mikolov NIPS 2015)

# Stack LSTMs (Dyer)

# Neural Turing machine (Graves)

# Sieglemann and Sontag 1995


