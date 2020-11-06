
# why retry 

failure due to packet loss, stale tcp connections, transient host failures

# why retry bad

can exhaust client thread pool, exhaust connections, exhaust service by creating duplicate work

# when to retry

1. server logic failure : NO
2. service overloaded  : do delayed retry.  Response to client must include "retry-after" value
3. transient failure : retry
4. hit rate limit : custom retry

# how to retry

##  exp backoff + circuit breaker 

exp backoff causes call amplification (bcos client of client will also retry)

circuit breaker reduces availability since it is binary and turns off calls completely.

## adaptive retry 

throttle calls based on budget to prevent call explosion

# client-side

1. do not retry
2. ensure retry interval is high enough
3. add jitter to retry
4. use token to mark duplicate request 
5. set expire-after deadline to prevent stale request processing
6. expire-after deadline must be less than the caller's deadline
7. develop fallback if failure
8. use stale data (caching)


# server-side

1. identify the client 
2. identify if request is duplicate
3. identify if request has expired
4. convey accurate error in response (is it throttle/internal- retryable or not/client - see aws)
5. if retryable error, convey to client the retry interval

# what to measure 

did retry improve availability ?

1. did retry make it to server
2. how many retries before success
