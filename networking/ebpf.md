
# BPF

BPF enables you to move functionality out of kernel

run code in kernel without writing a kernel module

defines third mode of execution : userspace, kernel and BPF

1. alternate to one process state model : BPF programs run on event and run to completion
2. security is assured for BPF programs: verified by JIT, and resource access is via restricted helpers
3. failure mode in BPF is via error message instead of kernel panic or userspace abort.
4. new bpf system call

Program written in high level language

Virtual machine 
* code written in restricted C.  No loops, restricted size, always exit, no bad pointer
* Python, Lua, C++
* BPF bytecode with 11 registers, go to verifier, interpreter and JIT compiler
* JIT converts BPF bytecode to native machine code
* events come with BPF context
* shared Map storage (access from userspace + kernel).   Maps of many different types (per cpu, sockmap, trie)

can you load precompiled bytecode using bpf, if no compiler available on system. (yes, as long as kernel same)

## attach bpf program to event targets

* socket
* kprobe
* uprobe
* tracepoint
* perf_events

# how to install

apt install bcc bpftrace

# iovisor

# Applications

40 BPF programs run on every server in Facebook, 14 at netflix

## networking

SDN config

### katran load balancing facebook

https://github.com/facebookincubator/katran/tree/master/katran/decap/bpf

### netflix flowsrus

## security 

firewalls, DDoS

### google krsi (kernel runtime security)

https://lwn.net/Articles/807865/

### Landlock : enhanced seccomp-bpf 

blacklist or whitelist system calls

## device drivers

## observability

* tcplife
* biolatency : histogram is kept in kernel-space which is efficient
* readahead.bt
* flame graphs performance better with BPF because of summary is kept in kernel space 
* bpflist instead of pmap
* bpftool instead of ps

# reference

Brendan Gregg
https://www.youtube.com/watch?v=7pmXdG8-7WU

Liz Rice
https://www.youtube.com/watch?v=4SiWL5tULnQ

# latest features

https://lpc2021.org/2021/09/19/bpf-networking-summit/

https://linuxplumbersconf.org/event/11/contributions/950/attachments/889/1704/lpc_from_xdp_to_socket_fb.pdf
