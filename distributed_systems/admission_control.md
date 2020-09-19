

# Problem of admission control for jobs with different deadlines

ensure total accepted jobs do not exceed capacity
1. Multiple clients sending jobs with different deadlines
2. On-demand variable load.  No available forecast of when next job is expected.

## Solution : keep a diary/calendar

keep "pending jobs" data structure sorted by time, containing available slots

this can be a circular queue/bitmap with length equal to "2 * max_deadline"

when you get new request with some deadline, walk back the "pending jobs" structure and reserve a slot

If a high priority client does not find an empty slot, it can overwrite the earliest booked slot which was assigned to a low priority client

As jobs are completed, mark the earliest slot you find as "free" (may not be current)

# Data structures for admission control problem

Time slotted array https://ieeexplore.ieee.org/document/5204837

Bandwidth Tree, Wang https://ieeexplore.ieee.org/document/995134

https://link.springer.com/chapter/10.1007/11534310_95

Analysis of Data Structures for Admission Control. https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.509.3738&rep=rep1&type=pdf

Time slot groups https://hal.archives-ouvertes.fr/hal-00789151/document

List based data structures Schneider https://www.user.tu-berlin.de/komm/paper/2012-Schneider-Linnert-data-structures-for-adv.-reservation.pdf

GarQ - Sulistio, Calendar Queue
http://www.cloudbus.org/papers/GarQ-IJPEDS2009.pdf

https://en.wikipedia.org/wiki/Calendar_queue

