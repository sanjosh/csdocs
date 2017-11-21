
Need
* time series database which can do aggregation, and decrease data resolution with time.
* graphing tool 

Examples
* statsd - etsy (can write node.js backend to redis)
* graphite - carbon, db is whisper or ceres
* elasticsearch
* influxdb - 
* rrdtool - lowers resolution as time passes
* Ganglia - uses RRDTool
* nagios
* Kibana

--------

# Collectd

collectd used in
* rocksplicator
* seastar

-----------

# Distributed Tracing
1. Dapper google
2. Zipkin
3. http://opentracing.io/

## Dapper

* Span is defined by <Span name, Span Id, Parent Id, Trace Id>
* Events for SpanId are annotated with timestamp
* Trace Context is created in thread local storage
* Deferred computation - callbacks must use same Trace Context
* All RPC calls use span and trace id in client & server
* Add timestamped annotations (strings) to a trace
* Control overhead via sampling
* Trace data written to local log files
* Pulled from host to Dapper daemons
* Written to Bigtable (each span is a column)
* each row = TraceId, Span12, Span23, Span34, ...
