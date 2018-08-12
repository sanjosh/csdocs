
# CockroachDB (like Spanner)

## Partitioning

range = 64MB in size

persisted locally in rocksdb

rebalancing algo

have raft group per range

A crucial enhancement to the organization of range metadata is to augment the bi-level range metadata lookup with a minimum spanning tree, implemented as a left-leaning red-black tree over all ranges in the map. This tree structure allows the system to start at any key prefix and efficiently traverse an arbitrary key range with minimal RPC traffic, minimal fan-in and fan-out, and with bounded time complexity equal to 2 * log2N steps, where N is the total number of ranges in the system.

https://smazumder05.gitbooks.io/design-and-architecture-of-cockroachdb/content/architecture/range-spanning_binary_tree.html

## Index

Secondary index - each index has indexID

add primary Key to allow storing non-unique index in key-value store

stored as <tableId/indexID/indexValue/primaryKey> => columnVal

## Storage

How table is mapped to kv store

used like columnar store but sorted by key instead of position

each table has tableID; this is prefixed to every key

each column has columnID

each column is stored as <tableId, primaryKey, columnID> => columnVal

not necessary to store rows for columns which are already part of primary key

all keys for same row stored next to each other because of columnId suffix

NULL column values not stored

if all columns NULL, store sentinel

