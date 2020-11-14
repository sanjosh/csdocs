# Rubik's cube

Combinatorial optimization problem with applications to
1. protein folding
2. tsp and mst
3. knapsack
4. resource allocation

rubik's cube has 4.3 x 10^19 states

minimal steps to solve = 26

hand-engineered solutions
1. Kociemba two-phase solver
2. Richard Korf IDA solver

# DeepCube 

8 corner cubelets with 3 stickers can be in 3 positions = 8 x 3 = 24 states  
12 side cubelets with 2 stickets can be in 2 positions = 12 x 2 = 24 states

this gives 20(8+12) x 24 one-hot encoding

Neural net for A3C
1. Policy head = outputs probability for 12 moves
2. Value head = scalar

## Training data

scramble solved cube k times, repeat l times
this gives k x l = N cube states

for each state in batch, do 1-depth BFS, evaluate value function

value loss is MSE, optimizer RMSProp

monte carlo tree search

https://www.youtube.com/watch?v=DYKS0rC98ME

## Solving the Rubik’s Cube Without Human Knowledge 2018

We introduce Autodidactic Iteration: a novel reinforcement learning algorithm that is able to 
teach itself how to solve the Rubik’s Cube with no human assistance.

https://arxiv.org/abs/1805.07470

## Solving the Rubik's Cube with Approximate Policy Iteration 2019

## Solving the Rubik's Cube with Deep Reinforcement Learning and Search 2019

DeepCubeA trains on states obtained by starting from the goal state and randomly taking moves in reverse. 
After training, the learned cost-to-go function is used as a heuristic to solve the puzzles using a weighted A* search

