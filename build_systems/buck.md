
# why buck is fast

DAG of build depedencies computed in parallel

Fine grained rules - break down user rules

Does not rebuild action graph if content of dependency changed (just executes it)

Hashes not timestamps: Buck knows when to rebuild a target by the hashes of its inputs. This means less developer time gets wasted with unnecessary rebuilds because you touched, but did not change, a file

Caches rules build artifacts.  RuleKey = hash (inputs)

Rulekey hash has Compiler flags, Macro definitions, Source file args, Build env, Buck version

Deterministic builds across mchines, toolchains

API changes does not cause library to be rebuilt

proper scripting lang - python

private headers for C++

share incremental compilation results across your team using Buck Server.

https://buckbuild.com/concept/what_makes_buck_so_fast.html

https://hackernoon.com/7-reasons-to-use-buck-build-5b44d7413585
