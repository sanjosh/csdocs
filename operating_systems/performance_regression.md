
# Autoperf

## Zero positive learning (Anomaly detection)

Zero-positive learning involves a one-class training problem, where only negative (non-anomalous)
samples are used at training time [50]. We employ autoencoders to learn the data distribution of the
non-anomalous data [13]. At test time, we then exploit the autoencoder to discover any deviation that
would indicate a sample from the positive class. The autoencoder model is a natural fit for our ZPL
approach, since it is unsupervised (i.e., does not require labeled training data as in one-class training)
and it works well with multi-dimensional inputs (i.e., data from multiple HWPCs).

reconstruction error

We take a majority vote among all performance counters for each anomalous sample.
The counter that comes first is the one that causes the performance regression. We report that counter
and the corresponding regression type as the root cause.


## k-means clustering

Training one autoencoder per such function is impractical. Furthermore, the number of samples
required to train these grows, too. 

To alleviate this, we group multiple functions into clusters and assign an autoencoder to each group.

For each cluster c, we build one autoencoder

Alam, A Zero-Positive Learning Approach for Diagnosing Software Performance Regressions
https://arxiv.org/abs/1709.07536

https://github.com/mlogic/AutoPerf/tree/master/autoperf
