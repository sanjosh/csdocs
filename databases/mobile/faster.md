
# FASTER (edge state manager)

Badrish Chandramouli

embedded library to accelerate object storage, indexing, logging


1. Faster Log
2. Faster KV

tiered storage : in-memory hash, local SSD, RDMA, S3

# Single node

hybrid log : stable, immutable, mutable

read cache

concurrent latch-free shared memory : Read-copy-update (RCU)

epoch protection

# multi node
