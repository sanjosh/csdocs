
# Editing Factual Knowledge in Language Models

Nicola De Cao, Wilker Aziz, Ivan Titov

https://arxiv.org/abs/2104.08164

https://github.com/nicola-decao/KnowledgeEditor

constrained optimization

learning-to-update problem

In our approach, we train a hyper-network with constrained optimization 
to modify a fact without affecting the rest of the knowledge; the trained
hyper-network is then used to predict the
weight update at test time

We treat editing the memories of a neural model
as a learning-to-update problem. We use an efficient parameterization of a hyper-network that is
trained to update the LM parameters when provided
with a single fact that needs to be modified. We do
not require meta-learning, re-training or fine-tuning
of the original network.
