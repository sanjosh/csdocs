
# Foundations of Unsupervised Deep Learning - Ruslan Salakhutdinov 

Non-probabilistic
1. Sparse coding
2. autoencoder
3. k-means

Probabilistic (generative)
	Tractable
  	Fully observed Belief Nets
		NADE
		PixelRNN
	Non-Tractable Models
		Boltzmann Machines
		Variational Autoencoders
		Helmholtz machines
	GAN
	Moment Matching networks

-------------

# Sparse coding

Sparse coding framed as Nonlinear decoder in an AutoEncoder setting

AutoEncoder is encoder + decoder
* Encoder : Input image -> Features (feedforward, bottomup)
* Decoder : Features -> Input image (feedback, generative, topdown)

If hidden and output layers are linear, then features are linear

With nonlinear hidden units, we have nonlinear generalization of PCA

* Binary AutoEncoder - use sigmoid function
* Stacked AutoEncoder
* Deep AutoEncoder

## Semantic hashing

Map documents into semantic 20D binary codes

Learn binary rep.  Search images using binary codes

1. Torralba.  Small Codes. CVPR 2008
2. Weiss.  Spectral hashing.  NIPS 2008
3. Kulis and Darrell NIPS 2009
4. Gong and Lazebnik CVPR 2011
5. Norouzi and Fleet ICML 2011

# Generative/Probabilistic model

Bernoulli Markov Random field

## Restricted Boltzmann Machine

learn latent structure in the input

belong to "Graphical models" which can represent dependency between random variables

RBM is a Markov Random model - Binary/Gaussian/Softmax

*RBMs for word counts* - Salakhutdinov & Hinton

*Collaborative filtering using RBM* - Salakhutdinov Mnih, ICML 2007

## Local vs Distributed representations

* Local : Clustring, RBF SVM, local density estimator, Nearest neighbour
* Distributed : RBM, Factor model, PCA, Sparse coding, Deep model

* Local : numbers of region is linear with number of parameters
* Distributed : every neuron affects many regions. number of regions is exp with number of parameters

Bengio.  Foundation and Trends in machine learning.  2009

## Deep Boltzmann Machines

*Multimodal DBM* - Srivastava and Salakhutdinov

*Multimodal linguistic regularities* - Kiros Zemel TACL 2015

## Helmholtz machine

(Hinton Dayan Frey Neal, Science 1995)

## Variational Autoencoder 

# Reference

1. Deep learning school Bay Area 2016 (https://www.youtube.com/watch?v=rK6bchqeaN8)

