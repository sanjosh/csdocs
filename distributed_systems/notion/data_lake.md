
# data lake

https://www.notion.so/blog/building-and-scaling-notions-data-lake

## problem

Notion users update existing blocks (texts, headings, titles, bullet lists, database rows, etc) much more often than they add new ones.

Notion's 6-to-12 month data doubling rate

## Initial 

Postgres to snowflake using FiveTran

## New 

ingest incrementally updated data from Postgres to Kafka using Debezium CDC connectors, then use Apache Hudi, an open-source data processing and storage framework, to write these updates from Kafka to S3

use S3 as a data repository and lake to store all raw and processed data, and ElasticSearch, Vector Database, Key-Value store, etc as its downstream.

Spark as main data processing engine

one Kafka topic per Postgres table and let all connectors consuming from 480 shards write to the same topic for that table

used Apache Hudi Deltastreamer, a Spark-based ingestion job, to consume Kafka messages and replicate the state of Postgres table in S3.


 
