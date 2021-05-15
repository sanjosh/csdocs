# strict mode

"use strict"


# Two types of objects

1. described by ECMA (built-in like Array or user-defined)
2. defined by host env (browser - like console, window and DOM)

# Global

* every JS env has a global object
* any var you do not declare before usage becomes part of global
* chain assignments can create globals (var a = b = 6 ; here b is global)
* avoid globals - always define variable using "var"
* globals defined with 'var' cannot be deleted, but implicit globals can - because they are properties of global object.

```
var global = (function() {
	return this;
} ());
```

# Single var at top of func

function func() {
   var i = 1, j = 2, myobj = {};
}

# cache the array length 

```
for (var i = 0, len = myarray.length; i < len; i += 1) {
}
//countdown
for (var i = myarray.length; i --) {
}
```
