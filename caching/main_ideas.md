
# three types 

1. latency cache : reduce latency (most common)
2. capacity cache : reduce TPS demands on backend; can cause thundering herd
3. availability cache : reduce downtime

https://www.robustperception.io/the-three-types-of-cache

# policy 

general idea
1. reuse distance

known
1. ARC
2. LRU

# writeback vs write-thru

# negative caching (linux fs)

# expiration

1. scaled ttl (increase timeout if same value returned on expiry; by twitter)
2. soft and hard ttl

# throttle 

throttle refresh so that mass cache expiration does not cause thundering herd on backend

# location of cache

1. client and server-side cache
2. internal or external cache


# layered caching (multi-tiered)

