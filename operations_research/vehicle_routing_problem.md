
# VRP

https://developers.google.com/optimization/routing/vrp

Modern Route Optimization with Python by Mauro Di Pietro
https://github.com/mdipietro09/DataScience_ArtificialIntelligence_Utils/blob/master/machine_learning/example_route_optimization.ipynb

## Variations

1. Capacitated Vehicle Routing Problem: vehicles have a limited carrying capacity for the goods that must be delivered.
2. Vehicle Routing Problem with Time Windows: the delivery locations have time windows within the deliveries that must be made.
3. Vehicle Routing Problem with Pickup and Delivery: goods need to be moved from certain pickup locations to other delivery locations.
4. Vehicle Routing Problem with Profits: it is not mandatory for vehicles to visit all nodes, the aim is to maximize the sum of collected profits.

# libraries

1. Folium
2. OSMnx : queries Open Street Map and converts the response into NetworkX graphs
3. Plotly
4. ORTools
5. networkx
6. Mapbox : custom online maps

# ORTools

index manager  keeps track of the nodes indexing

routing model is the main OR-Tools object.

## examples

https://github.com/google/or-tools/tree/stable/examples/python

https://github.com/or-tools/awesome_or-tools

https://developers.google.com/optimization/introduction/python

Pawel Lichocki - OR-tools
https://www.youtube.com/watch?v=AJ6LeiMe_PQ

# Flipkart

https://www.youtube.com/watch?v=v9tUEsHD6BE

Distinguish pre-determined shipments (postal service)  versus on-demand delivery (food ordering)

## manual process

divide delivery zone into regions, sort parcels by region

1. asymmetric - some get too few, some get too many
2. inefficient - sorting takes time
3. difficult to fulfil in time windows

## optimization problem

classic cost function : minimize sum of total travel time of all agents

problem for single agent = TSP which is NP complete

## variations of problem

1. VRP with time window
2. capacitated VRP (truck has limited space)
3. Capacitated VRP with time window

## solvers

optaplanner - java

local solver

## problem

Input
1. N customers
2. pairwise distance matrix
3. m vehicles with capacity
4. serviceable time window

Multiple objectives
1. minimize uneven distribution
2. minimize stretched routes
3. minimize total travel time

## exact algo

1. integer programming
2. dynamic programming


## approx algo

1. construction heuristics (initial routes)
2. improvement heuristics (improve routes)

find minimum insertion cost, subject to time window

## questions

traffic in city taken into account

graph neural nets (now) ?

leverage past data



## references

https://youtu.be/v9tUEsHD6BE?t=1774




