
# Anaconda

install miniconda

conda create --name sklearn
conda activate sklearn
conda install scikit-learn jupyter matplotlib tensorflow-gpu
conda env export > my_environment.yml

conda install --file requirements.txt

conda env list

# pip in conda

conda install -c anaconda pip


# Jupyter

https://jupyter.org/install

conda install -c conda-forge notebook

# Pycharm

https://askubuntu.com/questions/1230645/when-is-cuda-gonna-be-released-for-ubuntu-20-04

https://davidadrian.cc/definitive-data-scientist-setup/


# GPU driver on linux

install nvidia driver from "software updates"
disable secure boot in BIOS

about:gpu in chrome

cat /proc/driver/nvidia/gpus/0/information

sudo apt install nvidia-settings
nvidia-settings

## there are 2 graphics drivers, intel and nvidia

sudo apt install nvidia-prime
sudo prime-select nvidia

inxi -G

https://linuxconfig.org/how-to-install-the-nvidia-drivers-on-ubuntu-20-04-focal-fossa-linux

# Cuda toolkit

sudo apt install nvidia-cuda-toolkit

# Cudnn 

