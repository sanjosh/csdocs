
Dynamic Load Balancing for Distributed Memory Multiprocessors - Cybenko

Journal of Parallel and Distributed Computing - 7 (1989)

http://www.dartmouth.edu/~gvc/Cybenko_JPDP.pdf

```
Work_i(t+1) = Work_i(t) + 
  Sum_all_processors_j ( Alpha_ij * (Work_j(t) - Work_i(t))) + 
  Theta_i(t+1) -
  c

Alpha_ij = non-neg const = 0 if i and j not connected
Work_i(t) = num tasks done by proc i at time t
Theta_i(t+1) = new work generated at time t+1
c = constant amount of work any proc can do between [t, t+1]
```

 ----------

Optimal migration algo for dynamic load balancing - Hu Blake Emerson
Daresbury

Analogous to diffusion process where initial uneven temp drives movement of heat and eventually reaches equilibrium

http://yifanhu.net/PUB/concurrency98.pdf

