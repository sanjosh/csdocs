
1. ordering via commutativity (CRDT)
2. ordering via locks 
3. ordering via predetermined plan

# CURP

https://blog.acolyer.org/2019/03/15/exploiting-commutativity-for-practical-fast-replication/

# Calvin

idea : have a predetermined transaction execution plan

Activity plans must be deterministic so that replicas cannot diverge and history will always be recreated in exactly the same way. 
Calvin achieves the desired deterministic outcome by 
1. using a deterministic locking protocol for transaction execution, and 
2. reaching a global agreement about which transactions to attempt and in what order.

```
Transactions which must perform reads in order to determine their full read/write sets (which we term dependent transactions) are not natively supported in Calvin since Calvin’s deterministic locking protocol requires advance knowledge of all transactions’ read/write sets before transaction execution can begin.
```

## Sequencing layer

## Scheduling layer

## Storage layer

https://blog.acolyer.org/2019/03/29/calvin-fast-distributed-transactions-for-partitioned-database-systems/
