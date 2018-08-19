
# Create:

## using diff

diff -Naur olddir newdir > patch.file

## using git

1. git show > patch.file

or

1. git diff commitid1 commitid2 > patch.file
2. git format-patch -n (to send as email)

http://stackoverflow.com/questions/5623727/how-to-create-patch-for-a-new-file

-----------

# Apply patch

``` 
patch -p0 < patch.file
patch -p1 < patch.file
patch -p2 < patch.file
patch -p3 < patch.file
cat patch.file | patch -p0
```

