
Masked Autoencoders Are Scalable Vision Learners

MAE masked autoencoder

```
Our MAE approach is simple: we mask random patches of the input image and reconstruct the missing pixels. It is based on two core designs. First, we develop an asymmetric encoder-decoder architecture, with an encoder that operates only on the visible subset of patches (without mask tokens), along with a lightweight decoder that reconstructs the original image from the latent representation and mask tokens. Second, we find that masking a high proportion of the input image, e.g., 75%, yields a nontrivial and meaningful self-supervisory task.
```

https://arxiv.org/abs/2111.06377

https://keras.io/examples/vision/masked_image_modeling/
