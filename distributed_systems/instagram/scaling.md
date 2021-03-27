
# scaling infra

https://www.youtube.com/watch?v=hnpzNAPiC0E

storage
1. Cassandra : user feeds, activities
1. Postgres : user, friendship, media
1. memcache : key value

Computing
1. django : backend server
1. rabbitmq 
1. celery

comment flow
1. django
2. insert into postgres 
3. insert memcache

get feed flow
1. django
1. memcache

## replication and consistency

but we have stale memcache problem
1. hashing to data center based on userId
2. but replication of postgres is slow
3. postgres log daemon goes and invalidates memcache

how to display number of likes to user ?

since we invalidate cache after every write, query goes to db
1. so we store counts by mediaId 

but we still have thundering herd
1. so we changed memcache read
1. first memcache read also gets a lease
1. second memcache read - says dont go to database

so multi-dc works,   
but latency to europe and asia is higher

## scale-up

### CPU

how to use fewer CPU instructions, and use fewer servers

* we do CDN URL generation based on particular mobile devices
* used cython for optimizing code
* disable garbage collection in python

### network latency

each django can execute one request at a time

Three things shown in home page
1. stories
2. feed
3. suggested users

Fetch them in parallel - async IO

## Dev team scaling

For new feature, questions to answer
1. which server
2. new table or new column
2. cache ?
4. what index

Use TAO = DB + memcache.  Declarative data model

Source control branching : use one master approach

takes 10 min to deploy to 20K servers; do rollout about 50-60 times a day

use gates to control visibility to feature

