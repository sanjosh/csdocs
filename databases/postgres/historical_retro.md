
# Looking Back at Postgres

https://arxiv.org/pdf/1901.01973

# hacker news

https://news.ycombinator.com/item?id=23529954

## extensible data types

##  cost of UDF

```
 Postgres was the first DBMS to
capture the costs and selectivities of UDFs in the database catalog.
We approached the optimization problem by coming up with an
optimal ordering of selections, and then an optimal interleaving
of the selections along the branches of each join tree considered
during plan search
```

## log as data, data as log

```
The Postgres storage engine unified the notion of primary storage and historical logging into a single, simple disk-based representation. At base, the idea was to keep each record in the database in a linked list of versions stamped with transaction IDs—in
some sense, this is “the log as data” or “the data as a log,” depending on your point of view. The only additional metadata required
is a list of committed transaction IDs and wall-clock times. This
approach simplifies recovery enormously, since there’s no “translating” from a log representation back to a primary representation.
It also enables “time-travel” queries: you can run queries “as of”
some wall-clock time, and access the versions of the data that were
committed at that time.
```
