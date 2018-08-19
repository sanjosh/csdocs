
# decompilation

## where is "this" ptr in func call seq ?

C++ calling convention called THISCALL.  The way that the this pointer is passed is compiler-dependent. Microsoft Visual C++ passes it in ECX. GCC passes it as if it were the first parameter of the function. (i.e. between the return address and the first formal parameter.)

## where is return value stored

## how is inlined func called

# References

http://stackoverflow.com/questions/20251097/what-does-this-intel-jmpq-instruction-do

http://stackoverflow.com/questions/1658294/whats-the-purpose-of-the-lea-instruction

http://en.wikibooks.org/wiki/X86_Assembly/High-Level_Languages

http://stackoverflow.com/questions/9317922/att-ia-32-movzbl-syntax

https://www.hackerschool.com/blog/7-understanding-c-by-learning-assembly
