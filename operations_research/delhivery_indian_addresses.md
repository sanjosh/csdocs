

https://medium.com/@kabirrustogi/learning-to-decode-unstructured-indian-addresses-c80ffcda2e84

```
At Delhivery, we have built an in-house solution, AddFix,
which uses generative machine learning techniques to solve this problem.
The training data for the algorithm includes address strings that e-commerce
customers provide at the time they place orders, along with location
data captured from mobile devices of delivery boys who eventually
deliver e-commerce shipments to the customer’s doorstep.


Graphical models churn millions of customer address records in an
unsupervised way to learn the names of cities, localities, sub-localities,
building names and POIs that exist in a given geographical region,
along with their hierarchical relations and alternative spellings.

This step essentially generates a directed acyclic graph consisting of
different locality features that people commonly write in addresses.

Next, we determine the geographical boundaries of each node in the graph
based on the location data captured by mobile devices of ground staff.

Every month, we capture hundreds of reliable geocodes for each node,
which allow us to draw out polygons for the associated locality feature.

These polygons keep becoming more accurate as we do more deliveries.

Given a new address at the time of prediction, we search the graph for a
set of connected nodes that match most closely with the different locality
features provided in the address. To ensure that the matching is not very
sensitive to variations in spelling, we employ phonetic distance based fuzzy search,
which is specifically tuned for Indian languages. For instance, most standard
phonetic based similarity engines, will not be able to pick up that Gurgaon and
Gudgaon, sound similar.

The resultant output includes the entire location hierarchy of the given address,
i.e., state, city, locality, sublocality, rooftop, along with polygon boundaries
(where available) for each node in the hierarchy.


````
