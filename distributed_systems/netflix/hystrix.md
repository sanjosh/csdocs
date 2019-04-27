
# Netflix Hystrix 
* wrap all calls in a command
* metrics - measure num success/failures per service

## Timeout
* use timeout with each command

## Circuit breaker
* circuit breaker prevents call for period of time
* once circuit opens, calls are rejected immediately
* then circuit transitions to half-open, where calls are intermittently allowed
* to check if problem is resolved (slow start) configure fallback logic if request fails, times out

## Swimlane (failure domain)

## Bulkhead (analogy from compartments in ship) 
* reserve resources per client
* keep threadpool per dependency to limit number of concurrent calls
* OR use counting semaphore

## Handshaking
* ask server if it can take more work (throttling)

