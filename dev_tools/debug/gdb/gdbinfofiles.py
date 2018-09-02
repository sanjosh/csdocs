#/usr/bin/python
# gdb --batch --command gdbinfofiles.py <exe> <core>

import sys
import re
import traceback
import struct

verbose = False
#verbose = True

output = gdb.execute("info files", False, True)
lines = output.split('\n')
addrRE = re.compile(r"\s+0x([\da-fA-F]+) - 0x([\da-fA-F]+) is .*")
sum = 0
adding = 0
for line in lines:
  if line.find("Local core dump file") != -1:
    adding = 1
  elif line.find("Local") != -1:
    adding = 0
  if adding == 1:
    m = addrRE.match(line)
    if m != None:
      start = int(m.group(1), 16)
      end = int(m.group(2), 16)
      if verbose: print ("Start=" + str(start) + ",End=" + str(end))
      diff = end - start
      sum += diff

print ("Sum memory ranges = " + str(sum))
