
# Bagging vs boosting (ensemble)

ensemble can be made of decision tree, linear model, SVM

https://machinelearningmastery.com/bagging-and-random-forest-ensemble-algorithms-for-machine-learning/

Bootstrap

Bagging = Bootstrap Aggregation

https://stats.stackexchange.com/questions/77018/is-random-forest-a-boosting-algorithm

complex model has low bias & high variance

simple model has high bias & low variance

1. variance reduction for complex model = bagging (e.g random forest )
1. bias reduction for simple model = boosting

https://towardsdatascience.com/basic-ensemble-learning-random-forest-adaboost-gradient-boosting-step-by-step-explained-95d49d1e2725

1. Bagging: Training a bunch of individual models in a parallel way. Each model is trained by a random subset of the data
2. Boosting: Training a bunch of individual models in a sequential way. Each model is trained on entire data. Each individual model learns from mistakes made by the previous model.

1. Random Forest = bagging
2. Adaboost = boosting. learns from the mistakes by increasing the weight of misclassified data points
3. Gradient Boosting = Gradient Descent + Boosting


https://machinelearningmastery.com/bagging-and-random-forest-ensemble-algorithms-for-machine-learning/

Random forest changes the algorithm for the way that the sub-trees are learned so that the resulting predictions from all of the subtrees have less correlation.

It is a simple tweak. In CART, when selecting a split point, the learning algorithm is allowed to look through all variables and all variable values in order to select the most optimal split-point. The random forest algorithm changes this procedure so that the learning algorithm is limited to a random sample of features of which to search.

The number of features that can be searched at each split point (m) must be specified as a parameter to the algorithm. You can try different values and tune it using cross validation.
1. For classification a good default is: m = sqrt(p)
2. For regression a good default is: m = p/3


https://towardsdatascience.com/decision-tree-ensembles-bagging-and-boosting-266a8ba60fd9

Advantages of using Random Forest technique:
1. Handles higher dimensionality data very well.
1. Handles missing values and maintains accuracy for missing data.

Disadvantages of using Random Forest technique:
```
Since final prediction is based on the mean predictions from subset trees, it won’t give precise values for the regression model.
```

Advantages of using Gradient Boosting technique:
1. Supports different loss function.
1. Works well with interactions.

Disadvantages of using Gradient Boosting technique:
1. Prone to over-fitting.
1. Requires careful tuning of different hyper-parameters


# Boosting

1. Catboost
2. LightGBM
3. XGBoost

https://neptune.ai/blog/when-to-choose-catboost-over-xgboost-or-lightgbm
