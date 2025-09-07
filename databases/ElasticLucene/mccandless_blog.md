# summary

1. immutable is good : write-once, append only
2. cross-interaction between features (entitlements and search)
3. optimizing for disk
4. data integrity
5. optimizing for hardware

# amd opt

https://blog.mikemccandless.com/2021/01/apache-lucene-performance-on-128-core.html

```
All file access now uses Java's NIO.2 APIs, giving us better error handling (e.g., Files.delete returns a meaningful exception) along with atomic rename for safer commits, reducing the risk of hideous "your entire index is gone" bugs like this doozie.


```
https://blog.mikemccandless.com/2014/11/apache-lucene-500-is-coming.html

# promiximity query

https://blog.mikemccandless.com/2014/08/a-new-proximity-query-for-lucene-using.html

# end to end checksums

https://issues.apache.org/jira/browse/LUCENE-5842

#  entitlements

```
 Entitlements means restricting access for certain users to certain documents

properly doing spell correction in the presence of entitlements is dangerous.
If you build a global lexicon based on your index, that lexicon can easily "bleed"
entitlements when there are terms that only occur in documents from one entitlement class.
This might be acceptable for context-free spell correction, but if your spell correction
has context (can suggest whole phrases at a time) you could easily bleed a very dangerous phrase (eg, "Bob was fired") by accident.
```

https://blog.mikemccandless.com/2009/09/spell-correction.html

# pulsing codec

```
But there is an experimental codec, PulsingCodec, which implements the pulsing optimization
described in a paper by Doug Cutting and Jan Pedersen. The idea is to inline the docs/positions/payloads data
into the terms dictionary for low frequency terms, so that you save 1 disk seek when retrieving document(s) for that term.

```

https://blog.mikemccandless.com/2010/06/lucenes-pulsingcodec-on-primary-key.html

# segment index

```
The requirement to commit in order to replicate Lucene's recent index changes was such a nasty limitation that when the popular distributed search servers Elasticsearch and Solr added distributed indexing support, they chose not to use Lucene's replication module at all, and instead created their own document replication, where the primary and all replicas redundantly index and merge all incoming documents.

```

https://blog.mikemccandless.com/2017/09/lucenes-near-real-time-segment-index.html


# failure modes

https://blog.mikemccandless.com/2017/09/lucenes-near-real-time-segment-index.html

# concurrency

```
Long ago, Lucene could only use a single thread to write new segments to disk. The actual indexing of documents, which is the costly process of inverting incoming documents into in-memory segment data structures, could run with multiple threads, but back then, the process of writing those in-memory indices to Lucene segments was single threaded.


```
https://blog.mikemccandless.com/2017/07/lucene-gets-concurrent-deletes-and.html

# transducers

https://blog.mikemccandless.com/2011/01/finite-state-transducers-part-2.html

# durability

https://blog.mikemccandless.com/2014/04/testing-lucenes-index-durability-after.html
