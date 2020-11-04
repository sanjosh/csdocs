
# vanilla

```
model = Sequential()
model.add(LSTM(...))
model.add(Dense)
```

# Stacked

```
model = Sequential()
model.add(LSTM(return_sequences=True))
model.add(LSTM()
model.add(Dense)
```

# Bidirectional

```
model = Sequential()
model.add(Bidirectional(LSTM(...)))
model.add(Dense)
```

# CNN 1D

```
model = Sequential()
model.add(TimeDistributed(Conv1D(input_shape=(None, n_steps, n_features)))
model.add(TimeDistributed(MaxPooling1D(pool_size=2)))
model.add(TimeDistributed(Flatten()))
model.add(LSTM(...)
model.add(Dense(1))
```

# ConvLSTM

```
model = Sequential()
model.add(ConvLSTM2D(input_shape=(n_seq, 1, n_steps, n_features)))
model.add(Flatten())
model.add(Dense(1))
```

# TimeDistributed for many-to-many

## one feature input, one feature output


```
n_samples = 5
n_timesteps = 1
n_features = 1

X = (n_samples, n_timesteps, n_features)  
Y = (n_samples, n_timesteps)

model.add(LSTM(n_samples, input_shape = (n_timesteps, n_features)))
model.add(Dense(n_features))

```

## 5 time steps and 1 feature is input; 5 features is output without using TimeDistributed

Need Dense(5) so output is a vector


```
n_samples = 1
n_timesteps = 5
n_features = 1

X = (n_samples, n_timesteps, n_features)
Y = (n_samples, n_timesteps)

model.add(LSTM(n_timesteps, input_shape = (n_timesteps, n_features)))
model.add(Dense(n_timesteps))
```

## input vector, output vector

use TimeDistributed with return_sequences

```
n_samples = 1
n_timesteps = 5
n_features = 1

X = (n_samples, n_timesteps, n_features)
Y = (n_samples, n_timesteps, n_features)

model.add(LSTM(n_timesteps, input_shape=(n_timesteps, n_features), return_sequences=True))
model.add(TimeDistributed(Dense(n_features)))


```

# predict 1 step of output series from 2 input series

given 2 input series 

[a, b, c] 
[x, y, z]

and 1 output series

[1, 2, 3]

to predict [3] as a result of previous 3 time steps of both series [a, b, c] + [x, y, z]

define 

```
n_timesteps = 3
n_features = 2 # input series
n_output = 1
model= Sequential()
model.add(LSTM(input_shape = (n_timesteps, n_features))
model.add(Dense(n_output))
```

# predict 1 next step of each of 3 input series

given 3 input series 

[a, b, c] 
[l, m, n]
[1, 2, 3]

to predict next step of all 3 series from previous 3 time steps

[d] 
[o]
[4]

define 

```
n_timesteps = 3
n_features = 3 # input series
n_output = 3 # one step for each series
model= Sequential()
model.add(LSTM(input_shape = (n_timesteps, n_features))
model.add(Dense(n_output))
```

# predict more than 1 step of single series

given [1, 2, 3] 

predict [4, 5]

## using vector output model

```
n_timesteps = 3
n_features = 1 # input series
n_output = 2 # 2 steps ahead
model= Sequential()
model.add(LSTM(input_shape = (n_timesteps, n_features))
model.add(Dense(n_output))
```


## using encoder decoder model

```
n_timesteps = 3
n_features = 1 # input series
n_output = 2 # 2 steps ahead
model= Sequential()
model.add(LSTM(input_shape = (n_timesteps, n_features))
model.add(RepeatVector(n_output))
model.add(LSTM(return_sequences = True))
model.add(TimeDistributed(Dense(1))) # this will output a vector because of TimeDistributed
```

# predict more than 1 step of output series from 2 input series

given 2 input series 

[a, b, c] 
[x, y, z]

and 1 output series

[1, 2, 3, 4]

to predict [3, 4] as a result of previous 3 time steps of both series [a, b, c] + [x, y, z]

```
n_timesteps = 3
n_features = 2 # input series
n_output = 2
model= Sequential()
model.add(LSTM(input_shape = (n_timesteps, n_features))
model.add(Dense(n_output))
```

# predict more than 1 step of each of 3 series from 3 input series

given 

[a, b, c] 
[l, m, n]
[1, 2, 3]

to predict next 2 step of all 3 series from previous 3 time steps

[d, e] 
[o, p]
[4, 5]

## using Encoder-Decoder.  


```
n_timesteps = 3
n_features = 3 # input series
n_output = 2 # two step for each series
model= Sequential()
model.add(LSTM(input_shape = (n_timesteps, n_features))
model.add(RepeatVector(n_output))
model.add(LSTM(return_sequences = True))
model.add(TimeDistributed(Dense(n_features))) # this will output a 3x2 because of TimeDistributed
```

## using Vector Output model

TODO

# references

https://machinelearningmastery.com/how-to-develop-lstm-models-for-time-series-forecasting/

https://machinelearningmastery.com/timedistributed-layer-for-long-short-term-memory-networks-in-python/

https://github.com/keras-team/keras/issues/1029

https://datascience.stackexchange.com/questions/10836/the-difference-between-dense-and-timedistributeddense-of-keras
