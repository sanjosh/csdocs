
# Anycast

## equinix

https://blog.equinix.com/blog/2021/02/03/how-to-build-low-latency-services-using-anycast-routing/

anycast : you have one machine per AS advertising the IP.

two machines, geographically distributed, answering to a single IP address broadcasting to multiple AS.

BIRD : routing platform

https://en.wikipedia.org/wiki/Bird_Internet_routing_daemon

https://blog.equinix.com/blog/2020/10/29/leverage-bgp-and-bare-metal-to-build-an-anycast-network/

 using an A record that maps a domain name to a single IP address,

https://blog.equinix.com/blog/2021/06/15/how-to-solve-for-virtual-connection-migration/

## cloudflare

Instead of relying on a piece of hardware to load balance across our network, we use routing protocols to spread traffic and handle failure.

There are four major routing schemes: Unicast, Multicast, Broadcast, and Anycast.

At CloudFlare, we use Anycast at two levels: the WAN and the LAN. 

At the WAN level, every router in all of CloudFlare's 23 data centers announces all of our external-facing IP addresses

There are four key tasks that CloudFlare's servers perform: DNS, proxy, cache, and logging.

```
Using Anycast, each server within each of CloudFlare's data centers is setup to receive traffic from any of our public IP addresses. 
The routes to these servers are announced via the border gateway protocol (BGP) from the servers themselves. 
To do this we use a piece of software called Bird.
```

### problem with TCP and SSL state

Since packets will follow the shortest path, if a particular path is withdrawn then packets will find their way to the next shortest available route

At CloudFlare, we've done a significant amount of engineering to allow TCP to run across Anycast without flapping. 

This involves carefully adjusting routes in order to get optimal routing and also adjusting the way we handle protocol negotiation itself.

gets trickier still when you throw in SSL,

solution : use Segment routing in IPv6; eBPF filters remove & add SRv6 headers

(An Architecture of Highly Available Services using Anycast and Segment Routing in IPv6, Andrew Wang, Comcast)
https://pc.nanog.org/static/published/meetings/NANOG77/2082/20191030_Wang_An_Architecture_Of_v1.pdf

### crash handling

1. process crash
1. server crash
1. switch crash
1. router crash

## akamai


