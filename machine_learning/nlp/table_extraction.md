
# TREX is table recognition and extraction

Web Table Extraction, Retrieval, and Augmentation: A Survey

Annotating and Searching Web Tables Using Entities, Types and Relationships
https://www.cse.iitb.ac.in/~sunita/papers/vldb2010.pdf

Current Status and Performance Analysis of Table Recognition in Document Images with Deep Neural Networks
KHURRAM AZEEM HASHMI
https://arxiv.org/pdf/2104.14272v1.pdf

Deep Neural Networks and Tabular Data: A Survey
https://arxiv.org/pdf/2110.01889.pdf

Göbel, M., Hassan, T., Oro, E., Orsi, G.: A Methodology for Evaluating Algorithms for Table Understanding in PDF Documents, DocEng 2012

Shahab, A., Shafait, F., Kieninger, T., and Dengel, A.: An open approach towards the benchmarking of table structure recognition systems, DAS 2010

Oro, E., Ruffolo, M.: PDF-TREX: An approach for recognizing and extracting tables from PDF documents, ICDAR 2009

Silva, A.C.: Learning rich hidden markov models in document analysis: Table location, ICDAR 2009

Krüpl, B., Herzog, M.: Visually guided bottom-up table detection and segmentation in web documents, WWW 2006

# TaPas (table transformer)

https://huggingface.co/transformers/model_doc/tapas.html

# evaluating algorithms for table understanding

A Methodology for Evaluating Algorithms for Table Understanding in PDF Documents

https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.1052.2572&rep=rep1&type=pdf

# MXY tree

Tree clustering for layout-based document image retrieval Simone Marinai, Emanuele Marino, Giovanni Soda
http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.157.3677&rep=rep1&type=pdf

```
The MXY tree nodes
contain symbolic attributes describing the purpose of the
node. In particular, internal nodes represent the cut strategy considered (we can have horizontal/vertical cuts along
either spaces or lines), whereas leaves correspond to homogeneous blocks in the page (text, image, horizontal/vertical
line). The MXY tree data structure is encoded into a fixedsize feature vector by taking into account occurrences of
tree-patterns made by three nodes [3]. Trees composed of
three nodes can have two basic structures. The first pattern has the root and two children and is called balanced
tree-pattern. The second pattern is made by the root, one
child, and a child of the second node and is called chain
tree-pattern (see Figure 2 as an example).
```

Cesarini

# PDF-TREX (clustering)

lines 

The lines tagging step assigns to each line a tag: text line (TxL), table line (TbL), unknown line (UnL). 

To construct blocks the same agglomerative hierarchical clustering algorithm [4] adopted for constructing segments is used. 

Columns are built by using vertical overlapping ratio among segments and distances among columns contained in table areas.

# opencv-based

## table ocr

https://github.com/eihli/image-table-ocr

## soumi

https://github.com/Soumi7/Table_Data_Extraction/blob/main/medium_table.ipynb

## another

https://github.com/officialsiddharthchauhan/Table-Detection-in-a-Image/blob/master/table-detect.py.py

## box-detect

https://pypi.org/project/boxdetect/


# Deep learning

## DeepDeSRT

DeepDeSRT: Deep Learning for Detection and Structure Recognition of Tables in Document Images

https://www.dfki.de/fileadmin/user_upload/import/9672_PID4966073.pdf

## HybridTabNet

```
Instead of conventional convolutions, Siddiqui et al. [7] employed deformable convolutions 
to detect tables in document images. The authors empirically established that the dynamic receptive 
field of deformable convolutions adapted better in detecting tabular boundaries with arbitrary layouts
```

```
Convolutional Networks [55] have been very successful over the past years on applications, 
including object detection and segmentation [56,57,58]. However, they cannot model complex geometric 
transformations due to their fixed kernel size. Deformable convolutional layers [21] were 
introduced to overcome this limitation. The intuition behind deformable convolutional layers is to 
add 2D offsets at regular grid sampling positions in the standard convolution operation, 
which deforms the constant receptive field of the preceding activation unit.
The added offsets are learnable from the preceding feature maps. The receptive fields of the 
deformable layers are adaptive, which changes according to the scale of the object, and 
this allows the capture of objects at different scales [21]. The deformable layers use the same 
number of learnable parameters as convolutional layers, but exploit a much larger receptive field. 
This makes the performance of deformable layer s superior to that of convolutional layers [21].
```

https://www.mdpi.com/2076-3417/11/18/8396/htm

## cascadeTabNet

https://github.com/DevashishPrasad/CascadeTabNet

## TableNet

https://arxiv.org/pdf/2001.01469v1.pdf

## MMDetection customized

https://github.com/open-mmlab/mmdetection

MMOCR https://github.com/open-mmlab/mmocr

## aws textract

https://www.crosstab.io/articles/amazon-textract-review

## google form parser

# Datasets

## PubTables dataset

https://paperswithcode.com/dataset/pubtables-1m

## ICDAR

ICDAR 2013 dataset 150 tables: 75 tables in 27 excerpts from the EU and 75 tables in 40 excerpts from the US Government.
https://www.tamirhassan.com/html/dataset.html

## ICDAR 2017

2417 images in total,

## ICDAR 2019


## TableBank

 417,000 document image

## UNLV

only 427 of them contain tables.

## marmot table

, ICDAR-17 POD, ICDAR-19, TableBank, Marmot, and UNLV
