
# SQL on Hadoop

* Support HDFS, HBase, other data sources
* infer schema, json


|-----|----------|-------|
|     |FixedSchema|SchemaFree|
|-----|----------|-------|
| Complex schema| Parquet, Avro  | JSON|
| Flat records |  CSV | HBase|
|-----|----------|-------|


# Apache Drill 

* SQL 2003
* JSON data,
* schema inference
* uses Calcite

# Cloudera Impala 

own C++ SQL query engine

# Apache Hive

uses Calcite

# MPP SQL

# Apache Trafodion 

EsgynDB

# Apache Calcite

used by Hive, Drill, Flink, Phoenix, Samza, Storm

# HAWQ - ORCA

# Presto

https://groups.google.com/d/msg/presto-users/gBsQVJrbgcQ/j9e1ShEEHAAJ

https://groups.google.com/d/msg/presto-users/tXBuNa19hg8/OMht4UlxKwAJ

# Ignite

H2 engine

# HSQLDB (HyperSQL)

# SQL Op Sequencing

* First the product of all tables in the from clause is formed.
* The where clause is then evaluated to eliminate rows that do not satisfy the search_condition.
* Next, the rows are grouped using the columns in the group by clause.
* Then, Groups that do not satisfy the search_condition in the having clause are eliminated.
* Next, the expressions in the select clause target list are evaluated.
* If the distinct keyword in present in the select clause, duplicate rows are now eliminated.
* The union is taken after each sub-select is evaluated.
* Finally, the resulting rows are sorted according to the columns specified in the order by clause.

Operators
* TableScan
* Project
* Filter
* Aggregate
* Join
* Union
* Intersect
* Sort


