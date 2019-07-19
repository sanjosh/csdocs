
# ETA

Fares, Dispatch, Navigation, Pool, Pickup all need ETA

1 trip involves 1000s of requests to ETA

layers of ETA 
1. map data
2. routing
3. traffic
4. ML

1. djikstra runs in N.logN but N is half a million intersections in San Francisco and have to serve 500k req/sec
2. use graph partitioning 

## traffic

traffic = func(traversal info) and traversal info = func(time, weather)

GPS data on road segments
1. speed = AB/tA - tB
2. 1 day of GPS data = 0.5 TB
3. 1 week of traffic model = few TB

use traffic info to populate edge graphs

edge weight = func(traffic info)

1. how long is a real time traffic estimate valid
2. how to combine historical and real time traffic

## ML

ETA error has thicker tails in India

ML can capture variability in region, time, trip type, driver behaviour 

want non-parametric (no prior info on interaction) and non-linear models

## misc

fallback ETA to avoid system down situations

monitor ETA to obviate consumer issues

https://www.youtube.com/watch?v=FEebOd-Pdwg
