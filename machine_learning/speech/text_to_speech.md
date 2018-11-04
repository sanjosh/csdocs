
# F0 contour

An F0 contour is a realization of the vocal fold oscillation with slowly varying frequencies, whose dynamics are governed by a combination of different factors, in particular the length and elasticity of vocal folds, laryngeal muscle tension, and subglottal air pressure.

# Prosody

* Utterance 
* Intonational phrase
* accentual phrase
* phonological word

# Evolution of Synthesis 

1. Articulatory : model movement of vocal tract
2. Formant : create rules/filters for each formant
3. Concatenative : use db of stored speech to assemble new utterance
4. Parameric ( HMM-LSTM; includes google wavenet)

# Two stages of Text to speech

## Text to intermediate rep 

normalize  

* end of utterance detection [1, 2]

phonetic analysis :

* Homograph disambigutation : live vs live [Liberman and Church 1992]
* duration prediction
* intonation prediction

prosodic analysis : 

* g2p converter : predict phoneme for grapheme

## Intermediate rep to waveform 

unit selection from db


## Reference

1.  David	Palmerand	Marti	Hearst.	1997.	Adaptive	Multilingual	Sentence	Boundary	Disambiguation.	Computational	Linguistics	23,	2.	241-267.  
2. David	Palmer.	2000.	Tokenisation and	Sentence	Segmentation.	In	“Handbook	of	Natural	Language	Processing”,	edited	by	Dale,	Moisl,	Somers.
3. Andrew Maas.  CS 224s Stanford 2017 https://web.stanford.edu/class/cs224s/lectures/224s.17.lec14.pdf

