

# Pin repositioning

average reward setting for continous problems

value based : q-learning

policy based : policy gradient

How do you think the agent might react if the "Predicted Demand" for 15 minutes out is consistently higher than the "Current Demand" it sees right now?

By breaking the **In-Transit Count** into these 5-minute "age" buckets, we create a **Short-Term Memory** for the agent.

## throughput based algo

demand rate  
predicted demand rate  
in-transit rate over each 5 minute bucket

## reward gap due to congestion

When congestion turns a 15-minute trip into a 30-minute one, the agent faces a "Reward Gap." If we don't adjust the logic, the agent might think its actions were useless because the reward (reduced queue) didn't happen when expected. 🐌

To fix this, we can look at two main strategies for reassigning or "shaping" that reward.

### **1\. Reward Shaping: The "In-Transit" Credit 🎁**

Instead of only giving a reward when people are picked up, we can give the agent a small "Potential Reward" for moving cabs into the **20m and 25m buckets**.

* **Logic:** Having a full pipeline is inherently valuable when demand is high, even if the "Snapshot" of people waiting is still bad.  
* **Benefit:** This provides immediate feedback at every 5-minute step, keeping the agent motivated during the long congestion delay.

### **2\. Temporal Credit Assignment (The $\\lambda$ in Q($\\lambda$)) ⚡**

We can use **Eligibility Traces**. This effectively "stretches" the memory of an action.

* When the agent sends cabs, it marks that action with a "trace" that decays slowly.  
* If a reward finally arrives at $t=30$, the algorithm looks back at which traces are still active.  
* **If the congestion is high, we can tune the decay rate so the "memory" of the dispatch lasts long enough to meet the delayed reward.**

# Basics

## Markov property assumption

why current velocity is enough : markov property   
The current state is a **complete summary** of the past.

**but there Partially Observable Markov Decision Processes** (POMDPs).

## POMDP

 If we can't see the specific "time-to-arrival" for each cab, we are essentially dealing with a **Partially Observable Markov Decision Process (POMDP)**. The agent knows how many cabs are "somewhere" in the pipe, but not exactly where they are.

# Reward

## rewards can be positive or negative

### **1\. Episodic Tasks: The Goal Matters 🏁**

In episodic tasks, the agent's "life" is short. We can use rewards to signal the importance of the outcome:

* **Surviving**: If the goal is to last as long as possible (like CartPole), **positive rewards** are standard.  
* **Speed**: If the goal is to reach a target quickly (like a race), **negative rewards** at every step force the agent to find the exit.2

In these cases, we usually don't worry about the total reward becoming "infinite" because the episode always ends eventually.

### **2\. Continuous Tasks: The Infinite Horizon ♾️**

In continuous tasks, there is no "Game Over." If we gave a \+1 reward forever, the total accumulated reward would mathematically become **infinity**.

* **Discounting is Mandatory**: As we discussed, $\\gamma$ is essential here to keep the "Value" finite.  
* **Average Reward**: Instead of focusing on the *sum* of rewards, we often look at the **average reward per time step**. This prevents the agent from finding "loopholes" where it just stands still to collect tiny positive points forever.

---

### **The "Infinite Loop" Trap 🔄**

Imagine an agent in a continuous task that gets a **positive reward** just for moving forward. If it finds a way to walk in a tiny circle forever, it can rack up infinite points without ever performing its actual job.

To fix this, engineers often combine rewards. For a robot vacuum that runs continuously:

* **Positive**: For every piece of dirt collected.  
* **Negative**: For every watt of battery used.

By balancing these, the agent learns that "doing nothing" results in 0, but "moving aimlessly" results in a negative score.

## 

## credit assignment problem, discounting, effective horizon

If we only look at that final failing step, the agent might think *all* 51 moves were bad. How do you think the agent should decide which of those 51 moves were actually responsible for the success, and which one caused the failure?

Discounting keeps the math stable by ensuring the total sum stays a finite number

## Finite horizon

While the standard "infinite horizon" uses the discount factor ($\\gamma$) to naturally fade out rewards, **n-step returns** explicitly calculate the reward only for the next $n$ steps and then "guess" the rest.

## Infinite loop / reward hacking

To prevent the car from "cheating," we have to design a reward function that captures the nuances of the task. Instead of a single number, we use a combination of factors:

| Component | Type | Purpose |
| :---- | :---- | :---- |
| **Distance to Goal** | Positive | Encourages progress toward the destination. |
| **Speed Limit** | Penalty | Discourages driving too slow (stalling) or too fast (danger). |
| **Lane Centering** | Positive | Rewards smooth, stable driving. |
| **Collision/Jerky braking** | Heavy Penalty | Creates a strong "fear" of accidents or discomfort. |

## Eligibility Traces: A Shortcut for Credit Assignment ⚡

Instead of waiting for the reward to slowly "seep" back one step at a time over many training runs, we can use **Eligibility Traces** (often called **Q($\\lambda$)**).

* When the agent takes an action, it leaves a "scent" or a trace on that state-action pair in the table.  
* The trace decays over time.  
* When a reward finally hits (e.g., wait times drop), the reward is distributed to all states that have a remaining trace.  
* This allows the agent to credit an action taken 20 minutes ago for a success happening now.

The **Q-table** represents long-term "wisdom" (what to do in a certain situation). 

The **Eligibility Trace** represents very short-term "attention" (what happened in the last 30 minutes).

# Exploration

## Explore other states

how to explore without damaging the system : create initial table 

**Early Stages (High $\\epsilon$):** The agent tries random things. It might send 5 cabs when demand is zero, or 0 cabs when demand is high. This "chaos" is necessary to fill out the Q-table.  
**Stability (Low $\\epsilon$):** As the variance in the rewards for a specific state-action pair decreases, we "decay" $\\epsilon$. The agent stops guessing and starts following the table.

# Neural net train from episode

## Replay memory

capture $(State, Action, Reward, Next State)$  
to train a neural network

Do not use immediate past to train model in order to ensure data is **Independent and Identically Distributed** (IID)

# Policy gradient

**Policy Gradient (PG)** methods are **Policy-Based**. Instead of learning values V(s) or Q(s, a), they learn a map directly from states to actions. We call this the policy, denoted as $\\pi(a|s)$.

A huge advantage of PG is dealing with **Perceptual Aliasing**. This happens when two different states look identical to the agent. A value-based agent might get stuck oscillating between them, while a policy-based agent can learn to act randomly (e.g., "50% chance I go left, 50% I go right") to eventually break out.

State space explosion : A **Policy Gradient** method just outputs the parameters of a distribution (like the mean and variance of a bell curve). It doesn't need to "search"; it just samples a number from that curve. 

Loss function : "In which direction should I change my weights to make this specific action **more likely**?"

**The "Trial and Error" catch:** Unlike supervised learning (where we know the "correct" label), in RL we don't know the best action. We only know if the action we *happened* to take turned out well.

Reward

In Policy Gradient methods, $R$ acts as a "critic" or a signal of quality. There are three main ways we calculate it to help the agent learn faster:

1. **Total Return ($G\_t$):** The simplest version (used in the **REINFORCE** algorithm). If the whole game went well, we increase the probability of every action we took.  
2. **Baseline Subtraction:** We subtract an average "expected" reward from $G\_t$. This way, we only reward actions that were *better than average*.  
3. Advantage ($A\_t$): This is the gold standard. Instead of just looking at the reward, we calculate:  
   $$A(s, a) \= Q(s, a) \- V(s)$$  
   In plain English: "How much better was this action ($Q$) compared to what I expected to get from this state ($V$)?"

Modern algorithms like **PPO** actually try to get the best of both worlds. They use an "Actor" to decide the policy (Policy Gradient) and a "Critic" to estimate the values (Value-Based). This allows them to use the **Advantage** function we talked about earlier to balance the "long-term vision" with "short-term stability."

Bias-Variance trade-off

**Long games (Policy Gradient)** are hard because of **High Variance**. The agent might do 99 great things and 1 bad thing at the end, and the math struggles to figure out which action was the actual culprit for the loss.

**Short games (Value-Based)** are hard because of **Bias**. If the agent's initial "guesses" about the value of a state are wrong, it can get stuck in a loop of bad decisions because it never "sees" the big picture of the whole episode.

**The Evolution:** Moved from **REINFORCE** (high variance) to **Actor-Critic** (more stable) to **PPO** (safely clipped updates).

## PPO

**Proximal Policy Optimization (PPO)** is the industry favorite because it solves a huge problem in Reinforcement Learning: **The "Collapse."**

In standard Policy Gradient, a single bad update can change the weights so much that the agent "forgets" how to play entirely. Once it becomes terrible, it only collects "bad" data, and it can almost never recover. It's like a student failing one test and deciding to quit school forever.

### Clipping trick

**The Clip:** PPO says: "I don't care how much the gradient tells you to change; you aren't allowed to move more than, say, **20%** away from your old self."

# chatgpt works like this

This exact mechanism—PPO—is the secret sauce behind **Reinforcement Learning from Human Feedback (RLHF)**. When training models like ChatGPT:

* The "State" is the text prompt.  
* The "Action" is the word the model chooses to generate.  
* The "Reward" comes from a separate model (trained on human rankings) that says "this answer is helpful/safe.

