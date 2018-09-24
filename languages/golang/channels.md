
# Channels

channels can be buffered or unbuffered 

hchan struct 
{
	buf circular queue
	send index
	recv index
	mutex 
	sendq -> waiting "sudog" of goroutines
	recvq -> waiting
}

when producer blocks on full channel, it calls "gopark" (yield).  the scheduler then selects another goroutine from the runqueue

hchan stores waiting senders and receivers, stored as "sudog", 

after consumer dequeues, it pops the waiting producer and sets it to "runnable" by calling "goready" which puts it on the run queue.

when consumer blocks on empty channel, and producer comes along, it puts item directly into the consumer's buffer instead of putting it into "buf".  Its an optimization.  G1 writes into G2's stack !

unbuffered channels
1. recv first : sender writes to recv stack
2. sender first : recv receives from sudog.

selects : 
1. all channels locked
2. sudog is put into sendq/recvq of all channels.
3. channels unlocked and selecting goroutine is paused
4. CAS operation is done so there is one winner
5. resuming mirrors the pause sequence

# Reference

kavya joshi. Golang channels https://www.youtube.com/watch?v=KBZlN0izeiY
