
# Sox

can add noise to raw audio 
* sox "infile" "outfile" tempo 1.3 reverb

# Pitch detection

https://librosa.github.io/librosa/_modules/librosa/core/pitch.html

Yin, McLeod, SPICE

Melodia http://www.justinsalamon.com/melody-extraction.html

https://en.wikipedia.org/wiki/Pitch_detection_algorithm

# Spectral envelope estimation 

CheapTrick
https://github.com/tuanad121/Python-WORLD/blob/master/world/cheaptrick.py#L9

# Impulse noise removal

https://code.amazon.com/packages/Declicker/blobs/dbf73d0b06b645e36cf602ed026b31fa2cb79a85/--/bin/Declicker.py#L12-L14

https://arxiv.org/abs/1310.7447 Nongpiur

# Voice equalization

http://wiki.hydrogenaud.io/index.php?title=ReplayGain_specification#Loudness_filter

https://github.com/carlthome/python-audio-effects/blob/master/pysndfx/dsp.py#L28

https://stackoverflow.com/questions/42492246/how-to-normalize-the-volume-of-an-audio-file-in-python-any-packages-currently-a

# Dynamic range compression

https://code.amazon.com/packages/Dynamic_range_compressor/trees/master

https://en.wikipedia.org/wiki/Dynamic_range_compression

# Normalization

https://code.amazon.com/packages/Ebur128normalizer/blobs/aedc361e437e3bcf55affd5aa6f850290b9ec4ed/--/libnormalizer/normalizer.c#L7

https://en.wikipedia.org/wiki/Audio_normalization

# Mel cepstral distortion for computing audio distance

https://github.com/MattShannon/mcd

# Frechet Distance for computing audio distance

```
Extract features from the last layer of DeepSpeech2, whose output is used in the CTC loss during training. We use representations in the resulting feature space to compute the Frechet distance and MMD
```

https://arxiv.org/pdf/1909.11646.pdf

https://github.com/mbinkowski/DeepSpeechDistances

# Augmentation

https://github.com/facebookresearch/WavAugment

