
Szegedi Attila
https://www.youtube.com/watch?v=J5auCY4ajK8

## Push & Pull needed for tweets
Targeted: Pull via twitter homepage : Push via user & site streams. Mobile Push via SMS
Queried : Pull via search API : Push via track/follow streams (get tweets based on profile or keywords)

## Events
1. Content creation
1. Social graph changes
1. Profile updates
1. Search

Social graph changes occur 10 times more often than tweets !

## Hosebird

Hosebird is a router. it maintains persistent connections with end clients.

Pushes events into Different queues for public tweets, private tweets, social events,

Write API pushes to one Hosebird which fans out to a Tree of Hosebirds. Leaf Hosebird nodes will push events to clients.

Timeline is a union of tweets from different followed users.

When celebrities tweet, you may have to update many Redis nodes. Don’t do this. Don’t fanout. Instead, do realtime merge of their tweets when rendering to their followers.


## Firehose

Firehose is the edge machine

## Incoming tweets

On tweet, lookup the social graph of followers and Push tweet into multiple Redis depending on number of followers. This is a high fanout operation.

Redis schema : TweetId, UserId, Some metadata (conversation)

Timeline service reads Redis for your UserId and renders the tweet feed.

For search indexing, the tweet must also be tokenized and inserted into Lucene. Blender is system built for search. It reads from multiple Lucene depending on user profile, region, interests.

## analytics

URL shortener needed so you know which links have been clicked.
