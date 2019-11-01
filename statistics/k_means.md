

# K-means

Computational cost = O(n x k x d), where n = number of data points, k clusters, d number of attributes

ways to find number of clusters

Choose k that minimizes distortion and maximizes mean silhouette score


## Elbow method
Plot graph of kmeans.inertia vs number of clusters
optimal value is at knee
https://heartbeat.fritz.ai/k-means-clustering-using-sklearn-and-python-4a054d67b187

## Silhouette method

## Compare against null hypothesis

Example is gap statistic

## compare

The disadvantage of elbow and average silhouette methods is that, they measure a global clustering characteristic only. A more sophisticated method is to use the gap statistic which provides a statistical procedure to formalize the elbow/silhouette heuristic in order to estimate the optimal number of clusters.

https://heartbeat.fritz.ai/k-means-clustering-using-sklearn-and-python-4a054d67b187

https://www.datanovia.com/en/lessons/determining-the-optimal-number-of-clusters-3-must-know-methods/

 
