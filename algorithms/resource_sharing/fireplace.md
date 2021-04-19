
decision tree out-performed LSTM, reinforcement learning, power of two

input : resource consumption status of multiple servers in the fleet;
output : assignment of new VM to one of the input servers

reward function : increase mean CPU usage of fleet (pack micro-VM tightly)

used historical data (time series) to train via simulation

https://www.amazon.science/publications/fireplace-placing-firecracker-virtual-machines-with-hindsight-imitation

https://www.amazon.science/blog/using-machine-learning-for-virtual-machine-placement-in-the-cloud
