
# arrays

## creation

* np.zeros
* np.ones
* np.full
* np.eye - for identity matrix
* np.random

## indexing

### boolean indexing

```
a = np.array(...)
bool_idx = (a > 2) - bool_idx contains all elements greater than 2
a[bool_idx] - accesses all of the selected elements
```

## slicing 

x[start:stop:step]

## reshaping 

* x.reshape((1, 3)) OR 
* x[:, np.newaxis]

## concatenation

* np.concatenate([x, y], axis)
* np.vstack
* np.hstack
* np.dstack

## splitting

* np.split
* np.hsplit
* np.vsplit
* np.dsplit

## broadcasting

https://docs.scipy.org/doc/numpy/user/basics.broadcasting.html

## sorting on a column

https://stackoverflow.com/questions/4455076/how-to-access-the-ith-column-of-a-numpy-multidimensional-array


# poly fit

np.poly1d(np.polyfit())

# TODO

https://towardsdatascience.com/advanced-numpy-master-stride-tricks-with-25-illustrated-exercises-923a9393ab20

https://numpy.org/doc/stable/reference/generated/numpy.lib.stride_tricks.as_strided.html

https://betterprogramming.pub/numpy-illustrated-the-visual-guide-to-numpy-3b1d4976de1d
