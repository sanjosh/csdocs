
# Dreamer

https://ai.googleblog.com/2020/03/introducing-dreamer-scalable.html

Latent space model

We formulate visual control as a partially observable Markov decision process (POMDP) 

# PlaNet

https://ai.googleblog.com/2019/02/introducing-planet-deep-planning.html

# AlphaGo

# WorldModels

https://worldmodels.github.io/

```
In this work we look at training a large neural network2 to tackle RL tasks, by dividing the agent 
into a large world model and a small controller model. We first train a large neural network to 
learn a model of the agent’s world in an unsupervised manner, and then train the smaller 
controller model to learn to perform a task using this world model. A small controller lets 
the training algorithm focus on the credit assignment problem on a small search space, while 
not sacrificing capacity and expressiveness via the larger world model. By training the agent 
through the lens of its world model, we show that it can learn a highly compact policy to perform its task.

```

Our agent consists of three components that work closely together: Vision (V), Memory (M), and Controller (C).

V is a VAE

M is RNN 

C is simple single layer linear model

```
def rollout(controller):
  ''' env, rnn, vae are '''
  ''' global variables  '''
  obs = env.reset()
  h = rnn.initial_state()
  done = False
  cumulative_reward = 0
  while not done:
    z = vae.encode(obs)
    a = controller.action([z, h])
    obs, reward, done = env.step(a)
    cumulative_reward += reward
    h = rnn.forward([a, z, h])
  return cumulative_reward
  ```
