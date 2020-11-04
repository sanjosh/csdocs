
The Kalman-Yakubovich-Popov lemma connects two areas of control theory:
frequency methods and time-domain algebraic methods.

PID controller vs PI controller: Achieve asymptotic regulation in
presence of parameter uncertainties.

## Dimension

 Dimension | description |
 :--------:| ---------- |
 SISO vs MIMO |  
 Discrete vs continuous |  
 Adaptive control | Parametrizes uncertainty in terms of certain unknown parameters. Uses feedback to learn these parameters online. 
 Fuzzy control |  
 Stochastic control | 
 Intelligent control | Uses AI techniques. 
 Linear vs nonlinear |  
 Robust control  | The problem of designing controllers that satisfy both the robust stability and some performance criteria is called robust control.  Controllers designed using robust control methods tend to be able to cope with small differences between the true system and the nominal model used for design. Uncertainty is modeled as perturbation of nominal model.  Design tries to meet objective for any model in ball of uncertainty
 Optimal control | Based on calculus of variations. 
 H∞ control theory | Optimization method.  H stands for Hardy space.  One of the cornerstones of modern control theory. It was developed to solve such problems with very strong practical implications. The widely accepted modern technique for solving robust control problems now is to reduce them to linear matrix inequalities problems (LMI). 
 Fractional order control |  

## Approaches

Approaches | description 
:---- | :----
Frequency-Domain | Define transfer func H(s) = Y(s)/U(s) where Y(s)=Laplace of output and U(s) = Laplace of input H(s) = Laplace of system impulse response h(t)
Time-Domain Algebraic | Based on differential equations 
Polynomial-Matrix-Domain Frequential |
Geometric |
Structural-Digraph |

## Responses in a system

Various responses | description
:---- | :----
Forced response | all initial conditions are zero (hence depends only on input x(t))
Unit Impulse response  | when x(t) = delta func and all initial conditions are zero
Unit step response [d.c input] |
Unit ramp response  |
Free response | when input is zero
Total response |
Steady-state response  |
Transient response  |
 

Control system engineers are concerned with three main topics: observability, controllability and stability.

* Observability is the ability to observe all of the parameters or state variables in the system.
* Controllability is the ability to move a system from any given state to any desired state.
* Stability is often phrased as the bounded response of the system to any bounded input

Control theory can be broken down historically into two main areas: conventional control and modern control. 

Conventional control covers the concepts and techniques developed up to 1950.  
Modern control covers the techniques from 1950 to the present. Each of these is examined in this introduction.  

Conventional control relies upon developing a model of the control system using differential equations.  Due to the complexity of the mathematics, conventional control methods were used mostly for Single-Input-Single-Output (SISO) systems.

Lyaponov functions are constructed, which are described as energy like functions, that model the behavior of real systems. These functions are evaluated along the system trajectory to see if the first derivative is always dissipative in energy. Any gain in energy represents the system is operating near a pole and will therefore be unstable
