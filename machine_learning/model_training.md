
First, I continue to add complexity to my model until I can overfit the training data. This is an indication that the model has reached a point where it is sufficiently expressive for your data set. It’s important to overdo it during this step, because the next step will reduce the training set accuracy.

Second, I handicap the model with regularization or dropout. While doing this, I monitor both the training accuracy and the test accuracy. If the training set accuracy drops below an acceptable level before I achieve that level on the test set, I may need to go back to step one.

You might want to overfit on the training data initially, just for an indication that your model has sufficient complexity for the problem. If you are not able to overfit, this might mean that you can use a more complex model. After this you optimize regularization and reduce overfitting.

https://www.quora.com/Why-would-or-wouldnt-you-aim-to-overfit-the-training-data-first-while-training-a-model

Overfitting happens when a model learns the detail and noise in the training data to the extent that it negatively impacts the performance of the model on new data. This means that the noise or random fluctuations in the training data is picked up and learned as concepts by the model....

Overfitting is more likely with nonparametric and nonlinear models that have more flexibility when learning a target function. As such, many nonparametric machine learning algorithms also include parameters or techniques to limit and constrain how much detail the model learns.

For example, decision trees are a nonparametric machine learning algorithm that is very flexible and is subject to overfitting training data. This problem can be addressed by pruning a tree after it has learned in order to remove some of the detail it has picked up.

The sweet spot is the point just before the error on the test dataset starts to increase where the model has good skill on both the training dataset and the unseen test dataset.

There are two important techniques that you can use when evaluating machine learning algorithms to limit overfitting:

1. Use a resampling technique to estimate model accuracy.
1. Hold back a validation dataset.

https://machinelearningmastery.com/overfitting-and-underfitting-with-machine-learning-algorithms/
