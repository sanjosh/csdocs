
# GRPC vs Apache Thrift

* GRPC has a PID controller

[ref](https://github.com/grpc/grpc/blob/master/src/core/lib/transport/pid_controller.c)

From https://groups.google.com/d/msg/grpc-io/JeGybvbz8nc/Xzas8JEqBgAJ

GRPC has
* Request -> <Headers> <Message> <End>
* Response -> <Headers> <Message> <Trailers> <End>

Thrift is simply
* Request -> <Message> <End>
* Response ->  <Message> <End>

Moving headers and trailers around comes with a cost but it provides a standard mechanism for API agnostic metadata to be exchanged and for frameworks to inject/receive that metadata. Metadata exchange is critical to a serviceable API framework.

GRPC uses HTTP2 at the transport layer which is a multiplexing wire protocol, this comes with a framing overhead but provides a variety of benefits at the same time (flow-control, mid-stream cancellation, no need to open many sockets which avoids exploding TLS negotiation costs and saves file descriptors. It will also transit standard HTTP2 proxies which Thrift will not.

In Java Thrift typically uses a thread per socket with blocking reads and writes, this comes with pretty hard scaling limits. You can use Thrift in an async manner I think, at which point it's performance converges with GRPC but without the aforementioned benefits.
