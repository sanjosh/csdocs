
## Hardware

SSD

Not Off-the-shelf

Mesos

https://blog.twitter.com/engineering/en_us/topics/infrastructure/2016/the-infrastructure-behind-twitter-efficiency-and-optimization.html

## networking

Clos + BGP
https://tools.ietf.org/html/draft-ietf-rtgwg-bgp-routing-large-dc-09

blast radius

High fanout microservices demand a highly reliable network that can handle a variety of traffic. 
Our traffic ranges from long lived TCP connections to ad hoc mapreduce jobs to incredibly short microbursts. 
Our initial answer to these diverse traffic patterns was to deploy network devices that featured deep packet   
buffers but this came with its own set of problems: higher cost and higher hardware complexity. 
Later designs used more standard buffer sizes and cut-through switching features alongside a better-tuned TCP stack server-side to more gracefully handle microbursts.


we still see bursts of 3-4X of normal traffic when moving traffic between datacenters. 
This creates unique challenges for historical protocols that were never designed to deal with this such as the MPLSRSVP protocol where it assumes some form of a gradual ramp-up, not sudden bursts. 

Further, to solve the bin-packing issues that come with RSVP auto-bandwidth, we have implemented TE++, which, as traffic increases, creates additional LSPs and removes them when traffic drops off. 

Historically, when someone requested “www.twitter.com”, based on the location of their DNS server, 
we would pass them different regional IPs to map them to a specific cluster of servers. 
This methodology, “GeoDNS”, is partially inaccurate due to the fact that we cannot rely on users 
to map to the correct DNS servers, or on our ability to detect where DNS servers are physically 
located in the world. Additionally, the topology of the internet does not always match geography.

To solve this we have moved to a “BGP Anycast” model where we announce the same route from all 
locations and optimize our routing to take the best paths from customers to our POPs. 
By doing this we get the best possible performance within the constraints of the topology of 
the internet and don’t have to rely on unpredictable assumptions about DNS servers exist.

https://blog.twitter.com/engineering/en_us/topics/infrastructure/2017/the-infrastructure-behind-twitter-scale.html

## MySQL sharding - Graph

Our legacy Gizzard/MySQL based sharded cluster for storing our graphs. 

We use the Gizzard library to handle the partitioning layer. A forwarding layer maps ranges of source IDs to physical databases, and replication is handled by building a tree of such tables under the same forwarding address. Write operations are acknowledged after being journalled locally, so that disruptions in database availability or performance are decoupled from website response times.

## Social graph - Flock

FlockDB is a database that stores graph data, but it isn’t a database optimized for graph-traversal operations. Instead, it’s optimized for very large adjacency lists, fast reads and writes, and page-able set arithmetic queries.

Flock, our social graph, can manage peaks over tens of million QPS, averaging our MySQL servers to 30k - 45k QPS.

https://blog.twitter.com/engineering/en_us/a/2010/introducing-flockdb.html

## Error handling

Exceptions instead of response codes

1. Abstract class BadClientRequestException - Signifies the client sent a bad request to us and should not impact our success rate
2. Abstract class DependencyException - Signifies a system that we call is failing and should impact our success rate
3. Abstract class ValidDiscardingRequestException - Signifies the request was valid but is a shortcut to saying, “I am not going to complete this request”
4. All other exceptions - Signifies my server has a bug

Now, if you have an http server, you will have a few more such as:

5. NotFoundException
6. BadGatewayException
7. One exception per http response code (note that you generally subclass as sometimes you have many errors to one response code and want clarity in stats as to which one it was)

https://blog.twitter.com/engineering/en_us/topics/insights/2019/gotta-catch--em-all.html


## Manhattan distributed real time db

global & local secondary index

how to update index
1. sync
2. async
3. read my write consistency: Write the new index record (or multiple in parallel), only if it succeeds, write the primary record. 

## migration to Kafka

in Kafka there is only one process handling both storage and request serving

Kafka makes the case that replication itself will guarantee durability and will acknowledge a write request before the data is durably stored on disk.

https://blog.twitter.com/engineering/en_us/topics/insights/2018/twitters-kafka-adoption-story.html

## Dynamic Config management

https://blog.twitter.com/engineering/en_us/topics/infrastructure/2018/dynamic-configuration-at-twitter.html


## Zookeeper

One of the key design decisions made in ZooKeeper involves the concept of a session. 
A session encapsulates the states between a client and server. 
Sessions are the first bottleneck for scaling out ZooKeeper, because the cost of establishing and maintaining sessions is non-trivial. 
Each session establishment and removal is a write request and must go through the consensus pipeline.  
ZooKeeper does not scale well with write workload, and with hundreds of thousands of clients on each ZooKeeper host, the session establishment requests alone would keep the ensemble busy, preventing it from serving the usual read requests. We solved this with the local session feature introduced by engineers at Facebook, who faced similar issues. Currently on all Twitter’s ensembles, local sessions are used by default and will automatically be upgraded to global session when needed (e.g., client creates ephemeral nodes).

The next scaling bottleneck is serving read requests from hundreds of thousands of clients. In ZooKeeper, each client needs to maintain a TCP connection with the host that serves its requests. Sooner or later, the host will hit the TCP connection limit, given the growing number of clients. One part of solving this problem is the Observer, which allows for scaling out capacity for read requests without increasing the amount of consensus work. To further improve the stability of our ensembles, we often only allow Observers to serve direct client traffic, by removing the quorum members’ records from our DNS.

https://blog.twitter.com/engineering/en_us/topics/infrastructure/2018/zookeeper-at-twitter.html


## Frontend sec

1. samesite cookie
2. referrer 
3. CSP

## Javascript deploy

https://blog.twitter.com/engineering/en_us/topics/insights/2016/how-twitter-deploys-its-widgets-javascript.html


## Twitter Lite

Progressive web app

We write modern JavaScript (ES2015 and beyond) that is compiled with Babel and bundled with Webpack. API response data is first processed by Normalizr – which allows us to de-duplicate items and transform data into more efficient forms – before being sent to various Redux modules used for fetching, storing, and retrieving remote and local data. The UI is implemented with several hundred React components that do everything from render text to manage virtual lists, lazy load modules, and defer rendering. Twitter Lite supports 42 languages, and we use Globalize to deliver localized numbers, dates, and messages.

### speed

 We have been able to achieve speed and reliability through a series of incremental performance improvements known as the PRPL pattern and by using the new capabilities of modern browsers on Android (e.g., Google Chrome) which include Service Worker, IndexedDB, Web App Install Banners, and Web Push Notifications.

 https://developers.google.com/web/fundamentals/performance/prpl-pattern/

### offline

 we use a Service Worker to enable temporary offline browsing and near-instant loading on repeat visits, regardless of the network conditions. The Service Worker caches the HTML application shell and static assets, along with a few popular emoji. 


### Fast loading - 

the app streams the initial HTML response to the browser, sending instructions to preload critical resources while the server constructs the initial app state. Using webpack, the app’s scripts are broken up into granular pieces and loaded on demand. This means that the initial load only requires resources needed for the visible screen.

### Data usage

https://blog.twitter.com/engineering/en_us/topics/open-source/2017/how-we-built-twitter-lite.html

## Video quality metric

https://blog.twitter.com/engineering/en_us/topics/insights/2018/videoqualityonmobile.html


## Video processing lib (Vireo)


https://blog.twitter.com/engineering/en_us/topics/open-source/2017/introducing-vireo.html


## ML platform

Cortex platform

## Tweet ranking

With ranking, we add an extra twist. Right after gathering all Tweets, each is scored by a relevance model. The model’s score predicts how interesting and engaging a Tweet would be specifically to you. A set of highest-scoring Tweets is then shown at the top of your timeline, with the remainder shown directly below. Depending on the number of candidate Tweets we have available for you and the amount of time since your last visit, we may choose to also show you a dedicated “In case you missed it” module


In order to predict whether a particular Tweet would be engaging to you, our models consider characteristics (or features) of:

The Tweet itself: its recency, presence of media cards (image or video), total interactions (e.g. number of Retweets or likes)
The Tweet’s author: your past interactions with this author, the strength of your connection to them, the origin of your relationship
You: Tweets you found engaging in the past, how often and how heavily you use Twitter

https://blog.twitter.com/engineering/en_us/topics/insights/2016/moving-top-tweet-search-results-from-reverse-chronological-order-to-relevance-order.html

## Distributed log

https://blog.twitter.com/engineering/en_us/topics/infrastructure/2015/building-distributedlog-twitter-s-high-performance-replicated-log-servic.html

## Blobstore

Object store

## Caching

Redis

Nighthawk - sharded redis

twemcache

## SOA

As one of the most complicated services in Twitter, it makes more than 30 calls to different services with complex interdependencies for a typical search request, eventually reaching hundreds of machines in the data center darkness. 

uses Nodes lib + Finagle to make async calls to downstream services graph

Rather than passing them around as Future, Future<C> and Future<D>, we come up with a new concept of Node, a Future-like object which combines the computation logic and the data being produced, and abstracts away the “de-futuring” code that had to coexist with the computation logic before. Unlike Futures, Nodes can have dependencies declared in it, and you can construct a Node with all its dependencies

https://blog.twitter.com/engineering/en_us/topics/open-source/2016/simplify-service-dependencies-with-nodes.html

## Search Index Omnisearch  + Earlybird

Postings lists can be extremely long; compact storage of postings is important

K-way list intersection and union algorithms are the “inner loop” of the search query; they must be implemented efficiently

Earlybird has two custom postings list formats: an “active” postings list and an “optimized” postings list. The inverted index composed of active postings lists handles concurrent reads and writes using a single-writer, multi-reader lock-free data structure and algorithm. This allows us to achieve low-latency writes and high-throughput reads simultaneously — a key feature for a true real-time search engine. After the active list gets to some size (typically 8M documents), we optimize it into a read-only format to reduce size and query cost, allowing us to store and search more documents on a single machine.

https://blog.twitter.com/engineering/en_us/topics/infrastructure/2016/omnisearch-index-formats.html

https://blog.twitter.com/engineering/en_us/a/2016/introducing-omnisearch.html

## Search challenge

the Twitter search challenge is unique, for a few reasons:

Real-time Intent: A large proportion of our searches have a strong intent to find topical, real-time information. The state of the world moves rapidly and in some cases, results that are even a few minutes old can feel outdated and irrelevant. Query suggestions, i.e. typeahead, spelling and related searches, also need to be fresh and real-time.

Corpus Size: The corpus being searched on is huge, with hundreds of millions of new Tweets being created daily, in many languages.

Document Format: The documents have unique properties: 140 characters of unstructured text, but with rich entity types including hashtags, @ mentions, images, videos, and external links. Unlike web pages, Tweets don’t have hyperlinks between themselves, so link-based algorithms like PageRank cannot be used directly for ranking.

Multiple Result Types: The search results page is a blend of multiple types of results including Tweets, other accounts, images, videos, news articles, related searches and spelling suggestions. The different result types need to be ranked against each other in order to compose a page that best satisfies the searcher’s intent.

Personalization: Each searcher has their own social graph, interests, location and language preferences, so results need to be personalized in order to be relevant.

https://blog.twitter.com/engineering/en_us/topics/infrastructure/2016/search-relevance-infrastructure-at-twitter.html


## Snowflake - Unique id generation (K-sorted)

We needed something that could generate tens of thousands of ids per second in a highly available manner. This naturally led us to choose an uncoordinated approach.

These ids need to be roughly sortable, meaning that if tweets A and B are posted around the same time, they should have ids in close proximity to one another since this is how we and most Twitter clients sort tweets.[1]

Additionally, these numbers have to fit into 64 bits. We’ve been through the painful process of growing the number of bits used to store tweet ids before. It’s unsurprisingly hard to do when you have over 100,000 different codebases involved.

To generate the roughly-sorted 64 bit ids in an uncoordinated manner, we settled on a composition of: timestamp, worker number and sequence number.

Sequence numbers are per-thread and worker numbers are chosen at startup via zookeeper (though that’s overridable via a config file).

https://blog.twitter.com/engineering/en_us/a/2010/announcing-snowflake.html
