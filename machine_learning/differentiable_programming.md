
# Differentiable functional programming

Three narratives
1. Neuroscience
2. Representation : manifold
3. Probabilistic : find latent variables

Optimizing composed functions

Representations are types

Traditional
1. Feedforward
2. Convolutional
3. Recurrent

Newer additions
1. Neural Turing Machine (Graves et al., 2014) can infer algorithms: copy, sort, recall
2. Stack-augmented RNN (Joulin & Mikolov, 2015)
3. End-to-end memory network (Sukhbaatar et al., 2015)
4. Stack, queue, deque (Grefenstette et al., 2015)
5. Discrete interfaces (Zaremba & Sutskever, 2015)

correspondence between neural net and functional
1. Weight-typing = function abstraction
2. Encoding RNN = fold
3. Generating RNN = unfold
4. General RNN = Map
5. Bidirectional RNN = zip (mapAccum left) (mapAccum right)
6. CNN = map
7. Treenet Recursive neural net = catamorphism

## Reference

1. https://www.cs.nuim.ie/~gunes/files/Baydin-MSR-Slides-20160201.pdf
2. http://colah.github.io/posts/2015-09-NN-Types-FP/

# Swift


