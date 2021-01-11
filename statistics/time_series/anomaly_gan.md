
# TadGAN

earlier approaches
1. thresholding
2. statistical hypothesis tests
3. proximity-based : clustering and outliers
4. prediction-based : 
5. reconstruction-based : compare real with predicted

Propose unsupervised method; Mix autoencoder and GAN

this method works even if
1. No baseline construction
1. No segmentation possible

The core idea behind reconstruction-based anomaly detection methods is to 
learn a model that can encode a data point (in our case, a segment of a 
time series) and then decode the encoded one (i.e., reconstructed one). 

An effective model should not be able to reconstruct anomalies 
as well as “normal” instances, because anomalies will lose
information during encoding.

two adversarial Critics (aka discriminators) 
1. goal of Cx is to distinguish between the real time series sequences from X and the generated time series sequences from G(z), 
1. Cz measures the performance of the mapping into latent space. 

https://github.com/signals-dev/Orion

TadGAN: Time Series Anomaly Detection Using Generative Adversarial Networks
https://arxiv.org/abs/2009.07769
