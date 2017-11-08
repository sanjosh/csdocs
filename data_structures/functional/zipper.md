
# Zipper Tree (huet)

cursor deep into a structure which allows O(1) updates
focus is on a node

> The basic idea is simple: the tree is turned inside-out like a returned 
> glove, pointers from the root to the current position being reversed in 
> a path structure. The current location holds both the downward current 
> subtree and the upward path. All navigation and modification primitives 
> operate on the location structure. Going up and down in the structure 
> is analogous to closing and opening a zipper in a piece of clothing, 
> whence the name
*Huet, Functional Pearls. J. Functional Programming 7 (5): 549–554, September 1997*

# Zipper list 

```
list = ((first n-1 elements reversed) nth element (remaining elements))
```

first half is reversed so you can quickly get previous element which is this case is head


# References
[stackoverflow](https://stackoverflow.com/questions/380438/what-is-the-zipper-data-structure-and-should-i-be-using-it)
[xmonad window manager](https://donsbot.wordpress.com/2007/05/17/roll-your-own-window-manager-tracking-focus-with-a-zipper/)
[Learn you a haskell](http://learnyouahaskell.com/zippers)

