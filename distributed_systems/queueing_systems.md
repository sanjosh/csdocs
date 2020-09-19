
# Amazon SQS

* standard vs fifo queue
* dead letter queue
* cost allocation tags

## msg identifiers
* message id 
* receipt handle (each msg id has multiple deliveries; use latest for deletion)
* message dedup id (only fifo)
* message group id (only fifo; use in event sourcing pattern)
* upto 10 message attributes

## timer
* message retention period (default 4 days; max 14 days)
* set delay period on queue to postpone consumers from seeing every message
* set message timer on every message to postpone consumer from seeing it (max 15 minutes)
* visibility timeout for inflight messages before deleting
* long polling (to reduce empty responses) vs short polling

## queue size
* limited number of inflight msgs; unlimited stored msgs.  No error if limit exceeded in FIFO queue
* 256 kb limit per msg (use extended client library to store 2 GB in S3)
* max 10 messages per batch

## how to do RPC using request and response queue
* dont let producers share reply queue

