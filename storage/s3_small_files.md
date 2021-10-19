
# object compaction in cloud p99 conf tejas chopra netflix 

s3 expensive for small files

to store 1 TiB worth of 4K files, 100 writes/sec

1. S3 : operation cost 90 percent
2. EFS : no operation cost
3. DynamoDB : operation cost is 16 percent
4. S3 with compaction : you have to handle rename, delete


gridfs https://docs.mongodb.com/manual/core/gridfs/
