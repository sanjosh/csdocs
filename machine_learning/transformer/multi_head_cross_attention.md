
# transformer :cross attention and multi-head fusion

Cross-attention decoder if you want to treat hourly and 5-min inputs as separate modalities.

Cross-attention in a Transformer decoder helps combine two different time series inputs—in your case, the 5-minute series and the hourly series—by allowing the model to attend to one (the hourly) while processing the other (the 5-minute). This is especially useful for multi-resolution time series fusion, where each resolution contains complementary information.


Multi-head fusion to separately attend to hourly and fine-grained inputs.

Use cross-attention if one input is the target sequence or primary query (e.g., "what will the traffic be now?") and the other is a context source (e.g., "what was the hourly trend?").

Use multi-head fusion if the model is just trying to jointly learn from multiple temporal inputs without a primary/secondary relationship.
