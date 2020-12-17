
## spurious correlation

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

https://www.youtube.com/watch?v=vvTKjm94Ars (Ben Lambert)

## difference cointegration and correlation

correlation : man walks without leash on his dog, but they move in same direction.  distance between them has no actual limit

cointegration : man leashes his dog.  distance between them is finite.

causal : dog pulls man using leash.  path of man follows path of dog.

```
If there exists a relationship between two non-stationary I(1) series, Y and X , 
such that the residuals of the regression are stationary, 
then the variables in question are said to be cointegrated.

for y(t) = b0 + b1.x(t) + u(t)

if y(t) - b0 - b1.x(t) is stationary

then, X and Y are cointegrated.
```

Cointegration
* It is whether the spread between two instruments is stationary (diff in mean is const)
* It applies to long-term properties of time series Correlation

Correlation
* It is whether the two instruments returns move in the same direction
* It is associated with either short-term or long-term properties of time series

correlation without cointegration possible

cointegration without correlation possible

https://www.quora.com/What-is-the-difference-between-correlation-and-cointegration-Is-cointegration-a-good-measure-of-ris

https://www.r-bloggers.com/2017/11/cointegration-correlation-and-log-returns/

## cointegration tests


### ADF augmented dickey fullerson

https://www.youtube.com/watch?v=ea2sxwV6qRs

statsmodels.tsa.stattools.adfuller ( spread (X, Y) )

where spread(X, Y) = Y - hedge_ratio * X

where hedge_ratio = OLS(Y, X).model.params[0] 

### Engle-Granger test 

statsmodel.tsa.statstools.coint

### Johansen test


