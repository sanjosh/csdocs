
# How the HotSpot and Graal JVMs Execute Java Code

James Gough
https://www.youtube.com/watch?v=CCMDzPYWsAk

javac : convert to bytecode

* interpreter observes the execution and captures profile
* it triggers compilation request for code which is used more than once
* C2 is main HotSpot compiler implemented in C++
* C++ has problems: unsafe, legacy, lack of tooling
* JVMCI = JVM compiler interface - replace compiler within JVM

## Graal

* convert bytecode to assembly
* mx command line tool

Graal compiles itself (its own code) since it is a JIT compiler !!



