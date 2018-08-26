
# Complexity computation

Time complexity measures the time that an algorithm takes as function of the length in bits of its input. 

psuedo-polynomial : poly in numeric value of input but exponential in number of bits required to represent it.  one which depends on numeric value of input (e.g. max elem in array) rather than number of inputs

## Steps

* Given Recurrence: a(n) = a(n-1) + ...
* Find Generating func: A(z) = Sum i=0,k a(k)
* Find Functional eqn for Generating func:  A(z) = 1 + z.A(z)^2
* Get Asymptotic estimates of coefficients

## recurrence to use
* Recursive algo : use T(n,m)
* Divide and conquer : T(n) = aT(n/b) + f(n)

## some results
* Inverse ackermann func comes into play in union-find 
* V.LogV in priority queue
* In graphs, |E| can be assumed to be < |V^2| implies log(E) = O(log(V))

Potential method for computing complexity
http://en.wikipedia.org/wiki/Potential_method

## Bounds

* Big-O(n) = worst case = signifies upper bound within const factor 
* small-o(n) = not asymptotically tight upper bound
* Theta(n) = denotes tight bounds - sandwich between tight bounds - within const factor - use largest term
* Big-Omega(n) = best case = lower bound (across all algos)
* small-omega(n) = not asymptotically tight lower bound

## Constant factor

O(n) can exceed O(n^2) if constant factor is large

http://stackoverflow.com/questions/9540686/run-time-complexities-for-recursive-algorithms?rq=1
* insertion sort is faster for smaller numbers (its perf = O(numb of inversions))
* quicksort has higher worst case perf than heapsort

## Parametrized complexity

defines complexity wrt multiple params of the input for finer scale

http://en.wikipedia.org/wiki/Fixed-parameter_tractable#FPT

## Karp's 21 NP-Complete problems

http://en.wikipedia.org/wiki/Karp%27s_21_NP-complete_problems


## References
1. bigocheatsheet.com
2. http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/assignments/
3.  sedgewick
4. horowitz sahni
5. knuth graham patashnik
6. http://en.wikipedia.org/wiki/Big_O_notation#Orders_of_common_functions
7. http://stackoverflow.com/questions/4438150/computational-complexity-of-a-longest-path-algorithm-witn-a-recursive-method
8. http://stackoverflow.com/questions/487258/plain-english-explanation-of-big-o
9. http://stackoverflow.com/questions/3255/big-o-how-do-you-calculate-approximate-it
10. http://stackoverflow.com/questions/22594174/can-an-on-algorithm-ever-exceed-on2-in-terms-of-computation-time?rq=1


