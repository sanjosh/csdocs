
# libjit 

* creates obj file from IR (not from free C text)
* create context, add instr, compile and call
* support for creating struct
* closure - can be used to create func ptr from jit func

# GNU Lightning

# GCCJIT

# clang/llvm

* see MCJIT example (llvm/ExecutionEngine/MCJIT.h)

```
clang++ -emit-llvm
lli
```

* Alternative is ParseIR or ParseIRFile 

  http://stackoverflow.com/questions/22239801/how-to-load-llvm-bitcode-file-from-an-ifstream

  https://github.com/eliben/llvm-clang-samples

# nativejit 

# cling @ cern

built on top of LLVM

# intel ORP 

provides common routines used by any JIT for codegen & gc

# Webkit uses LLVM

https://webkit.org/blog/5852/introducing-the-b3-jit-compiler/

# hack hhvm 

convert php to c++

# Janino 

JAVA JIT, used by Spark

