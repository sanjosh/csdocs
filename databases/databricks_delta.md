
# Databricks Delta

problems
1. schema changes break data enrichment
2. partitioning does not scale for multidim data 
3. combine batch and streaming

Delta tables built on top of DBFS
1. versioned parquet
2. delta log of actions 
3. indexes and stats

advantages
1. acid trans
2. schema enforcement
3. time travel
4. streaming and batch unification

https://github.com/delta-io/delta

Delta Lake stores transaction log and checkpoint with the tables

Storage system must have
1. atomic visibility : write is visible or not
2. mutual exclusion : one writer can create or rename
3. consistent listing : all future listings return the created file

implement the logStore API to plug in your storage system

HDFS plugs into logStore

Delta lake does not support multi-table transactions and foreign keys. Delta Lake supports transactions at the table level.
