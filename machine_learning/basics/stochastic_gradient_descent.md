
# Stochastic gradient descent

For a quick simple explanation:

   In both gradient descent (GD) and stochastic gradient descent (SGD), you update a set of parameters in an iterative manner to minimize an error function.

While in GD, you have to run through ALL the samples in your training set to do a single update for a parameter in a particular iteration, in SGD, on the other hand, you use ONLY ONE training sample from your training set to do the update for a parameter in a particular iteration.

Thus, if the number of training samples are large, in fact very large, then using gradient descent may take too long because in every iteration when you are updating the values of the parameters, you are running through the complete training set. On the other hand, using SGD will be faster because you use only one training sample and it starts improving itself right away from the first sample.

SGD often converges much faster compared to GD but the error function is not as well minimized as in the case of GD. Often in most cases, the close approximation that you get in SGD for the parameter values are enough because they reach the optimal values and keep oscillating there.

If you need an example of this with a practical case, check Andrew NG's notes here where he clearly shows you the steps involved in both the cases. http://cs229.stanford.edu/notes/...

Source:
http://www.quora.com/Machine-Learning/Whats-the-difference-between-gradient-descent-and-stochastic-gradient-descent

why gradient descent over newton-raphson
https://www.reddit.com/r/MachineLearning/comments/okficy/d_dominance_of_the_gradient_descent_over_other/

People here stick to the "number of parameters" argument but this is not a good explanation. This is because quasi-Newton methods exist and those typically work very well in high dimensions with comparably low memory footprint.

The real reason is that we do stochastic optimization. It is already difficult to estimate the derivative of a stochastic function, but the second derivative is a lot worse. Moreover, you can't get the same benefit anymore from using second order information as in the deterministic case. As soon as the gradient is stochastic one can't do better than sub-linear convergence and the only thing to gain is better constants.

Now, constants are important and it is extremely easy to break ML optimizers by using a badly conditioned function. But it turns out that apparently neural networks do not care as long as there are enough parameters that one can get approximately right.

//Edit: Note that as soon as you go away from neural networks, good optimizers are leading again. e.g. support vector machines should really not be optimized using SGD, PEGASOS is really bad compared to a half competetent ADMM or active set method (even SMO!)

https://stats.stackexchange.com/questions/253632/why-is-newtons-method-not-widely-used-in-machine-learning
