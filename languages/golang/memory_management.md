
# Golang allocaotor is derived from tcmalloc

## tcmalloc

* small obj from thread cache
* small obj(< 32k) are mapped to one of 170k allocatable size classes
* large obj rounded to 4k and allocated from central heap
* central heap also has buckets by page size
* central heap mem is managed in terms of spans

## golang malloc

* works in spans like tcmalloc (contiguous region of 8k)
* three types of spans : idle, in_use, stack
* obj alloc in three classes  : tiny (16 bytes), small(32kb), large(anything else)
* tiny is for strings and standalone escaping variables

## Memstats package

```
go func() {
  for {
    var m runtime.MemStats
    runtime.ReadMemStats(&m)
  
    log.Println(float64(m.Sys) / 1024 / 1024)
    log.Println(float64(m.HeapAlloc) / 1024 / 1024)
    time.Sleep(10 * time.Second)
}
```


# References
https://povilasv.me/go-memory-management/
