

## Discrete Kalman filter : 

* linear stochastic difference equation.  
* For linear systems with Gaussian noise.  
* It is an adaptive low-pass infinite impulse response digital filter with cut-off frequency depending on the ratio between the process- and measurement (or observation) noise, as well as the estimate covariance.  
* Frequency response is less important, accuracy is more important.
* It has Time Update and Measurement Update phases.
* Time Update: projects current state estimate ahead in time. (find a priori for next time step)
* Measurement Update : adjusts projected estimate by actual measurement at that time. (adjust a priori estimate with actual measurement)
* Generalization of Gauss method of least squares, Fisher maximum likelihood method,  Wiener-Kolmogorov linear filter theory.

## Extended Kalman filter : 

Non-linear filter.  
linearizes current mean and covariance.  
A fundamental flaw of the EKF is that the distributions (or densities in the continuous case) of the various random variables are no longer normal after undergoing their respective nonlinear transformations. 
The EKF is simply an ad hoc state estimator that only approximates the optimality of Bayes’ rule by linearization.

## Unscented Kalman filter : 

## Non-linear filter.

## Ensemble Kalman filter
http://en.wikipedia.org/wiki/Ensemble_Kalman_filter

## Fast Kalman filter
http://en.wikipedia.org/wiki/Fast_Kalman_filter

## Recursive least squares filter
http://en.wikipedia.org/wiki/Recursive_least_squares

## Wiener filter
http://en.wikipedia.org/wiki/Wiener_filter

## Particle filter
http://en.wikipedia.org/wiki/Particle_filter

Predictor-Corrector model

Stochastic difference equation : Stochastic differential equation

Linear vs non-linear

Bayesian recurrence

Recursive Bayesian estimation

Sequential Bayesian estimation

## References

http://www.cs.unc.edu/~welch/media/pdf/maybeck_ch1.pdf
Maybeck’s book Stochastic Models Chapter 1 is good

http://www.cs.unc.edu/~welch/kalman/

http://www.cs.unc.edu/~welch/media/pdf/kalman_intro.pdf

Sorenson Least-squares estimation: from Gauss to Kalman  IEEE Spectrum 7 63-68 July 1970  
http://www.cs.unc.edu/~welch/kalman/media/pdf/Sorenson1970.pdf

* Maybeck, Peter Stochastic models, estimation and control Chapter 1
* Musoff, Zarchan Fundamentals of Kalman filtering
* Bozic Digital and Kalman filtering
* Catlin Estimation, control, and the discrete Kalman filter
* Brown Introduction to random signal analysis and Kalman filtering
* Sorenson Kalman filtering
* Chui Kalman filtering with real-time applications
* Kailath Lectures on Wiener and Kalman filtering

