
# top ten techniques for payment systems

1. fine-tune the timeouts
2. circuit breaker
3. structured logging
4. idempotency keys
5. load test
6. incident management
7. retro
8. reconciliation consistent
9. monitoring and alerting
10. understand capacity


````
We prefer using an Universally Unique Lexicographically Sortable Identifier (ULID)
for these idempotency keys instead of a random version 4 UUID.
ULIDs contain a 48-bit timestamp followed by 80 bits of random data.
The timestamp allows ULIDs to be sorted, which works much better with the
b-tree data structure databases use for indexing.
In one high-throughput system at Shopify we’ve seen a 50 percent decrease in
INSERT statement duration by switching from UUIDv4 to ULID for idempotency keys
```


https://shopify.engineering/building-resilient-payment-systems
