
## general

* N random variables
* Boltzmann distribution = probab distribution of configurations
* Entropy of this law 

ground state = configuration of minimum energy

```
The emergence of such long range correlations is a signature of a phase
transition separating a ‘weakly correlated’ and a ‘highly correlated’ phase. The
latter is often characterized by the decomposition of the (Boltzmann) probability
distribution into well separated ‘lumps’ (pure Gibbs states).
```


### Independent random variables

### Correlated random variables

## Terms

energy is stochastic rather than deterministic

entropy, S, = number of ways N particles with total energy E may be distributed in a volume V

partition function = free energy

phase transition = correspond to singurality in free energy

Boltzmann

population dynamics

symmetry breaking

time evolution of distribution is called "density evolution"

fixed point analysis is called "replica symmetric cavity method"



## random energy model

A statistical mechanics model is defined by a set of configurations and an energy
function defined on this space

assign Boltzmann probability to each configuration


## monte carlo

used for sampling from Boltzmann

## combinatorial optimization

quench in statistical physics = greedy search in combinatorial optimization

How to post as statistical mechanics problem ? (Sec 4.6, Sec 3.5)
* Interpret cost function as energy of statistical mechanics system and consider Boltzmann distribution
* In low temperature limit, the distribution concentrates over minima of E(x) and original optimization setting is recovered

### max cut

general problem is NP_hard but some categories are polynomially solvable (e.g. planar graphs)

max cut in graphs = ground state of spin glass

max flow = ground state of random field Ising model

## set partitioning problem (NP complete)

multiprocessor scheduling

A low cost configuration (small unbalance between two sets) can be seen as independent energy levels = model behaves like Random Energy Model

## error codes decoding

## statistical inference

## belief propagation

update rules that yield marginals on tree factor graphs are called
1. Bethe Peierls approximation in statistical physics
1. sum-product algorithm in coding theory
1. belief propagation in AI

appearance of long range correlations (typical of phase transition) leads to poor performance

messages become random variables

study distribution of random variables

