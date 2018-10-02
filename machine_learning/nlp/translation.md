
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

## Memory


# Convolutional Seq2Seq

[Gehring 2017]

# Facebook MUSE 

https://github.com/facebookresearch/MUSE

# Google NMT

https://ai.googleblog.com/2016/09/a-neural-network-for-machine.html

# Google Multilingual NMT

1. zero-shot translation
2. shared encoder and decoder
3. insert artificial token to indicate target language

# TODO

transformer https://ai.googleblog.com/2018/08/moving-beyond-translation-with.html

https://nlp.stanford.edu/read/

sockeye https://sockeye.readthedocs.io/en/latest/README.html

https://github.com/jonsafari/nmt-list

# References

1. Knight "A statistical MT tutorial workbook" (easy to understand, use instead of the original Brown paper)
2. Och "The Alignment-Template Approach to Statistical Machine Translation" (foundations of phrase based systems)
3. Wu "Inversion Transduction Grammars and the Bilingual Parsing of Parallel Corpora" (arguably the first realistic method for biparsing, which is used in many systems)
4. Chiang "Hierarchical Phrase-Based Translation" (significantly improves accuracy by allowing for gappy phrases)
5. Bahnadau.  Neural machine translation by Jointly learning to translate and align [proposed Attention model]
6. Luong.  Effective Approaches to Attention based NMT EMNLP 15
