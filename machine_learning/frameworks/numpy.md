
# arrays

## creation

* np.zeros
* np.ones
* np.full
* np.eye - for identity matrix
* np.random

## indexing

### boolean

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



