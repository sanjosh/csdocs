
# Yanacek - observability AWS re:invent 2023

## use dimensionality

the metric can be latency, error, volume

look at metric per dimension (e.g errors per webpage or per widget) instead of looking at all together

measure separately, the things which can fail separately

use composite alarms when the alarms are tied to a common problem

# find source of problem

triangulate with tracing

use servicelens map in cloudwatch

use service maps derived from traces

causes can be bad deployment, bad component, bad dependency, traffic spike

add alarm on the worst performing dimension of a metric (e.g. worst latency on any webpage)

split key metrics on separate dimensions for each infra boundary (e.g. different AZ, different ec2 instance)

have alarm on code version dimension (latency per code version)
 
configure auto-rollback : ci/cd checks alarm and rolls back (here, alarm on composite of all alarms)

# traffic spike

use dimension - find customers who are doing top-N requests

customer dimension is a high cardinality metrics but you only need top N

# uncover hidden issues (external issues)

real user monitoring (RUM) - client-side metrics

synthetic workload measurement

# uncover hidden issues (misattributed fault)

lets say you added code with stricter validation and it causes clients to fail

we need to check error rates by type (400 vs 500) but this can become a false positive alarm

get percent of clients with errors divided by total number of clients

# prevent future issues

monitor utilization - but how if everything is elastic 

look at ec2 instance with highest disk utilization

look at max threads per process

look at percent of running instances divided by max instances

# game days

fault injection service


















