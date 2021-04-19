
# U-Net

semantic segmentation requires localization : assign label per pixel 

1. earlier :  first downsample the image, learning a feature representation. This feature representation is then upsampled to predict class labels per pixel.
2. information lost during downsampling
3. U-net : save the downsampling layers' input, then feed them back during the corresponding upsampling step.


# V-Net

U-Net + Residual 


# references

1. Olaf Ronneberger, Philipp Fischer, and Thomas Brox https://arxiv.org/abs/1505.04597
2. V-net https://arxiv.org/abs/1606.04797
3. No New-net https://arxiv.org/abs/1809.10483
4. https://twitter.com/TivadarDanka/status/1380151448495865856
