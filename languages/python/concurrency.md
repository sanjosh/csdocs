
# Numba

numba (LLVM) https://youtu.be/-4tD8kNHdXs (scipy 2019)
numba best for numpy but not for python lists and dicts

# numexpr

# dask

# base

(Python Cookbook)

modules : threading, contextmanager(for deadlock avoidance), concurrent.futures

Since Only one thread in Python interpreter at a time, 
1. use threads for IO handler 
2. move comp. intensive code to C module : ctypes releases GIL before entering C code
3. Use PyPy JIT compiler
4. Use multiprocessing module to create process pool - ProcessPoolExecutor : runs comp intensive func in separate instance of Python interpreter

Either use Thread() class to start thread  - better bcos code can be run indep of thread
OR 
Derive from Thread class

ThreadPoolExecutor

Generators (green threads) as alternative to Threads

Actor model
