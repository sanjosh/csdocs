
# Text to image

* COCO dataset is hardest
* define custom text-image loss
* inception score is used as measure
* training tricks

# AttnGAN: Fine-Grained Text to Image Generation with Attentional Generative Adversarial Networks, Tao Xu

## Attentional Generator

* random_caption = F (random vec + sentence vector)
* image = Generator( random_caption )
* Use attention model since sentence vector mixes adjectives for various nouns

* Global sentence vector used to generate coarse image
* Regional image vector + word-context vector is used to form multimodal context vector, which generates new image features.

## Discriminator (DAMSM)

* Discriminator is trained with real image-caption examples
* Text encoder is BiLSTM
* Image encoder is CNN

* is every single word represented in image ? Solved using DAMSM (Deep attentional multimodal similarity model)
* convert image to set of feature maps
* dim of feature maps is made equal to word embeddings
* Attention vector over feature maps represents image's abstraction of the token
* DAMSM is trained to minimize difference between attention image vector and word embedding

https://arxiv.org/pdf/1711.10485.pdf

## Related work

* DRAW : deep recurrent attention writer
* align-DRAW 
* conditional PixelCNN 
* Approximate Langevin

# Generative Adversarial Text to Image Synthesis, Scott Reed

https://arxiv.org/pdf/1605.05396.pdf

# Other

https://paperswithcode.com/task/text-to-image-generation
