
* memcached
* redis

--------------
# Google groupcache (brad fitzpatrick)

* read-through only (no set or expire)
* use protobuf
* coordinated cache fill to prevent thundering herd
* replication of hot keys

--------------


# Flash based cache

* facebook mcdipper 
* twitter fatcache

------------

# Salient points

## Gumball entry to handle write + delete race condition [Ghandeharizadeh]

purpose of delete-gumball is provide info to subsequent `put` ops

1. on delete, create (key, gumball with current timestamp) which dies after "Delta D"
2. on get, if gumball exists or no key exists, then report cache miss with 'T_miss'
3. on put, ignore if gumball created before T_miss, because its a race condition
3. on put, ignore if (current - T_miss) > D, because gumball may have existed

## cache listens to log to update entry

----------------

openldap mdb
https://github.com/LMDB/memcachedb

------------------
