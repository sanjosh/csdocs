
https://dev.to/ricardo93borges/some-practices-to-design-restful-apis-interfaces-5a5i

# bad API design libvirt

TOCTOU problems : one api returns identifiers, pass it to second.  in between identifiers may change

http://www.linux-kvm.org/images/9/9b/03x03-Michal_Privoznik-libvirt-what_did_we_do_wrong.pdf

inconsistent error conditions

not extensible (no flags)

# why `_at` apis introduced in unix

the `_at` API take "fd" are argument

this prevents TOCTOU errors

# Netflix gRPC

```
How can we understand which fields the caller doesn’t need to be supplied in the response, 
so we can avoid making unnecessary computations and remove calls? With GraphQL this comes 
out of the box through the use of field selectors. 

In the JSON:API standard a similar technique is known as Sparse Fieldsets. 

How can we achieve a similar functionality when designing our gRPC APIs? 
The solution we use within the Netflix Studio Engineering is protobuf FieldMask.

You might notice that paths in the FieldMask are specified using field names, 
whereas on the wire, encoded protocol buffers messages contain only field numbers, not field names. 
This (alongside some other techniques like ZigZag encoding for signed types) makes protobuf messages space-efficient.

```
https://netflixtechblog.com/practical-api-design-at-netflix-part-1-using-protobuf-fieldmask-35cfdc606518

https://netflixtechblog.com/practical-api-design-at-netflix-part-2-protobuf-fieldmask-for-mutation-operations-2e75e1d230e4

# best practices

1. consistent naming (abbreviations, verbs, nouns)
2. fluent API
2. consistent error handling

# Adidas

https://adidas.gitbook.io/api-guidelines
