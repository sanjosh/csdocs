
# Aesop : change propagation across data stores

payments

in case of failure, need reconciliation between bank and initiator

payment transaction - needs ACID, write path optimized

fraud detection use case

cannot have one datastore for all use-cases (denormalized, search, write-heavy)

hbase, mysql, elasticsearch

once lifecycle complete, transaction data can be dropped from mysql and sent to archival store

options for keeping multiple data stores consistent
1. ETL not option since not realtime
2. dual write (ordering problems, non-primary key updates, manual changes)
3. log mining - tightly coupled to db

ways to do log mining
1. use mysql bin log - depend on bin log format
2. custom storage engine - publish to your pub-sub system

Aesop has 3 components
1. producer : converts change log to Avro
2. relay : zookeeper stores SCN
3. consumer : convert between schema, and apply to destination data store

Scaling by Sharding - partition on primary key

ensures ordering within partition

uses Linkedin databus

related work : Facebook wormhole

https://youtu.be/o_AbC0LyXmg

