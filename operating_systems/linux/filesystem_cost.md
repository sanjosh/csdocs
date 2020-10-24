
XFS

* open/close = 1 microsec
* rename = 30-60 microsec
* zero out 4 MB file = 7 millisec
* create + fallocate = 200 microsec
* unlink = 30 - 60 microsec

after enabling "dirsync"
* rename = 200-400 microsec
* unlink = 150-200 microsec
