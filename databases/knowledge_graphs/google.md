
## google

highlights
1. metatype : type can be instance of type
2. similar reasoning across graph
3. invariants
4. layers

At the scale of the Google Knowledge Graph, a single individual can not remember, let alone manage, the detailed structures used throughout the graph. 
To ensure the system remains consistent over time, Google built its Knowledge Graph from a basic set of low-level structures. 
It replicated similar structures and reasoning mechanisms at different levels of abstraction, conceptually bootstrapping the 
structure from a number of basic assertions. 

For example, to check specific invariant constructions, Google leveraged the idea that types were themselves instances 
of types to introduce the notion of metatypes. It could then reason about the metatypes to verify the finer-grained types 
did not violate the invariants it was interested in. 

It can validate that time-independent identities are not subclasses of structures, which are time-dependent. 

This scalable level of abstraction was relatively easy to add in a manner that worked out of the box because it was 
built upon the same low-level entailments on which the rest of the system was based.

This meta-level schema also allows validation of data at scale. For example, you can validate that painters 
existed before their works of art were created by identifying the painters as the "origin" of their painted 
work "products" and applying a general check on all relations between these metaclasses.

It is also critical to manage changing schemas and type systems, without creating inconsistencies with the 
knowledge already in the system.  Google, for example, addresses this problem by conceptualizing the 
metamodel layer into multiple layers. The basic lower layers remain fairly constant and higher levels are 
built through the notion of metatypes (which are really instances of types), which can be used to enrich the type system.


https://cacm.acm.org/magazines/2019/8/238342-industry-scale-knowledge-graphs/fulltext

