
# How to reduce the cost of deploying CNN on low-end devices

1. convolutions are expensive (multiplications).  Use fourier transform (winograd convolution and separable convolution).
2. quantize - use 8 bits for model weights instead of 32 bits
3. prune unused weights during training.  fewer parameters.  use sparse SGD.
4. squeezenet - reorg the layers.
5. do tensor decomposition (https://github.com/tensorly/tensorly)

# References

1. Aran Khanna. High Performance Deep Learning on Edge Devices With Apache MXNet.  https://www.youtube.com/watch?v=ev5F-Uc0PxM
2. Jeff Dean talk in cs231n
3. MobileNets: Efficient Convolutional Neural Networks for Mobile Vision Applications, Howard AG, Zhu M, Chen B, Kalenichenko D, Wang W, Weyand T, Andreetto M, Adam H, arXiv:1704.04861, 2017.
4. MobileNetV2: Inverted Residuals and Linear Bottlenecks, Sandler M, Howard A, Zhu M, Zhmoginov A, Chen LC. arXiv preprint. arXiv:1801.04381, 2018.

