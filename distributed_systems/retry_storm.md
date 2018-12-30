
# Handling retry storm

service
1. identify client
2. convey accurate info in response (is it throttle/internal- retryable or not/client - see aws)
3. if retry, what should be retry interval

client
1. do not retry
2. ensure retry interval is high enough
3. add jitter to retry
4. throttle the calls
5. develop fallback
6. use stale data (caching)


