
# service degradation at scale

define levels at which each service to operate on

how to degrade a service to reduce its memory or cpu requirements
1. turn off some features 
2. return fewer results, partial responses
3. request shedding or throttling
4. delay the requests to be services

platform services : multiple other services depend on them

interdependent services : caching and db have to lower their level together

https://m.facebook.com/atscaleevents/videos/service-degradation-at-scale-creating-instant-capacity-thote-gowda-yi-yu/375056554660227/
