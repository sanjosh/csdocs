
Websocket connections start out as regular HTTPS connections, and then the client issues a protocol switch request to upgrade the connection to a websocket

Websocket service

different websocket services 
1. dedicated to messages, 
2. to presence (listing which contacts are online), 
3. to other services.

when there are changes in backend service endpoints
1. HAProxy has 2 ways : Runtime API or restart
2. Envoy allows dynamic configuration without dropping connections.  Copies stats from parent to child during hot restart.

Envoy
1. zone-aware routing
2. health check via outlier detection
3. panic routing

Envoy config using Chef
1. listener
2. cluster
3. route (listener to cluster)
4. filter

Testing with curl
1. Header and cookie-based routing
2. path, prefix and query param based routing
3. SSL cert

need testing framework for the load balancer configurations. 
1. validate that test URLs routed to the correct endpoint 
1. behaviors related to request and response headers 

Envoy admin interface

Envoy provides JSON formatted listener logs.

Use DNS weighted routing to shift from HAProxy to Envoy

https://slack.engineering/migrating-millions-of-concurrent-websockets-to-envoy/
