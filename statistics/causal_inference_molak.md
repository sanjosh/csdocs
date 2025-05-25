
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

1. SLearner
2. TLearner
3. XLearner
3. DRLearner
4. LinearDML
5. CausalForestDML

# Algorithms to find causality

## Assumption based (structural causal models)

You specify the causal graph based on domain knowledge. then
1. Use do-calculus and backdoor/frontdoor criteria to identify causal effects.
2. Apply statistical methods (e.g., regression, matching, IPW) to estimate the effects.

### frontdoor (mediator)

Use this when confounders are unobserved, but mediator exists

If you can't block confounding directly, use a mediator that carries the causal effect

example
```
U -> X -> Z -> Y
U -> Y
```

U is an unobserved confounder between X and Y

But if you observe the mediator Z is affected only by X and Fully transmits the causal effect

You can recover the effect of X -> Y via Z


### backdoor (confounder is known)

Use this when you can observe confounders

Use backdoor adjustment to block confounding

A backdoor path is a non-causal path from X to Y that starts with an arrow into X and can create spurious associations. (e.g. Z -> X -> Y)

Find a set of variables Z that Blocks all backdoor paths from X to Y

Does not include any descendants of X

then estimate the causal effect of conditional on Z

### interventions

You simulate interventions with do-notation:
```
do(X=x): force X to value x (as in a randomized trial)
```

## data driven discovery

learn structure of graph from data without interventions.
1. PC Peter-Clark uses conditional independence tests
2. GES
3. LiNGAM assumes linear, non-Gaussian
4. NOTEARS
5. IDA
6. Invariant Causal Prediction
7. Interventional Methods


### Peter-Clark method


1. Start with a fully connected undirected graph 
2. Use conditional independence tests to remove edges
3. Orient edges using rules (e.g., v-structure detection)
4. Apply additional rules (e.g., Meek’s rules) to orient as much of the graph as possible.


### LiNGAM (Linear Non-Gaussian Acyclic Model)

Assume each variable is a linear function of its direct causes plus non-Gaussian noise.

Use Independent Component Analysis (ICA) to find the mixing matrix and noise components.

Use matrix decomposition to recover the causal ordering and structure.

See `lingam` package
