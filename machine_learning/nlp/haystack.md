
Question answering model (QA) must either 
1. identify the span in a document which answers the given question (positive-answer) 
2. OR state that the answer cannot be answered by the document (no-answer).

DocumentStore ->  Retriever -> Reader(BERT)

# DPR : dense passage retrievel

Karphukhin

## Retriever (ranking problem):

identify subset of passages on which to run reader

1. dual encoders : dot product of BERT output of question and passage
1. training data has positive and negative : 1 question, 1 positive passage, N negative passages
1. inference : precompute embeddings and index in FAISS
1. negative sampling : 

## Reader

Distilled BERT

# FARM

transfer learning for BERT

in multiple tasks, you add prediction head for each task

each document-question pair is stored in a data structure called Basket which will be given a single final prediction by the model.

# distillation

speed via distillation

student learns from teacher : from UniLM to 33M param BERT

two types of transfer in last layer
1. attention transfer
1. value-relation transfer

# how to combine ranking signals ?

page rank, domain rank, text embeddings

learning to rank

# store feature vectors ?

# graph data ?

# transfer learning in NLP

1. LM Pretraining
2. LM Adaptation based on domain corpus
3. train on downstream task like NER, doc classification

ImageNet moment in Question answering : SQuAD 2.0 due to BERT dense passage retrieval

understand context and coreference

