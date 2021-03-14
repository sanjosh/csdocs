
# STUN

https://tools.ietf.org/html/rfc5389

# TURN

Traversal Using Relays around NAT

# ICE

Internet Connectivity Establishment
https://tools.ietf.org/html/rfc8445
NAT for UDP

# Designing a NAT-friendly protocol (Wireguard from Tailscale )

how to get 2 clients behind NAT to talk to each other without a server ?

examples of NAT-friendly protocol : WebRTC, QUIC, Wireguard

Let’s say you’re making your own protocol and that you want NAT traversal. You need two things.

First, the protocol should be based on UDP. if you need stream, consider QUIC

Second, you need direct control over the network socket that’s sending and receiving network packets. Some protocols tightly integrate the NAT traversal with the rest (e.g. WebRTC).

## stateful Firewalls

1. Windows Defender firewall, 
1. Ubuntu’s ufw (using iptables/nftables), 
1. BSD pf (also used by macOS) 
1. AWS Security Groups

mostly, allow all outbound and block all inbound

firewalls allow based on what packets seen in the past

how to get 2 clients behind NAT to talk to each other without a server ?
1. get one side to open a port
2. let packets flow out and let firewall see them

## to communicate, first you need to be able to communicate.

NAT mappings get created when outbound traffic towards the internet requires it.

As long as some packet flow outwards with the right source and destination, any packet that looks like a response will be allowed back in, even if the other side never received your packet!

if both sides use fixed IP and ports, this can go through both firewalls.  

But both endpoints must attempt communication at roughly the same time. Stateful firewalls have limited memory, meaning that we need periodic communication to keep connections alive

## how to handle variable ports - STUN

when you talk to a server on the internet from a NATed client, the server sees the public ip:port that your NAT device created for you, not your LAN ip:port. So, the server can tell you what ip:port it saw

That’s fundamentally all that the STUN protocol is: your machine sends a “what’s my endpoint from your point of view?” request to a STUN server, and the server replies with “here’s the ip:port that I saw your UDP packet coming from.”

this is why the NAT traversal logic and your main protocol have to share a network socket. Each socket gets a different mapping on the NAT device, so in order to discover your public ip:port, you have to send and receive STUN packets from the socket that you intend to use for communication

But some NAT devices are more difficult; they create a completely different NAT mapping for every different destination that you talk to

This is called 
1. Endpoint-dependent mapping  : subcategory that specifies whether the mapping varies only on the destination IP, or on both the destination IP and port.
2. Endpoint-independent mapping (EIM)

## type of NAT : 

1. Full Cone
2. Restricted Cone
3. Port-Restricted Cone 
4. Symmetric

Easy NAT = home router
Hard NAT = office or cloud gateway

RFCs 4787 (NAT Behavioral Requirements for UDP), 5382 (for TCP) and 5508 (for ICMP)

Problem : when NAT traversal fails or when you need a side-channel ?  
Answer : we created DERP (Detoured Encrypted Routing Protocol), which is a general purpose packet relaying protocol. It runs over HTTP,

## NAT port mapping protocols

“Hi, please forward a WAN port to lan-ip:port,” and “okay, I’ve allocated wan-ip:port for you.

UPnP IGD Universal Plug’n’Play Internet Gateway Device) 

NAT-PMP

PCP (port control protocol)

## Double NAT or carrier-grade NAT

New problem : how do we connect two peers who are behind the same CGNAT, but different home NATs within?   
Answer : NAT must support hairpinning : notice its an internal address

Here STUN fails, instead use port mapping protocol

## IPv6

NAT64 = translates between IPv4 and IPv6 (with DNS64)

NAT44 : only IPV4

CLAT (Customer side translator) makes the OS pretend that it has direct IPv4 connectivity, using NAT64

CLAT is very common on mobile devices, but very uncommon on desktops, laptops and servers.

Detecting NAT64+DNS64 is easy: send a DNS request to ipv4only.arpa. That name resolves to known, constant IPv4 addresses, and only IPv4 addresses. If you get IPv6 addresses back, you know that a DNS64 did some translation to steer you to a NAT64. That lets you figure out what the NAT64 prefix is.


## Mechanisms for NAT traversal

1. Hairpinning (Double NAT)
2. relay (when all fails)
3. port mapping 

## Which NAT traversal solution to apply ?

Use ICE to decide (RFC 8445)

try everything at once, and pick the best thing that works.

swap candidate lists with our peer through the side channel, and start sending probe packets at each others' endpoints

One thing to be wary of is asymmetric paths. ICE goes to some effort to ensure that both peers have picked the same network path, so that there’s definite bidirectional packet flow to keep all the NATs and firewalls open.

## Summary

For robust NAT traversal, you need the following ingredients:

1. A UDP-based protocol to augment
1. Direct access to a socket in your program
1. A communication side channel with your peers
1. A couple of STUN servers
1. A network of fallback relays (optional, but highly recommended)

Then, you need to:

1. Enumerate all the ip:ports for your socket on your directly connected interfaces
1. Query STUN servers to discover WAN ip:ports and the “difficulty” of your NAT, if any
1. Try using the port mapping protocols to find more WAN ip:ports
1. Check for NAT64 and discover a WAN ip:port through that as well, if applicable
1. Exchange all those ip:ports with your peer through your side channel, along with some cryptographic keys to secure everything.
1. Begin communicating with your peer through fallback relays (optional, for quick connection establishment)
1. Probe all of your peer’s ip:ports for connectivity and if necessary/desired, also execute birthday attacks to get through harder NATs
1. As you discover connectivity paths that are better than the one you’re currently using, transparently upgrade away from the previous paths.
1. If the active path stops working, downgrade as needed to maintain connectivity.
1. Make sure everything is encrypted and authenticated end-to-end.



https://tailscale.com/blog/how-nat-traversal-works/
