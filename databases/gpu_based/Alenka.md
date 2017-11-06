

* takes sql string, parses it
* data_dict is catalog

--------
Alenka uses Nvidia's Thrust library
* no Cuda stream but uses pinned
* stable_sort_by_key for sorting, 
* copy_if for filtering and 
* copy_if and transform for grouping and, up until recently, 
* ModernGPU's RelationalJoin for joining records.

```
struct CudaSet
{
}
```

--------
# Files
* cm.cu
* compress.cu (pfor)
* filter.cu (gpu_regex)
* merge.cu (count_avg, count_simple, add, create_c)
* operators.cu (star_join)
* select.cu 
* sorts.cu
* strings*.cu
* zone_map

-------------

```
emit_bitmap
{
//create bitmap index
    copy column to gpu
}

emit_order
{
}
```

---------------

# Operations
* min, max, ave, sum, count
* ASC, DESC, sort
* op_type.push


