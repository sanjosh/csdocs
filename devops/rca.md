
# level

* rca
* auto-fix
* self-healing

# call trace

powerful tool but require domain expertise

cannot trace contention easily, all you see is a shifting hotspot 

need to instrument code, but really hard to instrument code correctly

this approach not easy for high TPS or high churn code

# correlation

false correlations can be high; use mutual information to reduce them but still noisy

# fault signatures

build a classifier; but may not have enough data

but fails on zero day 

# build black-box model of system

learn func to predict response time from (calls, hardware, config, contention)

keep building new models

causes of increased response time can be fragmentation

Build model to predict response time with data fragmentation

handle multiple query combinations

find driving cause of anomaly

multivariate

