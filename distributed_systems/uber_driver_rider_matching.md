
# Uber Rider-Driver matching

Takeaway
1. Intelligent matching reduces wait time
2. Dynamic pricing is key to reliability

what they track ?
1. Number of requests
2. ETA : time to get a car
3. Completion rate : got a car

## Maps 

1. Traffic
2. Route recommendation
3. travel time prediction
4. navigation

## Matching

requirements
1. How to match driver with rider
2. how to match rider with co-rider

cost func
1. more time on trip for driver
1. lower pickup time for rider

heuristics
1. shortest pickup time
2. trip upgrade

matching requires predicting travel time from driver to rider

how to determine price ?

1. in next 5 min, how many drivrs available and how many riders expected
2. demand curve-supply curve (consumr surplus, producr surplus)
3. create heatmap
4. construct surge multiple

* riders are sensitive to pickup time
* drivers are snsitive to pickup + open time

* welfare concept = value created for riders and drivers
* market equilibrium = price + pickup time (not plain demand supply)
* if price is too low, pickup time increases, on-trip time drops
* pricing require forecast of demand, supply and travel time

## Ref

1. castillo, knoepfle, weyl 2016. 
2. hall kendrick nosko uber surge pricing
3. Dawn Woodard https://www.youtube.com/watch?v=GyPq2joHZv4
