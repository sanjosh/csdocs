
Goroutines are multiplexed onto kernel threads

when is scheduler called - an op affects goroutine exec
1. goroutine creation
2. blocking on channel
3. blocking system call

goroutines tracked on heap-allocated FIFO runqueues

how to multiplex?
* reuse kernel threads that run goroutines - amortize cost
* park idle kernel threads in "idle list"
* limit number of kernel threads accessing runqueue to num cpu cores, only idle threads can acccess runqueue.
* contention increases non-linearly if number of cpu cores too high 
* keep runqueue per cpu core - with work stealing if runqueue is empty- with handoff to transfer runqueue of blocked kernel thread to another parked thread - needs monitor thread
* to prempt runaway cpu bound tasks - cooperative preemption using sysmon thread - it puts them onto global runqueue.
* threads without work "spin" looking for work - check global runqueue, poll net, run GC and steal work.

limitations
* no priority
* no strong preemption  (proposal)
* no NUMA locality (proposal)

# Reference
1. kavya joshi. Scheduler saga. gophercon 2018 https://www.youtube.com/watch?v=YHRO5WQGh0k
