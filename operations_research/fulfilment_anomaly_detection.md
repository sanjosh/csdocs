

# Flipkart fulfilment anomaly detection

govind pandey

https://www.youtube.com/watch?v=UiyQT6g7Bs8

1. seller -> pickup hubs
2. warehouse (product sorted by category)
3. sortation center (product sorted by destination)
4. delivery hubs (product sorted by final destination or truck)

# evolution

started with cron, then dashboard, then alerting

# Metrics 

1. breaches (not delivered on time)
2. leading indicators : throughput per hour in each warehouse or sortation center

leading indicators more important : signal of future breach

# algo

isolation forest after massaging time series data

