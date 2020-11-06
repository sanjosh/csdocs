
## why feedback control ?

Use Feedback control when there is uncertainty.  If function f known where f(input) = output), then feedforward is more apposite.
1. system to be controlled is a black box
2. governing laws can change silently over time
3. there are random fluctuations
4. clear goal exists

Goal is control, not optimization.  The known setpoint is a value rather than a condition(cost function) to be minimized.

In the black box, our goal is 
1. identify correct direction to the input we provide (increment or decrement?).  
2. Identify largest change which reduces tracking error

## how are computer systems different from mechanical or electrical 

do not have damped oscillations (p89)

have step-like response (output is delayed) whereas in electrical/mech, there is gradual response

## Basic terms  

* Setpoint = desired value you want to reach.  Can change during feedback loop operation
* tracking error = setpoint - output
* controller gain = by how much to multiply the tracking error
* process variable = output
* control variable = control input
* time scale T of process = how long it takes to settle to new steady state after change in input
* lag t = how long before change in input becomes observable in output

response = steady state + transient

## goals

* stability
* responsiveness
* accuracy

## Proportional

Proportional droop : a strictly proportional controller will never reach setpoint 

## Integral

* sum of tracking error
* eliminate steady state error

## Derivative

* rate of change of tracking error
* susceptible to high frequency noise noise

## Basic operation

### central loop

setpoint = get_setpoint(time t)
error = setpoint - actual
control_input = controller.work(error)
safe_control_input = actuator.work(control_input)
plant_output = plant.work(safe_control_input)
z = return_filter.work(plant_output)

### controller

```
Controller

  k_p proportional controller gain
  k_i integral controller gain
  k_d derivative controller gain
  i, d, prev_error

  def work(error)
    i = DT * error
    d = (e - self.prev)/DT
    self.prev_error = e

    return (k_p * error) + (k_i * i) + (k_d * d)
```

### how to find P, I, D

1. analytical model : use root locus methods
2. if semi-analytical model is known (e.g. self-regulating), then use AMIGO or Cohen-Coon
2. if no analytical model is known, use empirical ziegler nichols, 

### Ziegler Nichols

find slope of process characteristic curve.  this becomes the k_p term

### Semi-Analytical model

### Analytical model


## Issues

### what should be sampling rate ?

it must be 5/10 times greater than rate of change of signal  
in derivative control, too short interval leads to round-off errors but too-long results in finite-difference errors

### how soon does output change  ?

1. partial change seen immediately
2. no change until a certain duration : use Smith predictor
3. complete change but delayed by one or more time step
4. immediate change

### avoid small changes to input to prevent oscillations

1. quantize the changes in control signal : called dead zone 
2. error square controller to ignore small errors 

### avoid large changes to input to prevent overload and maintain stability

hysterisis

### recognize the max bound (actuator saturation, integrator clamping)

controlled system is unable to follow control input.  As a result, tracking errors add up

stop adding to integral term when actuator saturates.  This is called integrator clamping

### handle system initialization

use integrator preloading

### handle different modes of system via Gain scheduling

e.g. cruise control : highway mode and city mode require different gain factors

maintain a table of controller gains for different modes

### handle noise

apply smoothing filter to the tracking error signal or to control input

this will introduce lag

### get high tracking accuracy using nested control loop

### cases where setpoint is never reached


## Theory

Laplace transform

Poles of transfer function 
1. right half plane : unstable
2. left half plane : stable
3. real axis : non-oscillatory.  they vanish or grow depending on sign
4. with imaginary parts : oscillatory


### static input/output 

process characteristic curve

### dynamic input/output

process reaction curve

### types of known process models which can be force-fitted to a problem

1. self-regulating
2. self-regulating with oscillations
3. accumulation
4. non-minimum phase model


## Variations or extensions to the problem

### general linear

```
u_i = (a_0 * r_0) + (a_t * r_t) + ... + (b_0 * y_0) + ... + (b_t * y_)
```

this subsumes
1. standard PID version
2. setpoint-weighted form
3. incremental controller
4. derivative filtered

### Incremental or velocity form of PID controller

### using output feedback instead of error feedback

### nonlinear

### multidimensional problems

many control inputs affect many process outputs

## Examples

### cooling fan

maintain temperature by adjusting fan speed  
external factors besides fan speed decide temperature  

### game engine

maintain memory consumption by changing graphic resolution.    
do not know exact relation between objects and memory consumed.  

### cruise control

maintain speed by changing acceleration   
friction and slope of road not known, car may not be tuned  

### auto-scaling

max ratio of successful/total requests by vary number of servers

### linux dirty page throttling

maintain dirty page limit by throttling processes (make them sleep) which dirty a lot  
(see fengguang wu, intel)

### gobjfs

maximum batch size by waiting longer

### ad publisher

increase number of impressions by varying price


(Philipp Janert, Feedback control systems)
