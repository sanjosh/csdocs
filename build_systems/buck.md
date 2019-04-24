
# why buck fast

DAG of build depedencies computed in parallel

Fine grained rules - break down user rules

Does not rebuild action graph if content of dependency changed (just executes it)

Caches rules build artifacts.  RuleKey = hash (inputs)

Rulekey hash has Compiler flags, Macro definitions, Source file args, Build env, Buck version

Deterministic builds across mchines, toolchains

API changes does not cause library to be rebuilt

https://buckbuild.com/concept/what_makes_buck_so_fast.html



