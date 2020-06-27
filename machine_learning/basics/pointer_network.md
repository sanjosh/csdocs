
In technical terms, attention (at least this particular kind, content-based attention) boils down to weighted averages. In short, a weighted average of encoder states becomes the decoder state. Attention is just the distribution of weights.

In pointer networks, attention is even simpler: instead of weighing input elements, it points at them probabilistically. In effect, you get a permutation of inputs. Refer to the paper for details and equations.

http://fastml.com/introduction-to-pointer-networks/

We show Ptr-Nets can be used to learn approximate solutions to three challenging geometric problems -- finding planar convex hulls, computing Delaunay triangulations, and the planar Travelling Salesman Problem -- using training examples alone

https://arxiv.org/abs/1506.03134
