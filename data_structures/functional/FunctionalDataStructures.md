
In functional programming, data structure is
1. ephemeral imples single version
2. persistent implies multi version 

Amortized data structure (as opposed to worst case data structure)

Two methods to analyze them [Tarjan]
1. Banker's method (credits)
2. Physicist's method (potential)

Converting lazy amortized data structure to Worst case data structure
1. scheduling : pointer to every unevaluated suspension in object

Building func data structures techniques
1. Global rebuilding (keep 2 copies; do incremental transformations)
2. Lazy rebuilding
3. Structural sharing
4. Bootstrapping

Purely functional data structures can be seen as extension of lockless data structures
1. have multiple versions
2. reduced memory 
3. thread safety
4. incrementality (lazy eval)
5. can use memoization with them
