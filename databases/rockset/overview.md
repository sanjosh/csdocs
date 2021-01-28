
## Aggregator-Leaf-Tailer architecture (like CQRS)

1. tailer ingests from databases (writer)
2. leaf nodes do real time indexing
3. aggregator serve frontend applications (reader)

scale both sides independently

1. aggregator needs lot of memory for sorting and filtering
2. lead nodes need lot of storage
3. tailers need lot of CPU for conversion of data formats


## Smart Schema (parquet?)

nested semi-structured 

type information is stored with values

type binding at query time : strongly typed queries done on dynamically typed fields

schema is kept up-to-date as documents come in

"field interning" reduces storage overhead. store fields separate from values

"type hoisting" reduce query overhead.  use hardware instructions to compare integer arrays

## converged indexing

index every field.

create row store, columnar store, inverted index on top of key-value

e.g. if doc = { Name : SomePerson } 
then rocksdb has 
1. Key = R.0.name : Value = SomePerson (row store)
1. Key = C.0.name : Value = SomePerson (column store)
1. Key = S.name.SomePerson.0  : Value = ? (inverted index)

also have geo-index, currency index

multi-column indices : is done based on config

optimizer chooses between columnar or inverted index
1. for highly selective, use inverted
2. for large scans, use columnar
3. collect statistics from leaf nodes.
4. support joins
5. optimizer tries to use as many aggregators as possible to speed up query.  which are spun up on-demand

for updates : since every field is indexed, only that field is updated

time-series queries : works since they also index timestamp

ACID database ? No, its for analytics

although many inserts, because of rocksdb LSM, writes become sequential

## serverless

* each leaf runs rocksdb with writes going to distributed log
* distributed log = like Kafka (LogDevice)
* use rocksdb-cloud
* adding new read replica to serve more queries : we copy data to new leaf and tail new updates from log
* log is in front of database, not behind the database (not written after db)
* optimized for low-latency queries rather than high throughput : hence sharding is based on doc rather than term
* use kubernetes
* separate performance from durability
* table can have thousands of micro-shards mapped to topic + partition
* distributed log has topics and partitions : doc is mapped to topic & partition.  every leaf tails these topics + partitions

## query lambda 

convert SQL query to Lambda

named parametrized SQL queries stored in rockset and exposed via REST endpoint


# Ref

1. Pinterest Tech Talk: Aggregator-Leaf-Tailer architecture for low-latency queries on large datasets https://www.youtube.com/watch?v=tDgmtReLS8c
2. Query optimizer https://www.youtube.com/watch?v=hf7Zj0_NBvY&t
3. Query lambda https://www.youtube.com/watch?v=SttOIUZm1tk
