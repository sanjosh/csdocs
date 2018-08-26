
# Event loop

* whereas apache is one-thread-per-client, nodejs shares few threads among many clients.
* nodejs event loop uses libuv
* event loop also runs async network IO
* nodejs has worker pool for blocking tasks
* event loop has queue for pending events; worker pool has queue for pending tasks

# do not block event loop 

## use safe regex 

* bad regex can block nodejs event loop
* alternative:  use node-re2 which uses google re2
* check for vulnerable refex using safe-regex or rxxr2

## do not use these core node modules

* do not use encryption, compression, fs, child process modules in event loop

## async json parsing

* use async json modules : JSONStream, Big-friendly Json

## save partial results using javascript closure

```
function asyncAvg(n, avgCB) {
  // Save ongoing sum in JS closure.
  var sum = 0;
  function help(i, cb) {
    sum += i;
    if (i == n) {
      cb(sum);
      return;
    }

    // "Asynchronous recursion".
    // Schedule next operation asynchronously.
    setImmediate(help.bind(null, i+1, cb));
  }

  // Start the helper, with CB to call avgCB.
  help(1, function(sum){
      var avg = sum/n;
      avgCB(avg);
  });
}
```

## offload to worker pool

* use C++ addon or node-webworker-threads

# References

1. https://nodejs.org/en/docs/guides/dont-block-the-event-loop/

