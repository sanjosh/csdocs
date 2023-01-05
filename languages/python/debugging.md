
```
print module.__file__

import imp
imp.find_module('module name')

dir(module name)

print obj.__dict__

dir(obj)
vars(obj)

```


## code.interact

This function runs a read-eval-print loop, and creates an object instance of the InteractiveConsole class, which emulates the behavior of the interactive Python interpreter.



```
import code; 
import traceback as tb; 
tb.print_stack(); 
namespace = globals().copy(); 
namespace.update(locals()); 
code.interact(local=namespace)
```

https://twitter.com/karpathy/status/1610822271157022720

https://www.digitalocean.com/community/tutorials/how-to-debug-python-with-an-interactive-console
