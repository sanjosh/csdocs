
# ranking

three main approaches 
1. Pointwise : Logistic regression, PRank, and MCRank are examples of pointwise models.
2. Pairwise  :: 
3. Listwise : SoftRank, ListNet, AdaRank

# learning to rank

come up with optimal ordering 

```
The training data for a LTR model consists of a list of items and a “ground truth” score 
for each of those items. 

For search engine ranking, this translates to 
1. a list of results for a query and 
2. a relevance rating for each of those results with respect to the query. 

The most common way used by major search engines to generate these relevance ratings is 
to ask human raters to rate results for a set of queries

```

ranking is transformed into a pairwise classification or regression problem

## RankNet

cost function is to minimize number of inversions

## LambdaRank

scale gradients by the change in NDCG founds by swapping each pair of documents

## LambdaMART

LambaRank + MART

## reference

Christopher J.C. Burges.  From RankNet to LambdaRank to LambdaMART: An Overview 

https://medium.com/@nikhilbd/intuitive-explanation-of-learning-to-rank-and-ranknet-lambdarank-and-lambdamart-fe1e17fac418

https://elasticsearch-learning-to-rank.readthedocs.io/en/latest/

https://wellecks.wordpress.com/2015/01/15/learning-to-rank-overview/

Short intro to learning to rank : hang li
http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.222.6261

# libraries

https://sourceforge.net/p/lemur/wiki/RankLib/

# ranking quality

Mean Reciprocal Rank (MRR)

Mean Average Precision (MAP)

Expected Reciprocal Rank (ERR)

Normalized Discounted Cumulative Gain (NDCG).
