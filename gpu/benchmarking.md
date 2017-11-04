
Using host timers requires use of `cudaDeviceSynchronize()` which stalls the CPU execution until gpu commands completed.  Instead, it is better to use cuda events which are part of stream

```
{
    cudaEvent_t start, stop
    
    cudaEventCreate(&start)
    cudaEventCreate(&stop)
    
    cudaEventRecord(start)
    exec_kernel_on_gpu<<<1, 1, >>>()
    cudaEventRecord(stop)
    cudaEventElapsedTime(&millisec, start, stop)
	cudaEventDestroy(start);
	cudaEventDestroy(stop);
}
```

Bandwidth  
* GPU - device RAM : 177 GB/sec
* host - device RAM : 8 GB/sec

