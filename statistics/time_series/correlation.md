

# methods

## pearson correlation  (global)

## local correlation

TLCC : time lagged cross correlation

WIndowed TLCC

## Dynamic time warping

can deal with signals of different lengths

but if there is missing data, that needs to be interpolated

## Instantaneous phase synchrony

extract phase information using Hilbert transform

# for imbalanced data

# multiple resolutions (time scales)

## Scale space methods 

https://en.wikipedia.org/wiki/Scale_space

## DCCA Detrended Cross-correlation analysis

works for non-stationary signals


https://arxiv.org/pdf/0709.0281.pdf

## DPCCA : Detrended Partial-Cross-Correlation Analysis

# Multiple time series

https://cloud.google.com/solutions/correlating-time-series-dataflow

# MAR multi-variate auto-regressive


## financial correlation matrix

```
avoiding similar allocations of capital in stocks that are strongly correlated.
```
https://www.nature.com/articles/s41598-020-67536-y

# Papers

## correlation space

first 5 coefficients of the DFT is enough to approximate the correlation among stock indices with high accuracy

Han Qiu, Learning Correlation Space for Time Series
https://arxiv.org/pdf/1802.03628.pdf

## change point detection in correlation

Robust methods for DeCon, rank information for Multirank, the kernel trick for KCP and Euclidean distances for E-divisive. T

### DeCon : uses Robust methods

Bulteel, K., Ceulemans, E., Thompson, R., Waugh, C., Gotlib, I., Tuerlinckx, F., & Kuppens, P. (2014). DeCon: A tool to detect emotional concordance in multivariate time series data of emotional responding

### E-divisive : uses euclidean distance

Matteson, D., & James, N. (2014). A nonparametric approach for multiple change point analysis of multivariate data. 

### Multirank : uses rank info

Lung-Yut-Fong, A., Lévy-Leduc, C., & Cappé, O. (2012). Homogeneity and change-point detection tests for multivariate data using rank statistics.

### KCP : uses kernel trick

Arlot, S., Celisse, A., & Harchaoui, Z. (2012). Kernel change-point detection. Retrieved from http://arxiv.org/abs/1202.3878


### ref to paper

 
Cabrieto, detecting correlation changes in multivariate
https://link.springer.com/article/10.3758/s13428-016-0754-9

# TODO


laloux, noise dressing of financial correlation matrices
https://arxiv.org/abs/cond-mat/9810255

Yuan, A novel way to detect correlations on multi-time scales, with temporal evolution and for multi-variables
https://www.nature.com/articles/srep27707



