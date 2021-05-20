
## immutable

prefer frozenset to set, tuple to list

## define repr and str

## define eq and neq

```
    def __eq__(self, other) -> bool:

    def __ne__(self, other) -> bool:
        return not self.__eq__(other)
```

## hash implementation

```
def __hash__(self):
    return hash(self.__repr__())
```

## use property for getter, setter

```
class A
    _value : int

    @property
    def value(self):
        return self._value

    @value.setter(self)
    def value(self, new_val: int):
        self._value = new_val

```

## docstrings for methods

## enums derived from enum.Enum

## assertions should print intelligible message

```
try:
    assert a != b, "Failed
except AssertionError as e:
    e.args += (put additional values in this tuple)
    raise
```

## enforce keyword arguments using asterisk

put asterisk before keyword arguments
```
def func(self, *, forcenamed):
```

https://stackoverflow.com/questions/2965271/forced-naming-of-parameters-in-python

## use ABC inheritance

```
from abc import ABC, abstractmethod

class my(ABC):

   @abstractmethod
   def abc(self):
      raise NotImplementedError 
      or pass
      or implement
```

## enforce object can be member of set by inheriting from hashable


```
from collections.abc import Hashable

class my(Hashable):

   def __hash__

``` 

Similarly for contains method

## use dataclass for POJO

import dataclass

## use generators (yield)

```
def gen(n : int):
   for i in n:
      yield i
```

## use underscore for private

## use typing hints

## logger

never use root logger; configure it to write to file since default is stderr

```
import logging
logging.basicConfig(
    filename="test.log",
    level=logging.DEBUG,
    format="%(asctime)s:%(levelname)s:%(message)s"
    )
```

always create logger
```
logger1 = logging.getLogger(__name__)
```

used timed rotating handler

```
import logging
import sys
from logging.handlers import TimedRotatingFileHandler
FORMATTER = logging.Formatter("%(asctime)s — %(name)s — %(levelname)s — %(message)s")
LOG_FILE = "my_app.log"

def get_console_handler():
   console_handler = logging.StreamHandler(sys.stdout)
   console_handler.setFormatter(FORMATTER)
   return console_handler
def get_file_handler():
   file_handler = TimedRotatingFileHandler(LOG_FILE, when='midnight')
   file_handler.setFormatter(FORMATTER)
   return file_handler
def get_logger(logger_name):
   logger = logging.getLogger(logger_name)
   logger.setLevel(logging.DEBUG) # better to have too much log than not enough
   logger.addHandler(get_console_handler())
   logger.addHandler(get_file_handler())
   # with this pattern, it's rarely necessary to propagate the error up to parent
   logger.propagate = False
   return logger

```

https://www.toptal.com/python/in-depth-python-logging

## exceptions & stacktrace

use logger.exception

```
except Exception as error:
    logger.exception(error)
```
or
```
logger.debug(traceback.format_exc())
```

https://stackoverflow.com/a/31444861/2357408

logger.debug(traceback.format_exc())

## linking objects : shallow copy vs deep copy

use `id(instance)` to verify shallow copies

## linting

1. pylint
1. mypy
1. flake

## Files use Pathlib

glob better

```
from pathlib import Path
Path.cwd().glob
Path.cwd().rglob
```

mkdir and rename better
```
from pathlib import Path
Path('a/b/c').mkdir(parents=True, exist_ok=True)
Path('a').rename('b')
path.exists
path.parent.mkdir
path.touch
path.is_file
Path.iterdir
```

path formation is better
```
BASE_DIR = Path(__file__).resolve().parent.parent
TEMPLATES_DIR = BASE_DIR.joinpath('templates')
```

https://treyhunner.com/2018/12/why-you-should-be-using-pathlib/

https://docs.python.org/3/library/pathlib.html

## profiler

## tests

## module org 

init.py

setup.py
