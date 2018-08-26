
# F1 distributed relational db

* Built on top of Spanner
* Tables organized in hierarchy.  Child tables stored clustered and interleaved with parent table.
* each root row and its descendants (child rows) stored in single Spanner directory.
* Spanner supports local and global secondary indices.

All schema changes are non-blocking.  At most two different schemas can be active.  Grant leases on schema.  Subdivide each schema change into consecutive phases which are mutually compatible.

F1 has 3 types of transactions
1. Snapshot (readonly)
2. Pessimistic (aka Spanner trans)
3. Optimistic (read phase followed by write phase)

