
# Meal delivery routing problem

variant of vehicle routing problem 

uncertainty introduced
1. scheduling (couriers have some freedom to choose the hours they work), 
2. dispatching (couriers can reject an offered assignment)
3. routing (couriers can disregard the suggested sequence of deliveries).

additional requirement:
1. low latency : food must be picked quickly and delivered in time bound. 
2. wide swings in demand in space and time

how to balance the fulfillment of current tasks and the preservation of flexibility to complete future and unknown tasks.


At or before busy periods, like lunch and dinner time, when many orders arrive in a short time-span, 
the algorithm attempts to create more efficient routes, even at the expense of individual order service quality, 
in relatively calm periods, the emphasis switches to delivering orders fast.


problem characteristics
1. multiple pick-up points (restaurants), 
1. dynamic order arrivals, 
1. delivery capacity distributed throughout the day in the form of courier shifts, 
1. the possibility to pick up multiple orders simultaneously
1. Orders from the same restaurant may be combined into “bundles” with multiple drop-off locations

performance metrics
1. number of orders delivered
2. orders delivered per hour
3. orders per bundle which was picked
2. total courier compensation
3. courier utilization
3. order-submit-to-delivery time
4. order-ready-to-delivery time
5. order-ready-to-pickup time

# algorithms

## rolling horizon

during busy time, increase utilization while increasing delivery latency

### admission control

how to decide if order can be accepted ?

### algo

since order bundle determines a unique route, both can be used interchangeably.

every X minutes, 
1. sort all upcoming orders by non-decreasing ready time
1. compute number of target bundles to create (based on courier util or order latency)
1. put orders into bundles and decide routes
1. find all available couriers at that time
1. assign bundles to couriers. (bipartite matching, linear programming or integer programming)


### commitment strategy

after defining tentative courier-order assignments, a commitment strategy dictates which of these decisions are postponed 

assignments has two travel segments: 
1. “inbound” travel to the restaurant, 
2. an “outbound” delivery trip (i.e., an open route).

can commit to first without second.

send a courier to a restaurant without committing the delivery of a specific bundle

a courier may be instructed to move to a restaurant as soon as there is at least one order for the courier to pick up, but before a final determination is made about the exact set or sequence of orders to be assigned.


### priority scheme

to ensure earlier or more important orders are serviced first,
assignments are built by first partitioning the set of relevant bundles in priority groups based on their “urgency”

Priority scheme. Orders are classified according to their unavoidable delays in drop-off and pick-up:
• Group I: orders whose target drop-off time is impossible to achieve.
• Group II: orders not in Group I which can no longer be picked up at their ready time.
• Group III: orders not in Group I or II.

### hyperparameters

1. vary the period at which assignment is run
2. vary assignment horizon period
3. vary bundle sizes
4. vary priority
5. vary commitment strategy

## references

Reyes, et al.  The Meal Delivery Routing Problem (https://github.com/grubhub/mdrplib)
