
# Function tags

* `__device__` runs on GPU, called from GPU
* `__host__`  runs on CPU, called from CPU
* `__global__` runs on GPU, called from CPU (aka kernels)
* `__shared__` ?

* global funcs must return void
* global func cannot accept C++ ref
* device func cannot call itself !
* device func can use blockIdx, blockDim and threadIdx built-in variables
* same func can be tagged as "host" and "device"

# Dynamic parallelism 

* used in recursion to invoke one kernel from another (requires CC 3.5)

# References

[1](https://devblogs.nvidia.com/parallelforall/introduction-cuda-dynamic-parallelism/)
[2](https://code.google.com/archive/p/stanford-cs193g-sp2010/wikis/TutorialGlobalFunctions.wiki)
[3](https://code.google.com/archive/p/stanford-cs193g-sp2010/wikis/TutorialDeviceFunctions.wiki)

