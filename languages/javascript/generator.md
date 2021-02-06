
## put asterisk near function

```
function* name_of_func() {
}
```

returns { value : X : done : true/false}

## generator composition

generator calls generator using `yield*`

```
function* generatePasswordCodes() {
  // 0..9
  yield* generateSequence(48, 57);
  // A..Z
  yield* generateSequence(65, 90);
```

## two way

 unlike regular functions, a generator and the calling code can exchange results by passing values in next/yield

https://javascript.info/generators

