#/usr/bin/python
# gdb --batch --command gdbmemory.py <exe> <corefile>

import sys
import re
import traceback
import struct

verbose = False
#verbose = True

regexs = {
  "maintenance info sections": r"\s+0x([\da-fA-F]+)->0x([\da-fA-F]+) at .*",
  "info files": r"\s+0x([\da-fA-F]+) - 0x([\da-fA-F]+) is .*"
}

for cmd, regex in regexs.items():
    output = gdb.execute(cmd, False, True)
    lines = output.split('\n')
    addrRE = re.compile(regex)
    sum = 0
    for line in lines:
        m = addrRE.match(line)
        if m != None:
            start = int(m.group(1), 16)
            end = int(m.group(2), 16)
            if verbose: 
                print ("Start=" + str(start) + ",End=" + str(end))
            diff = end - start
            sum += diff

    print ("")
    print (cmd)
    print ("----------")
    print ("Sum memory ranges = " + str(sum))
