
https://eng.uber.com/building-ubers-fulfillment-platform/

https://eng.uber.com/fulfillment-platform-rearchitecture/

```
The entire fulfillment model revolved around 2 entities: Trip and Supply. 

The rt-demand service managed the Trip entity, 

rt-supply service managed the Supply entity. 

A Trip represented a unit of work (e.g. delivering a package from point A to B) 

the Supply entity represented a real-world person capable of doing the unit of work.

```

```
Concurrent read-modify-writes to the same entity: For example, a driver trying to go offline and a matching system trying to link a new trip offer to the driver
Writes involving multiple entities: If a driver accepts a trip offer, we have to modify the trip entity and the supply entity, and add waypoints of the trip in the supply entity’s plan
Writes involving multiple instances of multiple entities: If a driver accepts a batch offer with multiple trips, all the related entities need to be updated in an all-or-nothing fashion

```

```

Uber’s Cloud network architecture has 2 major components:

Physical Layer consisting of the interconnections between Uber and the Cloud vendors.

Logical Layer that includes the virtual connections created on top of the physical layer to achieve redundancy.

To provide optimal reliability at the physical layer, we provide 2 layers of N+1 physical redundancy with:

In each of Uber’s Network Point-of-Presence (PoP), Uber-Cloud interconnects are set up with the same capacity from 2 Uber peering routers, backing each other up

2 Uber Network PoPs serve Uber-Cloud interconnections with the same capacity built-in to each PoP, providing N+1 redundancy

```

https://cloud.google.com/network-connectivity/docs/interconnect/tutorials/dedicated-creating-9999-availability


https://cloud.google.com/vpc/docs/configure-private-google-access-hybrid
