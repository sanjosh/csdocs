

# API key generation

AWS has access key and secret key


```
Mix two different strings together: one for identifying the user (like a username) and one as a password. 
The first part makes it easy to lookup the key in your database, while the second one makes sure the key is correct (it's the secret part).
Once you have generated those 2 pieces, you can store them in a database, 
using the first string as a identifier and the second one as a password. 
The latter should be encrypted as we'll see just after.

API key is never stored as-is
For token, the best method is to use a salted hash to store passwords.
```

as the token password is hashed, there is no way to retrieve it later

Prefix your token with a string for identifiability

Allow multiple API keys in case on expires

Support revocation 

Add a key expiration

Store the key encrypted; should be unable to retreive it later

scope and permissions associated with key

provide endpoint to get key metadata (name of key, owner, expiration date, permissions)

provide ability to name the key so its easier to manage

tokens are encrypted while transiting from the client to server

```
In Python, you can use secrets.hex_token to generate secret tokens. 
Use secrets.compare_digest to compare the generated API keys if they are stored in plain text 
and avoid timing attacks (they shouldn't be though, see below)
```

https://docs.python.org/3/library/secrets.html

## attacks

timing attacks

## examples of implementation

github, aws, heroku, pypi, stripe

https://github.com/koladev32/djangorestframework-simple-apikey

## AWS API Gateway allows API key

Choose Auto Generate to have API Gateway generate the key value

https://docs.aws.amazon.com/apigateway/latest/developerguide/api-gateway-api-key-source.html

## other measures

rate limiting

IP whitelisting

## references

https://blog.mergify.com/api-keys-best-practice/

https://cloud.google.com/endpoints/docs/openapi/when-why-api-key

https://stackoverflow.com/questions/14412132/whats-the-best-approach-for-generating-a-new-api-key

# other options JWT and OAuth
