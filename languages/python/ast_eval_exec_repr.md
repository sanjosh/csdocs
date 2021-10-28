
# DSL

https://stackoverflow.com/questions/31080796/tiny-dsl-implementation-in-python?rq=1

https://dbader.org/blog/writing-a-dsl-with-python

# exec

# ast

## parse unsafe input

```
import ast
dictionary = ast.literal_eval("{'a': 1, 'b': 2}")
print type(dictionary)
```


## convert string to list

```
>>> import ast
>>> s = '["hello", "world", 1, 2, 3]'
>>> s_list = ast.literal_eval(s)
>>> s
["hello", "world", 1, 2, 3]
```

## ast parse instead of literal_eval

https://stackoverflow.com/a/18178379

https://stackoverflow.com/a/68732605

# exec instead of eval

https://stackoverflow.com/questions/26064859/using-python-eval-to-evaluate-classes

# type function

https://docs.python.org/3/library/functions.html#type

# repr

```
>>> repr(5)
'5'

>>> #repr() with list
>>> repr([1,2])
'[1,2]'

>>> #repr() with tuple
>>> repr((3,4))
'(3,4)'

>>> #repr() with dictionary
>>> repr({'x':1,'y':2})
"{'x': 1, 'y': 2}"

>>> #repr() with strings
>>> repr('Python')
"'Python'"
```

http://www.trytoprogram.com/python-programming/python-built-in-functions/repr/
