
# Using sklearn

```
from sklearn.preprocessing import LabelEncoder, OneHotEncoder

integer_encoded = label_encoder.fit_transform(values)
onehot_encoded = onehot_encoder.fit_transform(integer_encoded)
inverted = label_encoder.inverse_transform([argmax(onehot_encoded[0, :])])
```

# using Keras

```
from numpy import argmax
from keras.utils import to_categorical

encoded = to_categorical(data)
inverted = argmax(encoded[0])
```

# reference

1. https://machinelearningmastery.com/how-to-one-hot-encode-sequence-data-in-python/

