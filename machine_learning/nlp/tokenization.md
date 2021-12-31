
# MaxMatch for wordpiece tokenization

```
WordPiece uses a greedy longest-match-first strategy to tokenize a single word — i.e., it iteratively picks the longest prefix of the remaining text that matches a word in the model’s vocabulary. This approach is known as maximum matching or MaxMatch, and has also been used for Chinese word segmentation since the 1980s. Yet despite its wide use in NLP for decades, it is still relatively computation intensive, with the commonly adopted MaxMatch approaches’ computation being quadratic with respect to the input word length (n). This is because two pointers are needed to scan over the input: one to mark a start position, and the other to search for the longest substring matching a vocabulary token at that position.
```

https://ai.googleblog.com/2021/12/a-fast-wordpiece-tokenization-system.html

# fast wordpiece tokenization (LinMaxMatch)

wordpiece = subword unit

We propose an alternative to the MaxMatch algorithm for WordPiece tokenization, called LinMaxMatch, which has a tokenization time that is strictly linear with respect to n

LinMaxMatch extends the Aho-Corasick Algorithm, and the idea can be applied to more string search and transducer challenges.


```
A fundamental tokenization approach is to break text into words. However, using this approach, words that are not included in the vocabulary are treated as “unknown”. Modern NLP models address this issue by tokenizing text into subword units, which often retain linguistic meaning (e.g., morphemes). So, even though a word may be unknown to the model, individual subword tokens may retain enough information for the model to infer the meaning to some extent. One such subword tokenization technique that is commonly used and can be applied to many other NLP models is called WordPiece. Given text, WordPiece first pre-tokenizes the text into words (by splitting on punctuation and whitespaces) and then tokenizes each word into subword units, called wordpieces.
```

https://ai.googleblog.com/2021/12/a-fast-wordpiece-tokenization-system.html

# shrinking

https://discuss.huggingface.co/t/tokenizer-shrinking-recipes/8564

```
from transformers import AutoTokenizer

tokenizer = AutoTokenizer.from_pretrained(mname)

training_corpus = [ vocab.keys() ] # Should be a generator of list of texts.

new_tokenizer = tokenizer.train_new_from_iterator(training_corpus, vocab_size=vocab_keep_items)
```

