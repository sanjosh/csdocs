
# Generalized Search Tree 
(Hellerstein, Naughton, Pfeffer)

This is used in Postgres (GIST index)

* B+tree supports (less, leq, gt, ge)
* Rtree supports (left, right, overleft, overlap, overright, right, contains, contained, equal)

Create a generalized Tree which combines both of the above by
* Exposing node splitting algo 
* Exposing methods on the key class

Tree Methods that are exposed to user are
1. consistent(Entry E, query predicate q)
2. union(E)
3. compress(E)
4. decompress(E)
5. Penalty (E1, E2)
6. PickSplit(P) : given set P of M+1 entries (p, ptr) will split P into P1, P2

If domain has linear order, 
1. set "isOrdered" to true in Tree 
2. provide Compare(E, E) 
3. PickSplit ensures that split respects order
4. No two keys on a node overlap - Consistent(E1, E2, p) = false

If domain has linear order then search can be carried out using FindMin and Next
else search carried by general search analogous to R-tree

How does Tree balancing work
* if linear order, use Btree style - borrow and coalesce
* else use Rtree style reinsert

---

See Postgres code
* src/include/access/gist.h
* src/backend/access/gist.c

[github](https://github.com/postgres/postgres/tree/master/src/backend/access/gist)





