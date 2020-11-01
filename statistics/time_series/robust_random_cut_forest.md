

# Random cut forest

* Allows dynamic updates and deletions
* Only works for continuous variables
* Do random partitioning of data based on attribute until p is single point in partition
* Attributes picked with replacement
* Anomaly has smaller depth than normal points
* Depth converges as you creates forest (many trees)

# Robust Random Cut Forest - Guha, Mishra

Unsupervised outlier detection on stream

Divide data into shingles

Robust Random Cut forest = collection of independent Robust Random Cut Tree

RRCF is used as sketch or synopsis

Key idea : Use model complexity instead of path length as measurement of anomaly

## During training

pick attribute proportional to variance within that attribute, and a random value between min and max of that attribute  
Create N trees, each with M points  

## During inference

add the new point to each tree in the forest.  
Temporarily reassemble the tree after including p  
Return average depth   

## Updating 

Use time decayed reservoir sampling to update training pool

## Algorithm for weighted reservoir sampler,

1. For each item i choose a random number u(i) in [0, 1) and compute the value -(1 / w(i)) * log u(i)
2. Remember the K smallest values (and corresponding items) seen
3. A time decayed reservoir sampler can be obtained by setting weight(w(i)) to e^(lambda * age(i)).

Update trees upon point insertion or deletion

Each ensemble has a sampler (sampling points) : reservoir sampling

Time decay reservoir sampler

* Liu, Fei Tony.  isolation-based anomaly detection iForest, iTree 2012

http://proceedings.mlr.press/v48/guha16.pdf

https://docs.aws.amazon.com/kinesisanalytics/latest/sqlref/sqlrf-random-cut-forest.html
