
# object 

Methods are nothing more than properties that hold function values with implicit `this`

If you want to pass `this` explicitly, you can use a function’s call method
```
speak.call(rabbit, "argument1")
```

object has
1. property
2. prototype (fallback source for properties)


### prototype

` Object.getPrototypeOf()`

prototypes form tree structure with root `Object.prototype`

` Object.create` to create prototype

```
Rabbit.prototype.speak = function(line) {
}
```

Function.prototype

```
class C {
    constructor (v) {
    }
}
```

class can be used in expression
```
let object = new class { getFunc() { } };
```

Object.keys

hasOwnProperty 

## iterator

Symbol.iterator

```
Matrix.prototype[Symbol.iterator] = function() {
    return new MatrixIterator(this);
};
```

## getter and setter (using get and set)

```
class Temp {
    constructor(celsius) {
    }
    get fahrenheit() {
    }
    set fahrenheit() {
    }
}
```

## static

```
class Temp {
    constructor(celsius) {
    }
    static fromFahrenheit(val) {
        return new Temp
    }
}
```

## inheritance

```
class SymMatrix extends Matrix {
    constructor() {
        super()
    }
}
```

instanceof

## persistence

```
let object = Object.freeze({value : 5})
```


# Reference

1. Eloquent Javascript book
```
