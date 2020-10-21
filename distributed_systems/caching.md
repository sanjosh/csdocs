
* memcached
* redis

--------------
# Google groupcache (brad fitzpatrick)

* read-through only (no set or expire)
* use protobuf
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

# Effects when there is caching at multiple layers of stack

1. Informed Prefetching and Caching.  Patterson

2. Context-Aware Prefetching at the Storage Server  by Gokul Soundararajan, Madalin Mihailescu, Cristiana Amza
 	
3. Informed Prefetching for Distributed Multi-level storage systems by Maen Mahmoud Al Assaf
		 	
4. Pfc: Transparent optimization of existing prefetching strategies for multi-level storage systems by Zhe Zhang, Kyuhyung Lee, Xiaosong Ma, Yuanyuan Zhou

----------------

main ideas

* scaled ttl (increase timeout if same value returned on expiry)
* negative caching (linux fs)
* soft and hard ttl
* throttle refresh so that mass cache expiration does not cause thundering herd on backend
* client and server-side cache
* internal or external cache
* layered caching
