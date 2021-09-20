
https://dev.to/ricardo93borges/some-practices-to-design-restful-apis-interfaces-5a5i

# bad API design libvirt

TOCTOU problems : one api returns identifiers, pass it to second.  in between identifiers may change

http://www.linux-kvm.org/images/9/9b/03x03-Michal_Privoznik-libvirt-what_did_we_do_wrong.pdf

inconsistent error conditions

not extensible (no flags)

# why `_at` apis introduced in unix

the `_at` API take "fd" are argument

this prevents TOCTOU errors

# best

1. consistent naming (abbreviations, verbs, nouns)
2. fluent API
2. consistent error handling
