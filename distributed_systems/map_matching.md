
# Map matching

- map GPS signals to road positions

graph representation 
* intersection is a vertex, road is edge
* add properties for one way street, number of lanes

various distance btween pts
* lower bound is great circle or haversign distance (curvatureo of earth)
* shortest path - djikstra or "A\*"

System 
* Input is GPS signal = (lat, long, speed, course)
* Output is pos on road (lat long on actual road, road segment ID, road name, direction heading)

Problems
* GPS signals are noisy and sparse
* GPS signal obfuscated by buildings in urban areas

Use cases
1. driver position
2. fare calculation

Algo (see ref 2)
1. kalman filter
2. hidden markov

predict road taken given sequence of 5 gps signals
* for every gps signal, predict closest roads using geospatial index (min search radius)
* gps signal are observations in HMM
* road pos are hidden state in HMM
* compute emission probability - based on how close gps signal to road
* compute transition probability between every pair of consecutive hidden states (r1, r2)- distance 
* use viterbi algo on HMM

## Ref

1. https://www.youtube.com/watch?v=ChtumoDfZXI

2. Quddus, Ochieng, Noland.  Current map-matching algo for transport applications (2007)
3. Newson and Krumm.  Hidden Markov map matching through noise and sparseness
