
# Survey Chandola  Anomaly detection

1. Classification based
1. Clustering based
1. Nearest neighbour based
1. Statistical
1. Information theoretic
1. Spectral

Chandola, Varun, Banerjee, Arindam, and Kumar, Vipin.  Anomaly detection: A survey.  ACM computing surveys(CSUR), 41(3):15, 2009.

# Survey Charu Aggarwal

Charu Aggarwal, Outlier Analysis. Springer New York, 2013.

# TODO

HTM hierarchical temporal memory

# tools

https://github.com/datamllab/tods

https://github.com/rob-med/awesome-TS-anomaly-detection

https://datascience.stackexchange.com/questions/33099/multivariate-time-series-anomalous-entry-detection

# unomaly

1. baseline
1. flag
1. cluster

## log-based

for each event, tokenize message into hash

types of anomalies
2. structural anomaly (never seen, new in this system, parameter change)
3. parameter anomaly (parameter mismatch)
4. frequency anomaly (no events, spike in a window z-score, periodic event not seen)

```
periodic event

we collect the mean inter-arrival time of a log event and its standard deviation. If the standard deviation is very low, then we can assume that we’re dealing with a periodic task

To calculate online inter-arrival time variance, we used a parallel algorithm : two windows of 5000 samples are kept for each profile and rotated when full. This gives enough history to reliably compute a representative variance of the inter-arrival time. The algorithm then periodically performs a query against our database to find all events that have missed their “deadline”. These events are then reported as stopped. A similar suppression mechanism makes sure we don’t spam users with repeatedly stopping events.

```

https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance#Parallel_algorithm

# assumption free

http://alumni.cs.ucr.edu/~ratana/SSDBM05.pdf
Assumption-Free Anomaly Detection in Time Series

automatic anomaly detection in the cloud via statistical learning
https://arxiv.org/abs/1704.07706


# TODO

A Review on Outlier/Anomaly Detection in Time Series Data 2021
https://dl.acm.org/doi/10.1145/3444690
