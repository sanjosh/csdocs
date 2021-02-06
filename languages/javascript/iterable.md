
To make the range object iterable (and thus let for..of work) 
we need to add a method to the object named Symbol.iterator (a special built-in symbol just for that).

Arrays(index, len) are different from Iterable (next)

## Array.from(obj[, mapFn, thisArg])

takes an iterable or array-like value and makes a “real” Array from it. 

https://javascript.info/iterable



