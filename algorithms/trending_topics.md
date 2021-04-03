
# Operations

1. Find top-k in last N
2. Time granularity of N : counts can be smooth or hard (i.e. every 5 min)

# need

1. TTL
2. sort by count 
3. uniqueness

# Ideas

IDF = all doc/docs in which term occurs (low implies more doc have it)

1. low to medium IDF : words which occur in 50-100 percent of documents 
2. low TF : words which rarely occur within a document 

## smooth rollover (moving top-K)

## ignore common words

use dictionary to filter

## detect uncommon phrases (pattern of 2-3 words)

hash those n-grams, vectorize them and count them too

```
for each word
   count(hash(cur-2 + cur-1 + cur)) ++
   count(hash(cur-1 + cur)) ++
   count(hash(cur)) ++
```

# schemes

## start afresh at start of interval (restrict by fixed windows)

1. keep all observed keywords in Map  (space expensive)
1. drop counters at end of window (abrupt rollover)

## use TTL 

1. keep all observed keywords in Map  
1. auto-drop counters at TTL expiry (worst case, can consume space if uniform distribution)

## elasticsearch rare terms aggregation (restriction by knowledge of max count)

CuckooFilter is being used to see if a term is over threshold

Rare Terms aggregation uses a different approximate algorithm:

```
if CuckooFilterForFrequentItems.find(term) == false:
  rareTermsMap[term].count ++
  if rareTermsMap[term].count > max_doc_count:
    CuckooFilterForFrequentItems.insert(term)
    rareTermsMap.delete(term)
```

1. Values are placed in a map the first time they are seen.
1. Each addition occurrence of the term increments a counter in the map
1. If the counter > the max_doc_count threshold, the term is removed from the map and placed in a CuckooFilter
1. The CuckooFilter is consulted on each term. If the value is inside the filter, it is known to be above the threshold already and skipped.

https://www.elastic.co/guide/en/elasticsearch/reference/master/search-aggregations-bucket-rare-terms-aggregation.html

## count-min sketch

1. only works for fixed quantum of time
1. saves space by using overlap in the counters

## hokusai

## WordMap(word -> count) + Queue + CountMap(count -> list of words)

```
on_new_word(word)

  if word in map
    increment WordMap
    Move word to next bucket in CountMap
  else
    insert into WordMap
    append into CountMap[1]
  queue.append(word) 

  if queue len exceeded
    expired_word = queue.pop
    delete word from current bucket in CountMap 
    if count = 1
      delete from WordMap
    else
      decrement count in WordMap      
      insert into previous bucket in CountMap
```

https://stackoverflow.com/questions/21692624/design-a-system-to-keep-top-k-frequent-words-real-time

## suffix trie

with counter and ttl ?

# Approaches

1. map reduce
2. count min sketch in parallel (biased estimator, topkapi, hokusai)

# misc

Distributed Top-K Monitoring
Brian Babcock and Chris Olston
http://infolab.stanford.edu/~olston/publications/topk.html

storm-starter

https://www.michael-noll.com/blog/2013/01/18/implementing-real-time-trending-topics-in-storm/

https://snikolov.wordpress.com/2012/11/14/early-detection-of-twitter-trends/

https://blog.twitter.com/engineering/en_us/a/2015/building-a-new-trends-experience.html

https://blog.twitter.com/engineering/en_us/a/2013/streaming-mapreduce-with-summingbird.html

1. We need to keep the counts for 5min, 1 hour and 24 hours in a rolling window fashion.
2. There are multiple machines, each machine should keep track of the counts of topics. At every delta interval, each machine updates counts with central server and resets it counts to zero.
3. The central server merges the counts from all machines to have final list of topics and counts. At every delta interval, the central takes a snap shot of the top N topics and counts in an array and resets its counter. N is a tunable parameter. Higher N means more memory and accurate metrics, lower N means lower memory but less accurate metrics.
4. There are three counters that keep track of topic counts for last 5 mins, 1 hr and 24 hrs. As the central server takes a snap shot, it adds the counts with each of these counters and remove the counts from the 5mins/delta, 1h2/delta and 24hrs/delta array value from the coressponding counter thus maintaining the rolling counts for topics.
5. at any point of time, the sytems pull the topics and values from these counters to show the top tending topics for this duration

https://www.careercup.com/question?id=5649012457734144

https://medium.com/@narengowda/system-design-for-twitter-e737284afc95
