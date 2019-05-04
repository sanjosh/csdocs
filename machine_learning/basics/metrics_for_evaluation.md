
# Classification

1. precision-recall
2. ROC-AUC :  indep of threshold, not for imbalanced datasets
3. F1 score : dependent on threshold; use when you have small positive class
4. accuracy
5. log-loss


## ROC-AUC Curve

AUC = the probability that the positive case outranks the negative case according to the classifier 

ROC curve always increases monotonically

an asymmetry in the ROC curve can be attributed to unequal widths of the distributions. Furthermore, it is shown that AUC discriminates well between “good” and “bad” models, but not between “good” models. [Marzban]


## Multi-classification problems

micro average vs macro average

1. Multi-class : use F1-score, Log loss, Average accuracy
2. Multi-labels
3. Hierarchical


# Regression

1. MSPE
2. MSAE
3. R square


# Unsupervised models

1. Rand index
2. Mutual info

# NLP

1. BLUE score

# Ref

1. https://medium.com/usf-msds/choosing-the-right-metric-for-evaluating-machine-learning-models-part-2-86d5649a5428
2. https://towardsdatascience.com/an-interesting-and-intuitive-view-of-auc-5f6498d87328
3. Marzban, Comment on ROC Curve Univ of Washington, http://faculty.washington.edu/marzban/roc.pdf
4. https://stats.stackexchange.com/questions/66837/why-does-my-roc-curve-look-like-this-is-it-correct
