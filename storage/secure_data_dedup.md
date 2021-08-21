
# Convergent encryption 

storer, Secure Data deduplication, StorageSS 08

two approaches to secure deduplication:
1. authenticated : metadata + data
2. anonymous: metadata stored on separate server

Convergent encryption : encryption key K = hash(chunk)

the map that associates chunks to a given file is encrypted using a unique key, limiting the effect of a key compromise to a single file

keys are stored so that users only need to maintain a single private key regardless of the number of files to which they have access

https://www.ssrc.ucsc.edu/pub/storer-storagess08.html

## earlier work Farsite 

Douceur Reclaiming space from duplicate files

https://ieeexplore.ieee.org/abstract/document/1022312


