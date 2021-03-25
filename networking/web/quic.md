
# QUIC by Ian swett

Summary : TCP + TLS + reliable data delivery

Features:
1. Always encrypted
1. 0RTT connection
1. Multistream with no head of line blocking
1. Better loss recovery and congestion control
1. Mix reliable and unreliable transport
1. Improved privacy and reset resistance
1. Connection migration

QUIC is over UDP

previous versions HTTP/1.1 and HTTP/2

Stack becomes HTTP/3 over QUIC over TLS 1.3

HTTP/3 is not going to be backported to work over TCP

## SIGCOMM paper

Optimizations

1. Minimize memory copies
1. No memory allocation in data path
1. Dont call costly functions multiple times
1. Have workload specific data structures
1. Bind to same thread; reduce thread handoffs
1. Do batching
1. Optimize the Fast path
1. Compiler specific optimizations : data prefetch, function inlining, registers.  (Data prefetch is hard to do manually)
1. Locking; Lock free data structures
1. Memory locality : no pointer chasing, no virtual methods, keep connected data fields together
1. Feedback directed optimization

CPU rules of thumb : L1, L2, L3 cache miss.  RAM access cost is much higher

Spatial and temporal locality matter !

UDP sendmsg is 3.5 the cycle/byte of TCP in Linux

UDP GSO (segmentation offload) 

AF_XDP is new kernel API as fast as DPDK

mmap_RX_RING for receiving UDP packets.  Use BPF to steer by QUIC connection ID to send to same thread

Crypto offload (KTLS)

# Quic by Jana iyengar

improved google search latency by 3 to 8 perc, youtube rebuffers by 15 to 18 perc

TLS 1.3 copies features of QUIC Crypto

HTTP/1 : 1 RTT to setup TCP, 2 RTT to setup TLS and then head-of-line blocking

HTTP/2 : multiplex steams within a connection.

Problems:
1. Connection setup latency
1. TCP is hard to change because middle boxes have been built to analyze headers
1. TCP packet loss still causes head of line blocking because TCP is bit-based

HTTP/3 :

1. Zero RTT to a known server : send handshake followed by request without waiting for Ack
1. Stream multiplexing
1. Evolvable and deployable : no middle box interference because transport headers are encrypted 
1. Better loss recovery and congestion control : richer signaling (unique packet number), better RTT estimates
1. Resilience to NAT re-binding : 
1. In User space


## references

1. talk by Ian Swett Quic CPU performance
1. SigCOMM paper https://static.googleusercontent.com/media/research.google.com/en//pubs/archive/46403.pdf
1. talk by Jana iyengar https://www.youtube.com/watch?v=BazWPeUGS8M

