
# Arch Components

## processes

define a process for every concurrent activity

```
Erlang does not create OS thread for every process.  Process creation time is in order of microseconds.

 ...time taken to create an Erlang process is constant 1µs up to 2,500 processes; thereafter it increases to about 3µs for up to 30,000 processes...

We see that for up to 30,000 processes the time to send a message between two Erlang processes is about 0.8µs.
```

https://stackoverflow.com/questions/2708033/technically-why-are-processes-in-erlang-more-efficient-than-os-threads?rq=1


e.g. can be implemented using gen_event(event handler), gen_server, gen_statem(FSM) behaviour

## application

## supervisor

* it monitors the processes
* has different restart strategies


https://stackoverflow.com/questions/7307634/how-do-you-design-the-architecture-of-an-erlang-otp-based-distributed-fault-tole?rq=1

# Fault tolerance

* When a process dies, that process will be restarted
* You can know when a process dies and why it did
* You can force processes that depend on each other to die together if one of them goes wrong
* You can run a logger that automatically logs every uncaught exception for you, and even define your own
* Nodes can be monitored so you know when they went down (or got disconnected)
* You can restart failed processes (or groups of failed processes)
* Have whole applications restarting on different nodes if one fails

https://stackoverflow.com/questions/3172542/are-erlang-otp-messages-reliable-can-messages-be-duplicated?rq=1

# Actor model

* Message passing is the only way for processes to interact.
* Processes have unique names.
* If you know the name of a process you can send it a message.
* Processes share no resources.
* Error handling is non-local.
* Processes do what they are supposed to do or fail.

https://stackoverflow.com/questions/972662/how-does-erlangs-support-for-transparent-distribution-of-actors-impact-applic?rq=1
