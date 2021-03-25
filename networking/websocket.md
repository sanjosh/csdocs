
# http


## switching protocols

https://developer.mozilla.org/en-US/docs/Web/HTTP/Status/101

# websocket (layer 7 like http)

To change from HTTP to Websocket, use HTTP upgrade header

same ports

full duplex

WebSocket requests are not restricted by the Same-origin policy.

proxy support

## implementation

Nodejs https://socket.io/

Apollo GraphQL

Gorilla Golang https://github.com/gorilla/websocket


# Server sent events (EventSource in Javascript)

 allows the server to push updates to the client by leveraging the JavaScript EventSource interface. 

 EventSource opens a persistent, one-directional connection with the server over HTTP using a 
 special text/event-stream header and listens for messages, which are treated like JavaScript events by your code.

 https://stackoverflow.blog/2019/12/18/websockets-for-fun-and-profit/

# Long polling

server sends response to previous request when new request received


