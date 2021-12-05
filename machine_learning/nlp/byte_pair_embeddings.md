
https://www.youtube.com/watch?v=-0IjF-7OB3s

which n-grams really matter

keep memory down

use valid subset of n-grams which correspond to sub-parts of words

e.g. in topologist or astrologist
1. take "ist" instead of "gist" 
1. take "astro" instead of "astr"

how ?

split word into space-separated character

astronomy to a s t r o n o m y

count frequency of each pair of characters

combine pairs with highest frequency

repeat above process

eventually you get frequent n-grams like "geo", "astro", "ist"

https://github.com/bheinzerling/bpemb

