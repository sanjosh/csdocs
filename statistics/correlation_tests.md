
# Pearson

relation has to be linear

# Spearman Rank

1. find ranks of each value in a column
2. subtract ranks
3. use formula

relation has to be monotonic

# MIC (Maximal information coefficient)

Detect any kind of relationship — linear, nonlinear, monotonic, or complex — between two variables.

MIC belongs to the Maximal Information-based Nonparametric Exploration (MINE) family.

MIC = 1 means strong relationship (of any form), MIC = 0 means weak or no relationship.


see `minepy` package

# HSIC: Hilbert-Schmidt Independence Criterion

Projects data into Reproducing Kernel Hilbert Space (RKHS).

Measures dependence using the cross-covariance operator in RKHS.

HSIC = 0 implies variables are statistically independent.

For exact HSIC, you'd use packages like `pyHSICLasso` or `dcor`

