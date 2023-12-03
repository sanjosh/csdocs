
https://d1.awsstatic.com/whitepapers/AWS_Blue_Green_Deployments.pdf

# Approaches

## Using DNS

update record and change ttl

By updating the alias record, you can route traffic from the blue environment to the green environme

## at ELB

When it’s time to deploy, you simply attach the green
group to the existing load balancer to introduce traffic to the new environment. For
HTTP/HTTPS listeners, the load balancer favors the green Auto Scaling group because
it uses a least outstanding requests routing algorithm.

As you scale up the green Auto Scaling group, you can take the blue Auto Scaling
group instances out of service by either terminating them or putting them in Standby
state. For more information see, Temporarily removing instances from your Auto
Scaling group. Standby is a good option because if you need to roll back to the blue
environment, you only have to put your blue server instances back in service and
they're ready to go

## Auto-scaling group : launch configs

The templates used to launch EC2 instances in an Auto Scaling group are called launch configurations. You
can attach different versions of launch configurations to an auto scaling group to enable
blue/green deployment.

A launch configuration contains information like the Amazon Machine Image (AMI) ID,
instance type, key pair, one or more security groups, and a block device mapping. Auto
Scaling groups have their own launch configurations. You can associate only one
launch configuration with an Auto Scaling group at a time, and it can’t be modified after
you create it. To change the launch configuration associated with an Auto Scaling
group, replace the existing launch configuration with a new one. After a new launch
configuration is in place, any new instances that are launched use the new launch
configuration parameters, but existing instances are not affected. When Auto Scaling
removes instances (referred to as scaling in) from the group, the default termination
policy is to remove instances with the earliest launch configuration. 


## Managing Data Synchronization and Schema Changes

A general recommendation is to decouple schema changes from the code changes.
This way, the relational database is outside of the environment boundary defined for the
blue/green deployment and shared between the blue and green environments. The two
approaches for performing the schema changes are often used in tandem:

• The schema is changed first, before the blue/green code deployment. Database
updates must be backward compatible, so the old version of the application can
still interact with the data.

• The schema is changed last, after the blue/green code deployment. Code
changes in the new version of the application must be backward compatible with
the old schema.
