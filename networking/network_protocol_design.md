
# problems
1. multiple vendors
2. plug and play
3. long lived services cannot re-deploy
4. buggy implementations
5. need to cater to hardware implementations

# guidelines

1. postel principle
2. header design
3. consider packet size limits
4. forward compatibility : big fields, reserved fields, TLV, seq number
5. backward compatibility
6. keep same fields in same place
7. TLV encoding
8. sequence numbers
9. version number exchange 
10. keep vendor specific options
11. negotiate specific protocols to use
12. schema changes
13. whom to trust?
14. tunnels - wrapping headers in other headers
15. dos attacks - timeout 
16. nonces, IV
17. MUST, SHOULD, MAY

# Ref
1. Protocol design folklore - Radia Perlman - Interconnections book
2. https://tools.ietf.org/html/draft-iab-perlman-folklore-00
