
# Max a posteriori (MAP) vs Max likelihood estimation (MLE)

D = (x1, .. xn)

Assume joint distribution p(D, Theta)

Theta_MAP = arg_max p (theta | posterior distribution)

Theta_MLE = arg_max p (data | theta )

Advantages:
* Use MAP if prior is known (bayesian)
* MAP with flat priors = MLE
* MAP avoid overfitting
* tends to look like MLE as n -> inf

Disadvantages
* no representation of uncertainty since its point estimate
* Not invariant under reparametrization

## references

https://www.youtube.com/watch?v=kkhdIriddSI&list=PLD0F06AA0D2E8FFBA&index=31

https://wiseodd.github.io/techblog/2017/01/01/mle-vs-map/

https://stats.stackexchange.com/questions/95898/mle-vs-map-estimation-when-to-use-which
