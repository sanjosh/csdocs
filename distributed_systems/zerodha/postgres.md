
# postgres

pgconf india 2023

https://www.youtube.com/watch?v=nQiwg7siXG0

1. dont overdo index
2. denormalize and materialized views
3. delete unnecessary data
4. vacuum full versus vacuum analyze
5. tune individual tables instead of db
6. understand the query planner


# postgres - 2

https://zerodha.tech/blog/working-with-postgresql/

1. denormalize or materialized view
2. monthly partitions by timestamp
3. storing auto-increment IDs unnecessary


```
Since sharding by month progressively slows down bulk insert speeds as the month goes on, we use a temporary table to bulk insert the daily data and then use that throughout the next day for user-facing queries (a significant number of queries are for that data) and sync it to the actual table asynchronously.
```
and
```
 You can understand table health by querying pg_stat_user_tables. This tells you when a table was last vacuumed with which you can figure out if your vacuuming settings are optimal or not. You can also consider using the pg_stat_statements extension to record and analyze query usage metrics. It tells you the execution time of your queries, and how many times a particular table has been queried.
```

## common table expressions

```
CTEs (Common Table Expressions) can help compartmentalize and re-use sub-queries in a complex query. For large, complex queries, splitting them into CTEs and re-using them can help get better query plans and performance. Also, CTEs in a query run concurrently, so that can also big a plus. We’ve used CTEs heavily to optimize our queries.
```
