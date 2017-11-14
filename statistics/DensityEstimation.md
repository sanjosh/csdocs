
# Density estimation

Parametric is when distribution is assumed or known

Non-parametric
1. Parzen windows
   estimate likelihood = P(x | c_j)

2. Nearest neighbours
   do posterior estimation = P(c_j | x)

```
Given p(x) = (k/n) / V
where V = volume of region R
and k = number of samples inside R
and n = total number of samples

In Parzen, fix volume V and determine k - number of pts inside V
In nearest neighbour, fix k and determine V that contains k
good rule of thumb is to choose k = sqroot(n)
```

There are multiple approaches to approximate a model or a function to fit a
given data set. The list includes 

1. Splines
2. Least square regression
3. Levenberg-Marquardt
4. K-nearest neighbors
5. Histogram
6. Polynomial interpolation
7. Logistic regression
8. Neural Networks
9. Tensor products
... and many more


