

our approach leverages the fact that models tend to be more confident on 
results captured directly from their training data. These membership inference 
attacks enable us to predict if a result was used in the training data 
by checking the confidence of the model on a particular sequence.

* development of a method for inferring membership with high accuracy 

* techniques for sampling from models in a way that encourages the output of memorized 
content.

* compare the output of two different language models. When one model 
has high confidence in a sequence, but the other (equally accurate) model 
has low confidence in a sequence, it's likely that the first model has 
memorized the data.

https://ai.googleblog.com/2020/12/privacy-considerations-in-large.html
