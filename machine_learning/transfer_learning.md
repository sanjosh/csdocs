
# Transfer learning

1. Instance based (TrAdaBoost) : use instances from source domain after re-weighting
2. Mapping based : map source and target instances into new data space
3. Network based  : reuse part of the ANN
4. Adversarial based : find transferable features

Tan, Survey of Deep Transfer Learning, https://arxiv.org/pdf/1808.01974v1.pdf

# How transferable are features

Modern deep neural networks exhibit a curious phenomenon: when trained on images, they all tendto learn first-layer features that resemble either Gabor filters or color blobs.  This is visible across different datasets and different training objectives 

The choice of whether or not to fine-tune the first n layers of the target network depends on the size of the target dataset and the number of parameters in the first n layers.  
1. If the target dataset issmall and the number of parameters is large, fine-tuning may result in overfitting, so the features are often left frozen. 
2. On the other hand, if the target dataset is large or the number of parameters is small, so that overfitting is not a problem, then the base features can be fine-tuned to the new task to improve performance.  
3. Of course, if the target dataset is very large, there would be little need to transfer because the lower level filters could just be learned from scratch on the target dataset. 

Yosinski, How transferable are features in deep neural networks, https://arxiv.org/pdf/1411.1792.pdf

# TODO

1. feature extraction (donahue 2014)
2. fine-tuning (girshick 2014)

# Domain adaptation

1. instance re-weighting

# ref

http://www.quora.com/What-is-the-difference-between-transfer-learning-domain-adaptation-multi-task-learning-and-semi-supervised-learning
