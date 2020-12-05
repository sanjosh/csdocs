
Unsupervised anomaly detection
1. Deep Autoencoder (reconstruction error)
2. Density estimation

# Deep Autoencoder approach

Anomaly = Reconstruction error is greater than threshold

## Deep RNN autoencoder Marchi

denoising AE structure using both feedforward units and LSTM units for acoustic anomaly detection task

E. Marchi, F. Vesperini, S. Squartini, and B. Schuller, 
“Deep recurrent neural network-based autoencoders for acoustic novelty detection,”

## Convolutional Long Short‐Term Memory AE (Conv‐LSTMAE)

convolutional AE on Melspectrograms

B. Bayram, T. B. Duman, and G. Ince, 
“Real time detection of acoustic anomalies in industrial processes using sequential autoencoders,”

## Interpolating DNN

Interpolating Deep Neural Network (IDNN), where the proposed model utilizes multiple frames of a 
spectrogram whose center frame is removed as an input, 

it predicts an interpolation of the removed frame as an output

Anomalies can be detected based on an interpolation error = difference between the predicted frame and the true frame

K. Suefusa, T. Nishida, H. Purohit, R. Tanabe, T. Endo, and Y. Kawaguchi
“Anomalous sound detection based on interpolation deep neural network"

# Density estimation approach

Unsupervised methods model the distribution of all the normal samples during training, 

during inference, regard samples in the pdf regions with low probabilities as anomalies.

## Unimodal Gaussian 

B. Abraham and G. E. Box, 
“Bayesian analysis of some outlier problems in time series,” 

## Gaussian Mixture models 

D. Agarwal, “Detecting anomalies in cross-classified streams: a bayesian approach,”

## neural density estimation

Neural density estimators can readily provide exact density evaluations unlike generative modeling approaches

two approaches
1. normalizing flow
2. autoregressive

## Normalizing Flow (neural density estimation)

D. J. Rezende and S. Mohamed, 
“Variational inference with normalizing flows,

M. Yamaguchi, Y. Koizumi, and N. Harada, 
“Adaflow: Domain-adaptive density estimator with application to anomaly detection and unpaired cross-domain translation

## Autoregressive model (neural density estimation)

These models usually decompose the joint density as a product of conditionals over
individual dimensions, and model each conditional as a parametric density where a 
neural network outputs the parameters of that density

B. Uria, M.-A. Cotˆ e, K. Gregor, I. Murray, and H. Larochelle, ´
“Neural autoregressive distribution estimation,”

## MADE  (autoregressive neural density estimation)

adapt autoencoder to neural density estimation task.

make the autoencoder respect these constraints 
mask the weighted connections between layers of a standard autoencoder 

autoregressive property : 
computing the negative log-likelihood is equivalent to sequentially predicting (regressing) each dimension of input x

M. Germain, K. Gregor, I. Murray, and H. Larochelle,
“MADE: masked autoencoder for distribution estimation,”

## Group MADE (autoregressive neural density estimation)

joint distribution can be decomposed as conditionals over groups/frames instead of 
individual dimensional conditional. We model each conditional by either a Gaussian 
distribution (Group MADE-G) or a mixture of Gaussians (Group MADE-MOG). 

with suitable choice of group ordering, it can be probabilistic version of IDNN

Ritwik Giri, Chen, Helwani, Tenneti, Isik, Krishnaswamy
Group Masked Autoencoder Based Density Estimator For Audio Anomaly Detection
