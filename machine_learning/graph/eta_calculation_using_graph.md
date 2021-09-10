
https://www.nextplatform.com/2021/08/31/the-graph-neural-networks-behind-your-eta/

 factor the roads, driving conditions, historical and emerging traffic events.

All ETA predictions are the result of “supersegments” which are sequences of connected road segments that have predictable traffic flows. The moment you leave, the model already knows how long you’ll travel on each of those segments. And when you type in directions, it’s essentially a string of such segments served up sequentially.

In the graph, each node is a road segment with edges where two segments connect. Models are regional in nature. The traversal times along segments and supersegments are denoted in seconds and those are used as node and graph-level labels for prediction. Each supersegment might appear in the training set multiple times as well since it’s the core of many separate paths. “Road segments are on average 50–100 meters long and the supersegments contain on average around 20 segments,”

“On a segment (node) level, we provide the average real-time and historical segment travel speeds and times, as well as segment length and segment priority (eg, road classifications such as highways) as features. On a supersegment (graph) level, we additionally provide real-time supersegment travel times as a feature. Real-time travel speeds and times are provided for 17 two-minute windows prior to horizon 0.” The researchers add that they also have learnable segments and supersegment-level embedding vectors. “This enables sharing of information whenever the same segment appears in different supersegments, and whenever the same supersegment appears in different candidate routes.”

use “extended supersegments” or even larger graphs that pull from nodes in neighboring segments, in addition to the original segments that might have other related traffic implications. “This enables our models to make use of additional spatial context — such as traffic congestion on a connecting route — at the expense of data storage, slower training, and inference


ETA Prediction with Graph Neural Networks in Google Maps
https://arxiv.org/pdf/2108.11482.pdf

https://www.nextplatform.com/2021/08/31/the-graph-neural-networks-behind-your-eta/
