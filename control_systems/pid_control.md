
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

# PID controller talk - QCon 2019

Colm MacCárthaigh shows what PID loops look like in the context of modern systems, and how exponential backoff, flow-control, and other techniques can be wielded to build self-healing systems.

https://www.youtube.com/watch?v=3AxSwCC7I4s

1. P controller : proportional to error; but they oscillate
2. PI controller : adjust proportional to sum of error; but can be unstable
3. PID controller : used to damp oscillators; examples are auto-scaling, moving objects closer to closest data center

five patterns

## avoid Open loops

close the loops : measure first; then react

avoid infrequent operations like certificate rotation

make provisioning system declarative : declare the desired state of system; then describe steps to reach there
 
## Power laws

First compartmentalize to reduce blast radius

nuclear power plants; hulls in cargo ships

1. exponential back-off is like an integral
2. rate limiter : token buckets
3. backpressure : 

AWS SDK retry = exponential backoff + rate limiter + persistent state

Article by Marc Brooker on Exponential backoff and jitter
https://aws.amazon.com/blogs/architecture/exponential-backoff-and-jitter/

See "loop tuning" in control theory

## Liveness and Lag

Operating on old information is bad

1. Strive for O(1) scaling as much as possible
2. provision everything, every time (instead of sending diff, send the entire config)
3. report everything, every time
4. do everything, every time

Short queues are better

LIFO queues prioritizes recent state and helps in out-of-order backfill for catching up

## watch out False functions

Unix load metric is a compound function which does not behave in linear way

It is better to get to the underlying metric - take CPU utilization

## Avoid Edge triggering

Edge triggering invites modal behaviour - it gets tested only in high stress situations instead of always

Edge trigger requires you to solve deliver exactly once behaviour

its OK for alerting humans but bad for control systems.

Level triggered system is better

## Questions

hysterisis

Carl library for substrate and AWS SDK
