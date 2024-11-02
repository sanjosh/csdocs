

# third party APIs - Uber

https://www.p99conf.io/session/enhancing-p99-latency-strategies-for-doubling-tripling-performance-in-third-party-apis/

First request latency was 3x of normal request : Move from TLS 1.2 to TLS 1.3 

Reduce number of connections - migrate from HTTP1 to HTTP2

DNS cache expires due to low traffic - use Async DNS (background thread)

Creating too many connections because keepalive was 4 seconds ; reduce to 1.5 sec


