
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


