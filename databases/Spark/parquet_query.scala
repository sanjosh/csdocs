// start bin/spark-shell

import sqlContext.implicits._

val peopleDF = sqlContext.read.json("examples/src/main/resources/people.json")

// DataFrames can be saved as Parquet files, 
// maintaining the schema information
peopleDF.write.parquet("people.parquet")

// Read in the parquet file created above
// Parquet files are self-describing so the schema is preserved
// The result of loading a Parquet file is also a DataFrame
val parquetFileDF = sqlContext.read.parquet("people.parquet")

// Parquet files can also be used to create a temporary view 
// and then used in SQL statements
parquetFileDF.registerTempTable("parquetFile")

parquetFileDF.describe()

val nameDF = sqlContext.sql("SELECT name FROM parquetFile WHERE age = 18 AND name = 'veeral'")

nameDF.explain()

//== Physical Plan ==
//Project [name#112]
//+- Filter ((age#111L = 19) && (name#112 = ve))
   //+- Scan ParquetRelation[name#112,age#111L] InputPaths: file:/home/dce/sandeep/spark-1.6.1/people.parquet, 
      //PushedFilters: [EqualTo(age,19), EqualTo(name,veeral)]
