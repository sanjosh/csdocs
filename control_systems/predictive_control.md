
# Predictive control

# Model Predictive control / Receding Horizon 

In classical PID control, it is difficult to guarantee closed-loop stability when there are (non-)parametric uncertainties to deal with. 

Model Predictive Controllers employ a receding (which is a finite) horizon concept in 
establishing a control sequence in order to assure that closed-loop stability is generally guaranteed.

(https://www.researchgate.net/post/What-is-the-difference-between-predictive-model-predictive-control)

In the MPC approach, the current control action is computed on-line rather 
than using a pre-computed, off-line, control law.

A model predictive controller uses, at each sampling instant, 
* plant’s current input 
* plant output measurements, 
* plant’s current state, and 
* plant’s model 

to calculate, over a finite horizon, a future open-loop control problem that 
* optimizes a given performance index and 
* satisfies constraints on the control action;

(Stanislaw Zak)

* Smith Predictor 
* Generalized Predictive Control (GPC, Clarke et. al, Automatica, 1987), 
* Dynamic Matrix Control (DMC), 
* Extended Horizon Adaptive Control (EHAC), 
* Extended Predictive Self-Adaptive Control(EPSAC)
* Unified Predictive Control (UPC)

# Model predictive control rossiter youtube

System must predict far enough : Prediction horizon time is always greater than settling time.  If we predict less, you will crash.

Receding horizon : control input is updated at every sampling instant.  Prediction horizon is always relative to current position.

Performance index is numeric definition for control input trajectory.   
Typically quadratic indexes are used.  
For example, tennis experts plan several shots ahead but beginners only exert in shot return.
But high performance index implies high risk (shot can go wrong).  

how to compare control law 1 versus control law 2  
Control law 1 may have Slow rise time but accurate   
control law 2 may have fast rise time but oscillations or overshoot  

examples of performance indices
1. fastest settling time
2. smallest actuator energy
3. smallest error on average
4. minimize max deviation under disturbance

the problem with these indices are that they are non-linear function of parameters and may not lead to tractable optimizations  

need a performance index which is continuous linear function with unique minimum and always positive
1. NO cubics and higher order have multiple stationary points
2. NO ax + b which can go to -inf
3. Exponentials do not have stationary point
4. sinusoid do not have unique minimum
5. Only quadratic satisfy; also good they do not penalize small deviations

Performance index needs to be linked to output errors (be zero) and actuator input activity (be small)

But perf index = (sum of squares of output error and input) is ill-posed   
since system cannot simultaneously drive error and input to zero simultaneously 

penalize deviations from desired steady-state.
Use Perf index = sum of square of error + deviation from steady state + rate of change of input/input magnitude

https://www.youtube.com/watch?v=jLRJJHMAD20&list=PLs7mcKy_nInFEpygo_VrqDFCsQVnGaoy-&index=15

Degrees of freedom describe complexity of input prediction.  Must be proportional to performance index.
Advance info can only be used if you have large degree of freedom.  

Constraints are embedded into optimization; not allow system to overflow.  
System has to be aware of different operating points in operating range.
some constraints become more critical as the operating range changes

multivariable interaction : be aware of all inputs and outputs

typical linear models are 
1. transfer function or 
2. state space
3. impulse response  (FIR)
4. step response 

discrete or continuous ?   
depends on decision making process, rather than how process is operating.  
use discrete model since decision making is discrete  

sampling rate must be 10 times the response time.  
sampling too fast is useless because plant cannot respond to fast input changes.  

common discrete state-space model
```
x(k+1) = A.x(k) + B.u(k)
y(k) = C.x(k) + D.u(k) + d(k) 
where
d(k) disturbance
x(k) state
y(k) output
u(k) input
```

common transfer function model : CARIMA
```
a(z).y_k = b(z).u_k + T(z).zeta_k/delta
```

step response model is particular form of transfer function model.  
```
y_k = H(z).u_k + d_k where H(z) is step response; d_k is disturbance
```

n-step prediction; matrix for state space model
```
x(k+1) = P.x(k) + H.u(k) = past + decision variables
y(k+1) = P.x(k) + L.dk + H.u(k) = past + disturbance + decision
```

CARIMA model incorporates disturbance estimate and therefore, can give unbiased predictions in steady state

step response model 

unbiased prediction : resilient to parameter uncertainty and disturbance

https://www.youtube.com/watch?v=w_GA_7sNM3g&list=PLs7mcKy_nInFEpygo_VrqDFCsQVnGaoy-&index=2

# long-range predictive controllers(LRPC)

# Joe Qin, Survey of industrial model predictive control

http://cepac.cheme.cmu.edu/pasilectures/darciodolak/Review_article_2.pdf

# Mathworks

https://www.mathworks.com/videos/series/understanding-model-predictive-control.html

# Richalet overview

J. Richalet and et al. Model predictive heuristic control: Applications to industrial processes

https://dl.acm.org/doi/abs/10.1016/0005-1098%2878%2990001-8

# Application

## Lateral control of car

MacAdam driver model 1986

## used in self-driving cars

Pedro Lima, Predictive control for autonomous driving

http://www.diva-portal.org/smash/get/diva2:925562/FULLTEXT01.pdf

# References

J. M. Maciejowski. Predictive Control with Constraints. Prentice Hall, Harlow, England, 2002 (comprehensive theory)
 
E. F. Camacho and C. Bordons. Model Predictive Control. Springer, London, second edition, 2004. (applications)

B. Kouvaritakis and M. Cannon, editors. Nonlinear Predictive Control: Theory and Practice.  (applications)

H. Michalska and D. Q. Mayne. Moving horizon observers and observer-based control. (nonlinear)

