
# Database evaluation

## Schema

1. fixed or dynamic ?
1. Primary keys
2. relationships : many to many ?
3. blobs
4. other data types

## Data volume

growth

## Workload 

volume, throughput and latency

1. queries
2. inserts
3. deletes
4. updates

query types
1. range 
2. spatial
3. scans
4. text

## consistency

1. ACID
2. eventual
3. read your write

## availability

1. replication
2. multi-master

## Maintenance

1. auto-admin
2. reporting

## archive backup

## security

1. authentication
2. authorization
3. encryption

## Production/human factor

1. who will use the system ?  what are they familiar with ?  learning curve ?
2. who will debug the system if things go wrong ?  What is their skill set ?

## Choices

1. Relational
2. key value
3. document
4. graph
5. time series
6. columnar
7. hybrid
8. CRDT

#  cassandra vs mongodb vs postgres

1. joins, aggegrations
1. linear write scalability (sharding partition key)
2. schema
3. transactions

NewSQL

https://blog.yugabyte.com/data-modeling-basics-postgresql-vs-cassandra-vs-mongodb/
