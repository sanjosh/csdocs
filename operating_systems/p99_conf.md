
# Avi kivity

how to effectively mix throughput and latency computing

application level task isolation
low overhead with cooperative scheduling
good cpu affinity
fewer surprises from kernel

stall detector


# Peter Zaitsev

performance analysis for databases

USE
requires good understanding of arch and low level resource monitoring


RED
dont need to know internal details


Four Golden signals
monitoring distributed systems chapter in SRE book
Latency, Traffic, Error, Saturation


# bryan cantrill oxide rust

moore's law

wright's law

https://www.forbes.com/sites/jimhandy/2013/03/25/moores-law-vs-wrights-law

It's Time for Operating Systems to Rediscover Hardware
https://www.youtube.com/watch?v=36myc8wQhLo

Rust - not depend on its own standard library

sum types, ownership model, traits, hygienic macros is not the standard library

crates which are marked no_std do not perform heap allocations

no_std makes it much easier to build an OS in rust

oxide developing OS using Rust (message-passing, memory protected)

no_std allows Rust in confined contexts

# Peter Portante Redhat

modify Linux to give SRE control over logging bandwidth

set node rate-limit 

SRE uses systemd, podman, conmon to use the gate

behavioural policy : drop or block

# object compaction in cloud netflix tejas chopra

combine small objects into larger blobs

manage indexing


# high performance networking eBPF, XDP, io_uring bryan mccoid

networking layers
1. normal
1. async sockets : io_uring, epoll
2. low-level : AF_PACKET
3. kernel bypass : DPDK, netmap

XDP socket type to route eBPF to userspace

https://github.com/DataDog/glommio (rust async library using io_uring)

# Data Structures for High Resolution, Real-time Telemetry at Scale Filipe Oliveira


# osipov data hotspots at scale
