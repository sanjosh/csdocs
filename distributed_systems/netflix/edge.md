
# evolution of edge

https://www.youtube.com/watch?v=k01PHa5YDpQ

https://www.infoq.com/presentations/netflix-edge-gateway

NCCP stands for Netflix Content Control Protocol

API gateway becomes monolith

API gateway needs to split to handle discovery, search, playback

two ways to do it; we do both
1. client-side orchestration (discovery to one, playback to another - separate Domain)
2. API gateway side orchestration (route to different services)

two different cases : streaming + content engineering

## POP

TCP + TLS handshake can take 400 ms 

added POP 

client goes to POP where SSL terminated, then private highway (multiple protocol) to data center
