# Resolving Outages Faster

Liz Fong-Jones et al @ Google (SRE)

* building dashboards not the solution
* no two outages are identical
* define Service level objective/KPI (https://en.wikipedia.org/wiki/Service_level_indicator)
* How to formulate hypotheses faster and test them faster
* OODA loop  (observe orient decide act)

internal google tool called panopticon (fb has some tool 'canopy'; also coming to opencensus + stackdriver)

# Best Practices

1. layer peeling : precomputation and drill down queries (add critical queries into playbook)
2. dynamic data joins : 
3. exemplars : dtrace + distribution (save some historical samples for each bucket)

https://www.facebook.com/atscaleevents/videos/2132485973691162/

tools
1. https://opencensus.io/
2. https://cloud.google.com/stackdriver/
3. Google Dapper - distributed tracing

question : how to tie exemplar to SLI 
