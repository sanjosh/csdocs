
# FFT 

real = amplitude
imaginary = phase

from https://homepages.inf.ed.ac.uk/rbf/HIPR2/fourier.htm
```
 In image processing, often only the magnitude of the Fourier Transform is displayed, 
 as it contains most of the information of the geometric structure of the spatial domain image
```

and
```
Now once you got the result, zero frequency component (DC component) will be at top left corner.
If you want to bring it to center, you need to shift the result by \frac{N}{2} in both the directions.
This is simply done by the function, np.fft.fftshift(). (It is more easier to analyze).
Once you found the frequency transform, you can find the magnitude spectrum.

```
code
```
f = np.fft.fft2(img)
fshift = np.fft.fftshift(f)
magnitude_spectrum = 20*np.log(np.abs(fshift))
```
and
```
The function fftshift is used shift the quadrants of the FFT around to see the lowest frequencies in the center of the plot.
Fftshift only has to be called once, as it automatically shifts the quadrants around for 2D matrices
```
https://matlabgeeks.com/tips-tutorials/how-to-do-a-2-d-fourier-transform-in-matlab/

# filtering

High Pass Filtering is an edge detection operation

from https://matlabgeeks.com/tips-tutorials/how-to-do-a-2-d-fourier-transform-in-matlab/

```
Most of the energy in the Fourier domain is present in the center of the image, which corresponds to low frequency data in the image domain.
This corresponds to the many gradual changes in the images

 A strong line across an image will produce a perpendicular line in its FFT. 
```


from
https://dsp.stackexchange.com/questions/1637/what-does-frequency-domain-denote-in-case-of-images
```
, any 2d image can be represented (loosely speaking) as a sum of "rotated sines and cosines

 most of the perceptually important information of an image is stored in the phase (angle) component of the frequency representation.
```

# thresholding

separate foreground from background

https://homepages.inf.ed.ac.uk/rbf/HIPR2/threshld.htm

# Sobel filter

# Laplacian filter

# Notch filter for periodic noise reduction

https://stackoverflow.com/questions/65483030/notch-reject-filtering-in-python

https://docs.opencv.org/4.x/d2/d0b/tutorial_periodic_noise_removing_filter.html

https://i-systems.github.io/teaching/image_proc/iNotes/02_image_in_freq_py.html

Gonzalez book

# CLAHE

# Canny filter


# Median filter

best for removing impulse(salt&pepper) noise while preserving edges

# Gamma correction

# glare detection (light reflection)

# Moire pattern detection

# Luminance gradient

https://stackoverflow.com/questions/59280375/how-to-get-luminance-gradient-of-an-image

# References

1.  Rafael Gonzalez.  Digital Image processing
2.  Computer Vision: Algorithms and Applications by Richard Szeliski
