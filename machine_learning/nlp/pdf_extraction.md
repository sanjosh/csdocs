
# pdf extraction

https://filingdb.com/b/pdf-text-extraction

problems
1. text exists in page which is not visible
2. hidden text (same foreground and background)
3. spaces between letters of a word
4. no spaces between words
5. nonstandard fonts : rendering process converts codepoint -> glyph name -> glyph
6. word and para detection by clustering
7. text and para order
7. embedded images

testing : statistics of text length, page length, spaces to word ratio, percent of numbers

# pdf extraction toolkit

https://www.tamirhassan.com/html/pdfxtk.html

# table extraction

1. ocr + opencv
2. horizontal lines
3. text blocks
4. convert to html

# OCR methods

https://nanonets.com/blog/table-extraction-deep-learning/

opencv

```
enhance data in image

ret, thresh_value = cv2.threshold(
    table_image_contour, 180, 255, cv2.THRESH_BINARY_INV)

image dilation 

kernel = np.ones((5,5),np.uint8)
dilated_value = cv2.dilate(thresh_value,kernel,iterations = 1)

contours, hierarchy = cv2.findContours(
    dilated_value, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

for cnt in contours:
    x, y, w, h = cv2.boundingRect(cnt)
    # bounding the images
    if y < 50:
        table_image = cv2.rectangle(table_image, (x, y), (x + w, y + h), (0, 0, 255), 1)

```

## textract


https://aws.amazon.com/blogs/machine-learning/process-text-and-images-in-pdf-documents-with-amazon-textract/

## tesseract

# camelot

https://github.com/atlanhq/camelot

# pdfbox

https://github.com/apache/pdfbox


# traprange

https://dzone.com/articles/traprange-method-extract-table

https://github.com/thoqbk/traprange

# convert to html

Adobe Acrobat5 was able to consistently preserve the semantics of table content and translate them into HTML table markup tags, while also preserving the correct structure in almost all the cases. The tool does not provide any batch conversion or command line access, hence the conversion part is manual.

https://arxiv.org/pdf/1901.04672v1.pdf

# look at lines

https://github.com/pymupdf/PyMuPDF/discussions/926


# dbscan for clustering

Pipelines for Procedural Information Extraction from Scientific Literature: Towards Recipes using Machine Learning and Data Science
Huichen Yang, Carlos A. Aguirre, Maria F. De La Torre

k-means requires apriori specifying number of clusters

DBSCan : you don’t have to specify the number of clusters to use it. 

```
To improve MATESC ’s text grouping and section classification, we used the scikit-learn implementation of the
Density-Based Spatial Clustering of Applications with Noise (DBSCAN) 
algorithm to classify spans of text into their corresponding groups based on the euclidean distance between
each span’s metadata features. 

The features included x,y coordinates, font type, and font size of each text span. 

The current limitations of the algorithm include excessive splitting and (less frequently) merging 
due to the unordered clustering nature of the algorithm. Some text groups-spans and
lines-are over-split (under-merged) based on the difference
distance threshold. Future work involves further research in
DBSCAN’s parameter estimation, including fine-tuning of
radius and minimum point thresholds
```

https://arxiv.org/pdf/1912.07747.pdf

https://bitbucket.org/hcyang66/icdar-ost2019/src/master/

# matesc

```
MATESC takes as input text information extracted
using PyMuPDF (Liu et. al, 2018), a tool that
provides metadata features about each character,
including font type, font size and spatial location
relative to each pdf page. The input text is filtered and
cleaned by removing rare Unicode characters and
irrelevant information usually found in the margins of
each document page, using their spatial location.
These include publication identifiers, headers and
footers with page numbers, and watermarks. After the
text is cleaned, our algorithm uses heuristics to merge
each character into its corresponding line, while
considering font and spatial location differences to
differentiate between section titles and section
content. Those lines are then grouped into paragraphs
and ordered, considering single, double and triplecolumn documents in reconstructing a sequential
order
```

```
We get an idea of the structure of each page by
calculating the ratio between each the x coordinate
length and the length of the page without margins.
This ratio allows us to determine the number of
columns in each page (e.g., single, two-column, and
three-column). 

Then, depending on the column, we
use different rules for paragraph ordering. If the page
contains a single column, then we simply order by x.

If it consists of two or three columns, we order
separately by y for those paragraphs that are in the
same x range. Those groups are assigned to a column,
and then those columns are ordered by the x
coordinates of their bounding boxes.
```

https://www.scitepress.org/Papers/2018/69377/69377.pdf

# stackoverflow

https://stackoverflow.com/questions/tagged/pdf-extraction?tab=Votes


# TODO

X-Y cut algorithm

Docstrum algo
https://github.com/chulwoopack/docstrum

https://github.com/chadoliver/cosc428-structor

Frank Lebourgeois, Z Bublinski, and H Emptoz. 1992. A fast and efficient method
for extracting text paragraphs and graphics from unconstrained documents.

Jaekyu Ha, Robert M Haralick, and Ihsin T Phillips. 1995. Recursive XY cut using
bounding boxes of connected components

L. O’Gorman. 1993. The document spectrum for page layout analysis

Anikó Simon, J-C Pret, and A Peter Johnson. 1997. A fast algorithm for bottom-up
document layout analysis. I

