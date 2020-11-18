
# geomancy

Dynamic data layout algorithms are algorithms that dynamically change the location of data in response to performance drop.

placing data is a multi-dimensional knapsack problem [8] where performance changes based upon how data is placed in locations that individually could hold all the data

We approach the layout problem as a online learning problem where the throughput of the system is the reward

stores the raw performance data into the ReplayDB, a SQLite database located outside the target system.

## discovering features

To model the change in throughput, we identified performance values that are correlated with the average I/O
throughput of workloads running on the system. Correlated values (referred to as features) will directly 
influence or change another aspect of the system when the feature changes, and we measure correlation 
using the Pearsons correlation coefficient.

Bel, Chang et al . Geomancy: Automated Performance Enhancement through Data Layout Optimization
https://storageconference.us/2020/Papers/10.Geomancy.pdf

# univistor wang

T. Wang, S. Byna, B. Dong, and H. Tang, “Univistor: Integrated hierarchical and distributed storage for hpc,

# stacker subedi

P. Subedi, P. Davis, S. Duan, S. Klasky, H. Kolla, and M. Parashar, “Stacker: an autonomic data movement engine for extreme-scale data staging-based in-situ workflows,”

# LWPtool

C. Yu, P. Roy, Y. Bai, H. Yang, and X. Liu, “LWPTool: A Lightweight Profiler to Guide Data Layout Optimization

# CAPES Li

Y. Li, K. Chang, O. Bel, E. L. Miller, and D. D. E. Long, “CAPES: Unsupervised storage performance tuning using neural network-based deep reinforcement learning,”

# ASCAR 

Y. Li, X. Lu, E. L. Miller, and D. D. E. Long, “ASCAR: Automating contention management for high-performance storage systems,

