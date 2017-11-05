
* memcached
* redis

--------------
# Google groupcache (brad fitzpatrick)

* read-through only (no set or expire)
* protobuf
* coordinated cache fill to prevent thundering herd
* replication of hot keys

--------------

# Caching Proxy

* twitter Twemproxy
* facebook mcrouter : proxy or embedded library (NSDI paper)
* netflix rend - proxy writing to 2 levels
* netflix evcache
* netflix mnemonic - backend is lmdb or rocksdb

--------------

Flash based cache

* facebook mcdipper 
* twitter fatcache

------------

# Salient points

* gumball entry to handle write + delete race condition
* cache listens to log to update entry

----------------

openldap mdb
https://github.com/LMDB/memcachedb
