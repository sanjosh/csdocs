
# symbolic regression

1. genetic algorithms or sparse regression 
2. equation discovery : use domain knowledge to constrain space of possible equations
3. GNN and replace each internal function with analytic expression

# Discovering Symbolic Models from Deep Learning with Inductive Biases

Miles Cranmer, Alvaro Sanchez-Gonzalez, Peter Battaglia, Rui Xu, Kyle Cranmer, David Spergel, Shirley Ho

the deep model’s job is not only to predict targets, but to do so while broken up into small internal functions that operate on low-dimensional spaces.

encourage sparsity in the latent representations inside the neural net

Symbolic regression then approximates each internal function of the deep model with an analytic expression

use GNN

By encouraging the messages in the GNN to grow sparse, we lower the dimensionality of each function. This makes it easier for symbolic regression to extract an expression.


```
We emphasize that this method is not a new symbolic regression technique by itself; rather, it is a
way of extending any existing symbolic regression method to high-dimensional datasets by the use of
a neural network with a well-motivated inductive bias

While training, we encourage the model to use compact internal representations for latent 
hidden features (e.g., messages) by adding regularization terms to the loss
```

https://arxiv.org/pdf/2006.11287.pdf

packages : eureqa, PySR

https://github.com/MilesCranmer/SymbolicRegression.jl


# Rediscovering orbital mechanics with machine learning

Pablo Lemos, Niall Jeffrey, Miles Cranmer, Shirley Ho, Peter Battaglia
https://astroautomata.com/paper/rediscovering-gravity/

First, we train a neural network to model the dynamics of a system. 
we initialize trainable variables representing physical parameters of the system

Second, we distill this neural network into a simple symbolic rule using symbolic regression (with PySR).

messiness of the real world: noise, missing information, large dynamic ranges, unknown physical constants,

Our learned model is a Graph Neural Network (GNN) based on the “Interaction Network” defined in Battaglia et al., 2018,

# Probabilistic Grammars for Equation Discovery

Brence
https://arxiv.org/pdf/2012.00428.pdf

propose the use of probabilistic context-free grammars in equation discovery

we are interested in using grammars as generative models
