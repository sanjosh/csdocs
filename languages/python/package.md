# dir module

```
import modulename
dir(modulename) tells u names defined by module - var, func, module
```

# builtin
```
for builtin
dir(__builtin__)
```

# init py
```
The __init__.py files are required to make Python treat the directories as containing packages; this is done to prevent directories with a common name, such as string, from unintentionally hiding valid modules that occur later on the module search path. In the simplest case, __init__.py can just be an empty file, but it can also execute initialization code for the package or set the __all__ variable, described later.

 if a package’s __init__.py code defines a list named __all__, it is taken to be the list of module names that should be imported when from package import * is encountered.


from sound.effects import *

in __init__.py , we have __all__ = ["echo", surround"]
```
