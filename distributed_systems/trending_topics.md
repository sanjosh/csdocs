
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
