
# Uber Schemaless on MysQL

Migrated from Postgres to Mysql

Postgres 
* high write amplification : change in one column causes rowid to change; which requires updating every index.
* replication is physical
* opens new process per connection
* uses system V ipc instead of futex

MySQL
* need 2 lookups to find original row from secondary index.  secondary index tells u primary key.  then primary index tells you the physical row given primary key
* innodb has rollback segment for old versions of row
* new thread per connection
* uses futexes

In a Uber Trip row, one column after other gets updated.

* Triggers
* Indexes are denormalized - index contain extra fields
* Indexes are sharded
* Index support equaliy, non-equality, range queries
* index eventually consistent

## Schemaless cell

* each schemaless cell is immutable
* it becomes a row in MySQL entity table 
* {row_key, col_name, ref_key} => body
* body is json compressed with msgpack and zlib

# References

https://eng.uber.com/mysql-migration/
https://eng.uber.com/schemaless-part-one/
https://eng.uber.com/schemaless-part-two/
https://eng.uber.com/schemaless-part-three/
