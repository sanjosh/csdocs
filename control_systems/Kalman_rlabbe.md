
# Roger Labbe, Kalman and Bayesian Filtering in Python

https://github.com/rlabbe/Kalman-and-Bayesian-Filters-in-Python/

# g-h filter or alpha-beta filter

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


# g-h-k filter

extension of g-h filter which tracks acceleration in base signal

