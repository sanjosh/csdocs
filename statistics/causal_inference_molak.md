
# book Molak causal inference

# estimand

causal quantity you want to estimate.

The average treatment effect (ATE) — the difference in recovery time if everyone took the drug vs if no one did.

types of estimands:

Each of these is a different estimand depending on the causal question.

## ATE (Average treatment effect) 

E[Y(1) - Y(0)] - average effect of treatment vs no treatment

## ATT (Average Treatment effect on the Treated group)

E[Y(1) - Y(0) | T = 1] 

## CATE (Conditional ATE)	

Effect conditioned on covariates: E[Y(1) - Y(0) | X]

## ITT (Intention to Treat)	

# confounding variable

hidden factor which drives both the apparent cause and the effect

confounder (high temperature) drives icecream sales and pool accidents

but we assume high icecream sales cause pool accidents


# simpson paradoz 

aggregation excludes confounding variable

e.g. women apply to dept with higher acceptance rate, so it seems fewer women admitted across depts

# ladder of causation

association, intervention, counterfactual

# SCM structural causal models

# correlation metrics 

pearson and spearman cannot capture non-monotonic relationships (e.g quadratic)

use MIC or HSIC for independence testing

# counterfactuals

## computing counterfactuals

1. abduction
2. modification
3. prediction

(pg 31 bottom brady neal video)

# p-value 

pg 41 of molak

## control confounding variable to remove confounding (page 48)

# conditional independence (chap 5)

# causal inference

causal markov condition

# determine conditional independence

chain : A -> B -> C, where A and C dependent if we dont control for B

fork : A <- B -> C, where A and C dependent if we dont control for B

collider : A -> B <- C where A and C dependent if we control for B

Collider helps orient edges in graph

# rough sketch

1. take A, B and C
2. generate 3 datasets for fork, collider and chain
3. fit regression models on each to find best

# MEC Markov equivalence class

# d-separation used to build estimands

# techniques to build causal estimands

1. Back door
2. front door
3. do calculus

# causality works only under some assumptions

positivity 

exchangeability

#  code

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


# Meta-Learners

(from gemini)

meta-learners provide a framework for using any standard supervised model to solve a causal inference problem. 

the goal is to estimate the Conditional Average Treatment Effect (CATE), which is the expected effect of a treatment for an individual with a specific set of characteristics (features).

1. S-Learner
2. T-Learner
3. X-Learner
3. DR-Learner
4. LinearDML
5. CausalForestDML


## S-learner (or "single-learner") 

trains a single machine learning model, treating the intervention status as a regular feature. 

## T-learner (or "two-learner") 

trains two independent models: one for the group that received the treatment and one for the group that did not

## X-learner

## DR-learner (Doubly robust)

## Double Machine Learning (DML)

(also known as Debiased or Orthogonal Machine Learning) is a two-stage framework designed to solve for multiple confounders

The core idea is to "clean" both the outcome and the treatment variables of any influence from the confounders before estimating the causal effect.

two stage process

Stage 1: Model the Nuisance Functions. Use flexible machine learning models to predict the outcome (Y) from the confounders (W) and the treatment (T) from the confounders (W).
Stage 2: Estimate the Causal Effect on Residuals. Calculate the "residuals" (the parts of the outcome and treatment not explained by the confounders) and then model the relationship between them to get a clean, unbiased estimate of the treatment effect.


## LinearDML

Combines the flexibility of machine learning (to handle complex confounders) with the statistical rigor and interpretability of linear models (for the final causal estimate)

### Example:
A company wants to estimate the effect of a discount (T) on sales (Y).

1. Confounders (W): A user's extensive Browse history, past purchases, and device type (high-dimensional and complex).
2. Heterogeneity Features (X): The user's income and account age.
3. Hypothesis: The discount's effectiveness is different for users with different incomes, and this relationship is roughly linear (e.g., for every $10k increase in income, the sales lift from the discount increases by $0.50).

In this scenario, LinearDML would be an excellent choice. It would use a powerful ML model to control for the complex Browse history and then estimate an interpretable linear formula for how the discount effect changes with income and account age.

## CausalForestDML

use `EconML` package

CausalForestDML = DML + Causal Forest

### Causal Forest

(Susan Athey and Guido Imbens) 

adaptation of the popular Random Forest algorithm specifically for estimating heterogeneous treatment effects. 

Instead of building decision trees that minimize prediction error for the outcome, a Causal Forest builds trees that maximize the difference in the treatment effect across different groups. 

The final estimate for an individual is an average of the estimates from all the trees in the forest. 

Effective at uncovering complex patterns in how treatment effects vary across a population
