
# Audio denoising

1. computational auditory scene analysis
1. speech enhancement
1. feature enhancement

# Noise reduction approaches

1. Wiener filtering
2. minimum mean square error (MMSE)based estimation
3. signal subspace method
4. DDAE (deep denoising auto-encoder)

three criteria which are widely used in speech enhancement literature, namely, 
1. noise reduction
1. speech distortion, and 
2. perceptual evaluation of speech quality

separate statistical difference in explored space

1. additive noise
2. multiplicative noise
3. reverberative noise

# Pitch estimation needed for noise removal

1. Praat algorithm https://github.com/YannickJadoul/Parselmouth
2. YIN algorithm
3. YAAPT algorithm
4. SWIPE
5. crepe - https://pypi.org/project/crepe/https://arxiv.org/pdf/1802.06182.pdf

https://librosa.github.io/librosa/generated/librosa.core.piptrack.html

F0 is vibration frequency of the ligaments when pronouncing voiced sounds.

pitch is higher in both men and women voices when they are speaking emotionally

F0 fundamental frequency estimation
1. Time domain : uses Autocorrelation 
2. Frequency domain
3. Hybrid : YAAPT

https://stackoverflow.com/questions/43877971/librosa-pitch-tracking-stft

https://medium.com/@neurodatalab/pitch-tracking-or-how-to-estimate-the-fundamental-frequency-in-speech-on-the-examples-of-praat-fe0ca50f61fd

# Sox to remove background noise

## Create background noise profile from mp3
/usr/bin/sox noise.mp3 -n noiseprof noise.prof

## Remove noise from mp3 using profile
/usr/bin/sox input.mp3 output.mp3 noisered noise.prof 0.21

## Remove silence from mp3
/usr/bin/sox input.mp3 output.mp3 silence -l 1 0.3 5% -1 2.0 5%

## Remove noise and silence in a single command
/usr/bin/sox input.mp3 output.mp3 noisered noise.prof 0.21 silence -l 1 0.3 5% -1 2.0 5%

## Batch process files
/usr/bin/find . -type f -name "*.mp3" -mmin +30 -exec sox -S --multi-threaded -buffer 131072 {} /path/to/output/{} noisered noise.prof 0.21 silence -l 1 0.3 5% -1 2.0 5% \;

## Remove insignificant files
/usr/bin/find . -type f -name "*.mp3" -mmin +30 -size -500k -delete

https://gist.github.com/devoncrouse/5534261

to control amount of noise that is reduced, change “0.21” number after noise.prof

# Denoising autoencoder

During training, mix additive noise (gaussian) or multiplicative noise (bernoulli)
and get model to predict clean speech 

# Source separation

1. directly convert noisy/mixed speech to clean speech
2. learn a mask that applied to noisy speech can generate clean speech.

To learn masks
1) Supervised methods where the model is trained as a classification task.
2) Semi-supervised methods where the model is trained as a partition/clustering task.

# Datasets

CHiME challenge

Clean speech

Grid corpus

http://spandh.dcs.shef.ac.uk/gridcorpus/

Noise

https://github.com/karolpiczak/ESC-50

Demand

https://freesound.org/

http://web.cse.ohio-state.edu/pnl/corpus/HuNonspeech/HuCorpus.html

# Papers

Speech Enhancement Based on Deep Denoising Autoencoder
Xugang Lu, 
https://www.isca-speech.org/archive/archive_papers/interspeech_2013/i13_0436.pdf

“Speech restoration based on deep learning autoencoder with layer-wised learning,” 2012
Lu, X., Matsuda, S., Hori, C., Kashioka, H., 
Shahriyar, Speech enhancement using Convolutional denoising autoencoderhttps://ieeexplore.ieee.org/document/8679106
Time frequency masking for large scale robust speech recognition
https://www.isca-speech.org/archive/interspeech_2015/papers/i15_2469.pdf

Hao, FullSubNet: A Full-Band and Sub-Band Fusion Model for Real-Time Single-Channel Speech Enhancement
https://www.haoxiangsnr.com/demo/fullsubnet/

# github

https://github.com/SIFANWU/Deep-Denoising-Autoencoder

https://github.com/topics/denoising-autoencoders

https://github.com/yongxuUSTC/DNN-for-speech-enhancement

https://github.com/xiph/rnnoise (RNN background noise)

