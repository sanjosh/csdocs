
# client side vs server side

## client-side authentication using JSON Web Tokens (JWT).

stateless 

client-side authentication using JWT involves issuing a signed token to the client upon successful login, which is then stored on the client-side and sent back to the server with each subsequent request.

If the token doesn’t expire, it can be used indefinitely. However, if the token expires too frequently, it can inconvenience the users, who would have to log in frequently. Balancing the token expiration time is a critical aspect to consider.

The token is self-contained and doesn’t require accessing the server for validation, so JWT can be used across different domains.

JWTs are a great choice to implement single-sign on (SSO), where a user logs into a single application and is then able to access other applications without having to log in again. The JWT can securely transmit the user’s identity and authentication state between applications.



## server-side authentication using tokens (session based auth)

stateful

Server-side authentication with tokens involves creating a unique session token for each user when they log in. The token is stored on the server-side and used to authenticate subsequent requests from the same user.

Since all the session data is stored on the server, there is no offline access available, which can be a disadvantage in some scenarios.

With server-side authentication, you don’t need to re-authenticate the user on every request, which can improve your application’s performance.

Server-side authentication is easy to invalidate because we have complete control over the session data stored on the server. 

If your application requires real-time updates or notifications, server-side authentication can be more efficient because the server can push updates to the client based on the session ID.


## reference

https://blog.logrocket.com/node-js-server-side-authentication-tokens-vs-jwt/
