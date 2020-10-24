
# No-I/O dirty throttling

Fengguang Wu Intel

Slow down apps which are dirtying more pages.

create a control loop capable of determining how many pages each process should be allowed to dirty at any given time. 
Processes exceeding their limit are simply put to sleep for a while to allow the writeback system to catch up with them.  (backpressure)

earlier mechanism was "balance_dirty_pages" - make dirtying process do the disk sync; simple threshold which is not effective


Issues
1. throttling depends on BDI for which pages are being dirtied
2. per-process rate limit must be set based on number of processes dirtying, but this number has to be calculated dynamically

how to estimate number of processes dirtying the disk ?
1. set initial ratelimit_0 = X pages/sec
2. after 200 ms, find dirty_rate = (number of pages dirtied/200ms)
3. estimate N = dirty_rate/ratelimit_0

process must sleep for sleep(pages_dirtied/task_ratelimit)
where task_ratelimit = (balanced_ratelimit * pos_ratio)


cubic polynomial function to calculate global pos_ratio which describes how strongly system must adjust number of dirty pages

https://github.com/torvalds/linux/blob/master/mm/page-writeback.c#L824

## Cases to handle

1. Single disk vs JBOD
2. Small RAM vs large RAM machine

https://events.static.linuxfound.org/images/stories/pdf/lcjp2012_wu.pdf

https://lwn.net/Articles/456904/

https://lwn.net/Articles/415838/
