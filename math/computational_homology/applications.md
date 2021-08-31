
# Homological Sensor Networks

Vin de Silva and Robert Ghrist

http://www.ams.org/notices/200701/fea-ghrist.pdf

how to collate local information into global

deduce large-scale topological features from local combinatorial data

given a set of sensor nodes in planar Euclidean domain, does their union cover the domain ?
ways to solve this
1. computational geometry
2. if no relative position known, use probabilistic methods (Koskinen, On the coverage of a random sensor network in a bounded domain)
3. computational homology

Changing the positions of nodes can change the topology of the cover (i.e. holes) without 
changing the topology of the network graph (interconnections between nodes) 

## algebraic topology

euler characteristic of surface determines 
1. topogical classification (homeomorphism type of closed orientable surface)
2. geometric properties (gauss curvature)
3. dynamical properties (number of fixed points of vector field)

for arbitrary complexes, more sophisticated algebraic topology is required.

algebraic topology provides two ways
1. homotopy invariants (how many ways to map k-dim sphere into X; difficult to compute)
2. homology groups (weaker than homotopy)

homology measures chains built from simplices

## cech complex

describes the topology of union of balls

coverage area contains fence iff fence 1-cycle if null homologous in C(U) simplicial complex

flag complex of network graph :
1. assign k-1 simplex for every collection of k nodes that are pairwise within broadcast distance 

similar to vietoris-rips complex :

cover contains fence iff exists a in H2(R, F) such that da not 0

in a redundant cover, which nodes can be deactivated ?
1. choose smallest generators for H2(R, F) that require as few 0-simplices






# Ghrist THREE EXAMPLES OF APPLIED & COMPUTATIONAL HOMOLOGY

Homology is a machine that converts local data about a space into global algebraic structure.

Roughly speaking, homology groups count and collate holes in a space.

homological invariants
1. number of connected components of a space (dim H0) the type of ‘holes’ that a zero-dimensional instrument
can measure
2. euler characteristic

Sheaf : The operation of stitching local information over patches is the fundamental 
defining property of a sheaf, a means of assigning an algebraic object 
to open subsets of a space in such a manner that restrictions and overlaps are respected

Fubini theorem : count moving targets over time without embedding clocks on nodes

## persistent homology (find hidden features by varying epsilon)

Grothendieck : topology of a given space is framed in the mappings to or from that space.

define which homological features persist over range of parameters [ epsilon ]

Persistent homology was used to find significant features hidden in a large data set of
pixellated natural images 

find hidden structures in experimental data associated with the V1 visual cortex of certain
primate

see
G. Carlsson, T. Ishkhanov, V. de Silva, and A. Zomorodian, “On the local behavior of spaces of natural images,” Intl. J. Comput. Vision, 76(1), (2008), 1–
12.
and
G. Carlsson, T. Ishkhanov, F. M´emoli, D. Ringach, G. Sapiro, “Topological analysis of the responses of neurons in V1,” preprint (2007


## chaotic dynamics

Conley index

## numerous other examples

obstruction-theoretic in nature : topological measures of complexity of 
1. coordinating robots, 
2. synchronizing a network, 
3. performing distributed asynchronous computation
