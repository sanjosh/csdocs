
# Encoder Decoder network Approach
encoder is CNN : extract features from images
decoder is RNN/LSTM : translate features to caption

In [1], its CNN-CNN
encoder is CNN : extract features from images
decoder is also CNN : translate features to caption

beam search constructs a whole sentence without relying too heavily on any individual word from the ones which the RNN may generate at any specific time step

# Attention models

Xu[6] introduced the concept of attention into image captioning. 

```
Attention as a technique, in this context, refers to the ability to weight regions of the image differently. Broadly, it can be understood as a tool to direct the allocation of available processing resources towards the most informative parts of the input signal. Rather than summing up the image as a whole, with attention the network can add more weight to the ‘salient’ parts of the image.

Attention and its variants come in many forms: Semantic attention, spatial attention and multi-layer attention. Hard, soft, bottom-up, top-down, spatial, adaptive, visual, text-guided, and so on. 

(http://www.themtank.org/multi-modal-methods)
```

# Compositional framework

e.g. microsoft captionbot

# reinforcement learning

# Microsoft CaptionBot

1. Recognize celebrities and landmarks
2. recognize visual concepts

instead of RNN, they use MELM (max entropy language model) and DMSM (deep multimodal similarity model)


# Reference

1. Wang, Chan. CNN+CNN: Convolutional Decoders for Image Captioning]
2. Lu, et al .  Knowing When to Look: Adaptive Attention via A Visual Sentinel for Image Captioning
3. Show and Tell: A Neural Image Caption Generator
4. Fang et al From Captions to Visual Concepts and Back.
5. Johnson Karpathy et al. DenseCap: Fully Convolutional Localization Networks for Dense Captioning.
6. Xu, “Show, Attend and Tell: Neural Image Caption Generation with Visual Attention” (2015) 
7. Chen, SCA-CNN: Spatial and Channel-wise Attention in Convolutional Networks for Image Captioning 
