
GENERALIZATION THROUGH MEMORIZATION: NEAREST NEIGHBOR LANGUAGE MODELS
Urvashi Khandelwal†∗, Omer Levy‡ , Dan Jurafsky† , Luke Zettlemoyer‡ & Mike Lewis

https://arxiv.org/pdf/1911.00172.pdf

We introduce kNN-LM, an approach that extends a pre-trained LM by 
linearly interpolating its next word distribution with a k-nearest neighbors (kNN) model. 
The nearest neighbors are computed according to distance in the pre-trained embedding space 
and can be drawn from any text collection, including the original LM training data. 
This approach allows rare patterns to be memorized explicitly, rather than implicitly in 
model parameters. It also improves performance when the same training data is used 
for learning the prefix representations and the kNN model
