
# Nuts and Bolts of Applying Deep Learning - Andrew Ng

Three datasets : train, dev(aka validation), test
1. make sure dev and test set are from same distribution
2. Domain Adaptation

```
Given ML performance on different datasets
Human-level performance (base error rate)
 - this error difference is due to bias
Training
 - this error gap difference is due to variance
Training-Dev
 -	this error gap difference is due to training-test distribution mismatch
Dev
 -	this error gap difference is due to overfitting of Dev
Test
```

Is training error high ?
1. bigger model
2. train longer
3. try new model architecture

Is train-dev/validation set error high ?
1. need more data
2. add regularization
3. try new model architecture

Is dev set error high ?  (this is due to train-test distribution mistmatch)
1. get more data similar to test set 
2. do data synthesis or augmentation 
3. try new model architecture

Is test set high ? (overfit)
1. get more dev data

Automatic Data synthesis : generate synthetic data for OCR, speech, image similarity

What can AI/ML do?
1. Anything a person can do in less than 1 sec
2. predicting outcome in sequence of events which happen often

AI is new electricity

# Reference

Deep Learning school Bay Area 2016
https://www.youtube.com/watch?v=F1ka6a13S9I&feature=youtu.be

