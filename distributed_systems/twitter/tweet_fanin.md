
How We Learned to Stop Worrying and Love Fan-In at Twitter

https://www.youtube.com/watch?v=WEgCjwyXvwc

Fanout service -> Timelines caches <- Timeline service <- Read API 

1. User service
1. graph service
1. Ads service
1. Tweet service

Scatter/Gather
    
Timeline aggregation service (per user feed)

1. search index
1. recommendation service
1. trends service
1. ranking service

API gateway -> Timeline mixer -> Content services, Timeline service -> Timelines cache

1. pop + edge LB (l4 + l7)
1. web server is at next 
1. Aggregation services is next (with cache)
2. Content (search, relevance)
2. Core (tweets, user, graph)

backpressure to clients (e.g. max number of get requests in read cache is defined)

sandbox any failing services

ranked timeline feature 
1. first step is search + get additional features
2. reverse chronology sort
3. call prediction service (predict engagement)
4. db for session stat storage + feature storage


