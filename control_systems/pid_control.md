
# PID Controller

* closed loop system
* Used in Apache Spark to manage ingest rate

* PV = process variable = current value
* SP = set point = desired value for PV

* Cycle time (duty cycle) 
* Deadtime

* proportional = gain
* Integral = reset =
* Derivative = rate = damp oscillations

```
compute(time, PV)
{
  interval = time - prev_time
  
  error = SP - PV
  
  rate_of_change_error = (error - prev_error)/interval

  sum_of_error += error
  
  SP = PV - 
    (propConst * error) -
    (integralConst * sum_of_error) -
    (derivativeConst * rate_of_change_error)

  prev_error = error
  prev_time = time
  
}
```

* Oscillation
* Resonance
