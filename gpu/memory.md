
global mem can be allocated 
1. __device__ syntax
2. cudaMalloc(&gpu_ptr, size)

Host memory API
* cudaMallocHost to allocate pinned memory
* cudaHostAlloc 
* cudaFreeHost

Other
* cudaFree(gpu_ptr)

Memcpy
* cudaMemcpy(gpu_ptr, cpu_ptr, size, cudaMemcpyHostToDevice)
* cudaMemcpy(cpu_ptr, gpu_ptr, size, cudaMemcpyDeviceToHost)
* cudaMemcpyAsync()
* cudaMemcpySynchronize()

RAM types
* per thread private local memory
* per thread block shared memory
* all threads have shared global mmemory
* readonly constant memory
* readonly texture memory

memory allocation as 
* linear memory 
* CUDA array

Dimensions
* cudaMalloc and cudaFree
* cudaMallocPitch - 2D array
* cudaMalloc3D - 3d array

Copy dimensions
* cudaMemcpy
* cudaMemcpy2D
* cudaMemcpy3D

other funcs
* cudaMemcpyToSymbol
* cudaGetSymbolAddress
* cudaGetSymbolSize
* cudaPointerGetAttributes - find mem a ptr points to

use of __shared__ tag for shmem

cudaHostAlloc  - alloc page locked.  Various flags
* cudaHostAllocPortable for multiple devices
* cudaHostAllocWriteCombined to free up host L1 L@ cache
* cudaHostAllocMapped (and then use cudaHostGetDevicePointer)

cudaHostRegister - page locks mem allocated by malloc. Various flags
* cudaHostRegisterPortable for multiple devices
* cudaHostRegisterMapped

peer to peer access available with CC 2.0
cudaDeviceCanAcessPeer
cudaMemcpyPeer

# reference

[nvidia blog](https://devblogs.nvidia.com/parallelforall/how-access-global-memory-efficiently-cuda-c-kernels/)
