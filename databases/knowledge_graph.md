
# overview

## applications

1. entity resolution : resolve partial or misspelt names
2. question answering
3. draw non-obvious inferences

## requirements

1. strongly typed 
2. retain and prove evidence of relation
3. dynamic : update based on new knowledge
4. draw temporal inferences
5. multiple levels of knowledge : general, domain-specific, global, personal
6. multilingual
7. custom knowledge graphs

goals
1. coverage
2. correctness
3. freshness

# question answering

semantic parsing : converting a natural question into a formal KG query 

## neural approaches

prediction models commonly used in semantic parsing into three major categories
1. classification, 
2. ranking, 
3. translation.

Chakraborty, Introduction to Neural Network based Approaches for Question Answering over Knowledge Graphs
https://arxiv.org/pdf/1907.09361.pdf

https://github.com/BshoterJ/awesome-kgqa

# freebase cubed

https://dgraph.io/blog/refs/freebase-cubed.pdf

# dgraph, cubed

Knowledge Graph data was formatted in Triples, i.e. every fact was represented by three pieces, 
1. subject (entity), 
2. predicate (relationship), 
3. object (another entity). 

Queries had to go from [S P] → [O], from [P O] → [S], and sometimes from [S O] → [P].

https://github.com/google/graphd

https://dgraph.io/blog/post/why-google-needed-graph-serving-system/

# code

https://github.com/OceanskySun/GraftNet

# industry scale knowledge graphs

## microsoft

## google

At the scale of the Google Knowledge Graph, a single individual can not remember, let alone manage, the detailed structures used throughout the graph. To ensure the system remains consistent over time, Google built its Knowledge Graph from a basic set of low-level structures. It replicated similar structures and reasoning mechanisms at different levels of abstraction, conceptually bootstrapping the structure from a number of basic assertions. For example, to check specific invariant constructions, Google leveraged the idea that types were themselves instances of types to introduce the notion of metatypes. It could then reason about the metatypes to verify the finer-grained types did not violate the invariants it was interested in. It can validate that time-independent identities are not subclasses of structures, which are time-dependent. This scalable level of abstraction was relatively easy to add in a manner that worked out of the box because it was built upon the same low-level entailments on which the rest of the system was based.

This meta-level schema also allows validation of data at scale. For example, you can validate that painters existed before their works of art were created by identifying the painters as the "origin" of their painted work "products" and applying a general check on all relations between these metaclasses.

It is also critical to manage changing schemas and type systems, without creating inconsistencies with the knowledge already in the system. Google, for example, addresses this problem by conceptualizing the metamodel layer into multiple layers. The basic lower layers remain fairly constant and higher levels are built through the notion of metatypes (which are really instances of types), which can be used to enrich the type system.

## 

## facebook

the Facebook knowledge graph is designed for constant change. The graph is not a single representation in a database that is updated when new information is received. Instead, the graph is built from scratch, from the sources, every day, and the build system is idempotentproducing a complete graph at the end of it.

## ibm

The Discovery use case creates new knowledge that is not directly present in domain documents or data sources. This new knowledge can be surprising and anomalous. While search and exploration tools access knowledge that is already available in the sources available to the system, they are necessary but not sufficient for Discovery. Nonobvious discovery includes new links between entities (for example, a new side effect of a drug, an emerging company as an acquisition target or sales lead), a potential new important entity in the domain (for example, a new material for display technologies, a new investor for a particular investment area), or changing significance of an existing entity (an increasing stake by an investor in an organization, or increasing interaction between a person of interest and some criminal in an intelligence-gathering scenario).


Polymorphic stores offer a solution. The IBM Watson Knowledge Graph uses a polymorphic store, supporting multiple indices, database structures, in-memory, and graph stores. This architecture splits the actual data (often redundantly) into one or more of these stores, allowing each store to address specific requirements and workloads.

Evidence must be primitive to the system. The main link between the real world (which developers often try to model) and the data structures holding the extracted knowledge is the "evidence" of the knowledge. This evidence is often the raw documents, databases, dictionaries, or image, text, and video files from which the knowledge is derived. When it comes to making pointed and useful contextual queries during a discovery process, the metadata and other associated information often play a role in inference of the knowledge. Thus, it is critical not to lose the linkage between the relationships stored in the graph and where those relationships come from.

Federation of global, domain-specific, and customer-specific knowledge. In a case like IBM clients, who build their own custom knowledge graphs, the clients are not expected to tell the graph about basic knowledge. For example, a cancer researcher is not going to teach the knowledge graph that skin is a form of tissue, or that St. Jude is a hospital in Memphis, Tennessee. This is known as "general knowledge," captured in a general knowledge graph.

The next level of information is knowledge that is well known to anybody in the domainfor example, carcinoma is a form of cancer or NHL more often stands for non-Hodgkin lymphoma than National Hockey League (though in some contexts it may still mean thatsay, in the patient record of an NHL player). The client should need to input only the private and confidential knowledge or any knowledge that the system does not yet know. Isolation, federation, and online updates of the base and domain layers are some of the major issues that surface because of this requirement.


https://cacm.acm.org/magazines/2019/8/238342-industry-scale-knowledge-graphs/fulltext


