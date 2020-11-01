
# Generative models

capture dependence between dimensions; provides way to generate new datapoints

use of generative models  
1. density estimation and outlier detection : use the captured distribution
2. data compression (duality between them): use arithmetic coding to produce compressor
3. mapping from one domain to another :
4. planning in model-based reinforcement learning?
5. representation learning
6. understanding data

# Types of generative models  

## autoregressive : 

example is RNN, Wavenet

joint distribution defined in terms of simpler conditional distribution

suffer from slow sequential generation

## latent variable model 

example is VAE 

* joint distribution defined in terms of latent variables
* trained with max likelihood
* require inference to determine latent variable dependency

* p(z) = prior for latent variable
* p(x|z) connects latent variable to the observation
* joint distribution p(x, z) = p(x|z).p(z)
* marginal likelihood p(x)
* posterior p(z | x)

Inference = compute posterior p(z|x) given observation x

for that we first compute p(x)

max likelihood : chose parameter values that maximize probability of the training set under the model

no closed form solution therefore use iterative algorithm like EM or gradient descent

tractable inference is possible even though exact inference hard
1. mixture model
2. linear gaussian model
3. invertible model (normalizing flow)

Do you want the wrong answer to the right question or the right answer to the wrong question? --David Blei

## implicit 

subdivided into tractable (glow) and intractable (VAE)

example is GAN 

training is based on adversary rather than max likelihood

map noise vector to observations

cannot be used for compression or outlier detection

suffer from mode collapse - where model ignores some part of training data

optimizartion is saddle point


# Conditional generative models


https://storage.googleapis.com/deepmind-media/UCLxDeepMind_2020/L11%20-%20UCLxDeepMind%20DL2020.pdf

https://www.youtube.com/watch?v=7Pcvdo4EJeo&list=PLqYmG7hTraZCDxZ44o4p3N5Anz3lLRVZF&index=12&t=0s
