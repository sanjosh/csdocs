
# outbreak modeling

outbreak has a characteristic shape 

single wave outbreaks tend to have a characteristic shape (bell-shaped)

## basic reproduction number R0

number of cases arising from each primary case

R0 = (beta).N x (1/gamma) = infection rate x duration of infection

R0 below 1 = no outbreak = parallel to x-axis

## Herd immunity

resistance to spread of disease because high percentage are immune

## simplest model 

geometric progression.  each case gives rise to N new cases every day

## compartmental modeling (SI model)

divide people in susceptible and infected

S -> R

equations for rate of change

1. dS/dt = (-beta).S.I = rate of change of susceptible
2. dI/dt = (beta).S.I  = rate of change of infected

overall rate of new infections depends on S.I

## capture decline (SIR model)

SIR where R = recovered

S -> I -> R

1. dS/dt = (-beta).S.I = rate of change of susceptible
2. dI/dt = (beta).S.I - (gamma).I = rate of change of infected
3. dR/dt = (gamma).I = rate of change of recovered

parameters
1. beta = rate of infection
2. gamma = rate of recovery, 
3. average infectious period = 1/gamma

assumptions
1. individuals are immediately infectious after infection
2. everyone mixes with everyone else.

## SEIR model which incorporates quarantine

lets say you are asked to
1. stay home for 7 days if infected
2. stay home for 14 days if someone in house is infected

add category E = infected but not generating infections 

S -> E -> I -> R

## model with age structure incorporated

1. same age contacts
2. contacts between parents and children 

Divide SIR into two 
1. children : Sc -> Ic -> Rc
2. adults : Sa -> Ia -> Ra

parameters are extended too (GammaAdult) and (GammaChildren)

## SIAR model which incorporate asymptotic transmission

Add class A = asymptotic (transmissing but not showing)

## spatial structure (population density + travel between regions)

Have Per region SIR model

Show individuals moving between regions at rate Lambda

Account for population density using total number of individuals

## epidemic risk (probability that imported case leads to epidemic in new location)

Higher R0 = higher epidemic risk

solutions
1. find imported cases and isolate them (reduce infection rate)
2. social distancing (reduce infection rate; stay below hospital capacity)
3. quarantine (reduce infection rate)

if outbreak is ongoing, 
1. estimate model parameters, 
2. forecast 
3. define possible interventions

Model : S -> E -> U -> I -> R

where
1. U = dry symptoms
2. I = wet symptoms

## end of outbreak

time after final symptomatic case ?

how likely is it that outbreak is over if no case is seen in N days ?

SAIR model

# Reference

1. Robin Thompson Oxford public lecture https://www.youtube.com/watch?v=m6Hr69JH_wA
