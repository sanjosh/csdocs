
Metrics requirements
* Sends out data every flush interval
* Timestamp is key
* Query Aggregation keys can be different (e.g. which host, which build_tag, etc)

Types of metrics
* Gauges retain the value from previous flush
* Counter are cleared after every flush
* Metric have min,max,average calculated for flush interval
* Sets are for unique events

Examples 
* bytes_transferred is counter
* num_connected_clients is gauge
* num_error is counter
* latency is metric with (min max ave std_dev histogram)

