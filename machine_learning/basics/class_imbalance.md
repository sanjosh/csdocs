
How to combat imbalanced classes ?

# summary 1

1. Sampling based methods
2. Cost-sensitive methods
3. Kernel-based methods 

https://www.reddit.com/r/MachineLearning/comments/12evgi/classification_when_80_of_my_training_set_is_of/

# summary 2 

Accuracy paradox : accuracy is an illusion because it is reflecting underlying class distribution

SOLUTIONS

Change the performance metric.  use
1. confusion matrix
2. precision/recall/F-score
3. Kappa (Cohen's kappa)
4. ROC curve

* Resample the dataset

* Generate synthetic samples 
SMOTE - synthetic minority over-sampling method

* try other algo : decision tree ?

* try penalized models : impose additional cost for making mistakes on minority class

https://machinelearningmastery.com/tactics-to-combat-imbalanced-classes-in-your-machine-learning-dataset/

https://stackoverflow.com/questions/26156503/what-should-be-the-proportion-of-positive-and-negative-examples-to-make-a-traini

https://www.quora.com/In-classification-how-do-you-handle-an-unbalanced-training-set

https://www.amazon.com/dp/1118074629?tag=inspiredalgor-20

https://github.com/scikit-learn-contrib/imbalanced-learn

# summary 3

1. use asymmetric cost func 
2. undersample majority - cluster and remove some
3. oversample minority  - resample or SMOTE

https://machinelearninginterview.com/topics/machine-learning/how-do-you-deal-with-dataset-imbalance-in-a-problem-like-spam-filtering/

# NO NEGATIVE SAMPLES

Building classifier when you have Small amount OR no negative samples

http://efavdb.com/methods-regression-without-negative-examples/

generic logistic regression

http://stackoverflow.com/questions/13937720/how-to-train-a-classifier-with-only-positive-and-neutral-data

https://www.quora.com/How-do-we-train-a-classifier-for-which-we-only-have-1-a-set-of-data-that-is-explicitly-positive-training-data-and-2-a-set-of-data-which-is-unknown-has-the-potential-to-be-positive-or-negative

# SMOTE - Synthetic Minority Over-sampling Technique 




