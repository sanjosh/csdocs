
# use pinned host memory for data transfers (mlock)

* Use cudaMallocHost.  Then gpu driver can do DMA
* With additional flag `cudaHostAllocMapped`, GPU can be given ptr to the memory which can be accessed

[Ref](https://gist.github.com/alphaville/4d45a0d5103793e36558#file-zero_copy-cu)

```
{
  cudaHostAlloc(host_ptr, data_size, cudaHostAllocMapped)
  cudaHostDeviceGetPointer
}
```


```
{
    cudaGetDevice(&whichDevice)
    cudaGetDeviceProperties(&prop, whichDevice)
    if (prop.canMapHostMemory) {
        gpu can map host memory
    }
}
```

[Ref](http://courses.cms.caltech.edu/cs179/2015_lectures/cs179_2015_lec13.pdf)

# UVA added in CUDA 4.0 

* requires compute capability (CC) > 2.0
* gpu address space is distinct from cpu address space
* cuda can figure out which address space a ptr lives in
* no need to specify fourth arg 
`cudaMemcpy(dst, src, size, cudaMemcpyDefault)`

# Unified Managed memory - CC >= 3.0

cudaMallocManaged

