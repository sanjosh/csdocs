
# webassembly to analyze file solely on client side

WebAssembly is a low-level compilation target for many languages like Go, C and C++. It is since 2017 supported in all major browsers and enables performance critical code to run in the client or other JavaScript environments.

This means we could take our existing Go code, compile it to a WebAssembly module:

```
GOOS=js GOARCH=wasm go build -o main.wasm main.go
```

To be able to use the compiled main.wasm in the client, we first need to setup Go’s runtime on the browser. The Go authors have written a wasm_exec.js file that does exactly this and provides a global Go constructor.

By including this file into our project, we can then use that global Go constructor to create a go object. and use that together with the compiled webassembly module main.wasm, to instantiate it in the componentDidMount() lifecycle hook in React, using WebAssembly.instantiateStreaming():

```
componentDidMount() {
  const go = new Go();

  WebAssembly.instantiateStreaming(
    fetch("main.wasm"),
    go.importObject
  ).then(async result => {
    go.run(result.instance);
  });
}
```

 And we can now call our runUno function, from the Go code, directly in React:

const output = runUno(input)

https://unomaly.com/blog/packaging-uno-into-browser-using-webassembly

# webassembly pros and con

pros
1. reduce battery consumption on mobile
2. secure : use offset instead of pointer.  execution stack is separate from code segment (no malware exploit)
3. wasm already optimized - no compilation at load-time or runtime.

cons
1. not currently multi-threading
2. no source maps available for debugging
3. no platform API access (DOM, CSSOM, WebGL, IndexedDB)3. no platform API access (DOM, CSSOM, WebGL, IndexedDB)3. no platform API access (DOM, CSSOM, WebGL, IndexedDB)
4. No garbage collection unlike JS

https://blog.sessionstack.com/how-javascript-works-a-comparison-with-webassembly-why-in-certain-cases-its-better-to-use-it-d80945172d79

# use-cases

https://webassembly.org/docs/use-cases/

# server side 

WebAssembly was invented as a client-side technology, but it is also proven very useful on the server-side. S

https://www.secondstate.io/articles/why-webassembly-server/

# wasmedge SSVM 

application level VM versus docker which is OS-level container 

https://github.com/WasmEdge/WasmEdge

# WASI

WebAssembly Systems Interface (WASI) is a standard extension for WebAssembly bytecode applications to make operating system calls

https://www.secondstate.io/articles/wasi-access-system-resources/
