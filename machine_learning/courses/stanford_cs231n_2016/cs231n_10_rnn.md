
# RNN

map var length to fix length
1. 1 to n for 
2. n to 1 for 
3. n to n for MT

## char level language model

* Hidden state vector = tanh(prev hidden state, new input)
* Weight matrices

## LSTM

* four gates : input, forget, output, "g "
* (i, f, o) go thru sigmoid because they have to be differentiable in order to do backprop.
* but g goes thru tanh

ResNet is to PlainNet what LSTM is to RNN (via skip connections)

Additive interaction of LSTM improve gradient flow

* RNN has vanishing gradient problem 
* control gradient exploding with "gradient clipping"
* control gradient vanishing with LSTM

## GRU

simpler than LSTM

# Reference

1. Karpathy et al. Visualizing and understanding Recurrent networks
2. Greff. LSTM search space odyssey https://arxiv.org/abs/1503.04069
3. Hochreiter LSTM 1997
4. Jozefowicz. Empirical evaluation of RNN

