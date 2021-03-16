
## like sqs


The enqueue API allows the lease duration for an item to be specified. When an item is dequeued, its lease begins. If the item is not acked or nacked within the lease duration, it is made available for redelivery

## prefetch buffer

FOQS maintains a data structure called the Prefetch Buffer, which works in the background and fetches the highest priority item across all shards and stores them to be dequeued by the client.

The prefetch buffer replenishes itself by storing the client demand (dequeue request rate) for each topic. The prefetch buffer will request items at a rate proportional to this demand. Topics that are being dequeued faster will get more items put in the prefetch buffer.

##  background threads

FOQS has background threads which run operations such as making deferred items ready to deliver, expiring lease and purging expired items rely on columns storing timestamps.


https://engineering.fb.com/2021/02/22/production-engineering/foqs-scaling-a-distributed-priority-queue/
