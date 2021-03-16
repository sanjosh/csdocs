
# Load balancing 

--------

# Mitzenmacher Power of two random choices

## Balls and bins model
```
...even a small amount of choice can lead to drastically different results in load balancing.  Indeed, having just two random choices (i.e., d = 2) yields a large reduction in the maximum load over having one choice, while each additional choice beyond two decreases the maximum load by just a constant factor.
```

## Hash table

Above principle can also be used to reduce max time to search in hash tables - use two random hash functions instead of one and insert in bucket with shortest chain.  This reduces length of longest chain.

## analysis techniques for balls and bns model

1. layered induction
2. witness trees
3. fluid limits

these are used to derive upper/lower bounds for variations of balls-and-bins problem.


## Load balancing with limited info

If each task obtains limited info by querying load of 2 servers chosen at random, and chooses the least loaded of the two, then max load on the `n` servers is less.

## Collision protocols in message routing

can be analyzed with parallel balls and bins model.

## work stealing algo in parallel 

## Valiant paradigm for permutation routing (1982)

```A scheme for fast parallel computation```

## Load balancing with stale info (queue length info is delayed)

```going to the apparently shortest queue can be a bad strategy...herd behaviour is seen...  even for reasonably small delays, choosing the shortest of two randomly selected processors is a better global strategy than having all tasks choose the shortest from three
```


-----------

# Join Idle Queue Load balancing for web services - Lu Xie Kliot et al

Dispatcher running (Say) ECMP algo routes client requests to web servers

## Join shortest queue algo

Works with perfct info. Centralized load balancer.

## Power-of-d algorithm

Dispatcher samples d processors and obtains their queue length.
Job directed to processor with least number of jobs

## Join idle queue algo

```
central idea is to decouple discovery of lightly loaded servers from job assignment.

Informing a large number of dispatchers will increase the rate at which jobs arrive at idle processors, but runs the risk of inviting too many jobs to the same processor all at once and results in large queuing overhead.

the proposed JIQ algorithm load balances idle processors across dispatchers, which we call the secondary load balancing problem.

```

when processor becomes idle, it joins the I-queue at a dispatcher

-----------

# Dynamic Load balancing - Hac Johnson 

-----------

# Analysis of Simple algo for dynamic load balancing - Alanyali Hajek

-------

# Dynamic Load Balancing for Distributed Memory Multiprocessors - Cybenko

Journal of Parallel and Distributed Computing - 7 (1989)

http://www.dartmouth.edu/~gvc/Cybenko_JPDP.pdf

```
Work_i(t+1) = Work_i(t) + 
  Sum_all_processors_j ( Alpha_ij * (Work_j(t) - Work_i(t))) + 
  Theta_i(t+1) -
  c

Alpha_ij = non-neg const = 0 if i and j not connected
Work_i(t) = num tasks done by proc i at time t
Theta_i(t+1) = new work generated at time t+1
c = constant amount of work any proc can do between [t, t+1]
```

----------

# Optimal migration algo for dynamic load balancing - Hu Blake Emerson

Daresbury

Analogous to diffusion process where initial uneven temp drives movement of heat and eventually reaches equilibrium

http://yifanhu.net/PUB/concurrency98.pdf

