
# Generative Adversarial Networks 

## Minimax two-player game

Simultaneously train two models
1. Generative model G captures data distribution.  Must maximize probability of D making mistake
2. Discriminative model D estimates probability that sample came from training data rather than G 

The generative model can be thought of as analogous to a team of counterfeiters, trying to produce fake currency and use it without detection, while the discriminative model is analogous to the police, trying to detect the counterfeit currency.

In the space of arbitrary functions G and D, a unique solution exists, with G recovering the training data distribution and D equal to 1/2 everywhere

we alternate between k steps of optimizing D and one step of optimizing G.

The generator nets used a mixture of rectifier linear activations and sigmoid activations.  

the discriminator net used maxout activations. 

Dropout was applied in training the discriminator net.

# Practical

gan = Model(discriminator + generator)

in every batch

discriminator.trainable = true
discriminator.train(fake images, fake labels) // discriminator is perfected
discriminator.train(real images, real labels)

discriminator.trainable = false
gan.train(fake images, real labels) // forces Generator to generate real images due to loss, and since weights in discriminator are held fixed



## Generate fake images

* Random noise is used by Generator to generate images
* Discriminator is trained to discriminate real and fake images

* Loss from discriminator used to train Generator

https://www.oreilly.com/ideas/generative-model-using-apache-mxnet

# Applications

* Use the discriminator as a classifier for other problems
* SRGAN to increase resolution Ledig
* Interactive GAN Zhu 2016
* Image to image translation Isola 2016
* text to image synthesis Reed 2016
* Image completion Yeh Chen 2016
* DiscoGAN Kim 2017 (multiple GAN)
* Cycle GAN Zhu Park 2017

# References
1. https://en.wikipedia.org/wiki/Generative_model
2. https://en.wikipedia.org/wiki/Discriminative_model
3. Goodfellow. Generative Adversarial Networks https://arxiv.org/abs/1406.2661
4. https://blog.openai.com/generative-models/
5. Goodfellow. GAN.  NIPS 2016 tutorial (https://arxiv.org/pdf/1701.00160.pdf, https://www.youtube.com/watch?v=AJVyzd0rqdc)

