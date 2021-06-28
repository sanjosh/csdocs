
```
class Date(metaclass=MultipleMeta):
```

https://stackoverflow.com/a/49936625/2357408

```
__prepare__ method in MultipleMeta returns a MultiDict instance to replace Date class default__dict__ attribute passed 
by clsdict in __new__ method. therefore, it can hold multi function with the same name '__init__', and the value 
of that is a MultiMethod instance, which stores with different function annotation in it’s _method attribute
```


https://github.com/dabeaz/python-cookbook/blob/master/src/9/multiple_dispatch_with_function_annotations/example1.py
