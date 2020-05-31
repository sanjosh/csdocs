
# SD-WAN between Data centers

https://atscaleconference.com/videos/networking-scale-2019-operating-facebooks-sd-wan-network/

EBB = centralized global WAN connecting data centers

traditional RSVP-TE backbone not scalable https://en.wikipedia.org/wiki/RSVP-TE

network convergence, high power-space demand, control plane scalability

multi-plane architecture and controller sharding used to reduce blast radius and do A/B testing

IGP used on WAN

BGP injector injects prefixes into routers to move traffic to new routes

Network device retains old routes so as to continue working in case disconnected from control plane 

SFlow traffic collector were dropping metrics.    Migrated to NHG counters

LSP - label switched path

UCMP (Unequal-Cost Multiple Path) to avoid traffic loss caused by asymmetric plane network (one of eight planes failed due to line cards)

SR-controller segment routing

Are different classes of traffic divided between planes ? yes. Each class has its own traffic engineering algorithms

