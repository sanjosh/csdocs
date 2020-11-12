
# Diagram

from https://github.com/LahiruJayasinghe/PresentationSlides/blob/master/sparse_coding_and_dictionary_learning.pdf

# Sparse coding

Sparse coding is a technique for discovering a small number of “representatives” that can be used to reconstruct the original high-dimensional signal. In the linear generative model of sparse coding, given a set of k-dimensional vectors in a (possibly high-dimensional) real space, the goal of sparse coding is to find some number of basis vectors in addition to a sparse weight vector such that the linear combination of the basis vectors and the weight vector closely approximate the input vectors. (Note: there are other techniques for performing sparse coding."

"A distinguishing feature of sparse coding from other dimensionality reduction procedures (e.g. principal components analysis, singular value decomposition, etc.) is that the number of bases can exceed the input dimension"

https://earlbellinger.wordpress.com/2013/12/15/sparse-coding/

# Dictionary learning

"The so-called dictionary based methods (DBM) decompose a signal into a linear combination of waveforms through an approximation technique such as Matching Pursuit (MP) [Mallat1993], Orthogonal Matching Pursuit (OMP) [Pati1993], or basis pursuit [Chen2001]. The collection of waveforms that can be selected for the linear combination is called a dictionary. This dictionary is usually overcomplete, either because it is formed by merging complete dictionaries or because the waveforms are chosen arbitrarily (and we have more waveforms than the length of the signal we want to represent)."

http://www.seaandsailor.com/dictlearning.html

# Audio classification using dictionary learning

1. Wei, Real-time Classification via Sparse Representation in Acoustic Sensor Networks (http://www.cse.unsw.edu.au/~wenh/wei_sensys13.pdf
2. Zhang, Sparse Coding for Sound Event Classification (http://www.apsipa.org/proceedings_2013/papers/240_Sparse-Coding-Zhang-2942265.pdf)
3. Zubair, Audio Classification Based on Sparse Coefficients   (https://pdfs.semanticscholar.org/24fc/acb1e2204641a4d97d41dceb785f61e5ddc7.pdf)
4. Sturm, Analysis, visualization, and transformation of audio signals using dictionary-based method (https://static1.squarespace.com/static/5ad03308fcf7fd547b82eaf7/t/5b75a1e4032be48141d93eba/1534435822633/ICMC_08_final.pdf)

# Image classification using dictionary learning

https://github.com/ektormak/Lyssandra

Wright.  Robust Face Recognition via Sparse Representation.  (http://www.columbia.edu/~jw2966/papers/WYGSM09-PAMI.pdf)

# Learning resources

https://github.com/LahiruJayasinghe/PresentationSlides/blob/master/sparse_coding_and_dictionary_learning.pdf
https://en.wikipedia.org/wiki/K-SVD

# Code

## scikit

1. https://scikit-learn.org/stable/modules/generated/sklearn.decomposition.DictionaryLearning.html
2. https://scikit-learn.org/stable/modules/generated/sklearn.decomposition.SparseCoder.html

## others

1. https://github.com/fubel/sparselandtools (python library for sparse representations and dictionary learning.)
2. https://github.com/pirofti/ksvd_reg (k-svd algo)
3. https://github.com/DavideNardone/Greedy-Adaptive-Dictionary (find sparse atoms in speech signal)
4. https://pypi.org/project/ksvd/
