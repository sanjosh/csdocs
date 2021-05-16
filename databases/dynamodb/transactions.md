
https://www.youtube.com/watch?v=CK6h48zOY9k

Doug Terry FAST 19

# Architecture changes

1. Introduced Transaction coordinator Node after Request coordinator Node, and before Storage Node
1. Added Ledger and Recovery

# Latency 

1. TransactWriteItem : is indep of db size, but depend on number of participants.  Two round protocol added factor of 4 latency.
1. TransactGetItem : extra hop to Transaction Coordinator node
1. Get/Put have no additional latency

# design

timestamps given to transactions by Transaction Coordinators - it is some unique ID.

time sync not requirement for correctness

why not MVCC : DDB does not store multiple versions; you would have to keep versions and retire them.

why not explicit multi-step transactions and 2-phase locking : too costly

use timestamp ordering and not locks

1. transactions can arrive at each storage node in different order
2. each storage node reasons independently about transaction acceptance
3. but each node eventually reaches same state of data

use knowledge of already accepted transactions to reason about acceptance or rejection of incoming (but older) transaction

check conditions attached to each transaction

1. can accept old Transaction which came later (reordered) if the newer transaction was an unconditional Put (overwrite)
2. can accept newer transaction unless condition is not met
3. Unconditional PUT and DELETE can be accepted even if out of order

Time 45 min in video
1. Tx2 (update b = b + 1) comes before Tx1 (Put b=1)
2. wait for Tx1 before applying Tx2

## handling readonly

Reject (or retry) Readonly transaction if its in the future 

## Mix of Non-transcational with transactions

PUT with no timestamp comes to storage node

If either PUT and Transaction has condition, then PUT has to be aborted.  This is new failure mode

non-transactional reads : ddb never has dirty data since writes done in phase 2 (accept + write)

## timestamps

easily correct serializability : based on TS (no locks)

independent serializability : storage nodes need not talk to each other - makes it easier to test

## global tables 
