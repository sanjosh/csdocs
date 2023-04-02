
# Chart parsing

mindmeld
https://www.mindmeld.com/docs/userguide/parser.html

nltk chart parser

https://github.com/AriBernstein/Bottom-Up-Chart-Parser

# Parsing expression grammar (Ford 2004)

1. uses infinite lookahead - ok, because memory is cheap 
1. backtracking
1. can do lookahead assertions
1. left recursion works, so grammar looks more natural

"Writing a PEG parser for fun and profit" - Guido van Rossum
https://www.youtube.com/watch?v=QppWTvh7_sI

https://www.python.org/dev/peps/pep-0617/

https://medium.com/@gvanrossum_83706/peg-parsing-series-de5d41b2ed60

## how peg works

generates code (recursive descent parser)

```
you may parse token and fail and then parse it again in another rule
this means you parse same token twice at same position, 
parser can remember that it failed earlier
this can be done using memoization cache
its called packrat parsing
can work in linear time
```

LL(1) : one token lookahead, leftmost derivation


difference between EBNF and PEG : 
1. PEG has prioritized rules
2. EBNF - both paths are equivalent





