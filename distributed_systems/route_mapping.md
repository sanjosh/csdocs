
# Factors

1. use map 
2. time through intersection (right vs left turn)
3. use traffic data
4. future cost - if route is long
5. type of transporation - bicycle, car

# Algos

* highway hierarchy
* reach-based routing - A-star
* contraction hierarchy
* Bidirectional
* hub labeling algo

# facebook

road detection = semantic segmentation using D-LinkNet architecture (DeepGlobe Satellite Road Extraction Challenge). 

output = rasterized map 

followed by Vectorization and postprocessing techniques 

which convert them into road vectors compatible with geospatial databases such as OSM.

https://ai.facebook.com/blog/mapping-roads-through-deep-learning-and-weakly-supervised-training/

# ref

1. https://www.quora.com/How-does-the-algorithm-of-Google-Maps-work
2. http://www.drdobbs.com/architecture-and-design/priority-queues-for-motorists/184405153

