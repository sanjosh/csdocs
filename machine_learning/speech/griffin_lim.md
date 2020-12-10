
# Griffin Lim: Mel spectrogram to audio

Determine original signal given modified STFT

Decrease MSE between STFT of estimated signal and the modified STFT

x(n) = original sequence
X(mS, w) = its STFT
Y(mS, w) = its modified STFT which is not a valid STFT for any sequence

iterative algo which decreases the squared error in each iteration

“One method of decomposing a speech signaly(n) is to represent it as the convolution of an excitation function with the vocal tract impulse response...”

Signal Estimation from Modified Short-Time Fourier Transform. IEEE Transactions on Acoustics 1984
https://pdfs.semanticscholar.org/14bc/876fae55faf5669beb01667a4f3bd324a4f1.pdf

In ASR, the STFT is used during signal analysis of each frame of 20-40 ms. Signal spectrum can be decomposed into amplitude and phase. At such small durations, phase is discarded. But results indicate that the phase spectrum can contribute significantly to speech intelligibility over small window durations [Alsteris, Paliwal, 2005]
