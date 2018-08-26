## Marzullo algorithm

NTP

```
In Spanner’s case, Google mentions an upper bound of 7ms. That’s pretty tight; by contrast, using NTP for clock synchronization is likely to give somewhere between 100ms and 250ms.
```

https://www.cockroachlabs.com/blog/living-without-atomic-clocks/

```
So how does Spanner use TrueTime to provide linearizability given that there are still inaccuracies between clocks? It’s actually surprisingly simple. It waits.  Before a node is allowed to report that a transaction has committed, it must wait 7ms. Because all clocks in the system are within 7ms of each other, waiting 7ms means that no subsequent transaction may commit at an earlier timestamp, even if the earlier transaction was committed on a node with a clock which was fast by the maximum 7ms. Pretty clever.
```

