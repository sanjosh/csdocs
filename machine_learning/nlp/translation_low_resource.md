
# ranzato stanford cs 224n

https://www.youtube.com/watch?v=mp95Z5yM92c

low resource = less than 10K parallel sentences

topics discussed in dataset can be different (religion, govt, news)

OPUS = open parallel corpus

how to use in-domain monolingual data from two different languages (not parallel)

## checks for quality translation

1. LM filtering
2. transliteration filtering
3. length filter
4. language id filter
5. human assessment

## for mono data

1. train a count-based n-gram gives you prob (word|context)
2. then for given sentence, use above to compute score for every word
3. compute score of sentence
4. reject sentences below score

## how to use source-side monolingual data

one way is use DAE (denoising auto-encoder) to 
1. pretrain encoder, or 
2. add aux loss when you do supervised learning

how to use DAE
1. input is monolingual data 
2. add noise (e.g. drop words, swap words)
3. encoder-decoder job is to denoise (decoder is english, encoder is same as supervised)

decoder is not used for translation - only encoder is used

other ways to use source side monolingual data
1. self-training (measure discrepancy between noisy on new vs regular on old)

now nearby sentences are more likely to be predicted correctly

## how to use target side monolingual data ?

1. back translation

benefits
1. decoder learns good model
2. better generalization via data augmentation

## multilingual traing

1. use same encoder and decoder for all language pairs
2. prepend target language identifier to source sentence to inform decoder of desired sentence

preprocess data using byte-pair encoding to segment words into syllables; then good fraction of dictionary is shared

final touch
1. ensemble
2. fine-tuning
3. distillation

as dataset grows, 
1. you create larger model (more layers, parameters) and initialize it from smaller model
2. empirical : make encoder deeper; decoder does not matter much.

## unsupervised MT

no parallel data

cycle consistency  (like "unpaired image to image translation using cycle-consistent adversarial networks")

decoder may not produce fluent sentences

solution : share encoder and decoder parameters for english to french and french to english

## general

more data needed : 100 monolingual data give same signal as single parallel sentence

source and target domain mismatch: 
1. back-translation is not effective if topics in source and target can be different
1. in this case, self-training is better

## Filtering (new method)

1. learn joint embedding space on multilingual data 
2. then find closest matching sentence in embedding space



