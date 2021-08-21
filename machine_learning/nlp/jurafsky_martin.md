
# Jurafsky Martin 3rd ed

## Chap 8 : Sequence labeling : POS tagging and NER

Universal dependencies tagset has 17 tags used in POS tagging

Penn treebank 45-tag tagset

OntoNotes

Span recognition : BIO tagging

###  HMM generative model

###  CRF discriminative model based on log-linear

```
the CRF does not compute a probability for each tag at each time step. 
Instead, at each time step the CRF computes log-linear functions over a set of relevant
features, and these local features are aggregated and normalized to produce a global
probability for the whole sequence.
```

make repeated rule-based passes over a text
1. First, use high-precision rules to tag unambiguous entity mentions.
2. Then, search for substring matches of the previously detected names.
3. Use application-specific name lists to find likely domain-specific mentions.
4. Finally, apply supervised sequence labeling techniques that use tags from previous stages as additional features.

## Chap 14 : Dependency parsing


## Chap 17 : Information extraction

ACE relation extraction has 17 relations

UMLS, the Unified Medical Language System from the US National Library of Medicine has a network that defines 134 broad subject categories, entity types, and 54 relations between the entitie

### relation extraction

five main classes of algorithms for relation extraction: 
1. handwritten patterns, 
2. supervised machine learning, 
3. semi-supervised (via bootstrapping 
4. semi-supervised (via distant supervision)
5. unsupervised.

distant supervision

unsupervised (OpenIE)

### abbreviation detection

Schwartz-Hearst algorithm

### synonym detection

### temporal extraction and normalization

TimeML markup


### event extraction

Allen relations : The temporal relation between events is classified into one of the standard set of Allen relations


### template filling

## Chap 19 Semantic role labeling

semantic role labeling: task of assigning roles to spans in sentences, 

selectional restrictions : the preferences that predicates express about their arguments, such as the fact that the theme of eat is generally something edible.

Proposition Bank, generally referred to as PropBank, is a resource of sentences annotated with semantic roles

FrameNet

## Chap 21 : coreference resolution

Reference in a text to an entity that has been previously introduced into the discourse is called anaphora

mention detection algorithm


## Chap 23 : Question answering
