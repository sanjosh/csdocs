# DynamoDB

# keys

* partition key = hash key
* sort key = range key - orders elements within partition
* uniqueness decided solely by partition key

# secondary index

* need not be unique
* every item need not have the indexed attribute set (i.e. index can be sparse)
* projected attributes = same as covering index

# LSI

has same partition key but different sort key

# GSI

has different partition and sort key

## global table

replication across regions

## point in time backup

* intent log
* storage engine - innodb
* backup/restore is partition-aware
* prioritize replica addition over backup
* incremental backups ( overall size much greater rate of change )
* archive logs to s3; store metadata with log
* sweet spot for time between snapshots in order to optimize restore time
* per-second resolution, upto 35 days

* leases for freq work at consistent rate
* locks for infrequent work at inconsistent rate 
