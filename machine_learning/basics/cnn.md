
# CNN 1D

Conv1D(filters, kernel_size, input_shape = (n_timesteps, n_features))

* kernel size = length of convolution window.  
* filters = dim of output space - dim of last column in output shape

https://missinglink.ai/guides/keras/keras-conv1d-working-1d-convolutional-neural-networks-keras/

https://machinelearningmastery.com/cnn-models-for-human-activity-recognition-time-series-classification/

Another difference between 1D and 2D networks is that 1D networks allow you to use larger filter sizes. 
In a 1D network, a filter of size 7 or 9 contains only 7 or 9 feature vectors. 
Whereas in a 2D CNN, a filter of size 7 will contain 49 feature vectors, making it a very broad selection.

Another difference, though, is the fact that you can afford to use larger convolution windows with 1D CNNs. 
With a 2D convolution layer, a 3 × 3 convolution window contains 3 × 3 = 9 feature vectors. 
With 1D convolution layer, a window of size 3 contains only 3 feature vectors. 
You can thus easily afford 1D convolution windows of size 7 or 9.

https://missinglink.ai/guides/keras/keras-conv1d-working-1d-convolutional-neural-networks-keras/

