

1. self-stabilization
1. probabilistic

## diffusion speed

If P is probability transition matrix for message between (i, j),   how soon does P^t converge to stationary distribution ?

```
averaging time of a gossip algorithm depends on the second largest eigenvalue of a doubly stochastic matrix characterizing the algorithm
The relation of averaging time to the second largest eigenvalue naturally relates it to the mixing time of a random walk with transition probabilities derived from the gossip algorithm
```
(Randomized Gossip Algorithms Stephen Boyd)

## types of graph

complete, ring, expander (sparse graph with strong connectivity properties)

## types of exchange

1. pairwise exchange
2. more than 2

## type of dissemination

single piece : one node has to send to all

multiple pieces : each node has to send to all

## theory

1. percolation
1. markov chain

## disseminate

```
The system is bandwidth limited and in each time-step, only one message can be transmitted
We present a protocol based on random linear coding (RLC) that disseminates all the
messages among all the nodes in O(n) time, which is order optimal, if we ignore the
small overhead associated with each transmission

In the RLC protocol, the nodes start collecting several linear
combinations of the messages in M. Once there are k independent linear combinations
with a node, it can recover all the messages successfully
```

Deb, Algebraic gossip: A network coding approach to optimal multiple rumor mongering.

## anti-entropy

## aggregate computation

### Sum based on exp distribution

based on extremal property of the Exponential distribution:   
computing the summation can be performed by the computation of certain relevant minima

min(independent exponential random variables) is a random variable with rate = sum (individual exponential rates)

Algo : 
1. say node has value "x"
2. each node generates "r" random numbers (k1, ..., kr) from exponential distribution with rate = "x"
3. All nodes compute min
4. then Sum of x = r / (min_k1 + min_k2 + ... + min_kr) 

(Mosk-Aoyama and Shah)

Gossip Algorithms By Devavrat Shah
https://www.stat.berkeley.edu/~aldous/260-FMIE/Papers/shah_GA.pdf

### Push sum (based on successive division)

node has value Sk and weight Wk

weight = weight associated to the sum at this time

at each round, send (Sk/2, Wk/2) to random node and set own value (Sk/2, Wk/2)

eventually, everyone has 1/n of everyone else's value and weight

number of rounds = O(Log n)

correctness : due to mass conservation : the global sum of all network values (local value of each node plus the value in messages in transit) must remain constant along time.

(Kemp, Gossip Based Computation of Aggregate Information)

### Min

### Average

### quantile

push-synopses protocol

### threshold alerting

when values are changing dynamically, how do you know where a particular round starts and ends ?

Wuhib, A Gossiping Protocol for Detecting Global Threshold Crossings

## references

1. Paulo Jesus, A Survey of Distributed Data Aggregation Algorithms


# practical

OSPF ?

## consul

https://www.consul.io/docs/architecture/gossip

two different gossip pools : WAN and LAN pool

https://www.serf.io/

## Akka

Cluster membership is communicated using a Gossip Protocol, where the current state of the cluster is gossiped randomly through the cluster, with preference to members that have not seen the latest version.

https://doc.akka.io/docs/akka/2.5.4/scala/common/cluster.html#gossip-protocol
