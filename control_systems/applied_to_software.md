
# Thread pool

objective : find number of threads that 
1. maximizes throughput and 
2. minimizes memory demands

Use stochastic gradient approx (hill climbing) to match concurrency to throughput

u_k+1 = u_k + g.d_k

* g = control gain    
* d_k = difference
* u = concurrency level

State machine with 3 states : Initialize, inTransition, Climbing

stability : minimize changes in number of threads to reduce context switching overhead

time delay : there is lag in starting or stopping threads 
Use "dead time detection" - keep controller in "inTransition" state until change is effected

Assume (concurrency, throughput) curve has unimodal shape.   
this curve changes under several conditions
1. arrival of new workloads
2. existing workload changes from CPU to IO-bound
3. competition with threads in other processes on same host

use "change point detection" to adapt to changes in curve


Hellerstein, Applying Control Theory in the Real World: Experience With Building a Controller for the .NET Thread Pool
http://static.googleusercontent.com/media/research.google.com/en//pubs/archive/35085.pdf

# TCP (RED random early detection)

## stability margin

the goal of control engineers is to design systems with a margin of safety. 

These margins are called stability margins. 

There are two classical metrics to measure this relative stability. 
1. gain margin 
2. phase margin. 

Stability margins of a system can be readily deduced from Bode plots


## model

W_i(t) = window size at time t

R_i(t) = round trip time at time t = a_i + q(t)/C = fixed delay + queue delay

dW_i(t) = dt/R_i(q(t)) - [W_i(t)/2].dN_i(t)

first term increases window size by one for every round trip time

second term halves window size at arrival of loss (i.e. d_N_i(t) = 1)

C. V. Hollot, V. Misra, D. Towsley, and W. B. Gong. A control theoretic analysis of RED. 
http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.136.6022

https://www.net.t-labs.tu-berlin.de/teaching/computer_networking/documents/Misra00_AQM.pdf

# DB2 Self tuning memory STMM

workload : DSS, OLAP, OLTP

memory consumers
1. sort, hash join, 
2. compiled SQL cache, 
3. lock memory, 
4. one or more buffer pools, 
5. compilation memory, 
6. statistics memory

Some consumers need minimum memory otherwise db operation fails.

Do cost benefit analysis : determine time saved if more memory was allocated

objective : Maximize total saved time over all memory consumers

max f = Sum (x_k) individual saved time   
subject to Sum (u_k) = U total memory

According to constrained optimization theory (i.e., Karush-Kuhn-Tucker  
conditions), the maximum total saved system time can be  
achieved when the partial derivative for each memory size is equal  

use 2 algo
1. MIMO controller :
2. Oscillation damping controller: 

Use integral control :

Typically, in control theory, an integral control law is   
used to regulate the measured output to a desired reference value.  
However, for the memory tuning problem, this reference value  
does not exist because we do not know in advance what each  
consumer’s benefit value should be when the system is in the  
optimal state. Instead, we compute the average benefit of N  
memory consumers, and construct the measured output as the  
difference between the individual consumer’s benefit and average  
benefit.  

## gotchas 

1. avoid oscillation : there are limits on the amount of memory transferable in any tuning interval

2. filter noise

3. auto-adjust sampling interval : STMM determines the tuning interval by 
observing the signal to noise ratio in the benefit data from the memory 
consumers and finding a time interval over which the signal to noise 
ratio is within 70%

4. minimum memory size per consumer

5. dramatic workload shift : detect change in workload or memory distribution


Adam J. Storm, Adaptive Self-Tuning Memory in DB2


# DEUCON admin of db servers


novel decentralized control structure that requires only localized coordination among neighbor processors.

A survey of feedback performance control in computing systems is presented in [1].

Wang, Jia, Lu. Decentralized end-to-end utilization control for distributed real-time systems. 
https://www.cse.wustl.edu/~lu/cse521s/Papers/tpds_deucon_revision.pdf

# Webservers

Xu Liu.  Model predictive feedback control for qos assurance in webservers. 

# Survey of feedback control in software services

Queueing theory not suitable for QoS problems:  
Unfortunately, queuing theory generally requires assumptions about the input
traffic arrival pattern that are not always accurate, leading to potentially 
poor predictions regarding performance

Liquid task model : Response time is dominated by queueing delay

Use of difference equations

n-th order ARMA

1. x(k) = A.x(k-1) + b.u(k)
2. y(k) = C.x(k)

where y(k) = throughput or delay at k  
and u(k)  = control input

estimate A, b, c using measurement and regression least-squares estimator

we need actuators that manage resource allocation or alter the functionality of 
the server in a way that manipulates the rate at which work is done

Actuators in computing systems fall into three basic types as described below.
1. Input flow actuator : admission control
2. Quality adaptation actuator
3. Resource reallocation : In a multiclass server, a separate control loop is often associated with each client class

## Why feedback control applied to QoS ?

important cornerstone of applying feedback control to computing
systems is the existence of a natural translation from common QoS 
assurance problems into those of feedback control

### Absolute convergence guarantee

delay control is hard

### prioritization

### statistical multiplexing

Sharing of spare capacity is achieved using a variation of a min-max selector scheme [15] in which
the objective is to minimize degradation of premium traffic

### relative differentiated service guarantees

### optimization guarantees

### performance isolation


## ControlWare library

ControlWare allows the user to express QoS specifications offline, 
maps these specifications into appropriate feedback control-loop sets, 
tunes loop controllers analytically to guarantee convergence to
specifications, and connects loops to the right performance
sensors and actuators in the application such that the desired QoS is achieved.


T. Abdelzaher, J. Stankovic, C. Lu, R. Zhang, and Y. Lu. Feedback performance control in sofware services. 
https://www.cse.wustl.edu/~lu/papers/control03.pdf

# Web server caching model

Y. Lu, T. Abdelzaher, C. Lu, and G. Tao, “An adaptive control framework and its application to differentiated caching services,”

# Web server 

C. Lu, T. Abdelzaher, J. Stankovic, and S. Son, “A feedback control approach for guaranteeing relative delays in Web servers,”

# Control theory foundational technique for managing databases

1. Regulation
2. Disturbance rejection
3. Optimization

A control system is stable if for any bounded input, the output is also bounded. 
Since no real world system produces an unbounded output, in practice,
unstable systems produce large oscillations, especially limit cycles 
that alternate between extreme values of metrics. 

A control system is accurate if the measured output converges (or 
becomes sufficiently close) to the reference input, such as ensuring
that throughput is maximized without exceeding response time constraints. 

A control system has short settling times if it converges quickly 
to its steady-state value, which is often important if there are 
time-varying workloads. 

Finally, overshoot is an important consideration in control systems 
if there are threshold effects such as buffer overflows

One appeal of control theory is that it provides a framework to
analyze and design closed loop systems based on the properties
of stability, accuracy, settling time, and overshoot. We refer to
these as the SASO properties.

## Throttling for admin utilities

Our approach is to use self-imposed sleep . relies on another OS service: 

throttle(k+1) = Kp.error(k) + K_i. (Sum of errors till k)

for more, see
S. Parekh, K. Rose, J. L. Hellerstein, S. Lightstone, M. Huras, and V.
Chang, “Managing the performance impact of administrative utilities,”


Diao, Hellerstein, Parekh, Griffith, Kaiser, Phung 
http://www.cs.columbia.edu/~rg2023/pubs/JSAC05.pdf

# DB2 throttling

S. Parekh, K. Rose, Y. Diao, V. Chang, J. L. Hellerstein, S. Lightstone, and M. Huras. 
Throttling utilities in the ibm db2 universal database server.

# Fuzzy control for QoS

Y. Diao, J. L. Hellerstein, and S. Parekh, “Optimizing quality of service
using fuzzy control,” Distrib. Syst. Oper. Manage., pp. 42–53, 2002.

# Load balancing

Diao, J. L. Hellerstein, A. Storm, M. Surendra, S. Lightstone, S.
Parekh, and C. Garcia-Arellano, “Using MIMO linear control for load
balancing in computing systems,” in Proc. Amer. Control Conf., Jun.
2004, pp. 2045–2050.

# Differentiated caching

Y. Lu, A. Saxena, and T. F. Abdelzaher, “Differentiated caching services:
A control-theoretic approach,” in Proc. Int. Conf. Distrib. Comput. Syst.,
Apr. 2001, pp. 615–654

# Aqueduct background data migration

C. Lu, G.A. Alvarez, and J. Wilkes, “Aqueduct: Online data migration with
performance guarantees,” in Proc. USENIX Conf. File and Storage Technologies, Monterey, CA, Jan. 2002, pp. 219-230

# CPU scheduling

D.C. Steere, A. Goel, J. Gruenberg, D. McNamee, C. Pu, and J. Walpole, “A
feedback-driven proportion allocator for real-rate scheduling,” in Operating
Systems Design and Implementation, 1999, pp. 145-158.

[25] C. Lu, J.A. Stankovic, G. Tao, and S.H. Son, “The design and evaluation of a
feedback EDF control scheduling algorithm,” in Proc. IEEE Real-Time Systems
Symp., Phoenix, AZ, Dec. 1999, pp. 56-67.
