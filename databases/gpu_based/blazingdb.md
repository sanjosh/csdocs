
* Analytics db, not transactional
* Compressed column store, but also have row store
* Compressed columns sent to GPU 
* Never cache on GPU
* use cascading compression

Dictionary
* Use dictionary encoding for strings - which is sorted 
* long string takes 1,2,4 or 8 bytes
* for short strings, compare hashes

Decompression for processing: 
> We can roundtrip decompress 8 byte integers RRleDeltaRle 4x on an AWS g2.2xlarge 
> faster when we use the GPU. This includes sending the data TO the GPU and bringing 
> it back. Our decompression segments on CPU were set up so that every thread was 
> processing a segment to be decompressed so we were using every avaiable thread at 
> about 100%.

Operations
* On GPU :  join, order by, date transform, arithmetic UDF, group by, predicates
* Not on GPU : Don’t do wild card string search

**A major problem with GPUs is you see single bit errors with surprisingly high frequency**

[Ref](https://news.ycombinator.com/item?id=12484568)

