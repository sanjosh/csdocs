
# AWS re:Invent 2018: Close Loops & Opening Minds: How to Take Control of Systems, Big & Small ARC337

https://youtu.be/O8xLxNje30M

Control Planes manage lifecycle, provision service, provision user, provision software

 
only stable control system is PID`

Book Designing Distributed Control Systems  : Pattern language
 
Patterns

## checksum all things
 
## crypto auth

never allow non-prod control plane to talk to prod control plane

prevent human access to prod credentials

revoke and rotate credentials; watch out for cert expires

encrypt and auth everything
 
## cells shells and poison tasters

divide control planes horizontally; insulate data plane from control plane crashes; check up front that change is safe

## async coupling

make partial progress; workflows and queues can have deterministic retry behaviours

## closed feedback loops

measure state of the system

## small pushes and large pulls

should data plane pull from control plane or get push from control

do this based on relative sizes of fleets
 
## avoid cold starts and cold caches

caches are bimodal.  superfast when they have entries, slow when they are empty

## throttles

## deltas

how to push config state around
 
## modality and constant work

minimize number of modes of operation in the control plane

systems that change perf in response to workload or data patterns can be fragile

example : RDBMS not used in control plane

