
# PEFT

https://github.com/huggingface/peft

# LoRA (Low rank adaptation)

https://arxiv.org/pdf/2106.09685.pdf


```
A neural network contains many dense layers which perform matrix multiplication. The weight
matrices in these layers typically have full-rank. When adapting to a specific task, Aghajanyan et al.
(2020) shows that the pre-trained language models have a low “instrinsic dimension” and can still
learn efficiently despite a random projection to a smaller subspace.

In principle, we can apply LoRA to any subset of weight matrices in a neural network to reduce the
number of trainable parameters. In the Transformer architecture, there are four weight matrices in
the self-attention module (Wq, Wk, Wv, Wo) and two in the MLP module.
```

https://www.philschmid.de/fine-tune-flan-t5-peft

https://www.philschmid.de/bloom-sagemaker-peft  

# P-tuning (embeddings of prompts)

https://www.nvidia.com/en-us/on-demand/session/gtcspring22-s41735/

https://huggingface.co/docs/peft/task_guides/ptuning-seq-classification

P-tuning uses a prompt encoder to optimize the prompt parameters


# TRL

transformer PPO trainer

https://github.com/lvwerra/trl

# openai summarize from feedback

https://github.com/openai/summarize-from-feedback
