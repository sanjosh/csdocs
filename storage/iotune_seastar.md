
https://www.scylladb.com/2021/09/15/what-weve-learned-after-6-years-of-io-scheduling/

In Scylla different types of IO flows have different priorities.

# why iotune

```
seastar shared-nothing approach does not work with disks

shards must communicate when dispatching requests. In the old days Scylla came with the concept of IO coordinator shards; later this was changed to the IO-groups
```

# iotune

```
The same disk can show different read speeds depending on if it’s in so-called burst mode or if the load is sustained, if it’s a read or write (or mixed) IO, it’s heavily affected by the disk usage history, air temperature in the server room and tons of other factors.


 Scylla measures disk performance in advance with the help of a tool called iotune. This tool literally measures a bunch of parameters the disk has and saves the result in a file we call “IO properties.” Then the numbers are loaded by Seastar on start and are then fed into the IO scheduler configuration. The scheduler thus has the 4-dimensional “capacity” space at hand and is allowed to operate inside a sub-area in it.
```

# pure workload

```
there’s an upper limit on the request size above which the throughput will no longer grow. We call this limit a “saturation length.”

to be large enough to saturate the bandwidth and small enough to meet the latency goal
```

# mixed workload

mix is not linear sum of read & write

# unstable workloads

```
there are actually two times more speed numbers for a disk. Each speed characteristic can in fact be measured in two modes — bursted or sustained. EBS disks are even explicitly documented to work this way.    

when benchmarking the disk it’s often said that one must clearly distinguish between short and sustained workloads and mention which one was used in the test.
```




# code

https://github.com/scylladb/seastar/blob/master/apps/iotune/iotune.cc

1. sequential write bandwidth
2. sequential read
3. random write
4. random read

buffer size, queue depth, throughput, latency

sustained only; not bursty


# discussion

```

Instead of trying to measure the iodepth of the device, we observe that
in accordance of Little's law for closed systems, there is a
correspondence between iodepth and throughput.

Little's law for closed systems can be stated as:

N = X * E[T]

Where N is the system concurrency, X it's throughput, and E[T] the
expected time for completion of a request (latency).

Rewriting it as

X = N / E[T]

We can clearly see that for any given throughput X = Xi, minimizing N
also minimizes E[T]. Our goal now becomes issuing the least amount of
requests necessary for any given fixed throughput. In particular, as we
want to make use of all the disk available throughput, we admit requests
until the throughput of the device is reached.

Disks have two different throughput limits: one of them is measured in
bytes/sec, while the other is measured in IOPS. By controlling for them
individually we make sure that the device is operating within our limits
regardless of the size distribution: smaller requests will tend to
saturate the IOPS limit, while larger requests will tend to saturate the
bytes/sec limit.
```

https://groups.google.com/g/seastar-dev/c/qyEs2RiiEzk/m/kevAu5vZAgAJ


