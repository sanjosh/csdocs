
# CUDA Streams

```
kernel<<<blocks, threads, shared_mem_bytes>>> - default stream
kernel<<<blocks, threads, shared_mem_bytes, 0 >>> - stream 0
```

there is a per-thread default stream

```
nvcc --default-stream-per-thread
CUDA_API_PER_THREAD_DEFAULT_STREAM
```

cuda stream is api used to sequence ops in an order on device

cudaMemcpy is blocking on host but kernel launch (func call) is async
```
{
    cudaMemcpy(device to host) <- blocks on host but not gpu
    increment<<<1, N>>>(ptr)   <- does not block
    cpuFunc()                  <- can overlap with gpu computation
    cudaMemcpy(host to device) <- blocks on host but not gpu
}
```

cudaMemcpyAsync is nonblocking on host

cuda streaming api
```
{
    cudaStream_t stream1 
    result = cudaStreamCreate(&stream1)
    result = cudaMemcpyAsync(gpumem, cpumem, cudaMemcpyHostToDevice, stream1)
    // cuda waits for memcpy to finish before launching kernel
    increment<<<1, N, 0, stream1>>> (gpumem)

    // sync cpu with gpu
    cudaStreamSychronize(stream1)
    result = cudaStreamDestroy(stream1)
}
```

* streams themselves synchronize the GPU
* cudaStreamSynchronize syncs cpu with gpu

```
cudaStreamAddCallback
cudaEventCreate(event)
cudaEventRecord(event, streamA)
cudaStreamWaitEvent(syreamB, event, 0)
cudaStreamQuery
cudaDeviceSynchronize
```
