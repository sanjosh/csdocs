
# facebook MSU 

## fingerprint estimation network

Run image through fingerprint estimation network (FEN) to estimate details about the fingerprint left by the generative model. 

Used the properties of fingerprints as the basis for developing constraints to perform an unsupervised training. 

Put differently, we estimated fingerprints using different constraints based on properties of a fingerprint in general, 
including the fingerprint magnitude, repetitive nature, frequency range and symmetrical frequency response. 

We then used different loss functions to apply these constraints to FEN to enforce the generated fingerprints 
to have these desired properties. Once the fingerprint generation has been completed, the fingerprints can 
be used as inputs for model parsing.

## Model parsing 

uses estimated generative model fingerprints to predict a model’s hyperparameters, 
the number of layers of network, the number of blocks, and the types of operations used in each block

https://github.com/vishal3477/Reverse_Engineering_GMs

https://arxiv.org/abs/2106.07873

https://ai.facebook.com/blog/reverse-engineering-generative-model-from-a-single-deepfake-image/
