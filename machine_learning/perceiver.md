
# Perceiver

(Perceiver: General perception with iterative attention.)

current models designed for specific modalities and make domain specific assumptions

```
Our core idea is to introduce a small set of latent units that
forms an attention bottleneck through which the inputs must
pass (Fig. 1). This eliminates the quadratic scaling problem
of all-to-all attention of a classical Transformer and decouples the network depth from the input’s size, allowing us
to construct very deep models. By attending to the inputs
iteratively, the Perceiver can channel its limited capacity to
the most relevant inputs, informed by previous steps

We can compensate for the lack of explicit structures in our architecture
by associating position and modality-specific features with
every input element (e.g. every pixel, or each audio sample) – these can be learned or constructed using high-fidelity
Fourier features
```

```
Transformers are amazingly flexible but scale poorly with the input size because
all self-attention layers have the same number of inputs and
standard self-attention compares each input to every other
input at all layer
```

```
maps inputs from various modalities to a fixed-size latent space, that is further processed by a deep, fully attentional network. 
This process decouples the bulk of the network’s processing from the size and modality-specific details of the
input, allowing it to scale to large and multimodal data.
```

```
achieved its cross-domain
generality by assuming that its input is a simple 2D byte array: a set of elements (which might be
pixels or patches in vision, characters or words in language, or some form of embedding, learned or
otherwise), each described by a feature vector. The model then encodes information about the input
array using a smaller number of latent feature vectors, using Transformer-style attention, followed by
iterative processing and a final aggregation down to a category label.
```

```
We use a parameterization
of Fourier features that allows us to (i) directly represent the
position structure of the input data (preserving 1D temporal
or 2D spatial structure for audio or images, respectively,
or 3D spatiotemporal structure for videos), (ii) control the
number of frequency bands in our position encoding independently of the cutoff frequency, and (iii) uniformly sample
all frequencies up to a target resolution.

This parameterization is related to the NeRF position encoding scheme (Mildenhall et al., 2020), which is built around
frequency bands with increasing powers of two (the k th band has frequency 2 k).
```

```
The model leverages an asymmetric attention mechanism to iteratively distill inputs
into a tight latent bottleneck, allowing it to scale
to handle very large inputs.

```

# Perceiver for structured input and output

https://arxiv.org/pdf/2107.14795.pdf

```
we develop a mechanism for decoding structured outputs – language, optical flow fields, audiovisual sequences,
symbolic unordered sets, etc. – directly from the Perceiver latent space
```

who not transformers

```
 Transformers scale very poorly in both compute and memory [82].
A Transformer deploys attention modules homogeneously throughout its architecture, using its full
input to generate queries and keys at every layer. As discussed in [35], this means each layer scales
quadratically in compute and memory, which currently makes it impossible to apply Transformers
on high-dimensional data like images without some form of preprocessing. Even on domains like
language where Transformers shine, preprocessing (e.g. tokenization) is often needed to scale beyond
short input sequences. 

On the other hand, Perceiver IO uses attention non-homogeneously, first using
it to map inputs to a latent space, then using it to process in that latent space, and finally using it
to map to an output space. The resulting architecture has no quadratic dependence on the input or
output size: encoder and decoder attention modules depend linearly on the input and output size
(respectively), while latent attention is independent of both input and output sizes.

the latent space does not explicitly share the structure (spatial or otherwise) of the inputs. To decode this information, we
query for it using cross-attention.

```

limitations
```
we don’t currently address generative modeling, and we haven’t explored mechanisms to automatically tune the size of the latent space.
```
