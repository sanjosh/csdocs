
# Hokusai - Alex Smola


## scale sketches beyond single machine

1. accuracy (limited mem)
1. reliable (fault tolerance)
1. scalable (more inserts)

## hokusai

use combination of 3 ideas
1. count-min sketch
1. consistent hash : split keys between machines
1. interpolation (marginals of joint distribution, exp backoff of count statistics)

Accuracy increases with O(1/k) but reliability decreases

overreplicate : assigning keys to subset of machines instead of just one

### Interpolation

Sketch of 2 sets = sum of sketches  (i.e. we can aggregate)

Sketch of lower resolution can be obtained by aggregating adjacent bins since it is linear function (i.e. we can compress)

reduce bit resolution for sketch every 2^t steps

1. Time aggregation : decrease temporal resolution
1. Item aggregation : decrease accuracy 


## TODO

proportional hashing - Reed Usenix 2011
https://dl.acm.org/doi/10.5555/2002181.2002214

## ref

Alex Smola, Scalable machine learning
https://www.youtube.com/watch?v=FQoJV88ve0g

http://practicalquant.blogspot.com/2012/11/hokusai-adds-a-temporal-component-to-count-min-sketch.html

https://github.com/dgryski/hokusai
