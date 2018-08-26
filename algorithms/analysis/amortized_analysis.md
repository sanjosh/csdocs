
* lower bound - indep of algo
* tight bound - average across inputs
* upper bound - worst case input
* Amortized : upper bound on worst case.

------------

# Amortized

Aggregate analysis:

## Accounting banker method :
* use history of operations
* every op has real cost and billed cost 
* amount charged is the amortized cost 
* must be impossible to go into debt

## Physicist method :
* calculate potential energy stored in data structure
* in hash tble, potential grows linearly with load factor

-------------
