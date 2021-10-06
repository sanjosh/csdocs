
# nvidia GPU and GPU driver

nvidia-smi

NVIDIA-SMI 440.33.01 Driver Version: 440.33.01 CUDA Version: 10.2

## nvidia CUDA toolkit (runtime)

CUDA toolkit contains cuDNN, cuBLAS GPU-accelerated DNN and BLAS libaries, besides other stuff
https://developer.nvidia.com/gpu-accelerated-libraries

Compatibility matrix between GPU, the GPU Driver, the CUDA toolkit and cuDNN 
https://docs.nvidia.com/deeplearning/sdk/cudnn-support-matrix/index.html

How to get CUDA version
https://stackoverflow.com/questions/9727688/how-to-get-the-cuda-version

mismatched between cuda driver and runtime API
https://stackoverflow.com/questions/53422407/different-cuda-versions-shown-by-nvcc-and-nvidia-smi

nvcc —version

Installing cudnn
ubuntu procedure: https://docs.nvidia.com/deeplearning/sdk/cudnn-install/index.html

matching cuda-cudnn versions: https://docs.nvidia.com/deeplearning/sdk/cudnn-support-matrix/index.html


## nvidia cache may need to be deleted periodically


ls -la ~/.nv

## Torch version
python -c "import torch; print(torch.__version__)"
