
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
