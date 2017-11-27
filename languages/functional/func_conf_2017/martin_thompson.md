
martin thompson talk

measure nanosec/op for mem access.  5 levels (see slides)
* sequen - no miss
* cache miss
* random page
* random heap

issues
* tlb miss
* too big for cache

Queueing theory
* resp time and util eqn
* universal scalability law

MISC
* amd epyc infinity fabric
* numa optimizations
* google uses quick instead of tcp

scoreboard data structure ?

* pointer chasing hell
* func prog - most data structures are linked list & tree.  limits parallelism

CRDT 2 types
* operation based
* state based

Aeron messaging system
* log buffer
* concurrent publication
* data message header 

* Quake Doom games author - John - used functional

Ref
1. github.com/real-logic/aeron
