
# two approaches

## anycast

vercel, cloudflare

Optimization is based on BGP routing and announcement with little role of DNS.

This setup is very hard to build up and scale since for anycast to work perfectly at global level, one needs lot’s and lot’s of peering and consistent transit providers at each location. If any of peers leaks a route to upstream or other peers, there can be lot of unexpected traffic on a given cluster due to break of anycast.

This saves a significant amount of IP addresses since same pools are used at multiple locations.

## DNS

Akamai, Amazon Cloudfront rely on DNS

DNS recursor

Optimization logic is pretty much with authoritative DNS server which can change around IP in order to give a location which can serve off request in optimum manner. If one of edge servers is down, algorithm can take care of it by serving other location.

These approaches fails significantly if end users do not use DNS recursors of their ISP since reply is very much dependent on location/GeoIP parameters of source IP of DNS recursor.


https://anuragbhatia.com/2014/03/networking/different-cdn-technologies-dns-vs-anycast-routing/
