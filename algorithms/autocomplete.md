
# design autocomplete

(soln from some website)

## requirement
1. spelling mistakes
2. real time or batch
3. personalization (geographic location, language, personal hist)
4. how to choose top 5
5. data size (being added)
6. query volume per sec

## design goal
1. latency /response time
2. consistency
3. availability
4. maintain frequencies per search term

## client-side caching
1. decide shard for the prefix early on
2. cache trie for first 2-3 letters on client (26 letter * 5 resul * 10 bytes)
3. prefetch rest of the prefix tree and use deltas to update 
4. Use CDN

## server side
1. keep shard of 26 nodes for 26 char (assume english)
2. keep top 5 words at each node in trie
3. use sampling to update trie after 1 in 100 queries
4. offline update
5. some prefixes are hotter than others
6. as data grows, split the trie

## Data structures
1. Trie
2. Compressed trie
3. Suggest Tree
4. ternary search tree
5. Generalised suffix tree

