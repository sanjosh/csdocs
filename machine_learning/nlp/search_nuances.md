

# Symmetric vs. Asymmetric Semantic Search

symmetric semantic search your query and the entries in your corpus are of about the same length and have the same amount of content

asymmetric semantic search, you usually have a short query (like a question or some keywords) and you want to find a longer paragraph answering the query.

https://www.sbert.net/examples/applications/semantic-search/README.html

# Short vs long passage retrieval :

Models tuned for cosine-similarity will prefer the retrieval of shorter passages, while models for dot-product will prefer the retrieval of longer passages.

https://www.sbert.net/docs/pretrained-models/msmarco-v3.html

## dot product vs cosine similarity

```
... if your particular downstream task requires occurance count as a feature then dot product might be the way to go
```

https://stackoverflow.com/a/54412911/2357408

From Schakel and Wilson

```
Measuring Word Significance using Distributed Representations of Words
A host of experiments have demonstrated the extent to which the direction of word vectors captures semantics. In this brief report, it was pointed out that not only the direction, but also the length of word vectors carries important information. Specifically, it was shown that word vector length furnishes, in combination with term frequency, a useful measure of word significance.
```

https://arxiv.org/pdf/1508.02297.pdf

# Difference between Cross-encoders vs Bi-encoders

1. Cross-Encoder : pair of sentences  -> similarity
1. Bi-encoder : sentence -> embedding

https://www.sbert.net/examples/applications/cross-encoder/README.html

the Ranking part of "Retrieve-and-rerank" uses Cross-encoder

The advantage of Cross-Encoders is the higher performance, as they perform attention across the query and the document.

https://www.sbert.net/examples/applications/retrieve_rerank/README.html

