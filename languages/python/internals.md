
# CPython source 

https://realpython.com/cpython-source-code-guide/

# PEG

python switched to using PEG

https://devguide.python.org/internals/parser/

python.gram

https://github.com/python/cpython/blob/main/Grammar/python.gram

# Better error messages

add extra non-terminals "START OF INVALID RULES" in peg file

```
#. Rule names starting with "invalid_" are used for specialized syntax errors
#     - These rules are NOT used in the first pass of the parser.
#     - Only if the first pass fails to parse, a second pass including the invalid
#       rules will be executed.
#     - If the parser fails in the second phase with a generic syntax error, the
#       location of the generic failure of the first pass will be used (this avoids
#       reporting incorrect locations due to the invalid rules).
#     - The order of the alternatives involving invalid rules matter
#       (like any rule in PEG).
```

https://github.com/python/cpython/blob/main/Grammar/python.gram

traceback.py

https://github.com/pablogsal/cpython/blob/main/Lib/traceback.py


## Earlier way of doing it by using external module


Use sys.excepthook(type, value, traceback)

see  `get_suggestions_for_exception(value, traceback)`
https://github.com/SylvainDe/DidYouMean-Python

https://github.com/friendly-traceback/friendly-traceback

https://github.com/Qix-/better-exceptions

