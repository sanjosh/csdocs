
convolution : blending one func with another - "reverse, shift, multiply and sum"

convolution corresponds to the g-weighted average of the values of f around x

convolution in one domain = multiplication in another domain

Convolution = filtering in spatial domain

Multiplication = filtering in Fourier domain.

area under convolution = product of area under the factors

value of convolution at a point = intersection area of two curves

Support u want to pass signal x(n) thru filter y(n)

output z(n) will convolution of x(n) * y(n) in time domain

```
Let X(n) = Fourier x(n); 
    Y(n) = Fourier y(n)
    Z(n) = X(n) . Y(n) = term by term freq multiplication
then z(n) = Inverse Fourier Z(n) 
```

* A filter which outputs average of last k inputs attenuates higher frequencies.  
* Thats a convolution with rectangular func in time domain
* and a multiplication with "sinc function" in the frequency domain

* To get weekly rolling average, convolve time series against 1/5[1 1 1 1 1]
* To get monthly rolling average, make [1...(25 times)]

* Complexity of DFT = O(N^2) for N-len vector
* For N=2^n , FFT can be O(N.logN)

# References

[1](http://dsp.stackexchange.com/questions/9751/why-convolution-is-required-or-what-is-the-philosophy-behind-convolution?lq=1)

[2](http://dsp.stackexchange.com/questions/10453/how-are-two-signals-multiplied-and-how-is-it-different-from-convolving-two-sign)
