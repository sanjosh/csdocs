
## Cloudera fast forward labs

X is input, y is target variable

P(X, y) = P(X) + P(y | X)

the above decomposition implies two sources of drift

### feature drift (first term above)

Clothing brand
1. y = relevance of clothing item to customer
2. X = customer preference (age, size, loc) and brand's product line

here, feature drift can occur due to 2 reasons
1. customer prefernce can change
2. product line can change

this may or may not change classification boundary

### real concept drift (second term above)

customer moves to different location; 

### two windows

reference window  : data on which model trained

detection window :  new data

### supervised methods for drift detection

1. drift detection method DDM
2. early drift detection method EDDM
3. adaptive windowing (ADWin)

Problem with labeled data
1. Annotating data is expensive
2. verification latency can be high (several months to tell if credit card fraud occurred)
3. infinite latency (bank denies loan; cannot determine if loan would have been repaid)

### unsupervised methods for drift detection

infer real concept drift from feature drift

#### statistical test for change in probability distribution

two sample KS test for continuous

chi-squared for categorical

for multivariate, check each feature +  Bonferroni test

multivariate two-sample test - Maximum mean discrepancy

false alarms in this method because classifier is excluded from drift detection; all features seem equally important

#### statistical test for change in response variable

include classifier

generate class probabilities; then use k-fold procedure to obtain probability estimates

```
apply a Kolmogorov-Smirnov hypothesis test to see if the response distributions between reference and detection windows differ significantly
```

this method is still overly sensitive

by design, a KS test is responsive to changes across the entire response distribution

#### statistical test for change in margin density of response variable

for both windows, we classify each observation as in-margin or out-of-margin, based on its predicted confidence score.

#### Detect change in margin density of response distribution using a learned threshold



https://concept-drift.fastforwardlabs.com/

https://github.com/fastforwardlabs/concept-drift

## On the Reliable Detection of Concept Drift from Streaming Unlabeled Data

Tegjyot Singh Sethia,∗ , Mehmed Kantardzica

https://arxiv.org/pdf/1704.00023.pdf
