
# Augmented Language Models: a Survey (meta)

https://arxiv.org/pdf/2302.07842.pdf

fundamental defect of LLMs: they are generally trained to perform statistical language modeling given (i) a single parametric model and (ii) a limited context, typically the n
previous or surrounding tokens.

We decompose the works included in the survey under three axes. 
1. Section 2 studies works which augment LM’s reasoning capabilities as defined above. 
2. Section 3 focuses on works allowing LMs to interact with external tools and act. 
3. Section 4 explores whether reasoning and tools usage are implemented via heuristics or learned, e.g. via supervision or reinforcement


Reasoning can be divided
1. commonsense reasoning 
2. mathematical reasoning 
3. symbolic reasoning 


## Reasoning

```
Huang and Chang (2022); Qiao et al. (2022) for a more in-depth review of works on reasoning for LLMs.
```

in-context learning

Wei et al. (2022c) introduced chain-of-thought (CoT), a few-shot prompting technique for LMs.

Kojima et al. (2022) simply append Let’s think step by step

in the context of math problems, Least-to-most prompting (Zhou et al., 2022) allows a language model to solve harder problems than the demonstration examples 

Yang et al. (2022a), on the other hand, decomposes using rule-based principles and slot-filling prompting to translate questions into a series of SQL
operations. 

Nye et al. (2021) introduce the notion of scratchpad, allowing a LM to better perform on multi-step computation tasks such
as addition or code execution

Yu et al. (2022) show that standard LM finetuning on reasoning tasks lead to better reasoning skills such as textual entailment, abductive reasoning,
and analogical reasoning, compared to pre-trained models

## Tools

### iterative LM calling

PEER (Schick et al., 2022), 

Re3 (Yang et al., 2022c)

. Zeng et al.
(2022) introduce Socratic Models, a modular framework in which various models pre-trained on different
modalities can be composed zero-shot

### info retreival

LMs can be augmented with memory units

Lambda

BlenderBot

WebGPT

Mind’s Eye (Liu et al., 2022b) invokes a physics engine to ground LMs
physical reasoning. More precisely, a text-to-code LM is used to produce rendering code for the physics engine

PAL (Gao et al., 2022) relies
on CoT prompting of large LMs to decompose symbolic reasoning, mathematical reasoning, or algorithmic
tasks into intermediate steps along with python code


LM needs to ground itself in the real-world by learning about affordances i.e. what actions are possible in a
given state, and their effect on the world

Liang et al. (2022) use a LM to write robot policy code given natural language commands by prompting the model with a few demonstrations.

## Learning to reason, use tools, and act

RL is a natural framework for training LMs to act and use tools since many of these tools are nondifferentiable (e.g. search engines, calculators or programming language interpreters). Additionally, many
tasks that benefit from interacting with tools resemble sequential decision making problems (e.g., navigating a web-browser to buy a specified product) and have a well-defined reward (e.g., 1 if the model buys
the correct product and 0 otherwise).

Hard-coded reward functions. When teaching a LM how to use external tools, the standard practice is
to update the weights of the model using a scalar reward generated by a hard-coded reward function. This
task-dependent function is computed based on the tool output. The LM agent takes a textual input, which in
RL terminology corresponds to the current state of the environment, and generates a sequence of tokens, or
actions in RL terms.

Dognin et al. (2021) train a LM to learn how to interface with a graph-based
knowledge base by performing the text2graph and graph2text tasks.

RLHF works by using a pre-trained LM to generate text, which is then evaluated by humans by, for example,
ranking two model generations for the same prompt. This data is then collected to learn a reward model
that predicts a scalar reward given any generated text. The reward captures human preferences when
judging model output. Finally, the LM is optimized against such reward model using RL policy gradient
algorithms like PPO