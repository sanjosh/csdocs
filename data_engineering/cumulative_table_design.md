
# at fb

https://github.com/DataExpert-io/cumulative-table-design

```
We initially build our daily metrics table that is at the grain of whatever our entity is. This data is derived from whatever event sources we have upstream.

After we have our daily metrics, we FULL OUTER JOIN yesterday's cumulative table with today's daily data and build our metric arrays for each user. This allows us to bring the new history in without having to scan all of it. (a big performance boost)
```
