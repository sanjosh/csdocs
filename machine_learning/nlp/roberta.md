
# RoBERTa (Robustly optimized BERT)

https://arxiv.org/pdf/1907.11692.pdf

contributions
1. training the model longer, with bigger batches, over more data; 
1. removing the next sentence prediction objective; 
1. training on longer sequences; 
1. dynamically changing the masking pattern applied to the training data. 

The two segments are presented as a single input sequence to BERT with special tokens delimiting them:

```
[CLS], x1, . . . , xN , [SEP], y1, . . . , yM, [EOS].
with M + N < T 
where T = max sequence length during training
```

During pretraining, BERT used two objectives:
1. masked language modeling 
2. next sentence prediction (this is removed)


