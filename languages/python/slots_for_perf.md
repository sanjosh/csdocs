
## use slots to make attr static if attributes are known apriori

```
class Person:
   __slots__ = "name", "address", "email"

   def __init__():
       self.name = 
       self.address = 
       self.email = 
```


## use dataclass with slots

```
@dataclass(slots=True)
```

## limitations

no mixin and multiple inheritance

to use dynamic attribute with slots, add `__dict__`

```
 __slots__ = "name", "address", "email", "__dict__"
```


