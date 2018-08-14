# Bitmap index

## Data types

Data types 
1. Ordinals (that which can be compared; e.g. age of people) vs categoricals (cannot be compared e.g. city names)
2. Finite (integer : low, high) vs infinite cardinality (floating point)

Range queries can use bitmap indices if data type is ordinal.

NULL values in a column can be stored in a separate bitmap

## Encoding schemes

A bitmap index is a two dimensional bit matrix.

### Equality encoding 

If a column named “City” has 3 values (Delhi, Kolkata, Mumbai), then each value becomes an independent bitmap.  A column is an array of bitmaps.  

Number of bitmaps = number of values taken by column

* City column = bitmap[Mumbai] + bitmap[Delhi] + bitmap[Kolkata]
* If a row has a particular value, then bit in corresponding bitmap is set 
* If row[city] is Delhi, then bitmap[Delhi]=1 and bitmap[Kolkata]=0 and bitmap[Mumbai]=0
* Only one bitmap can have “1” bit for a particular row

|Attribute|Bitmap_Delhi|Bitmap_Kolkata|Bitmap_Mumbai|
|---------| ---------  | --------     | ------------|
|Delhi? | 1 | 0 | 0|
|Kolkata? | 0 | 1 | 0|
|Mumbai? | 0 | 0 | 1|

### Range encoding

Only works for values which can be compared against each other (i.e. ordinals, not categorical types)

Set the “1” bit for all bitmaps above that value.

### Bit sliced Index

[O’Neil and Quass 1997]
https://www.cs.duke.edu/courses/spring03/cps216/papers/oneil-quass-1997.pdf


### Attribute value decomposition 

[Chan and Ioannadis 1999]
http://www09.sigmod.org/sigmod/sigmod99/eproceedings/papers/chan.pdf

### Interval encoding

If number of values that a column can take is C, then keep C/2 bitmaps.

Good for two-sided range queries
[Chan and Ioannadis 1999]

### K-Of-N encoding

Keep N bits but only turn on K at a time

Number of column values it can represent =  [ (N!) / (N - K)! ] 

[Wong 1985]
http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.99.9693&rep=rep1&type=pdf

### RID List


## Queries on bitmap indices

Map each query to bitmap operations

### NOT

The underlying compressed bitmap must support a “bit flip” operation.

### Exact

Return all rows for which bitmap[Delhi] = 1

### Range

Range query can be one-sided (column < X) or two-sided  (X < column < Y)

For equality encoding, you have to do an OR of all the compressed bitmaps.  

For other encoding schemes, exact operation depends on the scheme.

### Aggregation and Iceberg query

Iceberg query is a special type of aggregation query which returns values above a threshold.

## Libraries available

### Bitmap Index

https://github.com/gingi/fastbit/tree/master/src

### Roaring Bitmap

Currently the fastest bitmap compression library, it uses adaptive encoding.

It supports following operations

1. intersection of two bitmaps
2. Union of two bitmaps
3. Symmetric union of two bitmaps
4. Difference between two bitmaps
5. Is the N-th bit set ? [contains]
6. Invert the bitmap [NOT operation]
7. Union of N bitmaps


## High Cardinality 

Because the size and efficiency of a bitmap index doesn’t just depend on the number of distinct values but a whole range of other factors as well, not least the size and the clustering of the data in the table.

https://richardfoote.wordpress.com/2010/02/18/myth-bitmap-indexes-with-high-distinct-columns-blow-out/

How to optimize bitmap indexes for high cardinality

http://i.cs.hku.hk/~ssdbm/slides/SSDBM.July11/Session7.2.pdf

Breaking the Curse of Cardinality on Bitmap Indexes

Kesheng Wu, Kurt Stockinger and Arie Shoshani
http://crd-legacy.lbl.gov/~kewu/ps/LBNL-173E.html

### Use binning


https://www.iaria.org/conferences2013/filesDBKDA13/keynote-dbkda-2013-final.pdf

Sec 6.4 of Accelerating queries on large datasets
http://crd-legacy.lbl.gov/~kewu/ps/LBNL-1677E-draft.pdf

Equi-width bins or logarithmic binning

### Order-preserving Bin-based Clustering

## TODO

https://richardfoote.wordpress.com/2010/05/06/concatenated-bitmap-indexes-part-i-two-of-us/

http://www.oaktable.net/category/tags/bitmap-indexes

Multi-column Bitmap Indexing by Eduardo Gutarra Velez

http://pizza.unbsj.ca/~owen/backup/EdThesis.pdf
```how do we efficiently determine whether a multi-column bitmap index is relatively small without first constructing it? We tried modeling the problem in terms of statistical characteristics such as correlation. However, we found simple heuristics based on indexing samples most effective. 
```
