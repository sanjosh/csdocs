
https://julialang.org/blog/2019/01/fluxdiffeq/

three common ways to define a nonlinear transform: 
1. direct modeling : write the function closed form
2. machine learning : learn the function (universal approximator)
3. differential equations : 

differential equations as way to specify prior in DNN

A neural network layer is really just a differentiable function which takes in a vector of size n and spits out a new vector of size m.

Neural ODE 

Instead of learning the nonlinear transformation directly, we wish to learn the structures of the nonlinear transformation. 

Thus instead of doing y = ML(x), we put the machine learning model on the derivative, y'(x) = ML(x) and now solve the ODE.

this gives a residual neural network

Rather than adding more layers, we can just model the differential equation directly and then solve it using a purpose-built ODE solver

 if we stick an ODE solver as a layer in a neural network, we need to backpropagate through it.
