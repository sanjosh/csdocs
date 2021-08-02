
```
Apache Cassandra was built with this traditional large thread pool architecture (staged event-driven architecture). 
With this kind of architecture, you break work into multiple stages.
```

```
Seastar is thinking about the machine as a distributed thing rather than a shared-memory machine
```

```
Linux kernel is a monolithic shared-memory kernel, which means that all CPUs share many of the same data structures, which they have to synchronize
```

```
Seastar is not just about eliminating context switches, synchronizations and such, it’s also very much about control.

Seastar is built around an idea of how to program multi-core machines efficiently: 
avoiding coordination and not blocking kernel threads. 
Seastar has this future/promise model which allows you to write application code efficiently 
to take advantage of both concurrency and parallelism

you have async/await in Rust, which is very similar as well.
```

```
PhD topic: what kind of capabilities the O/S should expose so you could implement POSIX abstractions in user space.
```

```

with the emergence of runtimes like the Java Virtual Machine (JVM) and more recently Node.js and others, 
I think it’s a fair question to ask how relevant POSIX is.

The page fault screws up everything because it will basically stop the Go runtime scheduler, which is a user space thing
```

Intel Optane



https://www.scylladb.com/2021/05/13/an-interview-with-pekka-enberg-modern-hardware-old-apis/
