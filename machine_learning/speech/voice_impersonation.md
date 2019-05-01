
# VoiceGAN

previous generative approaches
1. source filter model
2. spectral transformation model (PSOLA)

deficiency : require ability to isolate stylistic features of voice

voice transformation problem
* need to modify pitch and spectral envelope
* how can it be done : codebook-based conversion, minimal MSE, neural networks,
* deficiency of this approach : they capture instantaneous but do not capture style of voice; require parallel recording of source and target speaker saying same voice; must be time aligned

this paper approach
* GAN, specifically DiscoGAN
* DiscoGAN has 2 generators and 2 discriminators
* define reconstruction loss and style loss
* use magnitude spectrogram, retaining the phase of input signals to be transformed
* linguistic info is encoded in spectral envelope and is retained using loss func
* voice signals are variable length unlike image so GAN has to be modified using adaptive pooling

Model
* generator = 6 layer CNN encoder and 6 layer transposed CNN decoder
* discriminator = 7 layer CNN with adaptive pooling
* time domain signal is reconstructed from spectrogram using the Griffin-Lim method

## Reference

1. Gao, Singh, Raj : Voice impersonation using generative adversarial networks (https://arxiv.org/abs/1802.06840)

