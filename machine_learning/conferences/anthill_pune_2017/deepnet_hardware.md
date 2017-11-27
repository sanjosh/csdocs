
# Inference in neural nets - Saurabh Agarwal

neural nets - MAC ops (multiply and accumulate)
All MAC ops can be parallelized

compute libs 
1. CPU - GeMM, Blas, Lapack
2. GPU - CuDNN

Two types of arch - Temporal and Spatial

Numpy uses LaPack

im2col : image to column.  Every deep learning lib has this op

optimizations
1. Reduce precision: floating to fixed, weight sharing
2. Reduce num of ops

Vincent
- convert 32 bit FP to 8 bit fixed reduces RAM overhead by 75 perc

Replace large filter by series of smaller filters 
- 5x5 conv by 2 3x3 conv

# Followup
1. Yangquing Jia. Learning Semantic image representations at large scale

