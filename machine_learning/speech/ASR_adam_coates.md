
# Adam Coates talk on ASR

Deep learning for speech recognition 
Bay Area Deep Learning School 2016 Day 2 at CEMEX auditorium, Stanford
https://www.youtube.com/watch?v=9dXiAecyJrY&feature=youtu.be&t=13874

## Traditional ASR pipeline

Break sound into phonemes instead of characters (since two words may sound similar)

X = audio wave
O = feature rep
Q = phoneme
Acoustic model : learn P(O|Q) = probability of phoneme given feature
Pronunciation model : P(Q|W) = probability of word given phoneme
Language model : P(W) = probability of words
Decoder (GMM, HMM) : W+ = argmax over W {P(W|X)} = argmax over W { P(O|Q).P(Q|W).P(W)

## Deep learning 

Feature representation is usually spectrogram.  Lose information with spectrogram

Spectrogram = log([STFT]^2)

Feed Labeled pairs (spectrogram, text) to DNN/RNN

Main problem is length(audio) not equal to length(text)

Earlier way was to use bootstrap for alignment.

Now multiple ways to resolve alignment
1. attention 
2. sequence to sequence models [Chan 2015, Bahdanau 2015], 
3. CTC [Graves 2006] dynamic programming algo

CTC : Search through all possible alignments of audio(x) and text(y)

Find P(Y|X)

CTC loss has been incorporated in neural network
1. Warp CTC from Baidu
2. Stanford CTC (github.com/amaas/stanford-ctc)
3. tensorflow tf.ctc_loss

https://en.wikipedia.org/wiki/Connectionist_temporal_classification

Decoding P(Y|X) is never perfect.  But see Graves 2006 prefix decoding 

Even with better decoding, CTC model makes linguistic errors

For grapheme models, we hit "Tchaikovsky" problem : how to spell something you have never heard ?

Two solutions
1. Fuse acoustic model with language model
2. incorporate linguistic data (Simple n-gram model : KenLM)

Decoding with Language Model - Hannun 2014

Beam search

```
Q : How do you handle multiple simultaneous voices ?
A : dominant speaker.  filter out background speakers.  undefined otherwise

Q : Do you customize transcription for a speaker
A : No, but bunch of strategies.  See ivectors to quantify speaker
```

# TODO

1. Sainath Interspeech 2015 build models from raw audio
