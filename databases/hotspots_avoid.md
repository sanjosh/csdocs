
# avoiding data hotspots osipov p99 conf

hotspots due to sharding

fixed buckets; split the shard  (couchbase)

bit reverse the partition key in range-based 

create compound key : add monotonic timestamp-based key (desc order) to random uuid

distribute using first key, order within partition using second key

replicate dimension tables on all partitions (voltdb)

message queue sharding : use two dim keys (say) timestamp and some event property

## summary

| --- | --- | ---- |
| access | hash | range |
| --- | --- | ---- |
| write heavy/monotonic/time series  | linear scaling | hotspot |
| primary key read | linear scaling | linear scaling |
| partial key read | hotspot | linear scaling |
| indexed range read | hotspot | hotspot |
| non-indexed read | hotspot | hotspot |
| --- | --- | ---- |

https://www.youtube.com/watch?v=CE1HD_tUuoo
