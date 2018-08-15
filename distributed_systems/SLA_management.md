
SLA pervasive built into all CosmosDB components

---------

# Scale Independence, Michael Armbrust

A new technique for doing query optimization that allows developers to set an upper bound on the response time for their query result independent of the size of their database.

Extended SQL language 
1. provide cardinality constraints to schema.  use that info during joins.
2. make pagination a native part of query (cursor split into sub-cursors)
3. precompute answer

http://queue.acm.org/detail_video.cfm?id=2555932

----------

# PerfEnforce - Ortiz, Lee, Balazinska, Hellerstein

To guarantee the query runtimes associated with an SLA, PerfEnforce resizes the cluster in between queries either in a proactive or reactive approach. With a proactive approach, PerfEnforce decides to scale based on how well it met previous SLA deadlines. In a re- active approach, PerfEnforce decides whether to rescale the cluster before executing each incoming query.

How to rescale ...compare different deployments in terms of 
1. initial setup time, 
2. the storage type, 
3. time to change the cluster configuration between queries, 
4. query execution time, and 
5. total cost.

When to rescale (up or down)
1. reactive : PID, Reinforcement learning (Q-learning)
2. proactive : Perceptron learning

