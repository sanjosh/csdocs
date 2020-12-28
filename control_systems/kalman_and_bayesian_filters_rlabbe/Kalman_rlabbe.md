
# Roger Labbe, Kalman and Bayesian Filtering in Python

https://github.com/rlabbe/Kalman-and-Bayesian-Filters-in-Python/

# 1. g-h filter or alpha-beta filter 

how to blend prediction and measurement

```
prediction[k] = estimate[k-1] + (gain_rate * time_step)
estimate[k] = prediction[k]  + weight_scale * (measurement[k] - prediction[k])
weight_scale = 4/10 (fraction of weight to assign to residual)
```
where residual = measurement - prediction (error)`

estimates end up close to linear regression line than measurements

but gain rate has to be accurate, if not, above calculation is wrong

so estimate gain rate by blending error in prediction with previous value

```
gain_rate[k] = gain_rate[k-1] + gain_scale * (residual/time_step)
```

have to divide by time because this is a rate

```
Predict step
prediction[k] = estimate[k-1] + (gain_rate * time_step)

Update step
residual = measurement[k] - prediction[k]
gain_rate[k] = gain_rate[k-1] + gain_scale * (residual/time_step)
estimate[k] = prediction[k]  + weight_scale * (residual)
```

Predict-Update 2-step cycle

g and h must be set based on actual system/sensor being modeled

g is called the weight_scale in [0,1] which decides bias towards prediction or measurement.  
g can be set based on error expected in sensor.  
large g implies follow the measurement instead of prediction.  

h is called the gain_scale.  
large h will react faster to transient changes

setting g = 0 and h = 0 will ignore measurements entirely

## g-h filter is family of filters

includes
* Kalman 
* Benedict-Bordner
* Least Squares

Benedict-Bordner filter was invented to minimize the transient error in case of multiple modes in signal

(Eli Brookner in Tracking and Kalman Filtering Made Easy)

## Sensitivity

* wrong initial conditions
* extreme noise
* lag error in case the filter does not model the system accurately (i.e. prediction uses first derivative but signal is changing based on higher derivatives)

Ringing means that the signal overshoots and undershoots the data in a sinusoidal type pattern.

## g-h-k filter

extension of g-h filter which tracks acceleration in base signal

# 2. Discrete Bayes Filter

Bayesian formula factors into the Kalman filter equation

how to incorporate movement + noisy sensor

Convolution : Probability distribution * error function of sensor (kernel)

predict_move is a convolution : sum of series of multiplications

Use scipy ndimage filters convolve, numpy roll

information about exact position of dog is lost after N predictions with noisy sensor

but each prediction is followed by an update, which increases certainty

update is 

posterior = (likelihood x prior) / normalization factor

Predictor-Corrector algorithm

Problems with this filter
1. scaling is costly if multiple variables need to be tracked
2. filter is discrete  (world is continuous)
3. filter is multimodal (has multiple beliefs about exact position)
4. requires measurement of the change in state


# 3. Probabilities, Gaussians and Bayes

filter which is unimodal and continuous

Gaussian used to describe using 2 numbers

variance computation : square of difference can exacerbate effect of outlier

Sum of Gaussians = Gaussian

Multiplication of Gaussian = Gaussian

Gaussian used in Kalman because its convenient

1. update implemented using bayes
2. predict implemented using Total probability theorem 

Kalman filter equations assume the noise is normally distributed, and perform sub-optimally if this is not true

skew : measures asymmetry in probability distribution
kurtosis : measures tail of probability distribution


# 4. One dimensional Kalman filters

Replace the histogram in Discrete Bayes with a Gaussian 

Position is Gaussian; velocity is Gaussian

Kalman gain = function of std deviation of likelihood and prior (decides how much weightage to attach)

variables used
1. R = measurement noise
2. Q = process noise
3. P = variance of state
4. z = measurement
5. K = kalman gain

alternate derivation of Kalman filter using orthogonal projection approach - was used by Kalman





# see also

1. Peter Huber. Robust statistics
2. James Berger.  Bayesian robustness
