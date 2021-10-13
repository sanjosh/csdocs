
Modules : os, io, mmap, glob, sys, tempfile

flags: t = text, b=binary, x= create if not exist

```
with open(filename, 'rt') as f:
    print(str, file=f)
```

change encoding : open(filename, encoding='ascii', newline='?', errors='replace')

change separator : print(str, sep=',')

change line ending : print(str, end='!!\n')

byte string vs text string:
```
b = b'Hello World'
b[0]
for c in b:
    print(c)
```

read text from binary file
```
    data = file.read(16)
    data.decode(utf-8)
```

create files out of text/string : io.StringIO() or io.BytesIO() : like ifstream

compressed files : gzip and bz2 modules

DirectIO : read binary data into mutable buffer : use readinto()

memory map binary files :  Import mmap

```
Memory view :
m = memory_map("file") 
v = memoryview(m).cast('I')
v[1] = 7
```

If more than one Python interpreter mmaps the same file, the resulting obj can be used to exchange data between interpreters

pathname manipulation : os.path module, pathlib

filename matching : use glob or fnmatch module

tempfile module

Serial port : import serial

Pickle : objects which store external system state (open files, net connec, stack frames) cant be pickled.  For them use __getstate__() and __setstate__()
