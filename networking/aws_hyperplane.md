# AWS Hyperplane

Ref : https://atscaleconference.com/videos/networking-scale-2018-load-balancing-at-hyperscale/

AWS Hyperplane is an internal layer 4 service.  Provides persistent connections

Services on top of hyperplane
1. s3 load balancer
2. amazon elastic filesystem
3. vpc nat gateway
4. network load balancer
5. vpc privatelink
6. l4 load balancer
7. l4 nat

in each AWS region, there are availability zones.  hyperplane operates in an availability zone.  cellular architecture contain blast radius

hyperplane has 3 layers, runs on an EC2 instance
1. TOP : packet forwarding and rewriting - only layer which sees every packet
2. Flow Master : connection tracking (apply rules to flow).  Packets sent to appropriate Flow Master based on Hash.
3. Decider : chooses LB targets and assigns NAT source ports

## blackfoot

Blackfoot is a horizontally scaled stateless converter sitting on edge.  It translates between IP format and Amazon VPC encapsulation

## Nitro

* Embedded Nitro Controller runs on each EC2 instance. It does IP fragment re-assembly and traffic encapsulation.
* Nitro controller is aware of Hyperplane and sends packet back to it (to avoid path asymmetry)

Question : having packets go thru load balancer on egress is an anti-pattern in load balancing.  The preferred option is DSR (Direct Server Return) otherwise Load Balancer becomes a bottleneck.  

Answer : have to go thru hyperplane because of NAT + metrics.  Makes no diff in network latencies

## SHOCK Robustness principle (Self-healing or constant work)

* Be able to handle large shocks (LSE)
* Always operate in repair mode
* When node fails, Hyperplane does less work !
* Instead of propagating delta, they propagate all the data - even if all change, load does not increase
* Noisy neighbour problem : use Shuffle sharding technique to ensure no two customers share same set of nodes.
* How to avoid DDoS : shuffle sharding

https://aws.amazon.com/blogs/architecture/shuffle-sharding-massive-and-magical-fault-isolation/

# Hyperplane

10 min

https://www.youtube.com/watch?v=GkYGo1M3vyc 

hyperplane used by NLB, NATGW, PrivateLink, GWLB, TGW 

hyperplane : 
1. multi-tenant distributed system running on EC2
2. four components : flow tracker, packet processor, control plane, monitoring and kibana streams

hyperplane flow tracking database : built own

multi-tenancy : noisy neighbours

shuffle sharding : reduce impact of one customer on another




