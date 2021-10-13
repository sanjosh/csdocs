http://effbot.org/zone/python-with-statement.htm

With ensures "entry" and "exit" functions are called on object

```
class controlled_execution:
    def __enter__(self):
        set things up
        return thing
    def __exit__(self, type, value, traceback):
        tear things down

with controlled_execution() as thing:
    some code

with open("filename") as f:
    d = f.readline()
```
