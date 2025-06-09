
combine two time series models predicting at different intervals

# Residual Learning / Hierarchical Fusion
Let the hourly model predict the general trend, and the 5-minute model predict residual variations around it.

Use the hourly model to make a coarse prediction.

Compute the residual between actual and hourly model output at the 5-minute level.

Train the 5-minute XGBoost model only on this residual.

Final prediction = hourly_prediction (interpolated) + 5min_model_residual_prediction.

# Strategy 2: Meta-Learner (Stacking)

Build a meta-model (e.g., a third XGBoost or linear model) that takes:

Prediction from 5-minute model

Prediction from hourly model (interpolated to 5-minute)

Additional features (e.g., time of day, day of week)

And learns how to weigh them adaptively.

Inputs to meta-model:
  [XGB_5min_pred, XGB_hourly_interp_pred, time_features] → Final fused prediction


# Kalman Filtering Inspired Approach

Think of the hourly model as the "state estimator" (low-frequency trend) 
and the 5-minute model as the "observation model" (high-frequency noisy measurement). 

You can use adaptive smoothing to combine them:

Make α adaptive based on time of day, recent prediction error, or traffic volatility.

# Strategy 4: Feature Injection / Cross-Resolution Features

Train a new 5-minute XGBoost model that takes as input both its own features and also the hourly prediction as a feature. This acts as an implicit guide or prior.

Features = [5min features, interpolated hourly prediction]

# compare

| Strategy                       | Pros                                 | Cons                            |
| ------------------------------ | ------------------------------------ | ------------------------------- |
| Residual learning              | Easy, interpretable                  | May underperform if misaligned  |
| Stacking/meta-model            | Flexible, learns context-specificity | Needs 2nd training phase        |
| Kalman-style adaptive blending | Lightweight, continuous update       | Needs careful tuning of weights |
| Feature injection              | Simple integration                   | Still a one-stage learner       |


# transformer

## 1. Prepare Inputs at Both Scales

create two aligned time series:

Fine-grained sequence: e.g., past 24 hours of 5-minute intervals → 288 time steps.

Coarse-grained sequence: past 24 hours of hourly intervals → 24 time steps (up-sampled or embedded to match sequence length).

## 2. Create Multi-Channel Input Embeddings

embedding = LinearProjection([5min_model_output, hourly_model_output, time_of_day, ...])

## 3. Add Positional Encoding


Add sinusoidal or learned positional encodings to retain temporal order:

x = embedding + positional_encoding

## 4. Pass Through Transformer Encoder

Use a standard Transformer encoder (or encoder-decoder if predicting future values) to model temporal dependencies and multi-scale fusion:


x = TransformerEncoder(x)  # Attends across all time steps

This allows the model to dynamically focus on:

Long-term hourly trends

Short-term 5-min changes

Temporal patterns like rush hour, weekends, etc.


## 5. Output Layer
   
Apply a regression head on the final embeddings to predict future traffic:

y_pred = Linear(x)  # Predict next 5-min traffic values

You can predict:

One step ahead (next 5 minutes)

Or a sequence (next hour or day at 5-minute intervals)

## Optional Tweaks

### Cross-attention decoder 

if you want to treat hourly and 5-min inputs as separate modalities.

Fusion happens inside the Transformer decoder, where one input (e.g., the 5-minute sequence) queries the other (e.g., the hourly sequence, encoded by the encoder).

Fusing asymmetric or hierarchical inputs

Enabling context-aware decoding (e.g., 5-min predictions modulated by hourly dynamics)

Decoder is predicting traffic at 9:20 AM (5-minute resolution)
→ It attends to hourly traffic at 9 AM, 8 AM, 10 AM
→ Focuses only on what matters


### Multi-head fusion 

to separately attend to hourly and fine-grained inputs.

Both inputs (5-minute and hourly) are concatenated or co-embedded and passed through a joint attention layer. Fusion is symmetric and occurs early or inside the encoder.

Early fusion when inputs are more similar or aligned

Modeling interactions directly between inputs

You can optionally tag each input with type embeddings (e.g., "5-min" or "hourly") for disambiguation

Input sequence = [5min_t-2, 5min_t-1, 5min_t, hourly_t-1, hourly_t]
→ Each attention head looks at different parts (some focus on short-term, others on long-term)


Use a sliding window over time for training/inference.

## Transformers let you:

1. Avoid hand-engineered ways to combine hourly and 5-min signals.
1. Capture periodicities and seasonalities over multiple horizons.
2. Automatically learn which granularity is more predictive at each time step.

You can even use predictions from XGBoost (hourly + 5min) as features fed into the Transformer, letting it learn how to best fuse and correct them over time.


## Multi-Task Transformer with Cross-Attention + Multi-Head Fusion

                  +-------------------+
                  | Hourly Time Series|
                  +--------+----------+
                           |
                  +--------v----------+         <-- ENCODER (captures long-term patterns)
                  |   Transformer     |
                  |     Encoder       |
                  +--------+----------+
                           |
                  +--------v----------+
   5-min Inputs → | Transformer Decoder| → Predict 5-min traffic
                  |   w/ Cross-Attn    |
                  +--------+----------+
                           |
                  +--------v----------+
                  |   Multi-task Head  | → Also predicts hourly traffic
                  +-------------------+

1. Encoder:
Input: hourly-level series (24 values for 1 day, with timestamps, etc.)

Learns trends, rush-hour cycles, etc.

2. Decoder:
Input: recent 5-minute history (e.g., last 288 values for 24 hours)

Learns short-term volatility, signal dynamics

Uses cross-attention to selectively incorporate hourly context

3. Multi-Task Output Heads:
Head 1: Predict next-hour traffic (e.g., 1-step or multi-step ahead)

Head 2: Predict next 5-min traffic (e.g., 12 steps for 1 hour ahead)

You train both heads simultaneously with a combined loss:

loss = alpha * loss_5min + (1 - alpha) * loss_hourly

Where alpha balances your preference for 5-min vs hourly accuracy (e.g., 0.5 for equal weight).

### Optional Enhancements

Positional encodings separately per resolution

Use type embeddings to help distinguish 5-min vs hourly sequences in fusion

Use residual learning if one signal can correct the other (e.g., 5-min residual on top of hourly trend)


```
import torch
import torch.nn as nn
import torch.nn.functional as F

# Positional Encoding (can be replaced with learned embeddings)
class PositionalEncoding(nn.Module):
    def __init__(self, d_model, max_len=5000):
        super().__init__()
        pe = torch.zeros(max_len, d_model)
        position = torch.arange(0, max_len, dtype=torch.float).unsqueeze(1)
        div_term = torch.exp(torch.arange(0, d_model, 2).float() * (-torch.log(torch.tensor(10000.0)) / d_model))
        pe[:, 0::2] = torch.sin(position * div_term)
        pe[:, 1::2] = torch.cos(position * div_term)
        pe = pe.unsqueeze(0)
        self.register_buffer('pe', pe)

    def forward(self, x):
        return x + self.pe[:, :x.size(1)]

# Transformer Encoder for Hourly Series
class HourlyEncoder(nn.Module):
    def __init__(self, input_dim, d_model, n_heads, n_layers):
        super().__init__()
        self.input_proj = nn.Linear(input_dim, d_model)
        self.pos_encoder = PositionalEncoding(d_model)
        encoder_layer = nn.TransformerEncoderLayer(d_model, n_heads)
        self.transformer_encoder = nn.TransformerEncoder(encoder_layer, num_layers=n_layers)

    def forward(self, x):  # x: (batch, seq_len, input_dim)
        x = self.input_proj(x)
        x = self.pos_encoder(x)
        x = x.permute(1, 0, 2)  # (seq_len, batch, d_model)
        return self.transformer_encoder(x)  # (seq_len, batch, d_model)

# Transformer Decoder for 5-min Series
class FiveMinDecoder(nn.Module):
    def __init__(self, input_dim, d_model, n_heads, n_layers):
        super().__init__()
        self.input_proj = nn.Linear(input_dim, d_model)
        self.pos_encoder = PositionalEncoding(d_model)
        decoder_layer = nn.TransformerDecoderLayer(d_model, n_heads)
        self.transformer_decoder = nn.TransformerDecoder(decoder_layer, num_layers=n_layers)

    def forward(self, x, memory):  # x: (batch, seq_len, input_dim)
        x = self.input_proj(x)
        x = self.pos_encoder(x)
        x = x.permute(1, 0, 2)
        return self.transformer_decoder(x, memory)  # (seq_len, batch, d_model)

# Multi-task output head
class MultiTaskHead(nn.Module):
    def __init__(self, d_model, output_dim_5min, output_dim_hourly):
        super().__init__()
        self.output_5min = nn.Linear(d_model, output_dim_5min)
        self.output_hourly = nn.Linear(d_model, output_dim_hourly)

    def forward(self, decoder_out):  # decoder_out: (seq_len, batch, d_model)
        output_5min = self.output_5min(decoder_out)  # (seq_len, batch, output_dim_5min)
        # Use first token to predict hourly (e.g., summary representation)
        output_hourly = self.output_hourly(decoder_out[0])  # (batch, output_dim_hourly)
        return output_5min.permute(1, 0, 2), output_hourly

# Full Model
class MultiResTrafficTransformer(nn.Module):
    def __init__(self, input_dim_hourly, input_dim_5min, d_model=128, n_heads=4, n_layers=2):
        super().__init__()
        self.encoder = HourlyEncoder(input_dim_hourly, d_model, n_heads, n_layers)
        self.decoder = FiveMinDecoder(input_dim_5min, d_model, n_heads, n_layers)
        self.head = MultiTaskHead(d_model, output_dim_5min=1, output_dim_hourly=1)

    def forward(self, hourly_seq, fivemin_seq):
        # Encode hourly input
        memory = self.encoder(hourly_seq)  # (seq_len_hourly, batch, d_model)
        # Decode 5-min input with cross-attention to hourly
        decoder_out = self.decoder(fivemin_seq, memory)  # (seq_len_5min, batch, d_model)
        # Predict both outputs
        return self.head(decoder_out)

# usage:
model = MultiResTrafficTransformer(input_dim_hourly=4, input_dim_5min=4)
output_5min, output_hourly = model(hourly_seq, fivemin_seq)
```
