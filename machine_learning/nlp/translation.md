
# Vauquois triangle

various approaches

* semantic transfer
* syntactic transfer
* direct

# Statistical machine translation (SMT)

* older approach
* syntax based

# Neural machine translation (NMT)

seq2seq encoder-decoder model
* encode source sentence into a vector
* decode vector into a target sentence

big wins for NMT [Manning stanford lecture notes]
1. end-to-end training. all parameters are simultaneously optimized
2. distributed rep share strength - word and phrase similarity
3. better exploitation of context
4. higher quality

no black box models for reordering, transliteration


## Attention model

* address issue of long sentences by paying attention to only part of sentence
* LSTM for long term and WSD (word sense disambiguation)
* Attention for short term memory
* context vector is created from intermediate input of RNN/decoder
* attention weights
* soft attention is deterministic; hard is stochastic

in [Bahdanau, Neural machine translation by jointly align translate] it is shown that for translation, attention learns an alignment function, which certainly should help translating from English to French.


## Memory


# Phrase based

See Lample, Phrase-Based & Neural Unsupervised Machine Translation
https://arxiv.org/pdf/1804.07755.pdf

https://github.com/facebookresearch/UnsupervisedMT


# Aligning word vectors across languages

auto-build dictionaries and phrase translation tables

```
we formed short phrases of words using a technique described in (Mikolov et al., 2013b).  The idea is that words that co-occur more frequently than expected by their unigram probability are likely an atomic unit. This allows us to represent short phrases such as “ice cream” with single tokens, without blowing up the vocabulary size as it would happen if we would consider all bigrams as phrases.[1]
```

* Mikolov : learn linear mapping
* Xing: l2–normalize the word vectors and to constrain the linear mapping to be orthogonal  [2]
* this suffers from hubness problem
* fix that by applying corrective metric at inference time - such as inverted softmax (ISF) or cross domain similarity local scaling (CSLS).
* Joulin : learn non-orthogonal mapping [3]
* Conneau : build a bilingual dictionary between two languages without using any parallel corpora, by aligning monolingual word embedding spaces in an unsupervised way... adversarial method used [4]


## References

1. Mikolov et al.  Exploiting similarities among languages
2. Xing et al. Normalized Word Embedding and Orthogonal Transform for Bilingual Word Translation
3. Joulin et al. Loss in translation: Learning bilingual word mapping with a retreival criterion
4. Conneuau et al.  Word translation without parallel data
5. Lample et al. Ranzato Unsupervised Machine Translation With Monolingual Data Only
6. Ammar et al.  Massively multilingual word embeddings

## Code 

1. https://fasttext.cc/docs/en/aligned-vectors.html
2. https://github.com/facebookresearch/MUSE

# TODO

transformer https://ai.googleblog.com/2018/08/moving-beyond-translation-with.html

https://nlp.stanford.edu/read/

sockeye https://sockeye.readthedocs.io/en/latest/README.html

https://github.com/jonsafari/nmt-list

## Convolutional Seq2Seq

[Gehring 2017]

## Google NMT

https://ai.googleblog.com/2016/09/a-neural-network-for-machine.html

## Google Multilingual NMT

1. zero-shot translation
2. shared encoder and decoder
3. insert artificial token to indicate target language


# References

1. Knight "A statistical MT tutorial workbook" (easy to understand, use instead of the original Brown paper)
2. Och "The Alignment-Template Approach to Statistical Machine Translation" (foundations of phrase based systems)
3. Wu "Inversion Transduction Grammars and the Bilingual Parsing of Parallel Corpora" (arguably the first realistic method for biparsing, which is used in many systems)
4. Chiang "Hierarchical Phrase-Based Translation" (significantly improves accuracy by allowing for gappy phrases)
5. Bahnadau.  Neural machine translation by Jointly learning to translate and align [proposed Attention model]
6. Luong.  Effective Approaches to Attention based NMT EMNLP 15

## Datasets

1. WMT11 https://statmt.org
