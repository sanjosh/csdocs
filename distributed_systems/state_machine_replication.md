
# Raft


# Multipaxos


```
While consensus is the act of choosing a single value, 
state machine replication is the act of choosing a sequence (a.k.a. log) of
values. A state machine replication protocol manages a number of
copies, or replicas, of a deterministic state machine. Over time, the
protocol constructs a growing log of state machine commands, and
replicas execute the commands in log order. By beginning in the
same initial state, and by executing the same commands in the same
order, all state machine replicas are kept in sync. 
```

https://mwhittaker.github.io/publications/compartmentalized_paxos.html

Scaling Replicated State Machines with Compartmentalization [Technical Report]
https://arxiv.org/abs/2012.15762
