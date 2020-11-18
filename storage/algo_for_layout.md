
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

model-less deep reinforcement learningbased unsupervised parameter tuning system driven by a deep neural network (DNN).

Q-learning for throughput of Lustre storage system
    
Theoretically, automatic dynamic parameter tuning can be constructed as a Decentralized Partially Observable Markov Decision Process (POMDP), 
and Bernstein et al. have proven that it is a NEXPhard problem

Credit assigment problem : decide which modification caused improvement

## choosing performance indicators

Nonnumerical statuses, such as which I/O scheduler the system is using and what power status the system is in, should be converted into numerical values, such as 0, 1, or 2. Examples of such could be 0 for a round robin scheduler or 1 for a lottery scheduler.

System statuses that are accumulative in nature should generally be excluded unless they are known to be related to system performance. Such accumulative statuses include system uptime, total sent/received bytes over the network, total read/write bytes of I/O devices, etc.

Date and time should also be included if the workload is known to be cyclical

After performing each action on the target system, CAPES measures an immediate reward. For instance, after changing the congestion window size, we can measure the change of I/O throughput at the next second to use it as the reward. 

At a fixed rate (every action tick), CAPES decides on an action that either increases or decreases one parameter by a step size. The valid range and tuning step size are customizable for each target system

https://www.ssrc.ucsc.edu/media/pubs/ea175a9f07f9f172005c62cf0514051fa08ff0f1.pdf

https://github.com/mlogic/capes-oss

Y. Li, K. Chang, O. Bel, E. L. Miller, and D. D. E. Long, “CAPES: Unsupervised storage performance tuning using neural network-based deep reinforcement learning,”

# ASCAR 

Y. Li, X. Lu, E. L. Miller, and D. D. E. Long, “ASCAR: Automating contention management for high-performance storage systems,

# Zhang

F. Zhang, J. Cao, L. Liu, and C. Wu. 2011. Performance improvement of distributed systems by autotuning of the conguration parameters.

# Chen

Haifeng Chen, Guofei Jiang, Hui Zhang, and Kenji Yoshihira. 2009. Boosting the Performance of Computing Systems Through Adaptive Conguration Tuning

# Zheng

Wei Zheng, Ricardo Bianchini, and Thu D. Nguyen. 2007. Automatic Conguration of Internet Services

