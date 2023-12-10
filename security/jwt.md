
jwt = header + payload + signature

1. header = token + scheme used
2. payload = claims
3. signature = attestation

token may be signed but not encrypted so info in it is visible, although immutable

the user agent should send the JWT, typically in the Authorization header using the Bearer scheme

jwt can use public/private and not limited to shared secret

https://jwt.io/introduction

jwt is self-contained and portable, not requiring server storage

when not to use jwt
1. revoking can be challenging
2. use short expiration times

https://www.youtube.com/watch?v=P2CPd9ynFLg
