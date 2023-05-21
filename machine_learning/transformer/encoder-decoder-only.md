
# encoder only

The Encoder-only architecture, on the other hand, is used when only encoding the input sequence is required

output is fed to classifier or regressor

# decoder only

```
The critical difference between the Decoder-only architecture and the Encoder-Decoder architecture 
is that the Decoder-only architecture does not have an explicit encoder to summarize the input information. 
Instead, the information is encoded implicitly in the hidden state of the decoder, which is updated 
at each step of the generation process.
```

This architecture is useful for applications such as:

1. Text completion
2. Text generation
3. Translation
4. Question-Answering
5. Generating image captions

# encoder-decoder


https://www.practicalai.io/understanding-transformer-model-architectures/
