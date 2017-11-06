
(from IBM)

* Current RDD = Row oriented, Java obj, on java heap
* GPU RDD = columnar, binary rep, off-heap

Three approaches (not understood) ??
1. Change spark lib to use GPU without changing API
2. generate GPU code from Java bytecode
3. integrate spark with external GPU-accelerate system

[Ref](https://www.oreilly.com/learning/accelerating-spark-workloads-using-gpus)

GPUEnabler
1. Copy data in binry columnar RDD between CPU and GPU
2. Launch GPU kernels
3. Generate GPU native code using JIT
4. Cache GPU native code

Codegen
* JVM needs knowledge of GPU cores
* Codegen for CUDA

[Ref1](http://www.spark.tc/gpu-acceleration-on-apache-spark-2/)

[Ref2](http://spark-summit.org/2016/events/gpu-support-in-spark-and-gpu-cpu-mixed-resource-scheduling-at-production-scale/)

[Ref3](https://www.slideshare.net/ishizaki/exploiting-gpus-in-spark)

Special RDD
* MapGPUPartitionsRDD
* ConvertGPUPartitionsRDD

Iterator
* HybridIterator

import jcuda

-----------------

Tungsten backend has plan to add GPU support
Four backends : GPU, LLVM, JVM, NVRAM

Spark GPU support
[Ref](https://issues.apache.org/jira/browse/SPARK-3785)

Three Spark GPU projects
1. Spark-SWAT (https://github.com/agrippa/spark-swat)
2. SparkCL (https://gitlab.com/mora/spark-ucores)
3. HeteroSpark

Use of APARAPI to convert Spark Java bytecode to OpenCL
[Ref](https://aparapi.github.io/)

-------------

Acceleration

* infeasible to run JVM on GPU
* more feasible for ML where computation to data ratio is high

-------------

Changes done by most projects fall into 
1. API extensions
2. custom RDD storing data in off-heap, columnar format for easy transfer to GPU
3. generate CUDA/OpenCL from Java bytecode (amd aparapi)
4. resource management extensions to expose GPU capability to Spark Scheduler

