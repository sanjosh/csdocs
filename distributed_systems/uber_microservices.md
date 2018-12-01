
# Microservices

## Earlier Monolithic

### APIs
* driver/passenger - mobile - Rest API
* web UI ->
* stripe (sdk)
* sendroid (email)
* twilio adapter (sms)

### Core modules
* Billing
* Payments
* Notification
* Trip management
* Driver Management
* Passenger Management

## Microservices

Monolith complicates scaling + release management

split core modules

## Matt Ranney talk

Goto 2016
https://www.youtube.com/watch?v=kb-m2fasdDY

problems
1. use of multiple languages
2. hard to debug changes in json passed between services. Need types (WIWIK : servers are not browsers)
3. too many repos - 7000
4. operational - end to end context is lost
5. performance - have common flame graph for all languages; hard to debug if dashboards do not have standard format.  cannot postpone perf by claiming premature optimization.  Must have SLA (known perf) even if it is not fast.  Need knobs for each service.  Fanout causes latency problems.  Easy to trace when you propagate upstream context
6. Need structured logging.  They have Zap - opensourced fast logger
7. Load test in production.  All systems need to handle test traffic, without breaking metrics.  Pass context which indicates its a test.  Keep systems running at peak.
8. Failure testing - random killing
9. Migrations - constant.  Mandated for security and compliance
10. Build/buy trade-off.  Upgrade live merge.
11. Politics.  


