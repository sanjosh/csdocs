
# Load balancers at Paytm


eval criteria
1. high availability
2. balancing strategy - round robin, least connection, weighted lc
3. health check
4. extensibility
5. monitoring
6. perf test

categories of LB
1. dns
2. L3 or L4 (software or hardware) (haproxy)
3. L7 - hardware based F5, fortinet; software based nginx haproxy
4. routing at L4


types of routing
1. nat-ting (proxy)
2. direct route - load balancer will spoof mac address and send it back
3. ip tunneling is most scalable. Tunnel between LB and server

LVS - linux virtual server

LVS has Connection sync service which replicates connection state to secondary. This mitigates blips in case primary fails

## Ref

1. shrey agarwal paytm rootconf 2019 https://www.youtube.com/watch?v=gTS4Agwwgbw&list=PL279M8GbNsesB7sxLO5zNbBHkOVvb7uvy
2. willy tareau blog
