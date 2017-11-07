
# Computing overlap 

given `P1=[x1, x2] P2=[y1, y2]`

x1 -- y1 -- x2 -- y2

alternatives
1. (x1 <= y2) && (y1 <= x2)
2. max(x1, y1) <= min(x2, y2)
3. max(all num) - min(all num) < width of first box + width of second box

[Ref](https://stackoverflow.com/questions/3269434/whats-the-most-efficient-way-to-test-two-integer-ranges-for-overlap)

============

# Finding union of all intervals (scan line algo)

* sort all start and end points / or put in min heap
* when you see start, incr counter by +1, save lower bound
* when you see end, decr counter, save upper bound 
* if counter decr to zero, then return[lower, upper]

--------------

# Finding intersect of all intervals

* can use scan line algo
* twin heap algo better

```
L is a max heap
U is a min heap
put lower in L heap, upper in U heap

while U 
	l = L.pop() - max elem
	u = U.pop() - min elem
	if l <= u, add {l, u} to G
	remove lb(range corresp to u)  from L
	insert lb(r') and ub(r') to L and U 
```
