


# Problem : lack of robustness in NLP models

Large percentage of NLP models fail in Production. They show strong test set performance but are misled in production by shallow surface clues.

# Solutions

## Interpretability tools to understand model prediction

LIME

AllenNLP Interpret

https://demo.allennlp.org/named-entity-recognition

## Find top-K cue words using Pointwise Mutual Information


The top-K PMI words you obtain from your dataset must representative of the task and not spurious patterns

https://en.wikipedia.org/wiki/Pointwise_mutual_information

PMI (word, class)
/var/folders/08/wkf8w9f515q11lqxy7290lph13k9s3/T/com.microsoft.Outlook/Content.MSO/3530424C.tmp
Higher PMI indicates more likely co-occurence

Use Normalized and even Positive PMI
https://stackoverflow.com/questions/13488817/pointwise-mutual-information-on-text

https://stats.stackexchange.com/questions/179349/what-are-the-pros-and-cons-of-applying-pointwise-mutual-information-on-a-word-co

## Make the Model independent of Named Entities

Model prediction must not degrade with perturbation

Do perturbation sensitivity analysis

Perturb the sentence by replacing Named Entity by other equivalent entity and test

## Dataset ablation (different from model ablation)

Test using partial input : If model still succeeds, it means model has learnt surface cues.

Shuffle the input sentence : If model still succeeds, it has not learnt order.

Test after changing labels for small percent of data : How much does performance drop

Augment dataset with counter examples

## Data Augmentation

1. Synonym and hypernym replacement : performance must not drop
2. Random word swap/insert/deletion : performance must drop
3. Paraphrase replacement using PPDB or backtranslation (http://paraphrase.org/)

https://towardsdatascience.com/these-are-the-easiest-data-augmentation-techniques-in-natural-language-processing-you-can-think-of-88e393fd610

https://arxiv.org/abs/1901.11196

https://github.com/makcedward/nlpaug

## Ensemble of classifiers

Somewhat like boosting...

Build Naive model which is trained on surface cues

Build Stronger model that learns patterns which naive model cannot predict

Use stronger model for inference

## References

Sandya Mannarswamy.  Anthill Inside 2019

modern NLP techniques work like "a mouth without a brain"
https://thegradient.pub/frontiers-of-generalization-in-natural-language-processing/

Clever Hans
https://thegradient.pub/nlps-clever-hans-moment-has-arrived/

Niven, Kao. Probing neural network comprehension
https://www.aclweb.org/anthology/P19-1459/

McCoy. Right for the wrong reasons
https://www.aclweb.org/anthology/P19-1334/

https://thegradient.pub/frontiers-of-generalization-in-natural-language-processing/

