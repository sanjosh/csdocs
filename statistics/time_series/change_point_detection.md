
# Change point

# definition

change in distribution : change in mean and covariance matrix

# algorithms

## DeCon : uses Robust methods

Apply Robust PCA in each time window and determine if newly added time point is outlier
if this occurs for multiple consecutive windows, then distribution has changed

Bulteel, K., Ceulemans, E., Thompson, R., Waugh, C., Gotlib, I., Tuerlinckx, F., & Kuppens, P. (2014). DeCon: A tool to detect emotional concordance in multivariate time series data of emotional responding

## E-divisive : uses euclidean distance

Matteson, D., & James, N. (2014). A nonparametric approach for multiple change point analysis of multivariate data. 

## Multirank : uses rank info

Lung-Yut-Fong, A., Lévy-Leduc, C., & Cappé, O. (2012). Homogeneity and change-point detection tests for multivariate data using rank statistics.

## KCP : uses kernel trick

Arlot, S., Celisse, A., & Harchaoui, Z. (2012). Kernel change-point detection. Retrieved from http://arxiv.org/abs/1202.3878


## ref to paper
 
Cabrieto, detecting correlation changes in multivariate
https://link.springer.com/article/10.3758/s13428-016-0754-9

# Behavioral change point analysis


Gurarie, Andrews, Laidre, A novel method for identifying behavioural changes in animal movement data

The BCPA is robust to gappiness and measurement error,

https://onlinelibrary.wiley.com/doi/abs/10.1111/j.1461-0248.2009.01293.x

http://wiki.cbr.washington.edu/qerm/index.php/Behavioral_Change_Point_Analysis

# Breakout detection 

two types
1. mean shift
2. ramp-up

## EDM

E-Divisive with Medians employs energy statistics to detect divergence in mean.

EDM uses robust statistical metrics, viz., median, and estimates the statistical significance of a breakout through a permutation test.

EDM is non-parametric


https://blog.twitter.com/engineering/en_us/a/2014/breakout-detection-in-the-wild.html

https://github.com/twitter/BreakoutDetection

James, Kejariwal, Leveraging Cloud Data to Mitigate User Experience from ‘Breaking Bad
https://arxiv.org/pdf/1411.7955.pdf

# TODO

https://quantstrattrader.com/2015/01/21/an-introduction-to-change-points-packages-ecp-and-breakoutdetection/


J. Verbesselt, R. Hyndman, G. Newnham, D. Culvenor 
Detecting change within the trend and seasonal components of time series enables the classification 

https://paperswithcode.com/task/change-point-detection

https://techrando.com/2019/08/14/a-brief-introduction-to-change-point-detection-using-python/

https://en.wikipedia.org/wiki/Change_detection

van den Burg, Williams, An Evaluation of Change Point Detection Algorithms
https://arxiv.org/abs/2003.06222

Samaneh Aminikhanghahi and Diane J. Cook, A Survey of Methods for Time Series Change Point Detection
https://www.ncbi.nlm.nih.gov/pmc/articles/PMC5464762

https://pypi.org/project/ruptures/

https://github.com/shunsukeaihara/changefinder
