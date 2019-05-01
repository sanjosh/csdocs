
https://genderbiasnlp.talp.cat/how-to-write-a-shared-task-system-description-paper/

Abstract: four/five sentences highlighting your approach and key results.

Introduction: ¾ a page expanding on the abstract mentioning key background such as why the task is challenging for current modeling techniques and why your approach is interesting/novel.

Data: review of the data you used to train your system. Be sure to mention the size of the training, validation and test sets that you’ve used, and the label distributions (i.e. A, B or NEITHER), as well as any tools you used for preprocessing data (e.g. SpaCy).

System: a detailed description of how the system was built and trained. If you’re using a neural network, were there pre-trained embeddings, how was the model trained, what hyperparameters were chosen and experimented with? How long did the model take to train, and on what infrastructure? Linking to source code is valuable here as well, but the description should be able to stand alone as a full description of how to reimplement the system. While other paper styles include background as a separate section, it’s fine to simply include citations to similar systems which inspired your work as you describe your system.

Results: a description of the key results of the paper on stage 1 and stage 2 datasets. If you have done extra error analysis into what types of errors the model makes, this is extremely valuable for the reader. Unofficial results from after the stage 2 deadline can be very useful as well.

Discussion: general discussion of the task and your system. Description of characteristic errors and their frequency over a sample of validation data. What would you do it you had another 3 months to work on it? Are there any deployment considerations such as minimum accuracy for a useful application, fairness and bias, etc?

Conclusion: a restatement of the introduction, highlighting what was learned about the task and how to model it.
