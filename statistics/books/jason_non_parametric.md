
if data gaussian, use parametric   
else use non-parametric

# Parametric 

suite of methods
1. summary statistics (kurtosis, skew)
2. correlation
2. significance tests for comparing means

data transform : convert non-parametric to parametric

# non-parametric

may be required for variety of reasons
1. data not real-valued
2. data not fitting shape
3. data has outliers, peaks, shift

# normality tests

is a sample drawn from gaussian ?

use non-parametric methods if data fails these tests

visual
1. histogram
1. q-q plot

statistical
1. shapiro-wilk
1. D'Agostino K^2 test : calculate summary stats
1. Anderson-Darling test : modified version of nonparametric KS test

each tests returns statistic and p-value.   
test statistic is compared against critical value of distribution.  

fail to reject null hypothesis if test statistic < critical value at chosen significance level

null hypothesis is that its gaussian.   reject if p-value < alpha

skew = left or right shift  
kurtosis = how long tail

# convert data to normal

Power transforms Box-Cox
1. if exp, take log
2. if skew, take sqroot
3. reciprocal

# summary of gaussian data 

mean, std dev

# Rank statistics

non-parametric method require data to be ranked

convert data to rank format : sort and assign rank (scipy rankdata)

methods on rank data
1. rank correlation 
2. rank statistical hypothesis tests

non-parametric correlation

compare means (statistical significance)

# non-parametric data summary tukey

min, 1st quartile, median, 3rd quartile, max

box-whisker plot

# gaussian correlation

1. pearson 

# rank correlation

1. spearman rank correlation
2. kendal rank corr
3. goodman and kruskal
4. somer's 

# rank significance (compare means)

1. mann-whitney U-test requires independent samples
2. wilcoxon signed-rank if pairs have to be compared
3. kruskal-wallis H-test = non-parametric equiv of one-way ANOVA
4. friendman = non-parametric equiv of repeated measures ANOVA

# independence test

## chi-squared

contingency table of categorical variable

compare expected and actual frequencies

result is test statistic which has chi-squared distribution

null hypothesis : varables are independent

if test statistic > critical value, reject null hypothesis

if p value < alpha, reject null hypothesis

degrees of freedom
