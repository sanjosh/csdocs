
https://ai.stanford.edu/blog/weak-supervision/

https://ai.googleblog.com/2019/03/harnessing-organizational-knowledge-for.html

https://hazyresearch.github.io/snorkel/

# Noisy labels

Frenay and Verleysen 2014

# Ways to deal with label noise

##  Label correction 

data cleaning

treat the (unknown) true labels as hidden variables and to estimate a generative or discriminative model.

One common approach is to correct noisylabels to their true labels via a clean label inference step us-ing complex noise models characterized by directed graphi-cal models [26], conditional random fields [23], neural net-works [11,24] or knowledge graphs [12]. These methodsrequire the support from extra clean data or an expensivedetection process to estimate the noise model. (Wang, Symmetric Cross Entropy for Robust Learning with Noisy Labels)

## Loss correction methods 

Noise-resistant loss function : loss function based on mean absolute value of error is inherently robust to label noise.
(Aritra Ghosh, Robust Loss Functions under Label Noise for Deep Neural Networks)

generalized cross entropy loss

Symmetric cross entropy

Label smoothing regularization

https://medium.com/towards-artificial-intelligence/how-to-use-label-smoothing-for-regularization-aa349f7f1dbb

https://towardsdatascience.com/what-is-label-smoothing-108debd7ef06

(Pereyra, Regularizing neural network by penalizing confident output distributions)

(Muller, when does label smoothing help, https://papers.nips.cc/paper/8717-when-does-label-smoothing-help)

## Refined training strategies

MentorNet [8,27] supervises the training of a StudentNet by a learned sample weighting scheme in favor of probably correct labels.

Decoupling training strategy [15] trains two networks simultaneously, and parameters are updated when their predictions disagree.   

Co-teaching [6] maintains two networks simultaneously during training, with one network learning from the other network’s most confident samples.

These studies all require training of an auxiliary network for sample weighting or learning supervision.  

D2L [13] uses subspace dimensionality adapted labels for learning, paired with a training process monitor. The iterative learning framework [25] iteratively detects and isolates noisy samples during the learning process. The joint optimization framework [22] updates DNN parameters and labels alternately.

(Wang, Symmetric Cross Entropy for Robust Learning with Noisy Labels)


