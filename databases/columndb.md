
# The Design and Implementation of Modern Column-Oriented Database Systems

Daniel Abadi et al 

Main advantage : only access columns needed by query.
but if query needs to access only one record, it must read all columns

Columns-Read/Table-width is small for data warehouse dbs

Column-Store more suited for analytic applications.

MonetDB, VectorWise and C-Store

Storage:

Instead of tuple identifier to identify every row in a column, one can use position(offset) of tuple in column as a Virtual ID 

Store each attribute as fixed width, Store each record in same position across all columns of table

Column-specific compression

Vector processing of blocks of tuples.

Avoid join of columns or semi-joins possible as opposed to traditional hash or merge joins.

Direct operation on compressed data

Store same column sorted by different criteria.

Do not index column - generate index dynamically

Writes can be slow since multiple columns have to be written and compression is needed.  Data is first written in uncompressed, write-optimized pattern and then flushed periodically.

rows vs columns : N-ary storage model (NSM) vs Decomposition Storage Model (DSM)

How to process "deletes" and "update"

How to reconstruct rows from multiple column files

Joins
