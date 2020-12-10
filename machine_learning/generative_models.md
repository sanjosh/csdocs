
# lecture notes

https://deepgenerativemodels.github.io/notes/
They are based on Stanford CS236, taught by Stefano Ermonand Aditya Grover, 

# Autoregressive generative models

an autoregressive model is merely a feed-forward model which predicts future values from past values.

You can have stable, parallel and easy-to-optimize training, faster inference computations, and completely do away with the fickleness of truncated backpropagation through time, if you are willing to accept a model that (by design) cannot haveinfinite memory

examples
1. PixelCNN
1. WaveNet
1. Transformer

Given previous values x1,x2,...,xt, these models do not output a valuefor x(t+1), they output the predictive probability distributionP(xt+1 | x1,x2,...,xt)

Autoregressive models are supervised

Autoregressive models work on both continuous and discrete data.

Autoregressive models are very amenable to conditioning.

Generating output sequences of variable length is not straightforward.

Autoregressive models can model multiple time scales

Recurrent models trained in practice are effectively feed-forward.This could happen either because truncated backpropagation through time cannot learn patterns significantly longer than kksteps, or, more provocatively, because models trainable by gradient descentcannot have long-term memory.

https://eigenfoo.xyz/deep-autoregressive-models/



