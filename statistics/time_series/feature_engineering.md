

# features

Binary weekday/weekend flag

Holiday indicator (if applicable)

Traffic volume last week same time (lags)

use moving average

# type embeddings  or segment embeddings

to help distinguish 5-min vs hourly sequences in fusion

help a model distinguish between different input sources or modalities by giving each type a unique learned embedding — even if their features look similar.

```
# Suppose you have 2 types: 0 for hourly, 1 for 5min
type_embed = nn.Embedding(2, d_model)  # trainable

# During forward
hourly_embed = encoder_output_hourly + type_embed(torch.tensor(0, device=device))
fivemin_embed = encoder_output_fivemin + type_embed(torch.tensor(1, device=device))

```

# normalize

 subtract by running mean and divide by std deviation


# label smoothing

Soften the label by distributing a small portion of the probability mass to the other classes.

smoothed_label = [0.05, 0.90, 0.05]  # instead of [0.0, 1.0, 0.0]

Helps in tasks with noisy labels or when the model easily overfits.

Improves calibration — i.e., the predicted probabilities better match actual likelihood.

Doesn't make sense for regression tasks or where exact confidence is required.

```
criterion = torch.nn.CrossEntropyLoss(label_smoothing=0.1)

```


# embed dimension

longer sequences : longer history

overlapping sequences

# positional embedding

## relative vs absolute

Sinusoidal Encoding — good for generalization, no extra parameters.

Learned Positional Embedding — more flexible, often better for fixed-length time series tasks.

Time-aware positional encodings — e.g., continuous time gaps or encoding clock time (like "hour=13").


## rotary encoding

preserve the relative and absolute position of tokens in the sequence inside the attention mechanism itself

## spline encoding

https://scikit-learn.org/stable/auto_examples/applications/plot_cyclical_feature_engineering.html

## polynomial features for interactions

https://scikit-learn.org/stable/auto_examples/applications/plot_cyclical_feature_engineering.html


## kernels 

https://scikit-learn.org/stable/auto_examples/applications/plot_cyclical_feature_engineering.html


# inverse scaling of predictions

outputs are in the normalized space (mean ~ 0, std ~ 1), so we need to reverse the transformation.

# other

embedding dimesion size : richer representation

number of heads in transformer : more attention patterns

number of layers in transformer







