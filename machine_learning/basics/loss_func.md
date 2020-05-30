
# Loss functions

compare y_actual with y_predicted

# Regression loss

## Mean squared/Quadratic/L2 (regression loss)

concerned with the average magnitude of error irrespective of their direction 
due to squaring, predictions which are far away from actual values are penalized heavily 

Mathematically, it is the preferred loss function under the inference framework of maximum likelihood if the distribution of the target variable is Gaussian.

## Mean error/L1 loss (regression loss)

measures the magnitude of error without considering their direction 
Unlike MSE, MAE needs more complicated tools such as linear programming to compute the gradients. 
MAE is more robust to outliers since it does not make use of square. 

# Binary Classification loss

## Binary hinge loss

It is intended for use with binary classification where the target values are in the set {-1, 1}.
The hinge loss function encourages examples to have the correct sign,

## Binary cross entropy

It is intended for use with binary classification where the target values are in the set {0, 1}.
Cross-entropy will calculate a score that summarizes the average difference between the actual and predicted probability distributions for predicting class 1. The score is minimized and a perfect cross-entropy value is 0.

## Hinge loss  (classification loss)

score of correct category should be greater than sum of scores of all incorrect categories by some safety margin (usually one).
used for max margin classification.  
for learning nonlinear embeddings or semi-supervised learning.
Although not differentiable, it’s a convex function which makes it easy to work with usual convex optimizers used in machine learning domain.

## Cross-Entropy/Negative log likelihood (classification loss)

for multi-class classification
penalizes heavily the predictions that are confident but wrong, by multiplying the log of the actual predicted probability for the ground truth class

## Sparse multiclass cross-entropy

if you have large number of labels, one hot encoding process can consume memory
Sparse cross-entropy addresses this by performing the same cross-entropy calculation of error, without requiring that the target variable be one hot encoded prior to training.

## KL-divergence loss

more commonly used when using models that learn to approximate a more complex function than simply multi-class classification, such as in the case of an autoencoder used for learning a dense feature representation under a model that must reconstruct the original input. 

## triplet loss 

between anchor, positive and negative loss

## CTC Loss 

align two sequences

## reconstruction loss 

in auto-encoder

## generalized end-to-end

## cycle consistency

for GAN

# Contrastive loss

Contrastive losses [29] measure the similarities of sample pairs in a representation space.  Instead of matching an input to a fixed target, in contrastive loss formulations the target can varyon-the-fly during training and can be defined in terms of the data representation computed by a network[29].   Contrastive learning is at the core of several recent works on unsupervised learning 

(Kaiming He, Momentum Contrast for Unsupervised Visual Representation Learning)

# Adversarial loss

Adversarial losses [24] measure the difference between probability distributions. It is a widely successful technique for unsupervised data generation 

(Kaiming He, Momentum Contrast for Unsupervised Visual Representation Learning)

# Noise resistant loss functions

Label noise

loss function based on mean absolute value of error is inherently robust to label noise.
(Aritra Ghosh, Robust Loss Functions under Label Noise for Deep Neural Networks)

# References

https://towardsdatascience.com/common-loss-functions-in-machine-learning-46af0ffc4d23

https://jamesmccaffrey.wordpress.com/2013/11/05/why-you-should-use-cross-entropy-error-instead-of-classification-error-or-mean-squared-error-for-neural-network-classifier-training/

"this is a key feature of multiclass logloss, it rewards/penalises probabilities of correct classes only. The value is independent of how the remaining probability is split between incorrect classes."

https://datascience.stackexchange.com/questions/20296/cross-entropy-loss-explanation

https://rdipietro.github.io/friendly-intro-to-cross-entropy-loss/

https://pytorch.org/docs/stable/nn.html#loss-functions

https://machinelearningmastery.com/how-to-choose-loss-functions-when-training-deep-learning-neural-networks/
