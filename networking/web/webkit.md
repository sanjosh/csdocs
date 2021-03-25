
# Webkit rendering engine

## Components

1. Webkit  - thin os interaction layer
2. Webcore - Rendering, layout
3. Javascript (v8)

## Web Engine tasks
1. loading a frame (FrameLoader) or subresource (DocLoader)
2. parsing - make a DOM tree; XSS audit
3. script exec
4. layout (LineBox tree) 
5. style resolution (RenderStyle tree)
6. paint
7. html editing
8. js binding

## Data structures
1. DOM tree (element, attr nodes)
2. RenderObject Tree (hung off DOM tree; links to fonts, images)
3. RenderStyle Tree  (css style info)
4. RenderLayer tree (transparency, clipping, scrolling, backptr to RenderObject tree)
5. LineBox tree

## Painting

* Tree walk from root layer
* 12 phases
* incremental painting - background, floats, foreground, selection, outline

## HTML editing

* Hit testing - find the node where mouse is
* Selection control - find char in text
* Focus control
* execCommand
* undo/redo - build undo group trees
* html serialization
* copy/paste
* keyboard handling

## DOM binding

take DOM tree and generate various languages - JS, Objective-C, COM code, C++

Generate from W3C IDL and Cached

# References

Eric Seidel https://www.youtube.com/watch?v=RVnARGhhs9w
