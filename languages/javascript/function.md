
# functions

## base definition 

```
const square = function(x) {
}
```


## declaration notation

```
function sq(x, x) {
}
```


## arrow func 

```
const power = (base, exp) => {
};
```

## implicit

```
let h = a => a % 3;
```

## function argument

pass too many: the extra ones are ignored. 
pass too few: the missing parameters get assigned the value "undefined"

optional argument : provide default


## closure

closure = ability to refer to specific instance of local binding in enclosing scopre

the function which references local bindings called closure

```
function multiplier(factor) {
    return number => number * factor; // local binding created
}
```



Object.assign

## const

const binding can change variable but not binding
```
const sc = { visit : 0 };
sc.visit = 1; // YES
sc = { visit : 2 } ; // NO
```

# for loop

```
for (let i = 0; i < str.length; i++)
for (let entry of str)
sum(range(start, end, step))
```

# list

```
let l = {
    value : 1,
    rest : {
        value : 2,
        rest : {
            rest: null
        }
    }
};
```

## higher order

1. forEach
1. map 
2. reduce
3. filter
3. some
4. findIndex

# objects

```
let descrip = {
    key1 : "high",
    "consent" : 9
}
```

# Reference

1. Eloquent Javascript book
```
