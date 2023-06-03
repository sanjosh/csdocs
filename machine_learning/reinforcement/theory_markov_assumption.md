
# if process is non-Markov, that breaks assumption for RL 

https://ai.stackexchange.com/questions/18542/how-is-the-markovian-property-consistent-in-reinforcement-learning-based-schedul


## Reinforcement learning of non-Markov decision processes

Steven D.Whitehead a**, Long-Ji Lin

```
These non-Markov tasks are commonly referred to as hidden state tasks, since they 
occur whenever it is possible for a relevant piece of information to be hidden 
(or missing) from the agent’s representation of the current situation


This article examines two general approaches to extending reinforcement learning to hidden
state tasks. 

The Consistent Representation (CR) Method unifies recent approaches such as the Lion
algorithm, the G-algorithm, and CS-QL. The method is useful for learning tasks that require the
agent to control its sensory inputs. However, it assumes that, by appropriate control of perception,
the external states can be identified at each point in time from the immediate sensory inputs. 

A second, more general set of algorithms in which the agent maintains internal state over time is
also considered. These stored-state algorithms, though quite different in detail, share the common
feature that each derives its internal representation by combining immediate sensory inputs with
internal state which is maintained over time. 
```

## reward measure can be different

In principle, any number of reward measures can be used

the most prevalent measure is one based on a discounted sum of the reward received over time (multiply by gamma power )
