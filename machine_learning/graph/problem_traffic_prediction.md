

# ETA Prediction with Graph Neural Networks in Google Maps

https://www.nextplatform.com/2021/08/31/the-graph-neural-networks-behind-your-eta/

factor the roads, driving conditions, historical and emerging traffic events.

 
One of the first influential papers in the area was the diffusionconvolutional recurrent neural network (DCRNN) [17]. This paper
illustrated how explicitly accounting for the graph structure provides a significant reduction in forecasting error over several horizons. This generic blueprint of a spatial GNN component combined with a temporal component yielded several subsequent proposals, including STGCN [34], GaAN [37], Graph WaveNet [29], ST-GRAT [19], StemGNN [3], and GMAN [39].


the assumption of the time-series being aligned across nodes does not necessarily hold in practice

We adapted the MetaGradients [31] methodology from reinforcement learning, which allowed us to dynamically tune the learning rate during training and stabilise it across many uneven query batches, enabling a production-ready GNN model.

All ETA predictions are the result of “supersegments” which are sequences of connected road segments that have predictable traffic flows. The moment you leave, the model already knows how long you’ll travel on each of those segments. And when you type in directions, it’s essentially a string of such segments served up sequentially.

In the graph, each node is a road segment with edges where two segments connect. Models are regional in nature. The traversal times along segments and supersegments are denoted in seconds and those are used as node and graph-level labels for prediction. Each supersegment might appear in the training set multiple times as well since it’s the core of many separate paths. “Road segments are on average 50–100 meters long and the supersegments contain on average around 20 segments,”

“On a segment (node) level, we provide the average real-time and historical segment travel speeds and times, as well as segment length and segment priority (eg, road classifications such as highways) as features. On a supersegment (graph) level, we additionally provide real-time supersegment travel times as a feature. Real-time travel speeds and times are provided for 17 two-minute windows prior to horizon 0.” The researchers add that they also have learnable segments and supersegment-level embedding vectors. “This enables sharing of information whenever the same segment appears in different supersegments, and whenever the same supersegment appears in different candidate routes.”

use “extended supersegments” or even larger graphs that pull from nodes in neighboring segments, in addition to the original segments that might have other related traffic implications. “This enables our models to make use of additional spatial context — such as traffic congestion on a connecting route — at the expense of data storage, slower training, and inference

We combine two main kinds of unsupervised loss functions. Firstly, Deep graph infomax (DGI) [26] encourages the node embeddings to encode global structural properties, by carefully contrasting the road network against an artificially corrupted version.  Conversely, the graph auto-encoder (GAE) [16] leverages a link prediction-style loss and is hence mindful of local topology.

ETA Prediction with Graph Neural Networks in Google Maps
https://arxiv.org/pdf/2108.11482.pdf


# Spatial-Temporal Graph Attention Networks

Zhang et al in “Spatial-Temporal Graph Attention Networks: A Deep Learning Approach for Traffic Forecasting”.
https://www.ijcai.org/proceedings/2018/0505

PeMSD7 dataset provided by the Caltrans Performance Measurement System which has more than 39,000 sensor stations collecting real time data across California

for each aggregated time point t, we construct a graph

Each node feature v_t is the average velocity of traffic as measured at the node at time t.

228 nodes each representing a sensor location in the LA traffic measurement system

We connect each node based on the distance between traffic measurement sensors. A 1 is used if the nodes are more than a certain threshold distance away, a 0 is used otherwise. 

Data preprocessing: fusing spatial and temporal data using speed2vec

sliding window : to add time dependency into the feature vector, instead of simply taking the average velocity at time t as the feature, we will construct a feature h_t that is a vector of F previous measurements. 

Having learned spatial information about the data using the GAT model, we now feed the output of the GAT into an RNN. The RNN learns temporal aspects of the data for future predictions.

batch size = 50 graphs

https://medium.com/stanford-cs224w/predicting-los-angeles-traffic-with-graph-neural-networks-52652bc643b1

# Machine learning for spatiotemporal sequence forecasting: A survey.
