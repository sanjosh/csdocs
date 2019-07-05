
# Swiggy capacity planning

1. max sla time
2. free and busy delivery executives (DE)
3. batching possibility - customer density, DE capacity
4. traffic 

## Aggregate capacity
1. calc at zone level
2. ratio = number of orders/number of active DE
3. manually determined
4. reduce bad orders - undelivered in SLA

## Order limiter 
1. computed every X minutes
2. busy DE - time to free

## order level capacity
1. real time computation for a specific order
2. fast and approx calc

## efficiency levers
1. efficiency - number of orders per DE per hour
2. hungarian assignment
3. who to assign, when to assign

batching
1. geospatial
2. time proximity
3. predict if order can be batched in future

## time predictions
1. order to assigned time
2. first mile time
3. prep time
4. order to pickup time
5. last mile time
6. customer to customer time

## trade-offs
1. efficiency vs DE experience (batched order, DE wait time, order delay time)
2. efficiency vs speed
3. speed vs SLA
4. compliance vs accuracy

## input data accuracy
1. location (GPS inaccurate, address not correct)
2. DE behaviour - battery saving, says I have reached but not reached
3. restaurant - wait for DEs to arrive, optimize across channels

intervention to reduce data accuracy
1. product tech intervention (geofencing)
2. operational intervention

## identify sources of high variance
1. DE behaviour
2. load on restaurants
3. current system stress

## experiments
1. simulation
2. shadow mode
3. on-ground strategies (simple pre-post days, alternate days, control vs test zone, time slicing, randomized selection of orders, randomized geospatial)
4. rollout

kepler.gl visualization

## References

1. Piyush Srivastava Swiggy at hasgeek Logistics in Mobility conf 2018

