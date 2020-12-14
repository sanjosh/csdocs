
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

## Anomaly detection in APM (Elasticsearch, Prolert)

work so far
1. statistical methods : goodness of fit
2. distance based approach : embedding in metric space

in this paper : a natural extension of the p-value of an observation provides a good measure for
identifying outliers for APM use cases.

in this paper : use bayesian formulation since its intrisically online and can age out older data.

define q-value = generalized p-value

relative phase change in two periodic signals

individual values can be aggregated using joint probability or order statistics 

model must be able to handle or eliminate natural trends (diurnal)

lattice valued data : because metric is truncated to fixed precision.

data with low coefficient of variation : if heap memory is not returned

heavy tails arise because monitoring tools often sample max values.

multimodal distribution arises if same metric is used for (e.g.) different SQL queries

anomalies between related time series can lag because 
1. no observation available for one time series (which has failed)
2. large lag : slow mem leak later leads to increased response time

use time bucket statistics for different bucket lengths, or dynamic time warping to correlate over time

uses q-digest algorithm

outlier = 2.5 standard deviations from the rolling mean

(Veasey Dodson, Anomaly Detection in Application Performance Monitoring Data)
