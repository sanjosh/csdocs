

# Phi Accrual 

An accrual failure detector decouples monitoring and interpretation. 

That makes them applicable to a wider area of scenarios and more adequate to build generic failure detection services. 

The idea is that it is keeping a history of failure statistics, calculated from heartbeats received from other nodes, and is trying to do educated guesses by taking multiple factors, and how they accumulate over time, into account in order to come up with a better guess if a specific node is up or down. 

Rather than only answering “yes” or “no” to the question “is the node down?” it returns a phi value representing the likelihood that the node is down.

compute density distribution of arrival times in the past

https://doc.akka.io/docs/akka/2.5/common/cluster.html?language=scala#failure-detector

