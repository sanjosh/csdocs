
# SiNGAN 

https://arxiv.org/abs/1905.01164

```
Modeling the internal distribution of patches within a
single natural image has been long recognized as a 
powerful prior in many computer vision tasks [64]
```

```
Several recent works proposed to “overfit” a deep model to a single training example
[51, 60, 46, 7, 1].
```

[51] Dmitry Ulyanov, Andrea Vedaldi, and Victor Lempitsky. Deep image prior.

[60] Yang Zhou, Zhen Zhu, Xiang Bai, Dani Lischinski, Daniel Cohen-Or, and Hui Huang. Non-stationary texture synthesis by adversarial expansion

[46] Assaf Shocher, Nadav Cohen, and Michal Irani. Zero-Shot Super-Resolution using Deep Internal Learning.

[7] Caroline Chan, Shiry Ginosar, Tinghui Zhou, and Alexei A Efros. Everybody dance now

[1] Yuki M Asano, Christian Rupprecht, and Andrea Vedaldi. Surprising effectiveness of few-image unsupervised feature learning. 


# InGAN

https://arxiv.org/abs/1812.00231

InGAN is an automorphism, G : x → x, with px being the distribution of patches
in the input image. Retargeting is achieved by modifying
the size and shape of the output tensor, which changes the
arrangement of patches, but not the distribution of patches

Our InGAN is an image-conditional GAN (e.g., [17])
that maps an input image (as opposed to noise) to a remapped target output image

# DeepSIM

https://github.com/eliahuhorwitz/DeepSIM

We find that extensive augmentation is key for enabling
single image training, and incorporate the use of 
thin-platespline (TPS) as an effective augmentation.

Conditional generative models typically use simple crop-and-flip augmentations

Our model design follows standard practice for cGAN models (particularly Pix2PixHD

Two standard image primitives used by previous conditional generators are 
1. the edge representation of the image and 
2. the semantic instance/segmentation map of the image. 

Segmentation maps provide information on the
high-level properties of the image, but give less guidance on
the fine-details. Edge maps provide the opposite trade-off.
To achieve the best of both worlds, we use the combination
of the two primitive representations

Our method is capable of solving various image manipulation tasks including: 
(i) shape warping (Fig. 2) 
(ii) object rearrangement (Fig. 5) 
(iii) object removal (Fig. 5) 
(iv) object addition (Fig. 2) 
(v) creation of painted and photorealistic animated clips 

Single Image Animation the idea of generating short
clip art videos from only a single image was demonstrated
in [30] in an unsupervised fashion, we show that our model
can be used to create an artistic short video clips in a supervised 
fashion from a single image-pair

## image manipulation methods

A few notable image manipulation techniques include:
Poisson Image Editing [28], Seam Carving [3], PatchMatch
[4], ShiftMap [29], and Image Analogies [16].

Spline based include Field Morphing [5] and Image Warping by RDBF [1]
see [33] or survey

https://arxiv.org/pdf/2109.06151.pdf

[30] Tamar Rott Shaham, Tali Dekel, and Tomer Michaeli. Singan: Learning a generative model from a single natural image. 

[33] Richard Szeliski. Computer vision: algorithms and applications. Springer Science & Business Media,


