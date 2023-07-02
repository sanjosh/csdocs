


# Knowledge graph embedding


## TransE

translation in embedding space

```
Consider a head entity h related to a tail entity t via a relation r in our knowledge graph. 
(We will refer to this as a positive (h,r,t) triplet.) 
Using a translation embedding scheme, we can simply add h and r to move to t. 
More formally, we want to learn embeddings of h, r, and t, such that h + r ≈ t.
```

### What types of relations can TransE represent?


Inverse relation :  triplet (h,r1,t) exists if-and-only-if the triplet (t,r2,h) also exists, where r1 is reverse of r2
Tom Holland stars in “Spider-Man: No Way Home”, then “Spider-Man: No Way Home” must feature Tom Holland.

Composition relation : relations r1, r2, r3 such that, if the triplets (x,r1,y) and (y,r2,z) exist, then the triplet (x,r3,z) also exists.
Spider-Man protects New York City 
Spider-Man fighting Green Goblin
Green Goblin attacks New York City

Anti-symmetric relation : the triplet (h,r1,t) exists if-and-only-if the triplet (t,r1,h) does not also exist.
“Willem Dafoe” has a nationality of “American”, but “American” does not have a nationality of “Willem Dafoe”.

TransE cannot effectively model all types of relations (the symmetric relation, N-to-1 Relations)

## RotatE

RotatE learns embeddings for positive triplets (h,r,t) such that h ○ r ≈ t, where ○ is the Hadamard (element-wise) product on the embeddings.

RotatE is able to represent all types of relations that TransE can!

Symmetric relation : Additionally, RotatE can model symmetric relations that TransE cannot express! It does so as 180 degree rotations

Cannot model N-to-1 Relations

## TransR

can represent 1-to-N relations


## DistMult

can represent 1-to-N relations


## Complex:

can represent 1-to-N relations
   
## methods for measuring performance of knowledge graph embeddings. 

Mean Reciprocal rank
Hits@K

## references
 
https://medium.com/stanford-cs224w/simple-schemes-for-knowledge-graph-embedding-dd07c61f3267

Wang, M., Qiu, L., & Wang, X. (2021). A Survey on Knowledge Graph Embeddings for Link Prediction. Symmetry, 13, 485.

Knowledge Graph Embeddings Lecture. Stanford CS224W.

https://colab.research.google.com/drive/1OKIqEhxpysFNdLz7qAbWdsD-OEY68HGc#scrollTo=AhKMflBVlrCV&line=5&uniqifier=1

https://arxiv.org/pdf/2211.03536.pdf
