
# HyPer database

See Neumann paper on "Efficiently compiling query plans"

# Apache kudu 

see codegen directory

# Cloudera Impala 

See be directory

> Instead of using the IRBuilder to construct query-specific functions, we generally 
> prefer to compile a C++ function to IR using Clang, then inject query-specific 
> information into the function at runtime. This allows us to write functions in 
> C++ rather than constructing them instruction by instruction using the IRBuilder. 
> We also cross-compile the functions to both IR and native code, allowing us to 
> easily run either the interpreted or code-generated version. This is useful for 
> debugging: we can isolate whether a bug is due to code generation or the 
> function itself, and the native functions can be debugged using gdb.
