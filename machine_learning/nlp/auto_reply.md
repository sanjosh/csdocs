
# Build auto-reply

sequence to sequence

use autodiff

better formulation @ 18 min

feed expected reply also to RNN

approaches
1. greedy decoding : for simple yes/no answer
2. beam search decoding (with pruning) : generate different types of answers generated and top-K selected
3. attention model : to solve the problem of using fixed-length vector for variable length input.  Can be used to make K-th predicted word depend on N-th input word by using softmax of each individual states to determine output.
4. deeper network : create stack of RNN

Questions
1. how to personalize : embed the user as a vector at beginning or end of RNN
2. feed noise ? @ 31 min
3. no post-processing grammar correction was done
4. some emails are too long for which you cannot auto-reply.  for this case, a threshold is used to decide.
5. if you have small dataset, you normalize; divide problem into smaller problems and train jointly with many other tasks.
6. how to handle Punctuation ? Put space between word and punctuation.
7. Out of vocab words : Use word segments or word/char hybrid instead of just words
8. Use gradient clipping to prevent explosion.
9. use LSTM or GRU 
10. Can we use global state ? maybe use reinforcement learning ? see facebook paper
11. Can we incorporate user input ?  yes, restrict beam search based on user input.

# Reference

1. Quoc Le.  Sequence to sequence deep learning. https://www.youtube.com/watch?v=G5RY_SUJih4
