
1. Move from memcached to Redis
2. replicated Redis backend with client-side sharding.
3. use Redis TTL (instead of separate Memcached "reset_key_at" key as was done earlier)

race conditions hit

## wobble (going back in time) because TOCTOU (time of check, time of use)

Ruby called Redis 

time difference between Redis decision to throttle and the setting of http header in Ruby script

solve by persisting "reset at" time from Ruby to DB

## throughput dilution : rejected even though capacity

Redis replica had lag

Rejection was done based on Redis secondary, Current Capacity was returned based on Redis Primary


https://github.blog/2021-04-05-how-we-scaled-github-api-sharded-replicated-rate-limiter-redis/
