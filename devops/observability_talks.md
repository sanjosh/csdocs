
# Comprehending the incomprehensible (uber)

https://atscaleconference.com/videos/systems-scale-2019-comprehending-incomprehensible-architecture/

Yuri Shkuro - Jaeger tracing

single trace can have lots of points - hard to evaluate

1. how do we compare traces
1. how to find baseline
1. how to compress trace
1. capture events for network changes
1. capture events for code deployment 
1. capture retry metrics
1. load balancer events

Sample the events.  Capturing everything can have performance hits

separate metrics for synthetic traffic

Compare aggregates instead of individual traces

Fast failure attribution

Synthetic generator on Production with Test accounts is used to generate user trips and create statistical model

# Monarch @ google

https://atscaleconference.com/videos/systems-scale-2019-monarch-googles-planet-scale-monitoring-infrastructure/

zone = strongly connected network

monitor & store locally

1. Monarch zone can do ingestion, retention, queries
1. Router → Leaf  → Recovery Log 
1. Assigner does load balancing between Leafs
1. Queries come to Zone Mixer
1. Alert comes from Evaluator

1. Global view
1. Config Server talks to Zones
1. Queries go to Root Mixer which go to Zone Mixer

Query : Select time series, select window, Group By, Percentile

FETCH, WINDOW, GROUP BY, POINT

1. How to find global TPS - query all Zone mixers for RPC metrics*
1. How to detect Anomalies
1. Compare to last month/year
1. Cross schema joins

Usage quota

Panopticon

Do early Dimension reduction

