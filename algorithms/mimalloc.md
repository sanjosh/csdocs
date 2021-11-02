
https://www.microsoft.com/en-us/research/uploads/prod/2019/06/mimalloc-tr-v1.pdf

One increasing use-case for allocators is as back-end implementations of languages, such as Swift and Python,
that use reference counting to automatically deallocate objects. We present mimalloc, a memory allocator
that effectively balances these demands, shows significant performance advantages over existing allocators,
and is tailored to support languages that rely on the memory allocator as a backend for reference counting
