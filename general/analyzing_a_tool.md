
# Ask why.  
1. Why was this tool developed ?
2. What problems is this tool solving
3. history : What came before it - what was wrong about the earlier system ?

# Develop a mental model of the tool 
1. (e.g. similar to how does a car work when you press accelerator or brake or steering)
1. See if the tool has released the diagram of its internal working
2. Otherwise, build one and refine it
3. Ask questions while building diagram : does the tool keep some internal state ?
4. Can you summarize the tool in 1-3 sentences 


# What is good and bad about this tool
1. How many concepts do you need to have to remember to use it ?
2. Is the input file used by the tool readable ?  Can you add comments ?
3. Is the output message or error understandable ?
4. Extensible : Can you add custom syntax to the input ? Or plugins
5. Can you convert the input or output to a different format ?  
6. Can you export/import from other similar tools ?
7. Does it have a dry run facility ?
8. Does the behaviour change after you upgrade the version 
9. Is it easy to make mistakes in syntax (duplicate variables, typo, missing variable, hardcoding, multiple ways of doing same thing)
10. If you make a mistake, does it warn you
11. Does it have syntax checker (lint)
12. Security : does it expose passwords ?  can it accept secrets from other systems
13. learning : tutorials, key concepts, use-cases are described
14. modularity and refactoring : ability to split into multiple modules, import and export modules
15. performance : does it become slow to use in a large system ?  are frequent commands fast ?

# How does it compare with other tools solving same problem
1. immutable : create new and destroy old or does it update the same 
2. declarative : does it compute the difference on its own

# How does it play with tools in related ecosystems (work well or not)
1. pipelines : can you pass output to some other related tool 
