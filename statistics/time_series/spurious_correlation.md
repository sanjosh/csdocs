
Spurious means that there is some hidden (confounding) variable which causes both of the variables.

non-stationary series lead to spurious correlation (e.g. weight has a trend, do not compare my weight till age X versus your weight till age X)

spurious because within-series dependence is not removed

smoothing worsens the spurious correlation

to avoid the spurious correlation problem, regress two stationary time series against one another. 

https://stats.stackexchange.com/questions/8185/correlation-terminology-in-time-series-analysis

https://stats.stackexchange.com/questions/133155/how-to-use-pearson-correlation-correctly-with-time-series

Yule, G.U. (1926) "Why do we Sometimes get Nonsense-Correlations between Time-Series?" J.Roy.Stat.Soc., 89, 1, pp. 1-63

## cointegrated series

https://en.wikipedia.org/wiki/Cointegration

if two series are integrated to different orders, linear combinations of them will be integrated to the higher of the two orders.

But it is possible that certain combinations of those nonstationary series are stationary. Then pair x(t), y(t) is said to be cointegrated.

Cointegration implies that these pairs of variables have similar stochastic trends.

e.g. disposable income and consumption, govt spending and tax revenue

http://sfb649.wiwi.hu-berlin.de/fedc_homepage/xplore/tutorials/xegbohtmlnode40.html

https://en.wikipedia.org/wiki/Order_of_integration
