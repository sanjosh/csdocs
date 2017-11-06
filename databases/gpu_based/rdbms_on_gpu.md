
# Survey of relational GPU-accelerated db 

by Bress, Seigmund, Heimel, Bellatreche, Saake

Choice between OpenCL or CUDA

* Data transfer is expensive
* joins are 2-7 times faster on GPU
* selections are 2-4 times slower

Four factors in deciding whether CPU or GPU
1. op to execute
2. input data features (selectivity, skew, data type, size)
3. num of cores, mem bw, clock rate
4. load on the device

Dimensions of the problem
* Storage Systes : disk vs Ram based
* Storage Model ; row vs column
* Processing Model : tuple vs operator at a time
* Query Processing Model : single vs hybrid
* Transaction Support : yes or no
* Portability : hardware-oblivious or aware

in-memory vs disk-based db ?
* disk cost dominates so GPU-aware db must be in-memory

Column store versus row store

 Column store is better
 * coalesced mem acces
 * higher compression

Choice between Tuple-at-a-time versus operator-at-a-time
 * GPU lack of inter-kernel comm
 * GPU lack of virtual func support
 * GPU tuple-at-a-time increases mem requirement

Hence GPU-db must be operator-at-a-time (bulk)

To avoid IO overhead, use JIT to merge operators and avoid materializaing intermediate results

Keep Database in GPU Ram or Hybrid device ?
 * GPU RAM bandwidth is 16 times higher than PCIe
 * GPU RAM (16GB) is limited compared to CPU RAM(2 TB)
 * Need hybrid strategy - data placement algorithm

What is granularity of GPU RAM 
 * pages, columns or whole tables ?

More efficient to do few large transfers on PCI

Query placement and optimization
* If goal is lesser response time, parallelize the query ( vertical)
* if goal is higher throughput, create pipeline (horizontal split)

Data consistency between GPU and CPU
1. Keep each data item in one place
2. replicate (read one, write many) or primary copy
3. update on one and periodically sync


-----------------
## Pinned memory

Store data in pinned host memory:

* Pinned host memory saves one indirection, because DMA controller can transmit data directly to device.
* Amount of pinned memory is much smaller.

> GPUDB : Yuan and others identified a crucial optimization for
> main-memory DBMS with respect to GPU accelerated execution: In case data is
> stored in pinned host memory, query execution times can significantly improve
> (i.e., Yuan and others observed speedups up to 6.5x for certain queries of the
> Star Schema Benchmark (SSB) [52]).

--------------

## Data placement

Benefits of Uniform virtual addressing (UVA) :

There are two possibilities to manage the GPU RAM. 
1. The first possibility is an explicit management of data on GPUs using a buffer-management algorithm. 
2. The second possibility is using mechanisms such as Unified Virtual Addressing (UVA), which enables a GPU kernel to directly access the main memory. 

> Kaldewey and others observed a significant performance gain (3-8x) using 
> UVA for Hash Joins on the GPU compared to the CPU [37]. Furthermore, 
> data has not to be kept consistent between CPU and GPU, because there is 
> no ”real” copy in the GPU RAM.  However, this advantage can also be 
> a disadvantage, because caching data in the GPU RAM can avoid the 
> data transfer from the CPU to the GPU


----------

## Create Overlap between data transfer and processing

---------


GPUTx supports transcations on GPU

three basic protocols : 
1. 2 phase locking
2. partition based execution 
3. k-set based execution

they found 2-phase locking not suitable.  Need lock-free protocols on GPU.

OmniDB create hardware-oblivious database kernel (qkernel) which accesses hardware using CPU or GPU adaptors.

Virginian : 
* GPU uses Uniform Virtual addressing to access pinned host memory.
* operates on strings in GPU (instead of dictionary compression)

GPU-aware Query optimizer

Cost-based Analytical model developed

---------------

## Open challenges and research questions
* IO bottleneck : Disk-GPU as well as PCI
* Query optimization : Multiple GPU,
