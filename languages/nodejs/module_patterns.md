
# export an anonymous func

```
// bar.js
module.exports = function () {
  console.log('bar');
}

// app.js
var bar = require('./bar.js')
bar()
```

# export a named func

```
// fiz.js
exports.fiz = function () {
  console.log('fiz');
}

// app.js
var fiz = require('./fiz').fiz;
fiz();

```

# export an anon obj


```
// buz.js
var Buz = function() {};
Buz.prototype.log = function () {
  console.log('buz');
}
module.exports = new Buz();

// app.js
var buz = require('./buz')
buz.log();
```

# export a named obj


```
// baz.js
var Baz = function() {};
Baz.prototype.log = function () {
  console.log('baz);
}
exports.Baz = new Baz();

// app.js
var baz = require('./baz.js').Baz;
baz.log();
```

# export anon proto


```
// doo.js
var Doo = function() {};
Doo.prototype.log = function() {
  console.log('doo');
}
module.exports = Doo;

// app.js
var Doo = require('./doo.js');
var doo = new Doo();
doo.log();

```

# export a named prototype

```
// qux.js
var Qux = function() {} ;
Qux.prototype.log = function () {
  console.log('baz');
};
exports.Qux = Qux;

// app.js
var Qux = require('./qux.js).Qux;
var qux = new Qux();
qux.log();
```

# References

1. https://darrenderidder.github.io/talks/ModulePatterns/
