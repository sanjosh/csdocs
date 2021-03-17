
# Xavier initialization

# convolution instead of fully connected

So what happened in 2012 that changed the world of machine vision? The answer is
a technique called deep convolutional neural networks which the Super Visison
algorithm used to classify the 1.2 million high resolution images in the dataset
into 1000 different classes.

While traditional multilayer perceptron (MLP) models were successfully used for
image recognition, due to the full connectivity between nodes they suffer from
the curse of dimensionality and thus do not scale well to higher resolution
images.

Using convolution instead of fully connected layers you reduce number of free
parameters, save computations, achieve multi-resolution and shift-invariance.

Convolution can be thought of a filter that finds relationships between neighboring inputs.

# References
1. https://en.wikipedia.org/wiki/Convolutional_neural_network
2. https://www.quora.com/How-do-convolutional-neural-networks-work
3. https://www.quora.com/What-is-an-intuitive-explanation-of-Convolutional-Neural-Networks
4. https://www.quora.com/Are-convolutional-neural-networks-related-to-the-convolution-of-two-functions-in-mathematics
5. http://www.wildml.com/2015/11/understanding-convolutional-neural-networks-for-nlp/
