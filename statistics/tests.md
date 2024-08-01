
# objective

is test needed to compare entities or to establish relationship between them ?

data is continuous or categorical ?

# there is only one test

allen downey

## All tests try to answer the same question: 

Is the apparent effect real, or is it due to chance?

```
All of the so-called tests you learn in statistics class are just ways to compute p-values efficiently.  When computation was expensive, these shortcuts were important, but now that computation is virtually free, they are not.

And the shortcuts are often based on simplifying assumptions and approximations.  If you violate the assumptions, the results can be misleading, which is why statistics classes are filled with dire warnings and students end up paralyzed with fear.

Fortunately, there is a simple alternative: simulation.  If you can construct a model of the null hypothesis, you can estimate p-values just by counting.  This figure shows the structure of the simulation.
```

## use simulation

```
The first step is to get data from the system and compute a test statistic.  The result is some measure of the size of the effect, which I call "delta".  For example, if you are comparing the mean of two groups, delta is the difference in the means.  If you are comparing actual values with expected values, delta is a chi-squared statistic (described below) or some other measure of the distance between the observed and expected values.

The null hypothesis is a model of the system under the assumption that the apparent effect is due to chance.  For example, if you observed a difference in means between two groups, the null hypothesis is that the two groups are the same.

The next step is to use the model to generate simulated data that has the sample size as the actual data.  Then apply the test statistic to the simulated data.

The last step is the easiest; all you have to do is count how many times the test statistic for the simulated data exceeds delta.  That's the p-value.
```
https://allendowney.blogspot.com/2011/05/there-is-only-one-test.html

# chi-squared

its a comparison test for categorical data

for homogenity or independence

e.g. hash function

# t-test

its a comparison test for categorical and continuous data

1. for 1-level, use 1-sample 
2. for 2-level, use 2-sample unpaired 
3. to test same group twice for 2-level (before and after), use 2-sample paired
4. if 3+levels, use one-way ANOVA

# correlation

its a relationship test for continuous data

1. if 1 independent and 1 dependent, spearman correlation or regression

# assumptions

data is normally distributed.  if not, use non-parametric test

# reference

https://www.youtube.com/watch?v=ulk_JWckJ78

# TODO

https://machinelearningmastery.com/statistical-hypothesis-tests-in-python-cheat-sheet/
