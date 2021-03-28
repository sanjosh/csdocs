
# Real time and personalized notifications

## triggered notifications

celebrity tweet causes notification fanout.  number of notifications have power law distribution : bimodal  (typical vs heavy users)

different types of notifications : likes, mentions, follows, retweets, login

issues
1. latency (redis custom, manhattan data store)
1. notification spikes/fanout
1. heterogenous calls (different priority queues for different notifications)
1. multi-dc (replication, compare notifications across DC using immutable ops)

pull flow
1. write path : apply rules, datastore -> cache
1. read path : cache

push flow
1. device fanout
2. send to device - which triggers read path above

read vs write balance
* aggregation is done at read time
* write only ids, let latest text be fetched during read

personalization
1. track recent engagements
1. asymmetry 

## personalized notification 

new cluster

solved by collocation (followings are collocated - so no network lookups)

send each tweet to all personalized notification shards

recent engagements are stored in RAM (couple of days)

how to rebuild shard : consume from firehose queue to build collocation graph

data preprocessing - entity extractor 

find top N followings per user : calculate offline because it wont change often

## recommendations

find content or people

history store : track of engagement of notifications : use it to calculate if you need to calculate recommendations for a user.  save computation

https://www.youtube.com/watch?v=pme_n2zQiDQ
