

# Rate limiting done right

* monitor latency at server
* if latency increases, reduce advertised queue size so client gets backpressure
* limit concurrency, not the request rate for each client

effective quota = configured quota x target connections

admission control (time 28 min)
1. if client < quota OR
2. if total < target

tpsgen
latency test
throughput test

## Reference

1. Strange loop conference - Jon Moore comcast https://www.youtube.com/watch?v=m64SWl9bfvk
