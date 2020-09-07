
# Dividing capacity between multiple clients with different job timeouts

1. TPS of the Service is known.   
2. Each client expects a submitted job to be completed within a fixed time (Max timeout).   
3. Load is not constant but on-demand.

Since each client has a max timeout, we have to limit the number of pending jobs in the system.  This means Max Queue length needs to be calculated and enforced.  

Since each client has a different timeout, you cannot mix their jobs in the same queue, otherwise you will have head-of-the-line blocking.   So each client gets a different queue.    

The ratio in which each queue is serviced needs to be calculated

| Client |  Max timeout | max queue length | ratio of servicing queues |
| -----: |  -------:    | ------------:    | --------------:           |
|  C1    |  T1          |   L1             |  1
|  C2    |  T2          |   L2             | x2.  This is fraction between 0 and 1.  Decides how many Client_2 jobs will be serviced for every Client_1 job.   |
|  C3    |  T3          |   L3             | x2.x3  This is fraction between 0 and 1.  Decides how many Client_3 jobs will be serviced for every Client_2 job |


the ratio (1 : x2 : x3) is ratio in which jobs picked from (C1 : C3 : c3) queues

* C1 : 1
* C2 : x2
* C3 : x2.x3

*Homogeneity assumption* : Each job takes same time irrespective of client

Given TPS, T1, T2 and T3

We have to calculate L1, L2, L3 and x2, x3

L2 = x2.L1 ; since x2 jobs of L2 will get serviced with each job of L1

L3 = x3.L2 ; since x3 jobs of L3 will get serviced with each job of L2

By Little’s law, Number of jobs = TPS x Timeout

*How many jobs will get serviced within T1 ? All jobs from C1 and some jobs from C2 and C3.*

L1 + x2.L1 + x2.x3.L1 = TPS . T1

L1 (1 + x2 + x2.x3) = TPS . T1

*How many jobs will get serviced within T2 ?*

L2 + L2/x2 + L2.x3 = TPS . T2

L2 ( 1 + x2 + x2.x3) = TPS . T2 . x2

*How many jobs will get serviced within T3 ?*

L3 + L3/x3 + L3/x2.x3 = TPS . T3

L3 (1. + x2 + x2.x3) = TPS . T3 . x2.x3

The number of equations is less than number of variables, so we have to fix some variables

*Lets fix the ratio in which we service different clients/queues*

Let x2 = 1/2 and x3 = 1/2

now we can replace these in above equations and solve for L1, L2 and L3

Max queue length L_k is directly proportional to the combination of (max timeout, priority)
