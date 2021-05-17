
# BGP in data centers in FB

NSDI 21 https://www.youtube.com/watch?v=wHfYUbKNEyc

why bgp
1. scalability 
2. policy control
3. long-term stability

challenges of BGP
1. long convergence
1. routing instability
1. misconfiguration

design principles
1. config uniformity
1. operation simplicity

scalable network topology
1. server pod  (fabric switch, rack switch)
2. spine plane (spine switch)

use BGP ECMP at every hub

ASN allocation : number scheme for server pod and spine plane

route summarization
1. minimize HW FIB size requirements
2. reduce control plane processing
3. rack aggregate  and pod aggregate

BGP policy used to ensure 
1. reliability : route propagation scope, predefine backup paths
2. scalability : avoid backup path explosion by enforcing route summarization
3. maintainable : remediate problematic nodes without disrupting traffic
4. service reachability : avoid disruption when addition/removal

reduce time/need for BGP convergence

Operational experience
1. testing and deployment canary
