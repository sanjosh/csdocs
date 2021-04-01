

# Data center routing protocols

* Layer 2 - Spanning Tree protocol - MAC Addresses 
* layer 3 - IP addresses

Data centers are much bigger than they were a decade ago, with application requirements vastly different from the traditional client–server applications, and with deployment speeds that are in seconds instead of days. This changes how networks are designed and deployed.

 Instead of a few hundred servers that represented a large network in the past, modern data centers range from a few hundred to a hundred thousand servers in a single physical location. 

The applications that these organizations built—primarily search and cloud—represent the third wave of application architectures. The first two waves were 

1. the monolithic single-machine applications
2. the client–server architecture

 that dominated the landscape at the end of the past century.

Server-to-server communications is often called East-West traffic, because diagrams typically portray servers side-by-side. 

In contrast, traffic exchanged between local networks and external networks is called North-South traffic.

Multitenant networks such as public or private clouds have an additional consideration: *rapid deployment and teardown of a virtual network*. Given how quickly VMs—and now containers—can spin up and tear down, and how easily a customer can spin up a new private network in the cloud, the need for rapid deployment becomes obvious.

The web-scale pioneers picked a network topology called Clos to fashion their data centers. 

*Spine-Leaf *: servers are interconnected to the leaf via lower-speed links and the switches are interconnected by higher-speed links. A common deployment is to interconnect servers to leaves via 10 Gbps links, while interconnecting switches with one another via 40 Gbps links.

This is fundamentally the beauty of a Clos network: *like fractal design, larger and larger pieces are assembled from essentially the same building block*s. Web-scale companies don’t hesitate to go to 4-tier or even 6-tier Clos networks to work around the scale limitations of smaller building blocks. Coupled with the ever-larger port count support coming in merchant silicon, support for even larger data centers is quite feasible.

Thus, the first conclusion is that routing is best suited for Clos networks, and bridging is not.

A key benefit gained from this conversion from bridging to routing is that we can shed the multiple protocols, many proprietary, that are required in a bridged network.

How does a data center connect to the outside world? The answer to this question ends up surprising a lot of people. In medium to large networks, this connectivity happens through what are called border ToRs or border pods. 

ToR = Top of Rack switch

The main advantage of *border pods or border leaves *is that they isolate the inside of the data center from the outside. The routing protocols that are inside the data center never interact with the external world, providing a measure of stability and security.

*Multitenancy* : The Clos topology is also suited for building a network to support clouds, public or private.

OSPF
1. was rejected by most web-scale operators because of its lack of multiprotocol support.  In other words, OSPF required two separate protocols, similar mostly in name and basic function, to support both IPv4 and IPv6 networks.

IS-IS 
1. far better regarded protocol that can route both IPv4 and IPv6 stacks. 
1. However, good IS-IS implementations are few, limiting the administrator’s choices. 
1. link-state protocol was inherently unsuited for a richly connected network such as the Clos topology. Link-state protocols propagated link-state changes to even far-flung routers—routers whose path state didn’t change as a result of the changes.

why BGP  ?
1. less chatty than its link-state cousins, 
1. supports multiprotocols (i.e., it supports advertising IPv4, IPv6, Multiprotocol Label Switching (MPLS), and VPNs natively). 

With some tweaks, we can make BGP work effectively in a data center. Microsoft’s Azure team originally led the charge to adapt BGP to the data center.

what is different?
1. dense connectivity of the data center network different 
1. relatively sparse connectivity between administrative domains. 

A different set of trade-offs are relevant inside the data center than between data centers. 
1. service provider network : prefer stability over rapid notification of changes.  BGP typically holds off sending notifications about changes for awhile. 
1. data center network:  operators want routing updates tobe as fast as possible. 

BGP modified link failure handling 
1. a single link failure can result in an inordinately large number of BGP messages passing between all the nodes, which is best avoided. 

BGP modified for multiple paths
1. construct a single best path when a prefix is learned from many different Autonomous System Numbers (ASNs), because an ASN typically represents a separate administrative domain. 
1. But inside the data center, we want multiple paths to be selected

BGP in data center RFC 7938 https://tools.ietf.org/html/rfc7938

In the data center, eBGP and not iBGP is the most common deployment model

Autonomous System Number (ASN) is a fundamental concept in BGP. Every BGP speaker must have an ASN. ASNs are used to iden‐tify routing loops, determine the best path to a prefix, and associated routing policies with networks. 

ASNs used within the data center comefrom the private ASN number space

To avoid the problem of path hunting, the ASN numbering model for routers in a Clos topology is as follows:
1. All ToR routers are assigned their own ASN.
1. Leaves across a pod have a different ASN, but leaves within each pod have an ASN that is unique to that pod.
1. Interpod spines share a common ASN.

Metrics for best path :
1. OSPF, IS-IS, and other routing protocols have a simple metric by which to decide which of the paths to accept. 
1. BGP has eight!  Only one matters forthe data center: AS_PATH.

In traditional data center networks, the boundary between bridging and routing, the L2–L3 gateway, was where services such as firewall and load balancers were deployed.  The boundary was a natural fit because the boundary represented in some sense the separation of the client from the server. It was logical to assign firewalls at this boundary to protect servers from malicious or unauthorized clients.

Similarly, load balancers front-ended servers, typically web servers, in support of a scale-out model. This design also extended to fire‐walls, where load balancers front-ended a row of firewalls when thetraffic bandwidth exceeded the capacity of a single firewall.  These firewalls and load balancers were typically appliances, which were usually scaled with the scale-in model; that is, purchasing larger and larger appliances to support the increasing volume of traffic.

Virtual machines (IP address not constrained to single rack)
1. In the new world, the services are provided by virtual machines(VMs) running on end hosts or nonvirtualized end hosts. Two popular services provided this way are the load balancer and firewall services. In this model, as the volume of traffic ebbs and flows, VMs can be spun up or down dynamically to handle the changing trafficneeds.

Because the servers (or VMs) providing a service can pop up any‐where in the data center, the IP address no longer can be constrained to a single rack or router. Instead, potentially several rackscould announce the same IP address. With routing’s ECMP for‐warding capability, the packets would flow to one of the nearestnodes offering the service. 

BGP running on the server really needs to be just a BGP speaker, and doesn’t have to implement a full routing protocol with best-path computation, programming routes into the routing table,and so on. 

Web-scale pioneers recognized this and ran software such as ExaBGP, which only functioned as BGP speaker, for a long time.  

Today more full-featured open source routing suites such as FRRouting and BIRD routing are available for use on Linux and BSD servers.

## reference 

1. BGP in the data center, Dinesh Dutt https://www.oreilly.com/library/view/bgp-in-the/9781491983416/ch01.html 

https://www.xenon.com.au/wp-content/uploads/dlm_uploads/2017/10/BGP_Oreilly-2.pdf


## LVSR


 A variety of topologies have resulted, such as Clos, multi-tier leaf-spine, hypercube and Toroidal, which impose different demands on how best to distribute flows through data center networks and the need for better routing protocols.

Data centers are vastly different than the WAN networks that existed 20 years ago. The era of SDN-based control and the shift towards hyperscale IoT, cloud-based and real-time experience services are driving the need for a hybrid routing protocol in data centers. Hybrid routing protocols like BGP-based LSVR

https://www.datacenterdynamics.com/opinions/finally-cloud-scale-data-center-routing/

# Network architecture

## Spine-Leaf 

Leaf switches & spine switches

With virtualized servers, applications are increasingly deployed in a distributed fashion, which leads to increased east-west traffic 

good when east-west traffic (horizontal) more than north-south (vertical)

Spine switches have higher port density

Data flows within a leaf-spine fabric, on the other hand, take the same number of hops on the network regardless of the source and destination. The primary reason for this is that a leaf-spine architecture is fully-meshed as opposed to three-tier models that are only partially meshed.


## facebook

You can see where Facebook is using 1U fixed port switches where their largest modular chassis aren’t big enough: 

`*Fabric Aggregator: A flexible solution to our traffic demand*`

https://code.facebook.com/posts/226845501211938/fabric-aggregator-a-flexible-solution-to-our-traffic-demand/

https://engineering.fb.com/networking-traffic/fabric-aggregator-a-flexible-solution-to-our-traffic-demand/

https://engineering.fb.com/data-center-engineering/facebook-open-switching-system-fboss-and-wedge-in-the-open/


## google


Google’s efforts revolve around a three pronged plan of attack: 
1. use a Clos topology (https://en.wikipedia.org/wiki/Clos_network), 
2. use SDN (https://www.youtube.com/watch?v=ED51Ts4o3os) (Software Defined Networking), and 
3. build their own custom gear in their own Googlish way. 

http://highscalability.com/blog/2015/8/10/how-google-invented-an-amazing-datacenter-network-only-they.html

http://conferences.sigcomm.org/sigcomm/2015/pdf/papers/p183.pdf
Jupiter Rising: A Decade of Clos Topologies and Centralized Control in Google’s Datacenter Network

*The Datacenter as a Computer: An Introduction to the Design of Warehouse-Scale Machines*
https://ai.google/research/pubs/pub35290

