

## Terms 

1. Cloze 
1. few-shot or zero-shot

# Commonsense Knowledge Mining from Pretrained Models

 ```
 By transforming relational triples into masked sentences, 
 we can use this model to rank a triple’s validity by the estimated pointwise mutual information between the two entities.
 ```

PMI computation from probabilities
```

We first mask all of the tail words and compute the probability of each. 
We then find the word with highest probability pk, substitute it back in, and repeat j times.

Finally, we calculate the total conditional likelihood of the tail by the product of these terms,

```

 https://www.aclweb.org/anthology/D19-1109/

# Prompts
 
```
A prompt is a piece of text inserted in the input examples, 
so that the original task can be formulated as a (masked) language modeling problem. 

For example, say we want to classify the sentiment of the movie review 
"No reason to watch", we can append a prompt "It was" to the sentence, getting 
"No reason to watch. It was". It is natural to expect a higher probability from 
the LM to generate "terrible" than “great” then.
```

```
In the standard “pre-training and fine-tuning” paradigm, the gap between the 
pre-training stage and the downstream task can be significant: the objectives are different, 
and for the downstream tasks, we usually need to introduce new parameters—for example, 
for a BERT-large model and a binary classification task, it requires an additional set 
of 1,024 x 2 parameters. On the other hand, prompting makes it possible 
for downstream tasks to take the same format as the pre-training objectives,

```

## Discrete prompts

## Soft prompts

## In-Context learning or demonstration

Since GPT-3’s parameters are not fine-tuned on downstream tasks, it has to "learn" new tasks in an alternative way—through context.

https://gaotianyu.xyz/prompting/


# Small language models are few-shot learners

```
performance similar to GPT-3 can be obtained with language models that are much “greener” 
in that their parameter count is several orders of magnitude smaller. 

This is achieved by converting textual inputs into cloze questions that contain a task
description, combined with gradient-based optimization; exploiting unlabeled data gives further improvements. 
We identify key factors required for successful natural language understanding with small language models.

```

```
Enabling LMs to perform zero-shot learning by providing task descriptions was proposed by Radford
et al. (2019) and has been applied to text classification (Puri and Catanzaro, 2019), commonsense
knowledge mining (Davison et al., 2019) and argumentative relation classification (Opitz, 2019).
```

1. the choice of patterns and verbalizers, 
2. the usage of both unlabeled and labeled data, 
2. properties of the underlying language model

## pattern exploiting training (PET)

reformulating tasks as cloze questions with regular gradient-based finetuning

PET only works when the answers to be predicted by the LM correspond to a single token in its vocabulary

## TODO

(Radford et al., 2019; Schick and Schütze, 2021)


https://arxiv.org/pdf/2009.07118.pdf


