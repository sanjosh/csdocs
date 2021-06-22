
# pipeline

Text to Doc

Builtin NLP pipeline
1. tokenizer
2. POS tagger
3. Dependency parser
4. NER
5. Textcat

```
nlp.pipe_names

nlp.pipeline

def custom_component(doc):
   return doc

nlp.add_pipe(custom_component, before, after, last, first)
```

# Doc token and span

` for token in doc` 


Doc can be instantiated manually as well
```
    doc = Doc(nlp.vocab, words = words, spaces = spaces)
```

## similarity

requires word vectors; hence need a model which is md or lg (medium or large)

Doc and Span vectors default to average of token vectors


## custom attributes to doc, token or spans

call `set_extension` to register

1. attribute
2. method
3. property

# data structures

vocab = set of lexeme

lexemes = entry in vocab

stringstore = hash of strings


# custom pipeline

https://course.spacy.io/en/


# rule based matching using matcher

labeling can be semi-automated

PhraseMatcher

https://spacy.io/api/matcher

# performance

use `nlp.pipe` instead of `nlp()`

for only tokenizer, use `nlp.make_doc`


# visualizer

displacy
