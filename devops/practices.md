
canary : 
1. deploy in single box with separate metrics with bake time 
2. auto rollback on failure

Tests
1. test exceeds max tps 
2. dependency failure (increase dependency timeout, dependency down)
3. some hosts failed test
4. clean slate test - all new host test with libraries installed afresh
5. OOM test

# Netflix

sticky canary

https://www.infoq.com/presentations/sticky-canaries

ChAP will begin an experiment by spinning up any sort of controller experiment infrastructure, 
so these would be new clusters. We can then use a traffic control plane which publishes 
information to the Edge proxy layer. That layer has a servlet filter in it, which will 
actually perform the allocation that we need, and add headers to every request, 
indicating which group it's in and what experiment it's part of. As those headers propagate 
throughout the stack, at some point, in this case, an IPC client will recognize 
that it has a header that needs to take action on.

We have a header that says instead of pulling information from the normal 
production keyspace, pull it from a canary keyspace.

SPS is our key performance indicator for the product. We will actually see here 
is we have three columns. The first two columns are server and client views of 
SPS signal, so what the server thinks it's handing out, and then what the 
clients are actually seeing. The top row is successes and the bottom row is failures. 
The third column over here is another variation of our key performance indicator, 
and that is downloads per second. Users that are downloading content rather than 
streaming it, will show up in that column. As you can see, in this particular test, 
we saw a depreciation or a reduction in successes for all three metrics, 
Server, SPS Client, SPS and downloads per second
