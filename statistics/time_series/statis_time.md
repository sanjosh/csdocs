
# Alternatives to time series modeling using neural nets 

aditya patel - stasis

problems
1. missing data
2. noisy data

1. Similarity Measure approaches

dtw + knn classifier

2. Arima model

3. RNN

susceptible to noisy and missing data

4. 1D CNN

prediction label = mortality  
robust against missing and noisy data  
faster training  

5. TCN

residual block reduces exploding gradient

6. Time series to bag of words

quantize data into bins   
map each bin into character  
use NLP   

7.  Time series to image

transform cartesian coordinates to polar coordinates  
create Gram matrices - GASF, GADF
create image from Markov Transition fields  MTF
create image by calculating recurrence plots 
feed images to tiled CNN  


https://www.youtube.com/watch?v=WoLlZLdoEQk
