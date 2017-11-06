
---------

* each parallel invocation called block
* it can be referenced by blockIdx (threadLocal)


```
__global__ void gpu_func_called_from_cpu(int *a, int *b, int *c)
{
   c[blockIdx.x] = a[blockIdx.x] + b[blockIdx.x]
}

int main()
{
    gpu_func_called_from_cpu<<<1, 1>>>()
}

```

----------------

Block can be split into parallel threads

```
__global__ void gpu_func_called_from_cpu(int *a, int *b, int *c)
{
   c[threadIdx.x] = a[threadIdx.x] + b[threadIdx.x]
}

int main()
{
    gpu_func_called_from_cpu<<<NumBlocks, NumThreads>>>()
}
```

--------------------

* Thread block 
* threads which execute on single streaming multiproc
* threads within block can cooperate - data exchange, synchronize
* within block, threads have shared mem not visible to other blocks
* blockDim builtin variable = num threads per block
* declare using `__shared__`
* `__syncthreads()` - sync all threads within block

```
__global__ void func(int *a)
{
    __shared__ int temp;
    ...
    __syncthreads()
}
```


* Grid = collection of thread blocks
* communication between blocks is expensive; cannot synchronize

-------

* Warp is grouping during execution
* warp size = simd width = 32
* global memory load-store of all threads in warp is coalesced

-----------

* max concurrent kernels
* kernel from two different cuda ctx cannot execute concurrently 

------------

```
__global__ void cuda_func(a, b, c) {
	threadIdx.x
	threadIdx.y
	threadIdx.z

	blockIdx.x
	blockDim.x
}

int main()
{
	int numBlocks = 2; or dim3 numBlocks (3, 3);
	dim3 threadsPerBlock(N, N);
	cuda_func<numBlocks, threadsPerBlock>(a, b, c)
}
```

* threads are 3dim
* blocks are 3dim


