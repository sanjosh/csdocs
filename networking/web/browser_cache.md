
# caching

## cache-control

no-cache, no-store, private, public

## etag

## last-modified

## s-max-age

## max-age

# zerodha

The browser caches a file, stores a hash, the E-Tag, 
and checks with the server if the file has changed by sending the E-Tag

On the server side, there is a Redis map that maintains the E-Tags per user per resource. 

This tag is deleted when the cache becomes invalid, forcing a full HTTP 200 
response the next time there’s a request.

https://zerodha.tech/blog/scaling-with-common-sense/
