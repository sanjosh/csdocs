
# What physics teaches us about computation in high dimensions - Lenka Zdeborová

https://www.youtube.com/watch?v=B1VKyRrHz0w (Gibss lecture)

NP hard problems are being solved every day 

Training a 3-node NN is NP-complete problem

So we need a theory for average case complexity over natural distributions

# Random satisfiability

1. Mitchell, hard and easy distributions of SAT problems
1. Cheeseman, where the really hard problems

These two papers showed Random satisfiability 

Probability that formula has satisfying assignment drops to zero when (M=ratio of variables/N=ratio of clauses) goes beyond 5

At same point in curve, the median time of David Putnam algorithm goes sharply up.

Sharp threshold conjectured as N -> inf

Hard instances are close to threshold

See
1. Mezard, Analytic and Algorithmic Solution of Random Satisfiability 
1. Monasson, Determining the computational complexity from characteristic phase transitions, 1999

Both above papers suggested that hardness is related to phase transitions

Satisfiability threshold is around 4.22 (M/N)

Ding, Proof of satisfiability conjecture 

# hardness

What causes algorithmic hardness ?

class of problems : high dimensional Bayes-optimal inference

# Card game

Find minimum achievable error in guessing cards held by people

Such High dimensional probability distributions are mathematically and computationally hard

Map the problem to a spin glass 

Boltzmann-Gibbs distribution

Mean-field spin glass are exactly solvable using replica method

Phase transition in magnets (ferromagnet to paramagnet - 2nd order)

Same algorithm discovered in many fields
* Belief propagation algorithm - Gallagher 68, Pearl 82
* Thoules, Anderson, Palmer replica/cavity method
* Translating physics into message passing : 
1. Saad, Kabashima 98, 
2. Yedidia, Freeman, Weiss 01
3. Mezard, Parisi, Zecchina 02
4. Montanari, Maleki, Donoho 09

As n->inf, AMP algo follows gradient ascent with step size 1

First order phase transitions (when water is evaporating or freezing)

Phase diagram splits into three regions
1. Easy  solvable by Approx message passing
1. Impossible info theoretically
1. Hard phase conjecture : No poly algo works,

Diamond is metastable phase of carbon at normal temperature and pressure.  
Graphite is equilibrium state of carbon at normal temp & pressure.  
But diamonds do not turn into graphite because meta stability is very long living.  

Water in freezer.  States correspond to algorithmic hardness
1. Liquid = impossible
1. Supercooled liquid = computationally hard
1. ice = easy

Hard phase occurs in many computational problems

Paper "Non-adaptive pooling strategies for detection of rare faulty items"


# Compressed sensing : 

Is it useful to know that hardness is due to first order phase transition ? Can u get better algorithm

See Paper "Statistical physics based reconstructed in compressed sensing"

Design matrix such that sparse signal can be reconstructed from measurement.

Many solutions to linear problem, but only one is sparse.

easy to hard threshold is spinodal of a first order phase transition

Nucleation happens when dim into which system is embedded is finest

Similar, design compressed sensing matrix can be designed such that metastability vanishes.

See paper " Krzakala, Mezard, Sausset" and "Javanmard, Montanari"

Spatial coupling applicable to all problems where interaction graph matrix can be designed

Discovered in ECC - Felstrom, Zigangirov 99; Urbanke, Kudekar 10

Spatial coupling as a proof technique - Paper

# Deep learning

Interplay of network architecture, structured data, and training algorithm

Phase diagram of gradient descent has three regions

# Conclusion

Many computation problems can be reformulated as physics of disordered systems

First order phase transitions imply algorithmic hard region in inference problems

Statistical physics leads to new insights, algorithms and proofs

# TODO 

* Spin glass
* nucleation
* replica method

# References

1. Gibbs, Statistical mechanics
2. Statistical physics of inference: thresholds and algorithms https://www.tandfonline.com/doi/abs/10.1080/00018732.2016.1211393
3. Computational complexity of statistical inference : Simons Institute https://simons.berkeley.edu/programs/si2021
4. Mezard Montanari, Information Physics and Computation  2009
