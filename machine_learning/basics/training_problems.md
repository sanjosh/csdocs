
# Accuracy stuck at 50 percent

1. reduce learning rate
1. class imbalance
1. add more layers
1. check for frozen layers
1. normalize the features
1. data is not shuffled
1. labels are wrong
1. label noise
1. reduce batch size
1. batches contain single label


https://stackoverflow.com/questions/44066044/keras-accuracy-is-not-increasing-over-50

https://stackoverflow.com/questions/52840888/keras-accuracy-not-increasing-over-50-on-binary-cnn-problem

https://github.com/keras-team/keras/issues/6688

https://datascience.stackexchange.com/questions/40935/understanding-why-my-binary-classification-is-approaching-50-accuracy-using-ten

https://datascience.stackexchange.com/questions/40011/keras-lstm-accuracy-stuck-at-50

https://blog.slavv.com/37-reasons-why-your-neural-network-is-not-working-4020854bd607

*activation = ‘softmax’* should be used for multiclass classification whereas *’sigmoid’* for binary classification.
loss = categorical_crossentropy for multiclass, binary_crossentropy for binary

# High precision, low recall or vice versa

https://stats.stackexchange.com/questions/30313/improving-recall-in-a-neural-network

# accuracy on validation set is low

https://forums.fast.ai/t/increasing-validation-set-accuracy/267/13

overfitting

https://stats.stackexchange.com/questions/255105/why-is-the-validation-accuracy-fluctuating



# Flag unknown class in multi-class

There are broadly 2 "working" solutions to these type of problems:

You can check the softmax-posterior probability value of the output layer for all classes and threshold it(say 0.5). If the probability is < 0.5 for all other classes, then definitely this test case is an outlier(our unknown class in this case).

Adding a Garbage class and training it. But, collecting/randomly generating the features for this unknown class may sometimes become tedious and difficult. It is dependent on the application and on the number of classes. If you have smaller number of classes(<10), then you could try this too.

https://datascience.stackexchange.com/questions/37928/how-to-identify-the-unknown-class-in-machine-learning

https://datascience.stackexchange.com/questions/37706/how-to-handle-unknown-category-in-machine-learning-classification-problems?rq=1

https://datascience.stackexchange.com/questions/42623/how-to-deal-with-unknown-classes-with-a-neural-network-classifier?noredirect=1&lq=1

Open set classification

Dhifli, Diallo Toward an Efficient Multi-class Classification in an Open Universe
https://arxiv.org/pdf/1511.00725.pdf


# Label noise (labels are incorrect)

https://datascience.stackexchange.com/questions/28675/how-to-treat-the-datasets-with-unreliable-labels?rq=1

