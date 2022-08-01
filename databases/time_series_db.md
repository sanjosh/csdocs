
# workload

1. writes are insert, not update heavy, and those inserts are typically to recent time ranges; 
1. reads are typically on continuous time-ranges, not random; 
1. writes and reads typically happen independently, rarely in the same transaction.
1. aggregate computation

1. compression 
1. handle backward scans
1. downsampling

# Graphite

# InfluxDB

tagset data model

# OpenTSDB

# KairosDB

# PrometheusDB

# MongoDB

create a document for each device, for each hour, which contains a 60 by 60 matrix representing every second of every minute in that hour. 

This document is then updated each time a new reading comes in, rather than doing a new document insert:

to efficiently manage writes, the database must keep a client-side cache

# Chronix

# TimeseriesDB

used chunking over sharding

1. hypertable abstraction : table is set of chunks
1. chunk = partition 
1. keep recent chunks in RAM
1. chunks are auto created

## compression

1. gorilla compression for floats (XOR)
1. Delta-of-delta + Simple-8b with run-length encoding compression for timestamps and other integer-like types
1. dictionary for columns with repeating values
1. LZ-based array compression

## downsampling

continuous aggregate - moving average

extended Gorilla and Simple-8b in order to handle decompressing data in reverse order, which allows us to speed up queries that use backwards scans
https://github.com/timescale/timescaledb/pull/1434/files

https://blog.timescale.com/blog/building-a-distributed-time-series-database-on-postgresql/

# Monarch

https://research.google/pubs/pub50652/


# Scuba: Diving into Data at Facebook 

# Gorilla: A Fast, Scalable, In-Memory Time Series Database 

# Cubrick: Indexing Millions of Records per Second for Interactive Analytics 

# Shark: SQL and Rich Analytics at Scale 

