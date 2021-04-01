
Daniel lemire : Parsing JSON Really Quickly: Lessons Learned
https://www.youtube.com/watch?v=wlvKAT7SZIQ

* lookup table to classify char
* avoid hard to predict branch 
* simd
* use perf counters instead of time() - due to variable CPU frequencies
* use wide words
* avoid malloc
