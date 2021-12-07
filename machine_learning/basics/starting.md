
https://twitter.com/MattNiessner/status/1441027241870118913

start small

No fancy features: disable dropout, no batchnorm, no learning rate decay, etc.

set tup train/val loss curves

overfit

ablation

For generative models, such as GANs, always start without a discriminator loss. Instead, just do a simple L1 regression first - only once that works, add the D (Wasserstein is a good choice). GANs mostly struggle due to data issues -> start with a simple distribution

https://niessner.github.io/I2DL/
