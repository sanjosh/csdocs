
# Svelte

It generates code (JavaScript) that updates the visual tree directly, without diffing.

Svelte is a compiler that parses .svelte files, analyzes them and then generates a JavaScript file. 
The JavaScript file contains the logic to mount the component, handle events, and patch the DOM when values change.

The compiler takes in .svelte files, parses them into an AST Abstract Syntax Tree, analyzes the tree, and generates Javascript and CSS.

parsing
1. JavaScript : turned into AST using the acorn package.
1. Visual tags : uses it's own tag parser, but you can use parse5 to do the same job:
1. Css : package css-tree is used to walk the CSS and inspect the expressions.


https://dev.to/joshnuss/svelte-compiler-under-the-hood-4j20

https://github.com/sveltejs/svelte/tree/master/src/compiler

https://lihautan.com/the-svelte-compiler-handbook/

The Svelte compilation process can be broken down into 4-steps

1. Parsing source code into Abstract Syntax Tree (AST)
1. Tracking references and dependencies
1. Creating code blocks and fragments
1. Generate code

https://astexplorer.net/

does this spark joy - kondo
