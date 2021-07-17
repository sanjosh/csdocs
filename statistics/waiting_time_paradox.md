
# Renewal theory

https://en.wikipedia.org/wiki/Renewal_theory#The_inspection_paradox

https://golem.ph.utexas.edu/~distler/blog/archives/002680.html

cases
1. infinite buses
2. multiple lanes for buses

## average waiting time for next train 

`E[W] = E(T^2)/2.E(T)`

https://jakevdp.github.io/blog/2018/09/13/waiting-time-paradox/

if Bus arrival = Poisson process with Lambda = Average arrival rate

and X = waiting time, which follows exp distribution 

then E[X] = 1/Lambda

https://math.stackexchange.com/questions/1434322/exponential-waiting-times-for-bus-arrivals?rq=1

Depends on distribution of bus arrival
https://math.stackexchange.com/questions/52493/average-wait-time-arriving-at-subway-randomly

```
 if you arrive at a random time, you have more opportunities to encounter a longer interval than to encounter a shorter interval. 
 And so it makes sense that the average span of time experienced by riders will be longer than the average span 
 of time between buses, because the longer spans are over-sampled.
```
https://jakevdp.github.io/blog/2018/09/13/waiting-time-paradox/


## average waiting time if k people at stop

Expected waiting time if number of waiting people = k

As you observe the number of people in the queue, you update your distribution of X to form a posterior distribution.

```
E[X | N=k] = n - E[X | N=k ] 
```

https://math.stackexchange.com/questions/339015/when-does-the-next-bus-come

## Expected waiting time if already waited for some time


## Probability of missing bus if previous arrival was seen 

https://math.stackexchange.com/questions/497285/distribution-of-waiting-time-in-bus-station?rq=1

## expected waiting time if Two buses 

https://math.stackexchange.com/questions/1849049/2-trams-are-coming-every-5-and-10-minutes-on-average-how-long-do-i-have-to-wai?rq=1

## expected waiting time if Three buses

https://math.stackexchange.com/questions/654918/3-trams-are-coming-every-10-15-and-15-minutes-on-average-how-long-do-i-have-t

https://math.stackexchange.com/questions/222674/average-bus-waiting-time?rq=1

## probability two buses at same time

https://math.stackexchange.com/questions/311942/probability-of-two-buses-being-in-a-bus-stop-at-the-same-time?rq=1

