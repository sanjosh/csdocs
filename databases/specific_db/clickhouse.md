
# Yandex Clickhouse

metrage ?
Yandex metrica ?

* no update support
* no nested schema support
* all in C++
* support joins
* use LSM tree
* vectorized query execution
* 17 diff algo used for group by based on data types
* hashtable for few fields, int, string
* uniqCombined uses 3 diff data structures - array, hashtable, hyperloglog
* not realtime but near realtime
* form 10k rows create 1 batch per sec

* use boost
* use Poco library
* no google test
* no thrift
* no parquet, arrow etc
* no lex, yacc

* Wikimedia found it faster than druid
* compare against InfiniDB, Vertica, Spark-Parquet

* HTTP, JDBC, ODBC, 
* python, php, Perl, Go, Nodejs, Ruby, Scala, Rust

