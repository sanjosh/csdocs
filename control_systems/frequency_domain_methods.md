
# Frequency domain approach

**Properties of control systems**

  - Speed of response

  - System stability

  - Transient performance

**Pole-zero map in the s-plane**

**Graphical eval of residues** \[ Schaum’s Feedback and control : 4.11\]

**Stable system :** impulse response approaches zero as time approaches
infinity.

**Stability criterion applied to roots of characteristic eqn**

  - Routh stability criterion

  - Hurwitz stability criterion

  - Continued fraction stability criterion

**Transfer func = Laplace transform of its impulse response.**

**System time response**

**System frequency response**

**Block diagram transformation theorems** \[Schaum’s Feedback and
control : 7.5\]

**Signal flow graphs for simultaneous eqns**

**Frequency domain specifications**

  - Gain margin and crossover freq

  - Phase margin and crossover freq

  - Delay time

  - Bandwidth

  - Cutoff rate

  - Resonance peak

  - Resonant frequency

**Time domain specifications**

  - Overshoot

  - Delay time

  - Rise time

  - Settling time

  - Predominant time constant

## Four methods 

1. Root locus : time domain method
2. Nyquist diagram : freq-domain method
3. Nichols chart : freq-domain method
4. Bode plot : freq-domain method

### Nichols chart

### Bode plot

Assumes system is stable in open loop

Bode' plots use frequency as the horizontal axis and use two separate

plots to display amplitude and phase of the frequency response.

### Root locus analysis

from http://claymore.engineer.gvsu.edu/\~jackh/books/model/chapters/rootlocus.pdf


Denominator of transfer func |    
---------------------------------- | ----------------------------------- 
Real roots                         | exponential terms                   
Negative real roots                | system stable                       
Positive real roots                | system unstable (exp growth)        
Complex roots                      | sinusoidal terms                    
Complex roots (negative real part) | cause decaying oscillation          
Complex roots (positive real)      | have growing oscillation, unstable. 

### Nyquist analysis 

http://www.facstaff.bucknell.edu/mastascu/econtrolhtml/Freq/Freq6.html

http://documents.wolfram.com/applications/insydes/Tutorial/NyquistPlots.html

In the Nyquist plot, a resonance shows up as a circle, but there is no
indication what its frequency is -- the Nyquist plot is like sighting
down the frequency axis at the real and imaginary parts of the function.

Based on argument principle 

(NumZeros(f) – NumPoles(f)) = 1/(2\*Pi\*i)Integral(f’/f) = Winding number

Nyquist plots display both amplitude and phase angle on a single plot,
using frequency as a parameter in the plot. G(jw) is plotted as a
complex num for any angular frequency w.

It is a polar plot.

**Nyquist criterion** : all roots of charac eqn must lie within unit
circle.

*When studying feedback controls, we are not as interested in G(s) as in
the closed-loop transfer function: *

*G(s)*

*---------*

*1 + G(s)*

*If 1+ G(s) encircles the origin, then G(s) will enclose the point -1.
Since we are interested in the closed-loop stability, we want to know if
there are any closed-loop poles (zeros of 1 + G(s)) in the right-half
plane.*

The Nyquist criterion then states that:

  - P = the number of open-loop (unstable) poles of G(s)H(s)

  - N = the number of times the Nyquist diagram encircles -1

<!-- end list -->

  - clockwise encirclements of -1 count as positive encirclements

  - counter-clockwise (or anti-clockwise) encirclements of -1 count as
    negative encirclements.

<!-- end list -->

  - Z = the number of right half-plane (positive, real) poles of the
    closed-loop system 

The important equation which relates these three quantities is: **Z = P + N**

http://www.prosoundweb.com/install/sac/n26_4/nyquist/nyquist.shtml

