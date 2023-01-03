


# comment ranking : wilson score interval

https://medium.com/hacking-and-gonzo/how-reddit-ranking-algorithms-work-ef111e33d0d9

https://www.evanmiller.org/how-not-to-sort-by-average-rating.html

We need to balance the proportion of positive ratings with the uncertainty of a small number of observations

confidence sort

submission time is irrelevant

Comments are ranked by confidence and by data sampling — — i.e. the more votes a comment gets the more accurate its score will become.

```
If a comment has one upvote and zero downvotes, it has a 100% upvote rate, but since there’s not very much data, the system will keep it near the bottom. But if it has 10 upvotes and only 1 downvote, the system might have enough confidence to place it above something with 40 upvotes and 20 downvotes — figuring that by the time it’s also gotten 40 upvotes, it’s almost certain it will have fewer than 20 downvotes. And the best part is that if it’s wrong (which it is 15% of the time), it will quickly get more data, since the comment with less data is near the top.
```
