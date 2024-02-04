

# id tokens and access tokens

ID tokens (to reuse identity which is stored in another app) 

Access tokens (allow app to perform action in another app)

Refresh tokens

http redirect

claims, scopes, intended audience

revocation, expiration

https://www.youtube.com/watch?v=vVM1Tpu9QB4

# jwt
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


# OIDC : access token; refresh token; value or ID token

same session can generate multiple tokens

access token is used to call API; it has scopes

refresh token is saved by application on behalf of user, to obtain a new access token and new refresh token

ID token contains user information

token introspection service 

```
For the access token, on the other hand, there is a set of techniques, collectively known as sender constraint, that allow you to bind an access token to a specific sender. This guarantees that even if an attacker steals an access token, they can’t use it to access your API since the token is bound to the client that originally requested it.

```


