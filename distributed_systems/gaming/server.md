
Require
* 60 fps
* avoid choppy movements
* latest input to all OR illusion

Use
* not chatty protocol : only communicate difference
* use out of band for not urgent
* dedicated threads (?)
* memory pre-allocated, CPU reserved

## human angle

what can brain detect ?

## networking

disable nagle

Data sent across the network at 60HZ doesn’t typically arrive nicely spaced

UDP - build reliable acked delivery

# physics simulation approaches

1. deterministic lockstep
2. snapshot interpolation
3. state sync

## deterministic lockstep

send only inputs - no state

used for 2-4 players max 

playout delay buffer

run two simulations, one on the left and one on the right, 

use perfect determinism and synchronized inputs keep them in sync

## snapshot interpolation

do not run simulation on one side

instead of immediately rendering snapshot data received, buffer snapshots for a short amount of time in an interpolation buffer

trade a small amount of added latency for smoothness.

https://gafferongames.com/post/snapshot_interpolation/

## state synchronization (approx and lossy sync)

run simulation on both sides send both input and state


```
 Instead of sending state updates for every object in each packet, 
 send updates for only a few, 
 if we’re smart about how we select the objects for each packet, 
 we can save bandwidth by concentrating updates on the most important objects.
```

### priority accumulator on sender

not enuf space to send state of all objects.   
use priority accumulator (one value per obj) to decide which objects to send
reset priority for objects which were sent

### jitter buffer on receiver


### state update on receiver

use smoothing, quantization

quantize on both sides

delta compression with periodic absolute

https://gafferongames.com/post/state_synchronization/

## client

* to avoid stalling, separate the main thread from server-chatting thread 

## peer to peer

earlier model.  this required deterministic lockstep networking

problems:
1. have to wait for commands from all players.  latency of all = latency of lagged

## Hub and spoke

relay every incoming packet to all other clients

1996 Quake first used client/server instead of peer-to-peer

### dumb client - relay keystrokes

client has to interpolate between updates to provide the illusion of smooth movement 

### client-side prediction introduced

predict your own movement locally and give response to local user

but how to apply correction from server ?   
you do rewind-and-replay on last N frames
1. keep circular buffer of past character state, 
1. discard buffered state older than corrected state,
1. replay from corrected state

https://en.wikipedia.org/wiki/Client-side_prediction

https://gamedev.stackexchange.com/questions/114171/how-to-design-a-server-for-a-multiplayer-game

https://gafferongames.com/post/what_every_programmer_needs_to_know_about_game_networking/
