
# How to deal with non-differentiable functionns

## Reinforcement learning: 

if your problem can be framed as training an agent to take the best actions in an environment where the actions consequences are perfectly known and can be easily measured, reinforcement learning may be relevant. It’s very hard to get right (https://www.alexirpan.com/2018/02/14/rl-hard.html), but some impressive successes (https://www.theverge.com/2019/10/30/20939147/deepmind-google-alphastar-starcraft-2-research-grandmaster-level) have been achieved.


## Differentiable approximation: 

if your function is not too long to evaluate, you can treat it as a black box, generate large amounts of inputs/outputs, and use this as a training set to train a neural network to approximate the function. Since neural networks are themselves differentiable, you can use the resulting network as a differentiable loss function (don’t forget to freeze the network weights). This approach has been used among other things for differentiable rendering (http://hiroharu-kato.com/projects_en/neural_renderer.html). It’s a very powerful approach since it’s possible to obtain a differentiable approximation of the loss function of interest, even in cases where the loss function is not differentiable.


## Manual gradient computations: 

if you’re motivated and are familiar with the specific problem at hand, you can design custom tensorflow (https://www.tensorflow.org/guide/create_op) or pytorch (https://pytorch.org/docs/stable/notes/extending.html) operators, and provide the gradients yourself. Tensorflow Graphics (https://www.tensorflow.org/graphics) uses this for their differentiable OpenGL renderer.


## Automatic Differentiation: 

If you have access to the source code of the software that computes your function of interest, you can use automatic differentiation tools (Autograd (https://github.com/HIPS/autograd), tangent (https://github.com/google/tangent) etc) to make it differentiable. At the end of the day, any software only computes lots of basic operations on the CPU/GPU, that are all differentiable. Usually those automatic differentiation (https://en.wikipedia.org/wiki/Automatic_differentiation) libraries use source code transformation or operator overloading to compute the gradients.

### Ref 

1. https://fruty.io/2019/11/04/deep-learning-in-the-real-world-how-to-deal-with-non-differentiable-loss-functions/
