
# Four types of rate limiters

request rate limiter : 

concurrent request limiter : max outstanding jobs

fleet usage load shedder : ensure some percent of fleet available for critical API requests

worker utilization load shedder : shed low priority

# how to implement

Redis

shadow launch (dry run) capability 

dynamic turn off

https://stripe.com/blog/rate-limiters
