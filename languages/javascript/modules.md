
# CommonJS

require

modules automatically get their own local scope.

# ES modules (2015 ECMAScript)

When you import from another module, you import the binding, not the value, 
which means an exporting module may change the value of the binding at any time, 
and the modules that import it will see its new value.

export default


# Packaging

multiple stages of transformation:
1. converted from modern JavaScript to historic JavaScript
2. from ES module format to CommonJS, 
3. bundled : combine files because fetching a single big file is faster than fetching a lot of tiny ones
4. minified : reduce file size

