
# Importance sampling

Importance sampling is a technique to estimate properties of a particular distribution, by samples
from a different distribution, to lower the variance of the estimation, or when sampling from the
distribution of interest is difficult.

(Li, Deep reinforcement learning)

## MathematicalMonk

this is not a sampling method but a approximation method (variant of monte carlo approx)

E[f(x)] = 1/n Sum f(x_k) where x_k is drawn from distribution p

what if p(x) is difficult to sample

E [ f(x) ] = Integral f(x).p(x).dx 

divide and multiply by q(x) such that p(x) = 0 whenever q(x) = 0

q(x) is called "proposal distribution"

E [ f(x) ] = Integral f(x).(p(x)/q(x)).q(x).dx 

dividing by q(x) gives w(x) = p(x)/q(x) = importance weight

E [ f(x) ] = 1/n Sum f(x).w(x) where x is drawn from q(x)

Importance sampling has different variance than Monte carlo sampling

Improve expected error or error by reducing variance

you can choose q(x) so as to reduce variance [ where MSE = bias^2 + variance ]

choose q(x) large where |f(x)|.p(x) is large

the name "importance sampling" comes from fact that you get samples where it matters - i.e. where f(x) is significant

https://www.youtube.com/watch?v=S3LAOZxGcnk

## Ben lambert

https://www.youtube.com/watch?v=V8f8ueBc9sY
