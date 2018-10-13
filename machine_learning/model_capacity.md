

# Model capacity

Model Capacity is ability to fit a wide variety of functions

hypothesis space is the set of functions that learning algo used to select as the solution

It is changed by changing number of input features, and parameters associated with those features.

Statistical learning theory provides various means of quantifying model capacity.  Among these, the most well-known is the Vapnik-Chervonenkis dimension, or VC dimension. The VC dimension measures the capacity of a binary classifier. The VC dimension is defined as being the largest possible value of m for which there exists a training set of m different x points that the classifier can label arbitrarily.

(Deep Learning book, Goodfellow)

# VC dimension for characterizing classifiers

VC dim is measure of learning function's power.   It is indep of training set.

Shattering: Machine "f" can shatter a set of points if for every possible training set, there exiss some value of 'a' that gets zero training error.

VC Dim is max number of points that can be arranged so that function "f" can shatter them.

Vapnik showed that with some probability, Test error is bounded by Training Error and VC Dim

Test Error(a) <= Training Error(a) + Function(VC Dimension)

There exist methods to find VC dim for decision trees, perceptron, neural net, SVM

Use Structural risk minimization to find best learning machine

Create table of Training Error, VC Dim, Upper bound on Test Error

(Andrew Moore, VC Dim for characterizing classifiers, https://www.autonlab.org/_media/tutorials/vcdim08.pdf)

# Model selection methods

1. CV Cross validation
2. Akaike Information Criterion
3. Bayesian Information Criterion
4. Structural Risk Minimize with Vapnik-Chervonenkis Dimension
