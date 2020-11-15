
# list

1. Simhash (Random projections)
2. MinHash
3. TLSH (digital forensics)
4. Nilsimsa (anti-spam)

# Simhash Random projections

* N points  
* d dimensions  
* k hyperplanes  
* L repetitions  

Repeat the following procedure L times
1. Generate random hyperplanes h1, ... hk
2. To generate hash code ?
     Set k_th bit of hashcode = 0  if p.h_k < 0 where h_k is a hyperplane
                              = 1  if p.h_k > 0

Average points in a bucket = N/2^k

# Ref

https://www.youtube.com/watch?v=NJaJrVF__B4
