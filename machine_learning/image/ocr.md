
for stem
https://mathpix.com/ocr

easyocr
https://github.com/JaidedAI/EasyOCR

# for low resource

https://github.com/shrutirij/ocr-post-correction

 We use a character-level encoder-decoder architecture with attention and add several adaptations for the low-resource setting.

 https://aclanthology.org/2020.emnlp-main.478/

 OCR Post Correction for Endangered Language Texts
Shruti Rijhwani, Antonios Anastasopoulos, Graham Neubig

# ocr

1. preprocessing
1. segmentation
1. feature extraction : shape, strokes using RNN, CNN
1. recognition : 
1. post-processing : correct spelling mistakes usning NLP

https://towardsdatascience.com/what-is-ocr-7d46dc419eb9

# preprocessing

https://towardsdatascience.com/pre-processing-in-ocr-fc231c6035a7

## binarization

convert to black and white

crucial part of binarization is determining the threshold

various : otsu, adaptive

```
imgf = cv2.adaptiveThreshold(img,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,11,2) 
```

## skew correction

### Projection profile method

taking the sum of pixels along rows of the image matrix

get a histogram of pixels per row

skew angle = angle at which the maximum difference between peaks (or Variance) is found, 

### Hough transformation method

### Topline method

### Scanline method


## noise removal

cv2 fastNlMeansDenoisingColored

## thinning and skeletonization

aim is to make stroke widths uniform

not needed for printed text

for handwritten, call cv2 erode


# segmentation

https://towardsdatascience.com/segmentation-in-ocr-10de176cf373

```
axis = 1 is sum along rows

if foreground pixel is white (value 255)
horizontal_hist = np.sum(img,axis=1,keepdims=True)/255

if foreground pixel is black (value 0)
horizontal_hist = img.shape[1] - np.sum(img,axis=1,keepdims=True)/255

similarly
vertical_hist = np.sum(img,axis=0,keepdims=True)/255
```

## line level

segment image into lines

Rows that represent the text in a line have higher foreground pixels

## word level

sum along columns, 

columns with text have higher foreground pixels

gaps between words have higher background pixels

## character level

ligature = link joining successive characters

over-segmentation problem



