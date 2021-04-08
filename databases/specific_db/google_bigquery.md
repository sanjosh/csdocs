
Streaming writes buffered in BigTable (key value store)

Active storage management 
* rewrite input batches into new file with next generation number

Capacitor file format (dremel extension)
* it reorders rows for better compression (approximation algo)

Colossus file system
* Reed solomon

Dremel query engine

Time travel

Auth server cache got invalidated at midnight, caused thundering herd

Caching best practices
1. Is it a Capacity Cache or Latency Cache ?
2. Latency Cache must be fully provisioned 
3. Capacity Cache must be able to handle cold restart

Source
https://atscaleconference.com/videos/bigquery-managed-storage-for-analytics/

# Bigquery talk Ahmadi Surna

1. Storage and compute separation
1. integrated hardware/software
1. colocation and caching

query is broken into stages; each stage has several tasks in parallel

Scheduling
1. Data remains in RAM across stages (Shuffle - like Spark)
2. dynamic scheduling 
3. speculative re-run after slight delay

Distributed file system 

How to estimate resources for each query

Caching
1. result caching
2. In-memory Shuffle layer stores intermediate data
3. no caching of previous query plan 


## Query optimizer

Mix of
1. rule based (pushdown; use partial aggregation where possible)
2. cost based
3. dynamic optimization + adaptive resource allocation (depending on shape of query + data)

Joins
1. broadcast (one table smaller)
2. hash 
3. sort-merge (NOT USED)

modify query plans on-the-fly since cardinality estimates can be wrong for complex queries.  
1. dynamic partitioning : increase number of partitions on-the-fly if data skew.
2. change number of workers on the fly based on data size
2. switch between join algorithms (shuffle and broadcast) during query based on data sizes.
3. for analytical functions, choose different query plans
1. ability to re-execute parts of the query

predictable
1. prefer predictable algorithms (e.g. broadcast join)


https://www.youtube.com/watch?v=Zk5_RcRg3nA
