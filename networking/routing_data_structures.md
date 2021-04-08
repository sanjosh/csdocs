
# routing (forwarding layer)

1. lookup ip address to decide which interface the incoming packet (IP address) should go to
2. rewrite packet header
3. queue packet to interface

lookup table requires longest prefix match - radix tree

# policy table (control plane)


# blacklist or whitelist

radix tree for prefix match

for 32 bits, N = 2^32 and log(N) cost explodes - path compression

# ebtree

