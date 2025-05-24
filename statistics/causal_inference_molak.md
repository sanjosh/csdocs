
# book notes Molak causal inference

## confounding variable

hidden factor which drives both the apparent cause and the effect

confounder (high temperature) drives icecream sales and pool accidents

but we assume high icecream sales cause pool accidents

## counterfactuals

## simpson paradoz 

aggregation excludes confounding variable

e.g. women apply to dept with higher acceptance rate, so it seems fewer women admitted across depts

## ladder of causation

association, intervention, counterfactual

## SCM

## correlation metrics 

pearson and spearman cannot capture non-monotonic relationships (e.g quadratic)

use MIC or HSIC for independence testing

## computing counterfactuals

1. abduction
2. modification
3. prediction

(pg 31 bottom brady neal video)

## p-value 

pg 41

## control confounding variable to remove confounding (page 48)

## conditional independence (chap 5)

## causal inference

causal markov condition

## determine conditional independence

chain : A -> B -> C, where A and C dependent if we dont control for B

fork : A <- B -> C, where A and C dependent if we dont control for B

collider : A -> B <- C where A and C dependent if we control for B

Collider helps orient edges in graph

## rough sketch

1. take A, B and C
2. generate 3 datasets for fork, collider and chain
3. fit regression models on each to find best

## MEC Markov equivalence class

## d-separation used to build estimands

## techniques to build causal estimands

1. Back door
2. front door
3. do calculus

## causality works only under some assumptions

positivity 

exchangeability

##  code

```
model = CausalModel(
      data=df,
      treatment='X',
      outcome='Y',
      effect_modifiers='...',
      graph=gml_string
      )

estimand = model.identify_effect()

refute_subset = model.refute_estimate(
       estimand=estimand, 
       estimate=estimate,
       method_name="data_subset_refuter"
      )

estimate = model.estimate_effect(
      identified_estimand=estimand,
      method_name='...'
      )

to predict

model.causal_estimator.effect

```

## Models

SLearner
TLearner
XLearner
DRLearner
LinearDML
CausalForestDML
   
