
# Multivariate time series anomaly

two approaches

## Forecasting based model

* predict value at next timestamp
* detect anomaly based on prediction error

## Reconstruction based model

* learn marginal distribution over latent representation 
* detect anomaly based on low reconstruction probability

# Approaches

## MTAD-GAT (combination of forecasting and reconstruction)

each time series is a feature

uses 2 Graph attention layer : feature-oriented and time-oriented

Joint loss function 

Zhao, Multivariate Time-series Anomaly Detection via Graph Attention Network
https://arxiv.org/pdf/2009.02040v1.pdf

## OmniAnomaly (reconstruction based)

## DAGMM (forecasting based)

## LSTM-NDT (forecasting based)

## LSTM-VAE  (reconstruction based)

## GAN-Li and MAD-GAN (reconstruction based)

# Other approaches

## Correlated Anomaly Detection from Large Streaming Data 

Zheng Chen, et al 

https://arxiv.org/pdf/1812.09387.pdf

## Anomaly detection in APM (Elasticsearch, Prolert)

work so far
1. statistical methods : goodness of fit
2. distance based approach : embedding in metric space

in this paper : a natural extension of the p-value of an observation provides a good measure for
identifying outliers for APM use cases.

in this paper : use bayesian formulation since its intrisically online and can age out older data.

define q-value = generalized p-value

relative phase change in two periodic signals

individual values can be aggregated using joint probability or order statistics 

model must be able to handle or eliminate natural trends (diurnal)

lattice valued data : because metric is truncated to fixed precision.

data with low coefficient of variation : if heap memory is not returned

heavy tails arise because monitoring tools often sample max values.

multimodal distribution arises if same metric is used for (e.g.) different SQL queries

anomalies between related time series can lag because 
1. no observation available for one time series (which has failed)
2. large lag : slow mem leak later leads to increased response time

use time bucket statistics for different bucket lengths, or dynamic time warping to correlate over time

uses q-digest algorithm

outlier = 2.5 standard deviations from the rolling mean

(Veasey Dodson, Anomaly Detection in Application Performance Monitoring Data)


## More 

In forecasting, you care about **temporal correlation** (how yesterday predicts tomorrow). In anomaly detection, you care about **cross-sectional correlation** (how the variables relate to each other *right now*).

The most powerful anomalies are not when a single metric spikes; they are when the invisible "bungee cords" connecting your metrics suddenly snap. For example, if Rider Demand spikes 300% on New Year's Eve, that is a normal extreme. But if Rider Demand spikes 300% and App Opens remain completely flat, that is a severe system anomaly (likely a bot attack or a tracking failure).

Here is how you model correlation mathematically when your only goal is finding the "weirdness" of the present moment.

### 1. The Statistical Standard: Mahalanobis Distance

If you want a robust, math-based way to measure if a set of variables are breaking their historical correlation, you use **Mahalanobis Distance**.

Unlike standard Euclidean distance (which just measures raw distance using a ruler), Mahalanobis distance measures how far a point is from the center of a distribution *relative to the correlation of the variables*.

* **The Math:** If you have a vector of current values $\vec{x}$ (e.g., current Demand, Supply, Price), a vector of historical means $\vec{\mu}$, and a historical Covariance Matrix $\Sigma$, the distance is:

$$D_M(\vec{x}) = \sqrt{(\vec{x} - \vec{\mu})^T \Sigma^{-1} (\vec{x} - \vec{\mu})}$$


* **How it detects anomalies:** Look at the $\Sigma^{-1}$ term (the inverse of the covariance matrix). If Demand and Price are historically highly positively correlated, the matrix "expects" them to move together. If your current state $\vec{x}$ shows high Demand but plummeting Price, the $\Sigma^{-1}$ term mathematically penalizes this state, causing the Mahalanobis Distance to explode. You set a threshold: if $D_M > \text{Threshold}$, flag an anomaly.

### 2. The Deep Learning Standard: Multivariate Autoencoders

If your market has hundreds of time series and the correlations are highly non-linear (meaning a simple covariance matrix can't capture them), you use a **Multivariate Autoencoder**.

An Autoencoder is a neural network designed to compress data and then perfectly reconstruct it.

* **How it models correlation:** You feed the current slice of all your time series into the network. It forces the data through a tiny "bottleneck" (the latent space). To successfully compress 100 variables into 5 variables and then reconstruct them back to 100, the network *must* organically learn the deep correlations between them. It learns that "Variable A almost always moves with Variable B."
* **How it detects anomalies:** You pass live data through the trained Autoencoder. If the current correlation structure is normal, the network easily reconstructs it. If an anomaly occurs (the bungee cord snaps), the network gets confused because the data violates its internal rules of correlation. It spits out a broken, inaccurate reconstruction. You simply measure the **Reconstruction Error**. A spike in error means a correlation anomaly just occurred.

### 3. The Modern Topology Standard: Graph Neural Networks (GNNs)

This is the cutting edge for spatial/multivariate anomaly detection, especially useful if your time series represent physical locations (like 50 different neighborhoods in a city).

* **How it models correlation:** You explicitly define the correlation as a mathematical Graph. Every neighborhood's time series is a "Node." The historical correlation between them forms the "Edges" (thick edges for high correlation, thin for low).
* **How it detects anomalies:** A Graph Neural Network constantly checks the state of a node against its neighbors. If Neighborhood A suddenly shows massive driver supply, but all its highly correlated neighboring nodes show zero supply, the GNN flags Neighborhood A as an anomaly because its state violates the established topology of the network.

### 4. The Joint Probability Standard: Copulas (Again)

We discussed Copulas for forecasting, but they are incredibly potent for anomaly detection.

* **How it detects anomalies:** A Copula literally maps out the $N$-dimensional probability terrain of your variables. If you feed the current state of your market into the Copula, it returns a single number: the joint probability density. If the Copula says, "The probability of Demand being $X$, Supply being $Y$, and Price being $Z$ occurring at the exact same time is $0.00001\%$," you have definitively found a correlation anomaly.

### Summary Comparison

| Method | Best For | Pros | Cons |
| --- | --- | --- | --- |
| **Mahalanobis Distance** | Baseline statistical checks | Extremely fast, mathematically transparent. | Fails if correlations are complex or non-linear. |
| **Autoencoders** | Large-scale, complex systems | Captures deep, hidden non-linear relationships. | Black box; hard to know *which* specific correlation broke. |
| **Graph Networks (GNNs)** | Spatial or networked markets | Incredible at isolating localized anomalies. | Requires defining the graph structure upfront. |


## for hundreds of time series

When dealing with hundreds of variables, you hit the **Curse of Dimensionality**. If you have 500 data streams, your covariance matrix is $500 \times 500$. Inverting a matrix of that size is computationally fragile; if any of your streams are highly correlated or noisy, the matrix loses its rank, the math breaks, and your system crashes.

For high-dimensional anomaly detection, you must use deep learning. Based on your scale, your two best options depend entirely on the *shape* of your data.

### Option A: The Spatial Approach (Graph Neural Networks)

**Use this if:** Your "hundreds of streams" represent physical locations. For example, you have divided a city into 200 hexagonal grids, and you track Demand and Supply in each hex.

When data has a physical shape, the correlations are fundamentally spatial. A demand shock in Hex A will naturally spill over into adjacent Hex B, but it shouldn't affect Hex Z on the other side of the city.

**How to build it:**

1. **Define the Graph:** Every single hex grid is a "Node." The physical borders between them are the "Edges."
2. **Feature Ingestion:** You feed the current Demand, Supply, and Price into each respective Node.
3. **Message Passing (The Magic):** A Graph Neural Network (like a Graph Convolutional Network, or GCN) forces each Node to mathematically share its state with its neighbors. The network learns what a "normal" neighborhood cluster looks like.
4. **Anomaly Scoring:** If a specific Node reports high supply, but its surrounding Nodes report zero supply, the GNN isolates that specific Node and flags it.

* **The Power:** It doesn't just tell you "the market is weird." It tells you exactly *which neighborhood* broke its spatial correlation.

### Option B: The Logical Approach (Multivariate Autoencoders)

**Use this if:** Your "hundreds of streams" are non-spatial. For example, you are tracking 50 different vehicle classes across 10 different rider subscription tiers, combined with app latency metrics and payment gateway success rates.

Here, the correlations are invisible and highly non-linear. You need a system that can compress this massive web of logic into a few core principles.

**How to build it:**

1. **The Bottleneck:** You build an artificial neural network with a wide input layer (e.g., 500 neurons for your 500 streams) that funnels down into a tiny "latent space" (e.g., 10 neurons), and then expands back out to 500.
2. **The Training:** You feed it months of normal historical data. The network is forced to learn the deep, hidden correlations (e.g., "When metric 42 goes up, metrics 18 and 300 almost always go down") just to survive the bottleneck compression and reconstruct the data.
3. **Anomaly Scoring:** In production, you feed the live vector of 500 streams into the model. If a correlation breaks (a bot attack inflates metric 42 without changing 18 or 300), the Autoencoder's learned rules fail. It reconstructs garbage.
4. **The Metric:** You calculate the **Mean Squared Error (MSE)** between the original 500 inputs and the Autoencoder's output. A sudden spike in the MSE is your anomaly alert.


