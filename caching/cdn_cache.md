
# frontend

Use content hashing (e.g. app.9f1234.js) to make the items cacheable forever (immutable), and only invalidate when they actually change.

# cache headers

Cache-Control: public, max-age=31536000, immutable

Cache-Control

ETag

Expires

# CDN - DNS records

 DNS A/AAAA/CNAME records.

```
 User --> DNS Lookup for app.com
     --> Gets IP of nearest CDN edge node
     --> Sends HTTP request to CDN (e.g. GET /static/app.js)
         --> If cached: serve from edge
         --> Else: fetch from origin server → cache → return
```
