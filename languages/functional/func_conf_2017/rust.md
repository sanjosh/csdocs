
RUST - Alois Cochard

# Features
* Pattern matching
* higher order func
* immutable
* task based concurrency
* garbage collector
* iterator ?
* algebraic data types
* pattern matching
* type classes = called traits 
* no inheritance in Rust
* associated types  (type family in Haskell)

Servo browser engine was written in Rust - used in Firefox QUantum 

* let i = 3 // immutable
* let f = |a| a + 1 // first class func 
* closure
* higher order func
* move keyword used to move obj to heap // Box as_ref - why cant language detect (slide 16)?
* collect() lazy
* mut keyword - mutation
* Box::new

# DysFunctional (limitations)

* Lack of higher kindred types - RFC 324
* effect tracking not done
* variance rules - covariance and invariance only
* error handling - enum Result <T, E> { Ok(T), Err(E) }
* idiom brackets - Conor McBride Applicative Programming with Effects

# Practical RUST

* GC does Lifetime tracking - std::move() - obj can be passed by value or ref
* mutation tracking - can I between convert mut and non-mut ?
* Affine types - (soon in haskell) 
* Linear type - used exactly once in func
* wrapper types - 
```
	Box<T>(like move, heap alloc), 
	Arc<T> (share value between threads), 
	Rc<T> (share owner with ref count)
```
* Testing as part of language
* Benchmarking
* Automatic type classes derivation
* Concurrency with channels (a la haskell)
* Hygienic macro system (variadic)
* parallel iterators with Rayon library
* Compiler toolchain uses llvm.  does not convert to C


# Questions

* what is &Bar in parameter list  -pass by value or ref
* start new threads ?
* libraries - IO, string class - are they implemented in C ? (FFI)
* call from/to C or java - byte order of data structures ?
* debugging tools - heap, buffer overrun
* what kind of bugs do u hit and never hit as compared to C++ ?
* is language being actively developed/extended
* does iterator use zipper internally ?

# References

* github.com/rust-lang/rfcs
* doc.rust-lang.org
* rustbyexample.com
* Fearless concurrency in Firefox Quantum 
* Rust for func prog
* Rust prog lang - the book
