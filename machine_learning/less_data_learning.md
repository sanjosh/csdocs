
# Zero shot

https://www.youtube.com/watch?v=jBnCcr-3bXc

Timothy Hospedales

solve it using semantic transfer from external knowledge source

key idea is to embed each category as vector

output label is not discrete but a vector

learn mapping between embedding and category vector 

how to enforce separability for new category

two algorithm :
1. use regression or classification : given known class category vectors
2. train an energy function : large when data and task match

Energy function is bilinear Ew(x, v) where x is data, v is category vector

train using max margin ranking objective to 

where to get category vectors ?  
1. supervised using taxonomy
2. unsupervised like word token co-occurence

## Issues

### how to handle domain shift

### at test time, we have zero shot learning problem.  

borrow idea from semi-supervised learning (do label propagation)

### use multiple types of category vectors

### do multi-label zero shot

how to annotate rather than classify

addition of vectors like word2vec

### deep zero-shot learning

## application

zero shot domain adaptation (covariate transfer)

drone vision

cross lingual dictionary induction


# One shot

To learn from one image, network must learn a similarity function

siamese network

distance of anchor from positive is much smaller than distance to negative

triplet loss 

choose triplets that are hard to train on : where d(A, P) is almost equal to d(A, N)

Deepface, Facenet

C4W4L04

https://www.youtube.com/watch?v=96b_weTZb2w

https://www.youtube.com/watch?v=d2XB5-tuCWU

# LO Shot learning

dataset distillation

https://arxiv.org/abs/2009.08449

https://www.technologyreview.com/2020/10/16/1010566/ai-machine-learning-with-tiny-data/
