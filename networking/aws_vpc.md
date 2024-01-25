
#  VPC 

https://www.youtube.com/watch?v=gUesnoDzNr4&list=WL&index=66

VPC attach to internet gateway for public 

Same VPC can have public and private subnets

Set Route Table for VPC 

Network ACL is at network level

Security group at instance level

# AWS solution options

https://www.youtube.com/watch?v=XZbvQWkpJTI


## connect on-prem corporate data center to VPC 

two options
1. site to site VPN (VGW - virtual private gateway)
2. Direct Connect

## remote client to VPC

Client VPN endpoints; OpenVPN

## between private VPC of same company in different regions

VPC peering without going thru public internet; but VPC peering is 1-1 and not transitive

##  interconnect more than one private VPC with each other (do cross connect)

Use Transit gateway instead of VPC peering

## between VPC of different companies running in same cloud

VPC peering

## connect VPC to other SaaS services in same cloud

PrivateLink

## to talk to AWS services 

use VPC endpoint instead of public internet
1. VPC endpoint gateway to S3 and dynamodb
2. VPC endpoint interfaces for any other AWS service

