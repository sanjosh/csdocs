
# Multivariate time series anomaly

two approaches

## Forecasting based model

* predict value at next timestamp
* detect anomaly based on prediction error

## Reconstruction based model

* learn marginal distribution over latent representation 
* detect anomaly based on low reconstruction probability

# Approaches

## MTAD-GAT (combination of forecasting and reconstruction)

each time series is a feature

uses 2 Graph attention layer : feature-oriented and time-oriented

Joint loss function 

Zhao, Multivariate Time-series Anomaly Detection via Graph Attention Network
https://arxiv.org/pdf/2009.02040v1.pdf

## OmniAnomaly (reconstruction based)

## DAGMM (forecasting based)

## LSTM-NDT (forecasting based)

## LSTM-VAE  (reconstruction based)

## GAN-Li and MAD-GAN (reconstruction based)

# Other approaches

## Correlated Anomaly Detection from Large Streaming Data 

Zheng Chen, et al 

https://arxiv.org/pdf/1812.09387.pdf

