
Self-supervised = unsupervised where data provides label

# cvpr 2020 tutorial

https://www.youtube.com/watch?v=C4UQWJcp7w4

https://rohit497.github.io/Recent-Advances-in-Vision-and-Language-Research/

## vision

pretext 
1. colorize image
2. inpainting
3. jigsaw puzzle
4. relative location prediction

models
1. SimCLR, 
1. CMC Tian, 
1. MoCo He, 
1. CPC Ord

Single stream model : both image and caption to transformer
Two stream model : image and caption sent to separate transformer and then cross self-attention

pretraining tasks for image+text
1. Masked language model 
1. masked region model
1. image text match (ITM)
1. word-region alignment (UNITER)
1. multi-view alignment (OSCAR)
1. multi-task learning (12-in-1)

downstream tasks
1. visual QA (UNITER)
1. visual entailment 
1. natural language for visual reasoning
1. visual commonsense reasoning
1. expression comprehension
1. image-text retrieval (given image, find text or reverse)

optimization
1. gradient accumulation
1. dynamic batching
1. mixed precision training

interpretability
1. train classifier to find what features learnt
1. weight probing
1. embedding probing

modality probing
1. visual probing
1. linguistic probing
1. cross-modality probing

pixel-bert : 

oscar : 

villa

## video and text

TODO

# berkeley CS294-158  Image self-supervised

https://sites.google.com/view/berkeley-cs294-158-sp20/home

https://www.youtube.com/watch?v=dMUes74-nYY


cognitive principles
1. Reconstruct from partial : in-painting, colorize, split-brain autoencoder, denoising autoencoder
1. Jigsaw, rotation, relative position in image
1. contrastive learning (CPC, instance discrimination, word2vec)

contrastive predictive coding : 

label propagation ?

# berkeley CS294-158  Text self-supervised (Alec Radford)

https://drive.google.com/file/d/1zZG_CezUqXG2w07liPvy0XAQKZuEPbg9/view

https://www.youtube.com/watch?v=BnpB3GrpsfM

# neurips 2021 tutorial Lilian Weng · Jong Wook Kim

special type of representation learning

self-supervised learning tasks also called pretext task

early work
1. restricted boltzmann machine (contrastive divergence)
2. autoencoder ( denoising vincent 2008)
3. word2vec 
4. autoregressive modeling 
5. siamese networks (idea of using pair of networks)
6. multiple instance learning and metric learning (contrastive loss; triplet loss)

two types
1. self-prediction : predict one part of sample given another
2. contrastive : given multiple samples, predict relation among them

self-prediction has 4 subtypes
1. autoregressive
2. masked generation (context autoencoder, BERT)
3. innate relationship prediction 
4. hybrid

contrastive (similar samples stay together)
1. inter-sample classification
2. feature clustering (assign psuedo-labels to clusters; e.g. DeepCluster, InterCLR)
3. multiview coding (different views of data) (e.g. AMDIM)

loss functions for contrastive
1. contrastive  (labeled dataset required)
2. triplet
3. lifted structure loss
4. multipair n-pair loss
5. noise contrastive estimation
6. infoNCE
7. soft nearest neighbour loss

pretrain model to solve pretext tasks and then transfer learning to downstream task

pretext tasks 
1. vision
2. video
3. audio
4. multimodal
5. language


## pretext for vision

taxonomy of pretext tasks:
1. generative
2. self-prediction : predict another part of the sample
3. innate relation : transformation of sample should retain innate logic (rotation, jigsaw)
4. contrastive : relation between multiple samples. (known logic; or create new augmented samples)

generative
1. variational autoencoder
1. GAN

self-prediction
1. Autoregressive image generation (PixelCNN, Image GPT)
1. Image generation (Diffusion model - add noise and reverse construct; masked prediction; colorization)

innate relation prediction : 
1. jigsaw (Noroozi Favaro)
2. rotation (RotNet)
3. learning to count (Noroozi)

contrastive
1. Contrastive Predictive coding (CPC) : 
1. Instance level discrimination
1. exemplar CNN

pretext-invaraint representation learning (PIRL)

MoCo : Momentum Contrast

SimCLR

Barlow twins : learn cross-correlation matrix between two output features for two distorted versions of same sample

non-contrastive siamese network : SimSiam, BYOL

DeepCluster, 

PCL (prototypical cluster learning)

SeLa (self labeling)

SwAV (Swapping assignments)

InterCLR 

Divide and constrast Tian 2021

NNCLR Dwibedi

S4L : combine supervised loss + self-supervised learning

SupCon : Supervised contrastive loss 


## pretext for video and audio

exploit time dim to predicting object movement and 3d motion of camera

1. optical flow pretext task (segmenting based on motion)
2. sequence ordering pretext task (temporal order verification - forward or backward)
3. colorization 
4. contrastive multiview learning (different viewpoints at same time should share same embedding)
5. autoregressive generation : predict videos with VQ-VAE
6. audio pretext : autoregressive model (jukebox dhariwal).  source separation by steering jukebox latent space (tagbox manilow)
7. contrastive learning : COLA Saeed
8. audio pretext : masked language model for ASR.  e.g. Wav2Vec2.0, HuBERT, SpeechStew, BigSSL
9. multimodal pretext : MIL-NCE Miech 2020, CLIP Radford 2021, ALIGN Jia 2021

## pretext text for nlp

1. ALBERT : sentence order prediction

Quick-thought vectors

IS-BERT : 

SimCSE 

techniques
1. data augment : without modifying semantic (EDA, back translate, dropout and cutoff)
2. in-batch negative samples
3. hard negative mining
4. memory bank
5. large batch size

## contrastive learning

contrastive learning works because shared information between views.

InfoNCE is lower bound to Mutual info between views

contrastive methods suffer from dimension collapse : features span low-dim space

https://neurips.cc/virtual/2021/tutorial/21895

# Two types

1. Generative/Predictive
1. Contrastive

https://analyticsindiamag.com/top-8-resources-to-learn-self-supervised-learning-in-2021/

# Andrew Zimmerman 

In general, withhold some information about the data, and task the network with predicting it

need to define proxy loss 

https://project.inria.fr/paiss/files/2018/07/zisserman-self-supervised.pdf

1. learn relative positioning in image
2. predict bounding box by feeding predicted region to a image classifier
3. predict color from monochrome image


# techniques

## MoCo, 

https://github.com/facebookresearch/moco

## Textless NLP, 

https://analyticsindiamag.com/facebooks-answer-to-gpt-3-textless-nlp/

## DINO,  

segment unlabeled and random images and videos without supervision. 

## 3DETR, 

## DepthContrast, 

## SimCLR 

https://arxiv.org/pdf/2002.05709.pdf

## SwAV 

https://arxiv.org/pdf/2006.09882.pdf

# VISSL

VISSL is a computer Vision library for state-of-the-art Self-Supervised Learning research with PyTorch

https://paperswithcode.com/lib/vissl

# TODO

https://analyticsindiamag.com/contrastive-learning-self-supervised-ml/

https://ankeshanand.com/blog/2020/01/26/contrative-self-supervised-learning.html

https://ai.stackexchange.com/questions/12266/what-is-the-relation-between-semi-supervised-and-self-supervised-visual-represen

https://ai.stackexchange.com/questions/10623/what-is-self-supervised-learning-in-machine-learning?rq=1

https://amitness.com/2020/02/illustrated-self-supervised-learning/

https://ai.facebook.com/blog/self-supervised-learning-the-dark-matter-of-intelligence/

# Yann lecun

1. learn with fewer labeled samples + fewer trials
1. learn to reason
1. learn to plan complex action sequences 

energy function 

energy is used for inference not learning

# counting people

https://arxiv.org/abs/2103.16291
Leveraging Self-Supervision for Cross-Domain Crowd Counting


# library

https://github.com/open-mmlab/mmselfsup
