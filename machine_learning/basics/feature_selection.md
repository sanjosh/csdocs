
https://www.youtube.com/watch?v=VUvShOEFdQo

sebastian raschka

feature selection methods

# filter methods

requires normalized dataset

compute variance of each feature

feature with high variance may encode more information

does not take relationship between features into account

# embedded methods

# wrapper methods

## sequential feature selection

## recursive feature elimination

use linear regression (continuous) or logistic regression (discrete)

eliminate smallest model coefficients and corresponding input feature

```
from sklearn.feature_selection import RFE

rfe.fit
rfe.transform
rfe.support_
```

## permutation importance

for each feature column
1. shuffle values within that feature column
2. observe performance and compare to original

feature importance is average difference between baseline and permuted column

larger drop implies model relies on this feature more

## column drop invariant

instead of shuffling, drop the column and fit model to reduced dataset

## sequential feature selection

