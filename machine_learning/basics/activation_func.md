

## linear

## sigmoid

classification func with cross entropy loss

gradient comes close to 0 for high & low values making learning slow

## tanh

rescaled sigmoid

## ReLU

## Softmax

https://machinelearninginterview.com/topics/deep-learning/what-are-the-commonly-used-activation-functions-when-are-they-used/

---------------

1. sigmoid
2. ReLU
3. tanh
4. softmax
5. linear rectification (max{0, x})

https://towardsdatascience.com/activation-functions-neural-networks-1cbd9f8d91d6

---------------


1. sigmoid
2. hyperbolic tan (tanh)
3. linear rectification (max{0, x})

The former two choices are saturating activation functions because their derivatives approach zero as x → ±inf, which can cause gradient-based optimization algorithms to converge slowly. The derivative of the linear rectification function does not diminish as x → +inf, which helps avoid this “vanishing gradient problem” and often results in faster training and better performance (Nair & Hinton 2010). Neurons with this activation function are called rectified linear units (ReLU).  

(Shallue and Vanderburg, Exoplanets with deep learning)

---------------

Understanding Activation Functions using ReLU

https://www.youtube.com/watch?v=Qeorn8QvZFE
