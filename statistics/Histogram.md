
# Three views of Histogram
1. Quantile calculation (statistics)
   In Statistics, this is density estimation problem
   Its Non-parametric since distribution not known ahead of time
2. piecewise linear approx of function (segmentation algo)
3. wavelet composition of function (time -> frequency domain)

Algo complexity in terms of 
1. n = number of points
2. B = number of desired buckets where B = func(n)

Tradeoff efficiency and accuracy
* Minimize Euclidean error
* Minimize running time

Options
1. All data is known ahead of time
2. Streaming

# Types of Histograms

1. Maxdiff (greedy) : select B-1 points of highest difference 
   O (n.logB)
   performs better on spiked data

2. Equi-depth 

3. Compressed (maintains singular buckets)

4. V-optimal 
  minimize frequency variance within buckets
    -i.e. all elements in one bucket have same count
  quadratic complexity (n^2) in size of input
  derived from Bellman segmentation algo
  https://en.wikipedia.org/wiki/V-optimal_histograms
  cumulative weighted variance of the buckets must be minimized.

5. MHist (greedy)
  repeatedly select and split bucket with highest SSE
  make B splits in O(B + (n + log.B)) time
   performs better on smooth data

6. Q-digest : binary tree 
The idea of the algorithm is that if the original set size exceeds a threshold it pushes counts up the tree to higher nodes.
http://info.prelert.com/blog/q-digest-an-algorithm-for-computing-approximate-quantiles-on-a-collection-of-integers

7. T-digest

8. divide and segment (approx algo) by Terzi and Tsaparas

8. AHist (approx algo) - Guha Koudas 

10. GDY (local search)

11. Wavelets for histogram approx
Vitter and Min Wang

http://www.bearcave.com/misl/misl_tech/wavelets/histo/

# Outliers

all points within variance threshold kept in a bucket

Maintain spikes separately (singular)
* should lack of frequency be retained as 0 spike ?
* should deleted tuples be retained as negative value

that is why its better to approx the CDF since it is continuous

Keep average, stddev separately

# Extensions to problem

* Multi-dimensional histograms
* Histograms in distributed setting
* Histograms using Map-Reduce (Jestes, Li)

# Four parameters for histogram: 
1. Sort Value, 
2. Source Value, 
3. Partition Class 
4. Partition Rule.

# Misc

https://github.com/felix-halim/fehc/tree/master/src

Fast and Effective Histogram Construction∗
Felix Halim Panagiotis Karras Roland H. C. Yap

http://homepages.spa.umn.edu/~willmert/science/ksegments/

Guha Koudas and Shim

STHoles

