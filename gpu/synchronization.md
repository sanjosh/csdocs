
*(From CUDA Guide)*

* __syncthreads() - all threads in a block will wait

by default following are async
* kernel launch
* memcpy within device mem
* memcpy from host to device of 64KB
* memcpy by an async func
* memset 

sync points
* cudaDeviceSynchronize - wait for all commands in all streams
* cudaStreamSynchronize(stream) - wait for all cmds in given stream
* cudaStreamWaitEvent(stream, event)
* cudaStreamQuery(stream)

implicit sync points
* device mem alloc
* mem cpy
* device mem set
* cuda cmd to default stream
* page locked host mem alloc
