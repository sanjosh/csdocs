

## ibm

highlights
1. federation : general knowledge vs domain knowledge
2. lineage maintained
3. polymorphic store

The Discovery use case creates new knowledge that is not directly present in domain documents or data sources. 
This new knowledge can be surprising and anomalous. While search and exploration tools access knowledge 
that is already available in the sources available to the system, they are necessary but not sufficient 
for Discovery. 

Nonobvious discovery includes new links between entities (for example, a new side effect of a drug, 
an emerging company as an acquisition target or sales lead), a potential new important entity in the 
domain (for example, a new material for display technologies, a new investor for a particular investment area), 
or changing significance of an existing entity (an increasing stake by an investor in an organization, or 
increasing interaction between a person of interest and some criminal in an intelligence-gathering scenario).

Polymorphic stores offer a solution. The IBM Watson Knowledge Graph uses a polymorphic store, supporting 
multiple indices, database structures, in-memory, and graph stores. This architecture splits the actual data 
(often redundantly) into one or more of these stores, allowing each store to address specific requirements and workloads.

Evidence must be primitive to the system. The main link between the real world (which developers often try 
to model) and the data structures holding the extracted knowledge is the "evidence" of the knowledge. 
This evidence is often the raw documents, databases, dictionaries, or image, text, and video files from 
which the knowledge is derived. When it comes to making pointed and useful contextual queries during 
a discovery process, the metadata and other associated information often play a role in inference of the knowledge. 
Thus, it is critical not to lose the linkage between the relationships stored in the graph and where those relationships come from.

Federation of global, domain-specific, and customer-specific knowledge. In a case like IBM clients, who build 
their own custom knowledge graphs, the clients are not expected to tell the graph about basic knowledge. 
For example, a cancer researcher is not going to teach the knowledge graph that skin is a form of tissue, 
or that St. Jude is a hospital in Memphis, Tennessee. 
This is known as "general knowledge," captured in a general knowledge graph.

The next level of information is knowledge that is well known to anybody in the domain for example, carcinoma 
is a form of cancer or NHL more often stands for non-Hodgkin lymphoma than National Hockey League 
(though in some contexts it may still mean thatsay, in the patient record of an NHL player). The client 
should need to input only the private and confidential knowledge or any knowledge that the system does not 
yet know. Isolation, federation, and online updates of the base and domain layers are some of the major 
issues that surface because of this requirement.

https://cacm.acm.org/magazines/2019/8/238342-industry-scale-knowledge-graphs/fulltext

