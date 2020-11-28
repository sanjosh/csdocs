
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
prediction[k] = estimate[k-1] + (gain_rate * time_step)
gain_rate[k] = gain_rate[k-1] + gain_scale * (residual/time_step)
estimate[k] = prediction[k]  + weight_scale * (measurement[k] - prediction[k])
```
