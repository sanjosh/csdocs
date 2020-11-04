
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


# Multi_head CNN 

parallel heads reading same input with different kernel_size below

```
# head 1
inputs1 = Input(shape=(n_timesteps,n_features))
conv1 = Conv1D(filters=64, kernel_size=3, activation='relu')(inputs1)
drop1 = Dropout(0.5)(conv1)
pool1 = MaxPooling1D(pool_size=2)(drop1)
flat1 = Flatten()(pool1)
# head 2
inputs2 = Input(shape=(n_timesteps,n_features))
conv2 = Conv1D(filters=64, kernel_size=5, activation='relu')(inputs2)
drop2 = Dropout(0.5)(conv2)
pool2 = MaxPooling1D(pool_size=2)(drop2)
flat2 = Flatten()(pool2)
# head 3
inputs3 = Input(shape=(n_timesteps,n_features))
conv3 = Conv1D(filters=64, kernel_size=11, activation='relu')(inputs3)
drop3 = Dropout(0.5)(conv3)
pool3 = MaxPooling1D(pool_size=2)(drop3)
flat3 = Flatten()(pool3)
# merge
merged = concatenate([flat1, flat2, flat3])
# interpretation
dense1 = Dense(100, activation='relu')(merged)
outputs = Dense(n_outputs, activation='softmax')(dense1)
model = Model(inputs=[inputs1, inputs2, inputs3], outputs=outputs)
```

https://machinelearningmastery.com/cnn-models-for-human-activity-recognition-time-series-classification/
