
*(From Cuda C best practices guide - pdf)*

32 threads per warp
1536 threads per multiprocessor
upto 16 multiprocessor per GPU

# Short device functions

write CUDA kernel as collection of short "__device__" func
rather than one large "__global__" func.

# Dual purpose functions

define func as "__host__ __device__" so it can be called
from either CPU or GPU

# Concurrent streams

concurrent copy and compute using 2 streams

cudaDeviceProp - asyncEngineCount field gives num of copy engines available

```
cudaStreamCreate(&stream1);
cudaStreamCreate(&stream2);
cudaMemcpyAsync(a_d, a_h, size, cudaMemcpyHostToDevice, stream1);
kernel<<<grid, block, 0, stream2>>>(otherData_d)
```

# zero copy with mapped pinned memory

Mapped pinned host memory allows you to overlap CPU-GPU memory transfers with 
computation while avoiding the use of CUDA streams. But since any repeated 
access causes PCI transfers, consider creating a second area in device memory 
to manually cache the previously read host memory data.

```
float *a_h, *a_map;
...
cudaGetDeviceProperties(&prop, 0);
if (!prop.canMapHostMemory)
exit(0);
cudaSetDeviceFlags(cudaDeviceMapHost);
cudaHostAlloc(&a_h, nBytes, cudaHostAllocMapped);
cudaHostGetDevicePointer(&a_map, a_h, 0);
kernel<<<gridSize, blockSize>>>(a_map)
```

# Dram Size and frequency

|RAM  |  on chip |  Cached | access | scope | lifetime
|-----|----------|---------|-------|------|------|
|Register | On  | na | RW |
|Local | Off  | yes | RW |
|Shared | On  | na | RW |
|Global | off  | dep on CC | RW |
|Constant | Off  | yes | R |
|Texture | off  | yes | R |

local or global access latency about 400 to 600 cycles


# Coalesced access to global memory

cudaMalloc aligns to 256 bytes
choose thread block to be multiple of 32

L1 cache line is 128 bytes 
L2 cache line 

misc points
* loads/store by threads in warp can be coalesced under certain conditions.  
* number of memory transactions = number of cache lines hit by threads in warp.
* access patterns are useful -- k-th thread accesses k-th word in cache line.

# Shared memory

points
* when multiple threads in warp request same shmem loc, its a broadcast
* when diff warps request same shmem loc, it is serialized
* No penalty for unaligned access from shmem by a warp (unlike global mem)

# Local mem is off-chip and as expensive as global memory

* variables written as ".local" in ptx.
* nvcc option -ptxas-options=-v

# Plot by Compute capability

* Host to device BW
* device to GPU BW for each RAM type
* GPU freq
* num threads, warps, blocks
* Memory types
* L1 and L2 cache

# Resource usage

* hardware occupancy - aim for 50 percent
* register pressure
* CUDA Occupancy Calculator spreadsheet
* Check concurrentKernels field in cudaDeviceProp

# CUDA Contexts

* Avoid multiple contexts per GPU
* Use primary context
* Cuda context defines single host process access to GPU
* Contexts sharing same GPU are time sliced
* But see CUDA Multi process Service...

# Misc

* Use signed int as loop variables
* avoid use of "__syncthreads__" inside divergent code


