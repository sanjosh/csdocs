

https://www.amazingcto.com/postgres-for-everything/

Use Postgres for caching instead of Redis with UNLOGGED tables and TEXT as a JSON data type. Use stored procedures or do as I do, use ChatGPT to write them for you, to add and enforce an expiry date for the data just like in Redis.

Use Postgres as a message queue with SKIP LOCKED instead of Kafka (if you only need a message queue). Or as a job queue in Go with River

Use Postgres with Timescale as a data warehouse.

Use Postgres with pg_analytics as an in memory OLAP with Apache Datafusion

Use Postgres with JSONB to store Json documents in a database, search and index them - instead of Mongo.

Use Postgres as a cron demon to take actions at certain times, like sending mails, with pg_cron adding events to a message queue.

Use Postgres for Geospacial queries.

Use Postgres for Fulltext Search instead of Elastic.

Use Postgres to generate JSON in the database, write no server side code and directly give it to the API.

Use Postgres with auditing with pgaudit

Use Postgres with a GraphQL adapter to deliver GraphQL if needed.
