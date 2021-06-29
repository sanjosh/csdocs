
# Approaches
1. extractive (score Sentences and do extraction)
2. abstractive (Using Natural Language understanding)


# Features for summary generation
1. fixed phrases  (e.g. in summary)
2. uppercases
3. para is first/last/middle
3. do any frequent content words occur


# Coreference resolution
1. noun phrases
2. pronoun (they)
3. possessive (their)
4. demonstrative


# Statistical approaches 
1. TextRank  (like PageRank)
2. clusterRank
3. Topiary

# Neural machine translation

reframe problem as that of making input text more concise

## DiscoBERT

 creating 2 different graphs of the document. 

```
The first graph, the RST graph, is based on Rhetorical Structure Theory. 
This theory claims that the structure of text can be boiled down to a tree of independent units. 
In a similar fashion, the RST graph tries to analyze the dependency among these units and identify their roles in the sentence. 

The second graph, the Coreference graph, focuses on building an understanding of the key entities (people, organizations and more), 
events and themes that are being discussed throughout the text.
```

To generate the summary, DiscoBERT selects the top N ranked EDUs (with dependencies also being taken into account) and stitches them together chronologically.

https://arxiv.org/pdf/1910.14142.pdf

https://github.com/jiacheng-xu/DiscoBERT

https://multimodalai.azurewebsites.net/

https://towardsdatascience.com/discobert-a-bert-that-shortens-your-reading-time-be49d03e1ff

# Misc
k
https://www.quora.com/Natural-Language-Processing-What-are-algorithms-for-auto-summarize-text


