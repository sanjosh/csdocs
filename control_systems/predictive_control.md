
# Predictive control

# Model Predictive control / Receding Horizon 

In classical PID control, it is difficult to guarantee closed-loop stability when there are (non-)parametric uncertainties to deal with. 

Model Predictive Controllers employ a receding (which is a finite) horizon concept in 
establishing a control sequence in order to assure that closed-loop stability is generally guaranteed.

(https://www.researchgate.net/post/What-is-the-difference-between-predictive-model-predictive-control)

In the MPC approach, the current control action is computed on-line rather 
than using a pre-computed, off-line, control law.

A model predictive controller uses, at each sampling instant, 
* the plant’s current input 
* and output measurements, 
* the plant’s current state, and 
* the plant’s model 

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

