
Durbin & Koopman

observations are regarded as made up of distinct components such as trend, seasonal, regression elements and disturbance terms, each of which is modelled separately. 

state space model has two principles
1. state process describes latent variable evolution : markov, 
2. observations are independent of states

produce estimator for y_t given data {y1,.., ys} 
1. When s < t, the problem is called forecasting or prediction. 
2. When s = t, the problem is called filtering, and 
3. when s > t, the problem is called smoothing. 

System equation  : X(t) = A.X(t-1) + B.u(t-1) + e1(t)

Observation equation :  Y(t) = C.X(t) + e2(t)

* e1 : system noise
* e2 : observation noise
* u : input vector
* X : state vector
* Y : observation vector

https://radhakrishna.typepad.com/TimeSeries_Analysis_State_Space_Methods.pdf

https://www.statsmodels.org/stable/statespace.html

https://www.stat.pitt.edu/stoffer/tsa4/Chapter6.pdf

Lasse Engbo Christiansen, 02417 Time Series Analysis , 2017
https://www.youtube.com/channel/UCK71km-8VQmXVPg0pQWAyog
https://www.youtube.com/watch?v=9aTd7-Rx30Q
