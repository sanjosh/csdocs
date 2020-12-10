
# StatStream: Statistical Monitoring of Thousands of Data 

Dennis Shasha

compute correlations over thousands of data streams in real time

We make this computation more efficient by  
1. using a discrete fourier transform of basic windows to compute the correlation of stream pairs approximately; 
2. using a grid data structure to avoid the approximate computation for most pairs.

A much harder problem is to compute correlations with time lags. 
The time series will not necessarily be aligned at their basic windows. 
However, the digests we keep are enough to compute such correlation

http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.19.8732&rep=rep1&type=pdf

# Online Data Mining for Co-Evolving Time Sequences

Byoung-Kee Yi


“...indexing methods to search for sequences that are similar, despite gaps, translation and scaling.”


http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.15.8899&rep=rep1&type=pdf

http://reports-archive.adm.cs.cmu.edu/anon/1999/CMU-CS-99-171.pdf

# Fast similarity search in the presence of noise, scaling and translation in time-series databases. 

Proc. of VLDB, pages 490–501, September

1993. [5] R. Agrawal, K.-I. Lin, H. S. Sawney,and K. Shim. 

# Streaming Pattern discovery in multiple time series

Papadimitrou, Faloutsos VLDB 2005

# BRAID Stream mining through group lag correlations 

Yasushi Sakurai, Papadimitrou


# Optimal multi-scale patterns in time series streams

Papadimitriou SIGMOD 2006

# multiple time series belonging to one instance

PCA
https://stackoverflow.com/questions/52449331/pca-with-several-time-series-as-features-of-one-instance-with-sklearn

vector based ARIMA or hierarchical forecasting
https://stats.stackexchange.com/questions/412276/how-to-handle-many-times-series-simultaneously

LSTM with instance name as a feature input
https://stats.stackexchange.com/questions/305863/how-to-train-lstm-model-on-multiple-time-series-data

https://stats.stackexchange.com/questions/389291/strategies-for-time-series-forecasting-for-2000-different-products

matrix factorization
https://datascience.stackexchange.com/questions/5958/are-there-any-unsupervised-learning-algorithms-for-time-sequenced-data

