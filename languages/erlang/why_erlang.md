
# Why erlang

1. Erlang programs can have thousands of independent heaps which are garbage-collected separately.
2. String concatenatation takes O(1) time because it does not use contiguous chunk of memory to represent a sequence of bytes.  It uses I/O lists
3. Cannot make blocking network call in Erlang
4. transparency of data structures (?)
5. actor model
6. message passing abstracts the differences between local and distributed processes making distributed programming easier
7. hot code loading allows for in place releases on running services without disrupting any current activity.
8. supervisor and gen_server behviors provide a superior framework for building extremely robust and fault tolerant systems.

# references

1. https://www.evanmiller.org/why-i-program-in-erlang.html
2. https://stackoverflow.com/questions/3887433/advantages-of-erlang-over-something-like-node-js
