
# library, purpose, author

* Thrust - STL
* ModernGPU, Sean Baxter (Nvidia)
* CUB : https://nvlabs.github.io/cub/
* NPP

------

# Thrust

operations : sort, merge, scan, search, reduce, reorder, transform

* host_vector
* device_vector

* for stream, use "thrust::cuda::par.on(stream)"
* use of pinned memory - thrust::cuda::pinned_allocator<T>

* also thrust::seq, thrust::device, thrust::host

## PTRS
* thrust::device_ptr
* thrust::raw_pointer_cast()

## ITERATOR
* zip_iterator - array of struct stored in struct of array
* counting_iterator - return increase elem
* constant_iterator - return same elem
* transform_iterator
* permutation_iterator

## REDUCTION
* reduce
* reduce_by_key
* count
* min
* max
* inner_product

## TRANSFORM
* sequence
* fill
* replace
* transform

## REORDER
* copy_if
* partition
* unique

## SORTING
* sort_by_key
* sort


## Ref
1. [r1](http://stackoverflow.com/questions/25064383/how-to-asynchronously-copy-memory-from-the-host-to-the-device-using-thrust-and-c)
2. [r2](http://stackoverflow.com/questions/24368197/getting-cuda-thrust-to-use-a-cuda-stream-of-your-choice)
3. [r3](https://thrust.github.io/doc/group__execution__policies.html)

-----------------

mgpu::standard_context_t context;

mgpu::transform(func, num-threads, context)

context.synchronize()

cta_launch<num_threads>(func, 1, context)

expt

mem_t

to_mem

MGPU_HOST_DEVICE

