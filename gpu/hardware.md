
# device properties API
 
```
cudaSetDevice(num)
cudaGetDeviceCount()
cudaSetDevice()
cudaGetDevice()
```
cudaGetDeviceProperties()

[Ref](https://devblogs.nvidia.com/parallelforall/how-query-device-properties-and-handle-errors-cuda-cc/)

----------

# compute capability (CC)

Bandwidth
* gpu to device mem bandwidth
* gpu to host mem bandwidth 

Memory
* device mem size (global, shared)
* host mem malloc size

max concurrent kernels

```
    arch_20_cta<128, 8>,    // Big Fermi GF100/GF110  eg GTX 580
    arch_21_cta<128, 4>,    // Lil Fermi GF10x/GF11x  eg GTX 550
    arch_30_cta<256, 4>,    // Lil Kepler GK10x       eg GTX 680
    arch_35_cta<256, 8>,    // Big Kepler GK110+      eg GTX 780 Ti
    arch_37_cta<256, 16>,   // Huge Kepler GK210      eg Tesla K80
    arch_50_cta<256, 8>,    // Lil Maxwell GM10x      eg GTX 750
    arch_52_cta<256, 16>    // Big Maxwell GM20x      eg GTX 980 Ti

```

----------

GPGPU ?

---------

dynamic parallelism in Tesla K-20 - kernel launches other kernels inside device func
