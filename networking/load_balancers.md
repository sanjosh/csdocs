
# Load balancer

 ```
...in both the L4 and L7 load balancing domains, the industry is moving away from HA pairing 
towards horizontally scalable systems that converge via consistent hashing. 

... move from hardware to software - DPDK, Linux IPVS - 

(from envoy writeup)

```

Features
1. service discovery (zookeeper, consul, etcd, dns)
2. health check
3. sticky session state
4. TLS termination
5. observability
6. security and DOS mitigation (rate limit, authentication, tarpit)
7. control plane

Approaches
1. Middle proxy 
2. Edge proxy : middle proxy accessed via internet
3. Embedded Client library : Twitter Finagle, gRPC, Eureka/Ribbon
4. Sidecar proxy (service mesh) : Linkerd, Envoy, HAProxy, NGINX

Software vs hardware LB
1. software LB is more flexible, easy to upgrade, scaleout 
2. but challenges to support connxn persistence/high throughput line-rate in software LB


## Layer4 TCP

still relevant at the edge

gives Better throughput/CPU util

### Termination type

TCP connxn is terminated

### Pass through

use NAT

this type is required for DSR and for balancing using consistent hashing

### DSR

Egress direct to client

Load balancer uses GRE instead of NAT, which enables original client IP address to be preserved

DSR may not play well with security firewalls.

### Primary-secondary LB

### LB based on Distributed Consistent hashing

```
N edge routers announce all Anycast VIPs at an identical BGP weight. Equal-cost multi-path routing (ECMP) is used to ensure that in general, all packets from a single flow arrive at the same edge router.
```

e.g. Google Maglev

## Layer7 ALB

L7 can itself have layers.  For example, in case of http, layers are : 
1. TLS, 
2. Physical HTTP(/1 or /2), 
3. HTTP headers and trailers, 
4. Messaging protocol like gRPC or REST

Features
1. timeout, retry, rate limit, circuit breaker, shadowing, buffering, content based routing
2. observability
3. extensibility (scripting via Lua)
4. fault tolerance

## why both L4 and L7

```
    Although in my opinion L7 load balancers will ultimately completely replace L4 load balancers for service-to-service 
    communication, L4 load balancers are still extremely relevant at the edge because almost all modern large distributed 
    architectures use a two-tiered L4/L7 load balancing architecture for Internet traffic

    L4 for defending attacks
    
    dual layer of defense in case of deployment instability

```

# Service Mesh/sidecar proxy type LB

1. Data planes: Linkerd, NGINX, HAProxy, Envoy, Traefik
2. Control planes: Istio, Nelson, SmartStack

Ref [2]

# Products

1. AWS NLB and ALB
2. Google Cloud Load Balancer
3. HAProxy
4. NGINX
5. Envoy

```
Envoy explicitly supports L7 protocol parsing and routing for HTTP/1, HTTP2, gRPC, Redis, MongoDB, and DynamoDB
```

## HAProxy

http://wtarreau.blogspot.com/2006/11/making-applications-scalable-with-load.html

http://www.haproxy.org/download/1.2/doc/architecture.txt

## Google Maglev

at Service start
1. Maglev keeps map of VIP to service endpoint
2. Announce VIP to router over BGP
3. Router in turn announces VIP to google backbone

On user query
1. DNS returns VIP belonging to nearest location based on load
2. router gets VIP packet, forwards to Maglev machine using ECMP
3. Maglev selects service endpoint and uses GRE to forward packet to service
4. Service sends response using DSR

Internal design 
* line rate = 10 Gbps = 813K packets per sec (1500 byte)
* userspace application - packets read/written direct from NIC without kernel intervention
* pin each packet processing thread to a CPU core
* no shared data between packet processing threads
* packet process time = 350 ns
* batch processing causes min latency of 50 usec, max of 300 usec


IP Fragment handling
* fragments do not contain 5-tuple

Debugging : packet tracer tool constructs specially marked packets which are annotated by Maglev

other LB mentioned : embrane, ananta, duet

### New maglev consistent hashing 

* goals are Load balancing and minimal disruption on change
* lookup table 
* compare to Karger and Rendezous


## Facebook Proxygen L7 LB

## Facebook Shiv L4 LB

CON of ECMP
1. ECMP - problem is that unequal load balancing not possible (?)
2. If one backend goes down, massive rehashing required

why put shiv before proxygen? 
1. solve ECMP painpoints

based on IPVS, which caused following problems
1. heavy on CPU resources - requires dedicated box
2. bad perf when lots of new connections (SYN flood)
3. ipvs is part of kernel - any change, need kernel upgrade/reboot 


## Facebook Katran L4 network load balancer

Next gen L4 after Shiv

Forwarding plane rewritten using
1. eBPF
2. XDP

used ExaBGP for the VIP announcement 

```
To avoid restrictions such as keeping L4LB and backend hosts on the same L2 domain, we use a simple IP-in-IP encapsulation. This allows us to place L4LB and backend hosts in different racks. We used the IPVS kernel module for the encapsulation.
```

Now able to co-host shiv + proxygen on same machine

forwarding plane API provided

The BPF program used for handling packets is lockless and uses a per-CPU version of BPF maps. 

Katran uses an extended version of the Maglev hash to select the backend server.  Added ability to set unequal weights.

```
Katran crafts its encapsulation to work in conjunction with RSS. Instead of using the same outer source for every IP-in-IP packet, packets in different flows (e.g., with different 5-tuples) are encapsulated using a different outer source IP, but packets in the same flow are always assigned the same outer source IP.
```

limitations
1. no fragmentation
2. only DSR
3. requires L3 topology

# Primitives used in LB

## ExaBGP

## eBPF

https://www.iovisor.org/technology/ebpf

## XDP

https://www.iovisor.org/technology/xdp

## IPVS

## GRE

## ECMP

# Reference

1. Matt Klein. https://blog.envoyproxy.io/introduction-to-modern-network-load-balancing-and-proxying-a57f6ff80236
2. Matt Klein. https://blog.envoyproxy.io/service-mesh-data-plane-vs-control-plane-2774e720f7fc
3. Eisenbud et al, Maglev. Software network load balancer https://ai.google/research/pubs/pub44824
4. Katran https://code.fb.com/open-source/open-sourcing-katran-a-scalable-network-load-balancer/TLs 
5. Katran https://atscaleconference.com/videos/networking-scale-2018-layer-4-load-balancing-at-facebook/

# TODO

1. security firewall
2. proxy & rev proxy(Squid)
3. service mesh https://redtalks.live/2017/12/18/redtalks-live-23-aspen-mesh-w-shawn-wormke/
4. https://en.wikipedia.org/wiki/Server_Name_Indication
5. Tarpit networking wiki
6. Glasnostic https://glasnostic.com/blog/news-glasnostic-aws-gateway-load-balancer
