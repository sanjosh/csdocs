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

--------------  

// The same query run on an ORC file format

import org.apache.spark.sql._

sqlContext.setConf("spark.sql.orc.filterPushdown", "true")

case class Contact(name: String, phone: String)
case class Person(name: String, age: Int, contacts: Seq[Contact])

val records = (1 to 100).map { i =>; 
Person(s"name_$i", i, (0 to 1).map { m => Contact(s"contact_$m", s"phone_$m") })
}

sc.parallelize(records).toDF().write.format("orc").save("people")

val people = sqlContext.read.format("orc").load("people")

people.registerTempTable("people")

val nameDF = sqlContext.sql("SELECT name FROM people WHERE age = 15 and name='veeral'")

nameDF.explain(true)

// == Physical Plan ==
// Project [name#6]
// +- Filter ((age#7 = 15) && (name#6 = veeral))
   // +- Scan OrcRelation[name#6,age#7] InputPaths:
   // file:/home/dce/sandeep/spark-1.6.1/people, PushedFilters: [EqualTo(age,15),
   // EqualTo(name,veeral)]
