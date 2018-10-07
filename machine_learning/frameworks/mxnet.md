
# MXNet

1. imperative : Neural net computation always flows through slow python (e.g. pytorch)
2. symbolic : neural compute graph is compiled & executed in C (e.g. tensorflow, theano).

MXNet has both a symbolic API (mxnet.symbol) and an imperative API (mxnet.ndarray)

## HybridBlocks

One main reason that the network is faster after hybridizing is because we don’t need to repeatedly invoke the Python forward function, while keeping all computations within the highly efficient C++ backend engine.

Through HybridSequental and HybridBlock, we can convert an imperative program into a symbolic program by calling hybridize.

MXNet accomplishes this through the use of HybridBlocks. Each HybridBlock can run fully imperatively defining their computation with real functions acting on real inputs. But they’re also capable of running symbolically, acting on placeholders.

All of MXNet’s predefined layers are HybridBlocks. This means that any network consisting entirely of predefined MXNet layers can be compiled and run at much faster speeds by calling .hybridize().


# Model zoo

1. symbol file contains definition of neural network : layers, connections, activation functions
2. weights file stores values of parameters learned during training


# References
1. https://github.com/zackchase/mxnet-the-straight-dope
2. https://aws.amazon.com/blogs/machine-learning/introducing-gluon-an-easy-to-use-programming-interface-for-flexible-deep-learning/
3. https://mxnet.apache.org/tutorials/index.html
4. https://gluon.mxnet.io/chapter07_distributed-learning/hybridize.html

