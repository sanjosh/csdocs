
# challenges to productionizing

1. lack of value focus
2. lack of reproducibility
3. lack of domain data
4. overemphasis on test scores
5. difficulty of adoption
6. timelines

# Michelangelo from Uber

1. Manage data : generate feature and label data sets for training (and re-training) and feature-only data sets for predicting.
2. Train models
3. Evaluate models : store model config with (author, type, hyperparam, training & test data set, feature DSL, ROC, PR curve, learned param).
4. Deploy models : offline, online, library
5. Make predictions
6. Monitor predictions

* Shared Feature Store
* DSL to select, transform and combine features
* Automate Hyperparameter search
* Automation for Regular model retraining

[5]

# Hidden tech debt

## Complex models erode boundaries

1. Entanglement

ML systems mix signals together.

CACE principle: Changing Anything Changes Everything. CACE applies not only to input signals, but also to hyper-parameters, learning settings, sampling methods, convergence thresholds, data selection.

Mitigation : focus on detecting changes in prediction behavior as they occur.


2. Correction Cascade

Sometimes we create new Model B which is "Model A + small correction"

More expensive to analyze improvements to Model A

3. Undeclared Consumers

Model output being consumed without registration.  Can create hidden feedback loops

## Data dependencies cost more than code dependencies

1. Unstable data dependencies

2. Underutilized data dependencies

Legacy features, Bundled features, correlated features, epsilon features

Underutilized dependencies can be detected via exhaustive leave-one-feature-out evaluations. These should be run regularly to identify and remove unnecessary features.

3. Static analysis of data dependencies

Need automated feature management system as described in [McMahan, Ad Click prediction trenches], which enables data sources and features to be annotated.

## Feedback loops

1. Direct feedback loops

A model may directly influence the selection of its own future training data. 

2. Hidden feedback loops

```
One example of this may be if two systems independently determine facets of a web page, such as one selecting products to show and another selecting related reviews. Improving one system may lead to changes in behavior in the other, as users begin click ing more or less on the other components in reaction to the changes.
```

## AntiPatterns

1. Glue code added for integrating generic packages.  Mitigation : Wrap black box packages into common API.
2. Pipeline jungles created for Data collection and feature extraction.
3. Dead experimental codepaths
4. Abstraction debt 
5. Common smells : plain old data type, multiple language, prototype smell.

## Configuration Debt

* It should be easy to specify a configuration as a small change from a previous configuration.
* It should be hard to make manual errors, omissions, or oversights.
* It should be easy to see, visually, the difference in configuration between two models.
* It should be easy to automatically assert and verify basic facts about the configuration: number of features used, transitive closure of data dependencies, etc.
* It should be possible to detect unused or redundant settings.
* Configurations should undergo a full code review and be checked into a repository.

## Changes in external world

1. avoid use of fixed thresholds in ML system
2. monitoring : monitor prediction bias, enforce action limits, monitor upstream data.

## Areas of debt

1. Data testing debt
2. Reproduciblity debt
3. Process mgmt debt
4. Cultural debt

Ref [6]

# whats your ml test score

TODO

Monitor input data
Monitor output prediction

# Reference

1. Kreutzer. Can Neural machine translation be improved with user feedback. https://arxiv.org/abs/1804.05958
2. Breck. What’s your ML test score? A rubric for ML production systems.  https://ai.google/research/pubs/pub45742
3. Daniel Dahlmeier.  On the Challenges of Translating NLP Research into Commercial products. ACL 2017. http://www.aclweb.org/anthology/P17-2015
4. https://nishkalavallabhi.github.io/NLPProductionThoughts/
5. Michelangelo from Uber https://eng.uber.com/michelangelo/
6. Sculley. Hidden Technical Debt in Machine Learning Systems NIPS
