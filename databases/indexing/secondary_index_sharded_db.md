
# Problem

In a sharded database, a secondary index can be local or global.

1. Local means the secondary index is sharded based on same policy as the primary index.  Secondary index only indexes data on that particular node.
2. Global means the secondary index can index data existing across all nodes.  Secondary index is sharded independently of the primary index

| Operation on secondary index  | Local                 | Global         |
| ----------------------------  | -----                 | ---------      | 
| Update                        | easy                  | hard           |
| resharding node               | hard                  | easy           |
| recover on node failure       | easy                  | hard(query all)|
| query needs secondary index   | hard(query all nodes!)| easy           |

# Survey of daabases

| Database    | Local              |  Global   |
| ----------  | -------            | --------  |
| MongoDB     | Y                  |           |
| Cassandra   | Y                  |           |
| HBase       | Y(region index)    |           |
| MapR-DB     | Y                  |Y          |
| Aerospike   | Y(transient)       |Y          |
| DynamoDB    | Y                  |Y          |
| Couchbase   | Y(map-reduce view) |Y          |

## MongoDB

Local secondary index only.  

This is why Couchbase outperforms MongoDB on some queries.

https://stackoverflow.com/questions/41800012/is-there-a-notion-of-global-secondary-index-in-mongo

## Cassandra

Local

One person solved the problem by maintaining a separate table for their secondary index.  They had to deal with data integrity issues.
https://pantheon.io/blog/cassandra-scale-problem-secondary-indexes

## HBase

Well-written critique of HBase secondary indexing model.
https://www.linkedin.com/pulse/secondary-indexing-hbase-tale-how-screw-up-simple-idea-michael-segel

Prefers covering indexes in Phoenix fork of Hbase.
https://ztheworld.wordpress.com/2014/01/27/secondary-indexes-in-hbase/

HBase secondary index manual
http://hbase.apache.org/book.html#secondary.indexes

## MapR-DB (Hbase like)

Global

Before 6.0, secondary index was kept in ElasticSearch
1. First you retrieve row key from ElasticSearch
2. Then you retrieve json from MapR

After 6.0, secondary indexes are native (inside MapR-DB).
They do auto-propagation, auto-scale & auto-management of these indexes. 
They support Composite (i.e. multi-attribute) indexes.

## Aerospike

Local

Transient secondary index which is held in RAM (not persistent on disk)
The secondary index is co-located with primary index

https://www.aerospike.com/docs/architecture/secondary-index.html

## DynamoDB

Support both.  Partition key is different for local and global secondary index.

http://docs.aws.amazon.com/amazondynamodb/latest/developerguide/SecondaryIndexes.html

http://docs.aws.amazon.com/amazondynamodb/latest/developerguide/GuidelinesForGSI.html

http://docs.aws.amazon.com/amazondynamodb/latest/developerguide/GuidelinesForLSI.html


## Couchbase

Global secondary index
https://developer.couchbase.com/documentation/server/current/architecture/global-secondary-indexes.html

https://blog.couchbase.com/faster-indexing-and-query-with-memory-optimized-global-secondary-indexes-gsi/

Map reduce views
https://developer.couchbase.com/documentation/server/4.1/developer-guide/views-intro.html


