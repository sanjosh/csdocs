
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

# table extraction

1. ocr + opencv
2. horizontal lines
3. text blocks
4. convert to html

# OCR methods

https://nanonets.com/blog/table-extraction-deep-learning/

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

