

# SIGv4

every request is finely scoped down and signed with a token that is 
valid only for a given AWS service, in a given AWS region, on a given day.

1. canonicalize the request and any headers we want to sign into a string. 
   That’s so the sender and the recipient can all agree about what is to 
   be signed in the first-place. 

2. add the signature algorithm, time, and credential scope. The signature algorithm 
   and time are included here to prevent downgrade and replay attacks, but 
   credential scope is where things get really interesting.  In SIGv4, the 
   clients don’t even use their secret keys to sign the requests, instead 
   they use credentials that are finely scoped down in important ways. 
   Each scoped credential is valid only for a request made using a 
   particular version of the signature protocol, to a particular AWS service, 
   in a particular AWS region, on a particular day.

3. calculate signature

4. add signature to request

https://docs.aws.amazon.com/general/latest/gr/sigv4_signing.html

# SIGv4A

new requirement : S3 has multi-region access points

requirement : never to have the same key material in two regions

SIGv4A uses public-private keys and asymmetric cryptographic signatures for every request.

 adds another step to derive a public-private ECDSA key pair from that scoped credential.


https://shufflesharding.com/posts/aws-sigv4-and-sigv4a

