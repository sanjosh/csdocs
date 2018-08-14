
## Atom_Record_Sequence model
1. Atom = primitive type
2. record = struct of Atom
3. sequence = array of atom, record or sequences

## Two possible indices for schema-agnostic
1. forward index : Map : document_id -> path
2. [documentdb chose] inverted index : Map : path -> document_id (posting list)
 
## Requirement
 Index update
1. must meet SLA
2. must meet resource budget
3.  Not assume update pattern
4.  have Smallest read/write amplification
 
## SLA-aware system 

Key to guaranteed performance is lack of resource contention at all levels

What is needed to build SLA-aware system? [ explores thoughts not in paper ]
1. admission control
2. Log-structured storage on disk
3. latch-free in-memory
4. data structures with bounded worst case performance
5. for read-modify-write, bound the cost of looking if something exists in RAM + Disk
6. reduce the work hand-off between threads
7. keep as many threads as CPU cores + use of continuations (async futures)
8. work conserving : no blocked threads
9. cooperative : instead of back-off, threads must complete each other's outstanding work
10. CPU cache locality
11. resource reservation : preallocate at OS level
12. rate limiting
 
They chose BW-tree

[Shukla, DocumentDB]
