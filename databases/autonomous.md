
# Auto-tuning research categories

Choose OLTP/OLAP/HTAP

What to tune ?
1. Physical design : Choose best layout (row, column, compress) or index or materialized view
2. Runtime behaviour : Query optimization parameters for application based on workload trace.  Dynamic resource allocation (add a node)
3. Data location : replicate table, move up tier, repartition table

Is the tuning component external or internal to the system being tuned ?

Workload modeling : 


# Peloton - NoisePage 2017

https://noise.page/publications/

Goal is to improve overall latency



Event stream contains 
1. queries with resource utilization 
2. DBMS/OS telemetry data
3. begin/end of optimization actions which were undertaken

Construct forecast models based on the event stream.

## Workload classification

Unsupervised learning (DBSCAN) used to group queries with similar characteristics.   
This reduces number of forecast models to build.  

Cluster queries based on
1. runtime metrics (sensitive to changes in logical design)
2. logical semantics
3. query execution plan (most robust - hence picked)

each query now belongs to a "query cluster"

How to determine if clusters of queries are out-dated ?
1. use cross validation to determine when cluster error rate goes above threshold

## Workload forecasting

1. ARMA - no, because linear assumption is not valid.  There are exogenous factors.
2. Multiple LSTM per group to forecast different time horizons

LSTM 1 predicts number of queries in next one hour at 1 minute granularity.  
Input is past 2 hours of queries at 1 minute resolution

LSTM 2 predicts 24-hour horizon at one hour granularity.  
Input is past 24 hours of queries 

## Action planning and execution

* prune redundant actions which were suggested
* certain actions have an inverse
* each action has a cost : how many resources required, how much time

choose action based on
1. forecast
2. current db config
3. objective function

Use receding horizon control model (RHCM) from control theory

At each time epoch, 
1. estimate workload for some finite horizon
2. only apply first action in sequence 
3. wait till next epoch (this avoids aborting in-flight actions)

Objective : minimize sum of (query latency * number of queries) across all queries, weighted by those queries which arrive immediately

How large a time horizon to use ?

Action
1. migrate hot tuples to row store; cold to column store



# DBSeer by Mozafari

DBSCAN used to cluster OLTP workloads in 

## references

Mozafari and et al. Performance and resource modeling in highly-concurrent oltp workloads. 

# Basu Reinforcement learning

Automated database configuration

cost model is not known apriori but learnt through reinforcement learning.

markov decision process
1. state = db config
2. actions = config changes
3. reward = cost of config change + cost of query/update evaluation

add discount factor to give more importance to immediate costs

define cost-to-go function for a policy

policy iteration : to find optimal policy, start from arbitrary policy and improve cost estimation

problems with policy iteration
1. no cost model
2. curse of dimensionality
3. probability distribution of queries is not known apriori

reduce search space by pruning based on conditions in config

calculate optimal policy using "least squares policy iteration" (LSPI)

But LSPI needs predefined cost model.  

Use recursive least squares estimation (RLSE)


## references

D. Basu and et al. Cost-Model Oblivious Database Tuning with Reinforcement Learning,

# MonetDB database cracking

build indexes at runtime by looking at query access patterns

# Probabilistic reasoning to automate tuning

David Sullivan
https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.90.8651&rep=rep1&type=pdf

# Online physical design tuning

Bruno, N., Chaudhuri, S.: An online approach to physical design tuning. In: ICDE
(2007)

# Online index selection

Schnaitter, K., Abiteboul, S., Milo, T., Polyzotis, N.: On-line index selection for
shifting workloads. In: SMDB (2007)

# Semi-automatic index tuning (WFIT)

Work function algorithm

Schnaitter, K., Polyzotis, N.: Semi-automatic index tuning: keeping DBAs in the
loop. Proc. VLDB Endow. 5(5), 478–489 (2012)

# Microsoft AutoAdmin 

Create a hypothetical index.  Gather statistics for index using sampling and provide it to optimizer

create a hypothetical config with hypothetical indexes

Run query against SQL server in no-exec mode.  Find if the optimizer uses the hypothetical fake index

## ref

Chaudhari, AutoAdmin “What-if” Index Analysis Utility

# Microsoft Azure : Database-as-a-service auto-scaling

Relational Database-as-a-Service (DaaS) platforms today support the abstraction of a resource container that guarantees a fixed amount of resources.

web servers auto-scaling is done based on historical resource utilization. this approach does not work for databases which are stateful (web servers are stateless).

three orders of magnitude separate the cost of the smallest and largest containers in Azure SQL DB

this paper focuses on scale-up type of auto-scaling (not scale-out)

high resource utilization does not necessarily mean high demand
1. query will consume more IOPs if given more
2. query will use up memory as cache if given more

challenges
1. to estimate demand, since it cannot be measured due to complex interactions in database engines
2. translate latency goal and cost budget into resource demand/container size

demand estimation via
1. derive robust signals from telemetry
2. combine multiple signals using domain knowledge
3. use multi-tenant data across different containers to derive and verify thresholds

other challenges
1. cost budget is specified over a longer period (month) but container sizing changes occur every hour
2. latency goal may not be met due to poorly written application code.  Therefore, increase container size only if there is resource demand + latency goal not met.

## how to derive robust signals from telemetry

define robustness to outliers using the notion of the breakdown point of an estimator

```
Microsoft SQL Server reports wait statistics categorized into more than 300 wait types.6 Each wait type is associated to a (logical or physical) resource for which the request waited.  
Using rules, we map the wait times to the resource to determine the total time the tenant’s requests waited for that resource.   
We classify waits into a broad set of classes for the key physical and logical resources: CPU, memory, disk I/O, log I/O, locks, and system.  
```

## derived signals

track trends for early identification.  Use Thiel-Sen estimator 

track correlation to identify main bottleneck.  USe Spearman rank coefficient

## resource demand estimator

ML models tend to overfit.  
1. when collecting training data, can only observe a very small fraction of space of the possible customer workloads
2. tenant can execute arbitrary SQL code.  Cannot make closed-world assumption.  Workload pattern is not known apriori

Instead use domain knowledge to create hand-crafted rules and build a decision tree.   
The outcome is decision if same/larger/smaller container is required.

Model is explainable.

## budget manager

how to ensure per-hour resource cost does not exceed per-month budget ?

use token bucket (as in network flow) and allow bursts


Sudipto Das
https://www.microsoft.com/en-us/research/publication/automated-demand-driven-resource-scaling-in-relational-database-as-a-service/

# IBM DB2 Performance wizard

# Microsoft DBSherlock


# iTuned

database engines are complex.  tuning parameters have complex interactions

Highlights

## Adaptive sampling to select new experiments to run based on history of old experiments

previous techniques
1. Gridding : create grid on all tunable parameters
2. SARD - statistical approach to ranking database parameters - Plackett Burman design ( 2 settings per parameter)

these techniques are not feedback-driven

1. samples past experiments using space fillng design (latin hypercube sampling)
2. analyze the surface to determine next experiment  
3. compute probability density function (PDF)
4. compute expected improvement based on pdf

use Gaussian Process representation of response surface to represent and visualize parameter effects

the next experiment to run should be picked either from regions where uncertainty is large

## run experiments at near-zero overhead

standy databases

## portable across database systems

## sensitivity analysis to eliminate insignificant parameters

Songyun Duan Tuning Database Configuration Parameters with iTuned
https://users.cs.duke.edu/~shivnath/papers/ituned.pdf

# Pythia (multi-tenant database)

A. Elmore, S. Das, A. Pucher, D. Agrawal, A. E. Abbadi, and
X. Yan. Characterizing Tenant Behavior for Placement and
Crisis Mitigation in Multitenant DBMSs

# TODO

CloudScale [19], AGILE [16], PRESS [9], AutoControl [17], AutoScale [8], CloudStone [13], SCADS [26], and
Huber et al. [11] in Das https://www.microsoft.com/en-us/research/wp-content/uploads/2016/06/p883-das-1.pdf

Related Work in Peloton 

Borodin, A., El-Yaniv, R.: Online Computation and Competitive Analysis. (Work function)

