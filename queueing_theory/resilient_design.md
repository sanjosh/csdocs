
# Resilient Design 101: Queue Theory

Avishai Ish-Shalom 

https://www.youtube.com/watch?v=zsozsY0GPFQ

UX numbers (at 30 min into talk)

UX powers of 10

Google’s RAIL model

1. Smooth motion perception threshold 20 ms
1. Immediate reaction threshold 100 ms
1. Delay perception threshold 300 ms
1. Focus threshold 1 sec
1. Frustration threshold 10 sec

timeout budgets (at 37 min)

each stage decrements time from budget

# Math of reliability at scale

1. Hot hand fallacy (time 15 min)
1. Gambler’s fallacy
1. base rate fallacy (28 min)

https://www.youtube.com/watch?v=jACAYK63dtg

https://blog.sys-notes.com/presentation/

# The world changed.  Did our designs

https://docs.google.com/presentation/d/1daGaS-zjXwrpfy2OMOluzo4A9tMEpWnNG-RFJqyWioc/edit

# scylladb oct 2020

1. disaster follows tail behaviour  
1. group work latency follows high percentile  
1. customer satisfaction follows high percentile  

kingman formula

backpressure
1. blocking code is example of backpressure
2. executor, async and remote call need explicit backpressure

for low latency
* keep queue small or empty
* apply backpressure
* overprovision

interactive workload : load shedding at back of queue - oldest


