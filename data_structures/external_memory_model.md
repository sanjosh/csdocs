
# Internal memory model

Assumptions for algorithms in this model
* memory is infinite
* access cost is uniform

These assumptions does not apply to external memory algorithms

# External memory model

Parameters for External memory algorithms
* N = number of items
* M = number of items that fit into RAM
* B = number of items that fit into disk block
* D = number of independent disk drives
* P = number of CPUs

## Aggarwal & Vitter model

* scan(N) = number of IOs to read N contiguous items = Theta(N/B)
* sort(N) = number of IOs to sort N items = Theta((N/B).log_M/B(N/B))
* search(N) = Theta(log_B(N))

For all realistic values of N, B, M
* scan(N) < sort(N) << N

## Cache oblivious model

* Cache-oblivious algo are efficient for each level of hierarchy
* Cache-oblivious models hide M and B

## PDM (parallel disk model)

## UMH (uniform memory hierarchy)

by Alpern, Carter, Feig

## P-UMH (parallel UMH)

# References

1. Demaine. Cache-oblivious algo LNCS 
2. Meyer Sanders.  Algorithms for memory hierarchies
3. Vitter.  External memory algorithms and data structures.  ACM survey 2001
