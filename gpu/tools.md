
# Versions

Two versions to care about
* Compute capability of device
* driver API version - CUDA_VERSION

# nvidia-smi

# NVCC

`nvcc x.cu -gencode arch=compute_10, code=sm_10`

only support -std c++11

```
-gencode arch=compute_35,code=compute_35
-maxregcount - specify max register used per threads (can reduce max thr block size)
-rdc - generate relocatable
-res-usage - show resource usage
-verbose - 
-Werror
--keep (keep intermediate files)
```

code compiled for one generation (e.g. Fermi) will not work for Kepler

PTX is not actual GPU assembly code; it is assembly for virtual arch

programs which run during compilation phase (ptxas)
cudart library

# cuda-gdb

cuda-gdb is extension of gdb

`nvcc -g -G  -Mcuda=nordc`

env variables to run with gdb 
* CUDA_ENABLE_COREDUMP_ON_EXCEPTION
* CUDA_ENABLE_CPU_COREDUMP_ON_EXCEPTION
* CUDA_COREDUMP_FILE

cuda_gdb commands
* info cuda kernels
* cuda kernel <n> 
* info cuda threads
* cuda thread <n>

software coordinates are thread, block, kernel
hardware coordinates are lane, warp, SM and device

cuda device sm warp lane block thread
cuda kernel block thread
cuda kernel

Concepts
* devices
* sms
* warps
* lanes
* kernels
* blocks
* threads
* contexts

```
set cuda context_events_on
set cuda break_on_launch_application
set cuda kernel_events all
set cuda memcheck on
break foo.cu:23 if threadIdx.x == 1 
```

to disable async kernel for debugging 
`export CUDA_LAUNCH_BLOCKING = 1`

# nvprof

# nvvp (visual profiler)

# nvtx API

# cuda context

cudaGetDeviceCount
cudaSetDevice
cudaGetDeviceProperties

# cubin = cuda binary file

nvcc embeds cubin in host exec
to generate separately, run `nvcc -cubin`

# cuobjdump 

take both cubin and host binary

```
cuobjdump -sass, -elf, -ptx
cuobjdump -lelf (to list cubin files)
cuobjdump -xelf all
cuobjdump -res-usage
```

# nvdisasm 

takes only cubin files

to generate control flow graph
`nvdisasm -cfg a.cubin |  dot -ocfg.png -Tpng`

# nvprune

nvprune strips binary to only contain device code for specified target
