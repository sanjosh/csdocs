
# comparing two time series

https://datascience.stackexchange.com/questions/28293/how-to-compare-different-sets-of-time-series-data?rq=1

https://datascience.stackexchange.com/questions/13489/how-to-cluster-multiple-time-series-from-one-data-frame?rq=1

https://datascience.stackexchange.com/questions/18848/classify-multivariate-time-series?rq=1

dynamic time warping

https://www.researchgate.net/post/Is_there_any_clustering_algorithm_for_time_series_analysis

# Deep Temporal clustering

Naveen Sai Madiraju, Seid M. Sadat, Dimitry Fisher & Homa Karimabadi
https://arxiv.org/abs/1802.01059

The algorithm utilizes an autoencoder for temporal dimensionality reduction and a novel temporal clustering layer for cluster assignment.

Then it jointly optimizes the clustering objective and the dimensionality reduction objective

# Time series clustering paper

https://www.intechopen.com/online-first/clustering-of-time-series-data

## main questions

1. how to measure the similarity between time series; 
2. how to compress the series or reduce dimension and 
3. what algorithm to use for cluster.

clustering method: 
1. shape-based, 
2. feature-based, 
3. model-based

## data representation

### data adaptive

* Symbolic Aggregate Approximation (SAX) 
* Adaptive Piecewise Constant Approximation (APCA) 
* Piecewise Linear Approximation (PLA) 
* Singular Value Decomposition (SVD) 
* Symbolic Natural Language (NLG) 


### non-data adaptive

* Discrete Fourier Transform (DFT) 
* Discrete Wavelet Transform (DWT) 
* Discrete Cosine Transformation (DCT) 
* Perceptually Important Point (PIP) 
* Piecewise Aggregate Approximation (PAA) 
* Chebyshev Polynomials (CHEB) 
* Random Mapping 
* Indexable Piecewise Linear Approximation (IPLA) 


### model-based

* Auto-regressive Moving Average (ARMA) [28, 29], 
* Time-Series Bitmaps [30], 
* Hidden Markov Model (HMM)

### data dictated method


## distance measure

Metrics to be used in clustering must cope with the problems caused by common features of time-series data such as 
1. noise, 
2. temporal drift, 
3. longitudinal scaling, 
4. offset translation, 
5. linear drift, 
6. discontinuities
7. amplitude scaling.

### similarity in time

### similarity in shape

### similarity in change

## clustering algo

### partitioning, 

* k-means, 
* clarans, 
* k-mediods

### hierarchical, 

### graph-based, 

### model-based, 

Model-based algorithms usually try to estimate the likelihood of the model parameters by applying some statistical techniques such as Expectation Maximization (EM)

### density-based clustering.

* DBSCAN
* OPTICS

## example funFEM algorithm for clustering

Fisher-EM


