
1. RTMP
2. h264 - video
3. aac - audio

generate streamId (for hashing), security token, URI

broadcaster →  POP Proxygen →  Encoding host

Encoding host : central 

authenticate, associate host to stream, generate encoding, generate DASH output, store media for VOD

create 1 second DASH segments

adaptive bitrate

thundering herd - cache blocking timeout

new feature: two people talking at same time 

everstore to store videos

## REF

1. https://dl.acm.org/citation.cfm?doid=3132747.3132775
2. https://www.youtube.com/watch?v=IO4teCbHvZw&pbjreload=10
3. https://www.infoq.com/podcasts/sachin-kulkarni-facebook-live/
