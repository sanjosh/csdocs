
Speaker diarization

It generally answers to the question ”Who spoke when?” and it is divided in two modules: 
1. speaker segmentation 
2. speaker clustering. 

speaker segmentation is finding the times when there is a change of speaker in the audio stream. 

Speaker clustering consists in merging speech segments, detected by the speaker segmentation step, related to a same speaker.

=========

Speaker Clustering Based on Bayesian Information Criterion
WEI-HO TSAI 


https://pdfs.semanticscholar.org/5d6c/2f91c6199ed268b29434ec184ecf5990f71f.pdf

=========


Robust Unsupervised Speaker Segmentation for Audio Diarization

Hachem Kadri, Manuel Davy and Noureddine Ellouze 

Recent research on audio segmentation mostly focused on four categories: 

1. energy based
2. model-based (Kemp et al., 2000), 
2. metric-based (Delacourt and Wellekens, 2000), 
3. information criterion-based approaches (Cettolo and Federico, 2000; Cettolo and Vescovi, 2003; Chen and Gopalakrishnan, 1998). 

Energy audio segmentation only detects change-points at silence segments, which generally are not directly connected with the acoustic changes of the audio signals. 

Model-based segmentation approach requires predefined audio classes and complete training data. 

The metric-based approach are not stable and need thresholds generally selected from experiments results. 

The information criterion-based scheme are proposed for evaluating models constructed by various estimation procedures when the specified family of probability distributions does not contain the distribution generating the data. 

The so-called Delta Bayesian information criterion (BIC) segmentation algorithm is widely employed in many studies (Chen and Gopalakrishnan, 1998).  The BIC is intended to provide a measure of the weight of evidence favoring one model over another.  According to previous research, the Delta-BIC is threshold-free and suitable for unknown acoustic conditions.  However, this method, extremely computationally expensive, can introduce an estimation error due to insufficient data when the speaker turns are close to each other (Chen and Gopalakrishnan, 1998; Huang and Hansen, 2004). 

In order to minimize these effects, Delacourt and Wellekens (2000) tested different metric criteria to associate them to the BIC criterion such as the Kullbach-Leibler distance, the similarity measure and the Generalized Likelihood Ratio measure (GLR). Still, this method encountered problems in case of short segments and requires also a high computation cost. On another issue, Zhou and Hansen (2000) recommend the use of the T 2 −Statistic for metric-based segmentation in the aim to reduce this computation cost.  However its technique, T 2 −BIC, depends on many empiric parameters which affect the quality of the detection of speaker turns. 

In our previous work (Kadri et al., 2006), we developed a hybrid segmentation algorithm called DIS T 2 BIC to improve the detection of speaker turns close to each others using a fixed threshold independent of the type of the audio stream with a low computation cost. Never- theless all of these techniques suppose that the audio signal don’t contains different acoustic changes and simultaneous speeches of two or more speakers and then find difficulties in segmenting streams containing background noise and overlapped speeches.


==========

https://github.com/wblgers/py_speech_seg

========

Tritschler and Gopinnath proposed the use of the Bayesian Information Criterion (BIC) over mel-cepstrum coefficients (MFCCs) [4]. 

Delacourt and Wellekens proposed a new twopass segmentation technique called DISTBIC and improved performance by utilizing distance-based segmentation before applying the BIC [2]. 

Ajmera et al introduced an alternative of the BIC which does not need tuning, and some heuristics [3]. 

Meanwhile, novel features like the smoothed zero crossing rate (SZCR), the perceptual minimum variance distortionless response (PMVDR), and the filterbank log coefficients (FBLC) were introduced by Huang and Hansen [10]. 

Another method is the so-called METRIC-SEQDAC [9]. 

Finally, a hybrid algorithm was proposed, which combines metric-based segmentation with the BIC criterion and model-based segmentation with Hidden Markov Models (HMMs) [7]

Margarita Kotti


https://dl.acm.org/citation.cfm?id=1343216

=======

Ajmera
https://publications.idiap.ch/downloads/reports/2004/rr04-35.pdf

===========


http://rvlasveld.github.io/blog/2013/07/12/introduction-to-one-class-support-vector-machines/

Zhenhao Ge, et al Speaker change detection using features through a neural network speaker classifier

