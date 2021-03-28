
# multi-factor stratified sample

https://stats.stackexchange.com/questions/22662/stratified-sampling-with-multiple-variables

https://en.wikipedia.org/wiki/Sample_size_determination

# Algorithm

https://ec.europa.eu/eurostat/cros/system/files/S7P2.pdf

Optimal allocation algorithm for a multi-way stratification design
Paolo Righi, Piero Demetrio Falorsi

Cochran book 1977

Deville Tille cube method has balancing equation
http://www.math.helsinki.fi/msm/banocoss/Deville_Tille_2004.pdf

Deville, Tille.  Efficient balanced sampling: The cube method

An interesting property of the cube method is that the stratification can be generalised
to overlapping strata, which can be called ‘quota random design’ or ‘cross-stratification’
(Deville, 1991).

Deville, 1991 Theory of quota surveys : unable to download
https://www150.statcan.gc.ca/n1/en/pub/12-001-x/1991002/article/14504-eng.pdf

Build a decision tree

Tille. Sampling algorithms 2006 book

# Is Sampling working

Define an Estimator or Statistic for the Population

https://en.wikipedia.org/wiki/Estimator

The estimator based on the Sample must match observed value for Population :  

Percent suppressions by auditor + Percent reactive suppressions undetected by auditor = Percentage of reactive suppressions in entire population.

* Tester_result = P/F
* Auditor_result = P/F
* Was_Audited = Y/N
* Audit_Mismatch = Y/N
* Was_Suppressed
* Suppress_reason_was_audit_miss

```
 Audited : Audit_mismatch : Suppressed : Suppress_due_to_tester_failure
    N    :                     Y       :   examine sampling strategy
    N    :                     N       :   NA
    Y    :                     Y       :   examine gaps in test plan
    Y    :                     N       :   NA
```


what are the average failures per strata ?

Define estimator - if X perc of Audited tests have no mismatch, then with N confidence interval, we can say..

The Purpose of sampling algorithm is to pick a representative set with high confidence

The metrics defined for the sample must reflect the metrics defined for the entire population.

Sample mean ~ Population mean (IOW, number failed in audit ~ number suppressed in unaudited)

Suppressions in audited apps = Suppressions in non-audited apps

# Metrics

track events which cause disruptions while examining daily metrics or doing retrospective
1. new device was introduced on this date
1. test update
1. disruptions happened on this date

# TOOLS

Jupyter based notebook

Pandas

https://stackoverflow.com/questions/47575265/stratified-random-sampling-with-population-balancing?noredirect=1&lq=1

https://stackoverflow.com/questions/45516424/sklearn-train-test-split-on-pandas-stratify-by-multiple-columns?rq=1


https://stackoverflow.com/questions/44114463/stratified-sampling-in-pandas


https://stackoverflow.com/questions/41035187/stratified-samples-from-pandas?noredirect=1&lq=1

Postgres

ElasticSearch

Apache Spark

Redshift

R - CRAN



