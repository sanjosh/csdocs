
# overview

https://www.youtube.com/watch?v=9Rdwh0rNaf0

## In-process architecture

single file format

written in C++11

## storage

analytical 

columnar format

vectorized execution (SIMD)

zonemaps (min max indexes)

## Postgres dialect

## portable

duckdb in browser and phone using wasm

## formats

csv, parquet, json, iceberg, delta

## duckdb can directly read pandas df whose name is deduced from python variable name

```
When you run a query in SQL, DuckDB will look for Python variables whose name matches the table names in your
query and automatically start reading your Pandas DataFrames. Looking back at the previous example we can see this in action:

The SQL table name mydf is interpreted as the local Python variable mydf that happens to be a Pandas DataFrame,
which DuckDB can read and query directly. The column names and types are also extracted automatically from the DataFrame.


```

https://duckdb.org/2021/05/14/sql-on-pandas.html

replacement scan

https://github.com/duckdb/duckdb/blob/c3ca3607c221d315f38227b8bf58e68746c59083/tools/pythonpkg/src/python_replacement_scan.cpp#L7


## file format is backward compat - snowduck

## extensions

new types, data formats, operators, sql syntax, compression, mem allocator

## limitations

not multiple writers, not write-heavy, only single node 


# in browser

https://duckdb.org/2024/10/02/pyodide.html

