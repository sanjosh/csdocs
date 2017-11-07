# SQLite testing notes

## Three independently developed test harnesses 
1. Compare SQL output against SQLite and other db
2. tcl - api testing
3. C code

## Anomaly
* Out-of-memory tests
* I/O error tests
* Crash and power loss tests
* Compound failure

## Fuzz testing
* Fuzz tests - invalid, out of range inputs

## Malformed database files
* Boundary value tests - max limit of internal structures

## Regression
* add test for every bug detected

## Resource leaks
* memory, file descriptor, thread, mutex

## Dynamic runtime checking
* Extensive use of assert() and run-time checks
* Valgrind analysis (now google ASAN?)
* Pluggable memory allocator - check leak, buffer overrun, uninit mem, use-after-free.
* Pluggable mutex - macros to verify if mutex is held
* Journal file testing
* Undefined behavior checks

## Disabled optimization tests
* disable SQL optimizations at runtime

## Checklists

## Static analysis

[SQLite testing](https://www.sqlite.org/testing.html)
