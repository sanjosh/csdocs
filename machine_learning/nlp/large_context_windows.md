
# tricks

1st problem is the quadratic time and space complexity of attention layer computations w.r.t. the number of input tokens n.
When the embedding size d > n, the 2nd problem is the quadratic time complexity of linear layers w.r.t. embedding size d.
3rd problem is Positional Sinusoidal Embedding used in the original architecture.
In Transformer architecture, the shapes of learnable matrix weights are agnostic to the number of input tokens n.
So, a trained Transformer in 2K context lengths can consume tokens of any length, even 100K. But the model will not produce meaningful results on 100K tokens during inference if it isn’t trained on 100K.
Training the vanilla Transformer on a giant corpus and only on a large context length is unfeasibly expensive due to the quadratic complexity w.r.t to n and d. LLaMA on 2K context length was estimated to be trained for ~$3M. Thus, LLaMA on 100K would cost ~$150M.
One option is to train the model on 2K tokens context and then fine-tune it in longer contexts (for example, 65K). But it won’t work with the original Transformer because of the Positional Sinusoidal Encoding.
[Trick #1] To address this, remove Positional Sinusoidal Encoding and use ALiBi, a simple and elegant positional embedding that doesn’t hurt accuracy. Then you can train on 2K and fine-tune on 100K.
[Trick #2] You don’t need to calculate attention scores between all tokens. Some tokens are more important than others, so Sparse Attention can be used. It will speed up both training and inference.
[Trick #3] Flash Attention efficiently implements the attention layer for GPU. It uses tiling and avoids materialization of big intermediate matrices (n, n) that doesn’t fit into GPU SRAM. It will speed up both training and inference.
[Trick #4] Multi-Query attention instead of Multi-Head attention. That means you share weights across all heads when linearly projecting K and V. It dramatically speeds up incremental inference.
[Trick #5] Conditional computation avoids applying all model parameters to all tokens from the input sequence. CoLT5 applies heavy computations only to the most important tokens and processes the rest of the tokens with a lighter version of layers. It will speed up both training and inference.
[Trick #6] To fit a large context, you need a lot of RAM in GPU, so people use 80GB A100 GPUs

https://blog.gopenai.com/how-to-speed-up-llms-and-use-100k-context-window-all-tricks-in-one-place-ffd40577b4c
