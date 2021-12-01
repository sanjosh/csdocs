
Given an analytically intractable distribution, how to build a sample

You are given a blackbox which can answer : given x, tell P(x) = probability with which X occurs in distribution

How to reduce number of operations required to create a sample ?

Construct a Markov chain whose stationary distribution = P(x)

Put X on d-dimensional lattice
each state is vector in {0..n}^d

At each vertex, pick neighbour and check P(neighbour)
set the transition probabilities (refer calculations)

sum of probabilities at each vertex = 1

you can estimate E[g(x)] while walking the graph

https://jeremykun.com/2015/04/06/markov-chain-monte-carlo-without-all-the-bullshit/

-----------

https://stats.stackexchange.com/questions/65056/a-practical-example-for-mcmc

----------

https://twiecki.io/blog/2015/11/10/mcmc-sampling/
