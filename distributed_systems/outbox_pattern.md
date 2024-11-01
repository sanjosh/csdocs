
# outbox pattern

events are immutable and cannot be altered after the fact. 

https://www.decodable.co/blog/revisiting-the-outbox-pattern

vital that these two operations, updating the appointment database and sending the notification, happen atomically—that is, they either both happen, or neither of them does. 

https://microservices.io/patterns/data/transactional-outbox.html

As part of its local database transaction, the appointment service inserts the notification message which it wants to send into a table in that database

A separate process, called the outbox relay, picks up that message from this outbox table and sends it to Kafka. This happens asynchronously and can be retried if needed, without impacting the clients of the appointment service in any way.

## mechanism for retrieving messages from the outbox table.

once events have been picked up from the outbox table, they can and should be removed from the outbox table, preventing it from growing larger and larger. 

```
Through its function pg_logical_emit_message(), Postgres lets you write arbitrary messages to the WAL
SELECT * FROM pg_logical_emit_message(
  –- This message is transactional, only emit it
  -- if the transaction commits
  true,

  –- An arbitrary prefix which can be used to differentiate
  -- between different kinds of messages
  'appointments',

  -- The actual outbox message payload, for instance as JSON
  '{ ... }'
);

For services using MySQL as a datastore, the BLACKHOLE storage engine can be used in a similar way.

```

## idempotency for consumers

consumer checks UUID against state store table - but how long to retain that table ?

consumer gets incremental timestamp 

## dapr

## debezium

## kafka 2pc



