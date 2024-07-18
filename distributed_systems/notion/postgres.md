
# sharding postgres

https://www.notion.so/blog/sharding-postgres-at-notion

https://www.notion.so/blog/the-great-re-shard

## sharding difficulties

increased maintenance burden, newfound constraints in application-level code, and architectural path dependence

the inflection point arrived when the Postgres VACUUM process began to stall consistently, preventing the database from reclaiming disk space from dead tuples

more worrying was the prospect of transaction ID (TXID) wraparound, a safety mechanism in which Postgres would stop processing all writes to avoid clobbering existing data

## application level sharding

off the shelf : Citus for Postgres or Vitess for MySQL.

```
the block table was the highest-priority for sharding.
However, a block may reference other tables like space (workspaces) or discussion (page-level and inline discussion threads).
In turn, a discussion may reference rows in the comment table, and so on.

We decided to shard all tables reachable from the block table via some kind of foreign key relationship.
Not all of these tables needed to be sharded, but if a record was stored in the main
database while its related block was stored on a different physical shard,
we could introduce inconsistencies when writing to different datastores.
```

partition data by workspace ID

our goal was to design a sharded setup that would handle our existing data and scale to meet our two-year usage projection with low effort. 

why 480 shards ?  480 is divisible by a lot of numbers — which provides flexibility to add or remove physical hosts while preserving uniform shard distribution

We wanted a single source of truth for routing from a workspace ID to a logical shard, so we opted to construct the tables separately and perform all routing in the application.

Physical database (32 total) and Logical shard, represented as a Postgres schema (15 per database, 480 total)
