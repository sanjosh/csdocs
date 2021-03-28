
Schema-Agnostic Indexing with Azure DocumentDB

http://www.vldb.org/pvldb/vol8/p1668-shukla.pdf

documents as trees

path is indexed

1. forward index mapping : docId -> path
2. inverted index mapping : path -> docId

chose inverted index

inverted index is also a valid json doc !

interior nodes = schema, leaf node = value

index = union of trees

stored as partial forward path 

Bw-tree
