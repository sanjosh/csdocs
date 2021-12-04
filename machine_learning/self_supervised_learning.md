
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
2. feature clustering
3. multiview coding (different views of data)

pretrain model to solve pretext tasks and then transfer learning to downstream task

pretext tasks 
1. vision
2. video
3. audio
4. multimodal
5. language

taxonomy of pretext tasks:
1. generative
2. self-prediction
3. innate relation
4. contrastive

pretext for video

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

pretext text for nlp
1. ALBERT : sentence order prediction


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

