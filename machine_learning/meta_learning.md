
# giving student feedback at scale for coding and more complex assignments

```
New students were constantly coming up with new mistakes and new strategies.
Almost every new student solution will be unique, and a single misconception can manifest itself in seemingly infinite ways.
```

## supervised 

```
While annotating student code is difficult work, instructors are really good at thinking about how students would tackle 
a coding problem and what mistakes they might make along the way. Generative grading [2,3] asks instructors to 
distill this intuition about student cognition into an algorithm called a probabilistic grammar. 
Instructors specify what misconceptions a student might make and how that translates to code.
```

## meta-learning

why previous methods for automated feedback struggled were the 
1. high cost of annotation and 
2. diversity of student solutions.

1. many tasks, few samples per task
1. few-shot classification
1. solve unseen problems

frame the feedback challenge as a few-shot classification problem.

```
Every student solution is annotated by an instructor using a feedback rubric containing a list of misconceptions tailored to a single problem.
```

new deep neural network called a ProtoTransformer Network that combines 
1. the strengths of BERT from natural language processing and 
2. Prototypical Networks from few-shot learning literature.

other
1. creating synthetic tasks for code, 
1. self-supervised pretraining on unlabeled code, 
1. careful encoding of variable and function names, 
1. adding question and rubric descriptions as side information

https://ai.stanford.edu/blog/prototransformer/
