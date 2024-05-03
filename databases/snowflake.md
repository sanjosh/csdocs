
# Incremental processing with change queries in Snowflake

Akidau et al

https://dl.acm.org/doi/pdf/10.1145/3589776

## table and stream duality

Tables represent the complete state of a dataset at each point in time; effectively equivalent
to a table in a relational database. Streams, on the other hand, capture the changes to a dataset over time; if only one row changes within a time interval, the stream captures that single change

Streams are, in effect, just insert-only tables, and are utilized as such frequently. DML performs stream to table conversions, with MERGE [59] being the Swiss Army Knife of stream to table conversion, resolving a stream of changes as applied to a table


In this paper, we present Snowflake’s primitives for table-to-stream conversions: 
1. CHANGES queries
2. STREAM objects


## Changes queries

the redo log with extra metadata as a stream table to be queried on

A CHANGES query [56] is a special type of Snowflake query that can be used to observe the changes
to a table object between two points in time

## Stream objects

To accurately represent progress through changes, where to store this state, and how to tolerate errors and faults

A STREAM [57] is a schema-level catalog object. It is created on a table (persistent or view), called
its source table. A STREAM’s state, called its frontier, represents a point in time before which all
changes to its source have been consumed

When queried from within a DML statement, the STREAM is modified as part of its enclosing transaction; when that transaction
commits, the STREAM’s frontier is moved to the end of the change interval. We call this action
consuming the STREAM . When queried from within a multi-statement transaction, it always returns
the same set of changes throughout

Each STREAM is expected to be consumed by a single reader, and multiple
STREAMs can be efficiently created on the same table.

## snowflake tables

Tables in Snowflake are comprised of a set of immutable, columnar
data files, called micro-partitions. Micro-partitions are stored in a blobstore such as Amazon S3,
Azure Blob Storage, or Google Cloud Storage, while the metadata tracking them is stored in a
FoundationDB [65] cluster

## change tracking


Query differentiation eventually pushes the derivative operator down to
the scan operators of the query plan. At this point, we need a way to compute the changes that
occurred on a persistent table. In Snowflake, this functionality is supported by per-row metadata
stored in hidden change tracking columns


# Andy Pavlo S2024 #19  

https://www.youtube.com/watch?v=NhWp1bTG0Cw

1. Managed OLAP DBMS in C++ written from scratch
2. Shared disk architecture with compute-side caching
3. Columnar storage
4. Vectorized query processing
5. cascase-style query optimizer
6. Cloud hosted object store
7. VM instances used; now serverless
8. catalog stored in FoundationDB
9. use LLVM codegen for tuple serde between workers
10. work-stealing between workers
11. scale number of nodes by looking at estimated data to be processed in query plan
12. mixing customer data ?
13. built own caching layer and fetch data by offset from s3 to hide s3 latency.
14. stores all tables as micropartitions in columnar format
15. three data types for semi-structured data (variant, object, array)
16. uses consistent hashing to assign micropartition files to worker nodes
17. statistics : maintain zone maps.  No histograms or sketches
18. adaptive optimization : push-down aggregation
19. ways to access remote data (iceberg table, hybrid table, snowpipe, external table)
20. 

## databricks vs snowflake

TPC-DS benchmark



# Blog snowflake on Aggregation placement

# Building an elastic query engine on disaggregated storage NSDI 2020




