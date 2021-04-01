
# SPOCA Yahoo content delivery

Chawla, Semantics of Caching with SPOCA: A Stateless, Proportional, Optimally-Consistent Addressing Algorithm
2011 Usenix

Zebra determines which serving cluster will handle a given request based on geolocality and popularity.

SPOCA determines which front-end server within that cluster will cache and serve the request.

1. Each front-end server is assigned a portion of the hash space according to its capacity.
1. The SPOCA routing function uses a hash function to map names to a point in a hash space.
1. Input = the name of the requested content
1.  Output = the server that will handle the request.
1.  Re-hashing happens till the result maps to a valid hash space.
