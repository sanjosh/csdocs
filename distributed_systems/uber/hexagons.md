
# use hexagons for tiling

initially used geofencing for demand heatmaps.  but drivers cancel because of price cliffs between regions.  needed smoothing

cities change - cannot have fixed geofences

requirements
1. need dynamic neighbourhoods
2. need smooth gradients
3. need clear center of demand

create grid of hexagons

why hexagons and not triangle, square
1. subdivision (heirarchy)
2. easier neighbour traversal system
3. lesser distortion (earth is a sphere)

Google used square S2 grid whereas Uber uses H3

create global grid over earth
1. 122 base cells
2. subdivide into smallest hexagon

https://www.youtube.com/watch?v=_-265mfMzl4
