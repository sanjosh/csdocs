
# tools

https://github.com/toniblyx/my-arsenal-of-aws-security-tools

# AWS account

root user

MFA

IAM groups
IAM policies


# VPC

VPC = list of subsets
VPC = across AZ

## Local zone

A VPC spans all of the Availability Zones in the Region. After creating a VPC, you can add one or more subnets in each Availability Zone. You can optionally add subnets in a Local Zone, which is an AWS infrastructure deployment that places compute, storage, database, and other select services closer to your end users. A Local Zone enables your end users to run applications that require single-digit millisecond latencies

AWS Local Zones are a type of AWS infrastructure deployment that places AWS compute, storage, database, and other select services closer to large population, industry, and IT centers where no AWS Region exists today.


## Route table

Each subnet must be associated with a route table, which specifies the allowed routes for outbound traffic leaving the subnet. Every subnet that you create is automatically associated with the main route table for the VPC
Security group

 Each instance in your VPC could belong to a different set of security groups.
 When you launch an instance in a VPC, you can assign up to five security groups to the instance. Security groups act at the instance level, not the subnet level.

## Talk to another VPC

Two types of endpoints can currently be provisioned:
1. Interface Endpoints (powered by AWS PrivateLink)
1. Gateway Endpoints.


## PrivateLink

via NLB (l4)

Whatever EC2 instance you want to expose to the other VPC must be served from behind an NLB. An NLB is a layer 4 load balancer which forwards TCP/IP traffic to any registered targets.

https://docs.aws.amazon.com/vpc/latest/privatelink/add-endpoint-service-permissions.html


## VPC Peering

## transit Gateway


https://d1.awsstatic.com/whitepapers/building-a-scalable-and-secure-multi-vpc-aws-network-infrastructure.pdf?did=wp_card&trk=wp_card


## centralized egress

## centralized ingress

## cross-account access

https://tomgregory.com/cross-account-vpc-access-in-aws/

Three options
1. VPC peering
2. privatelink
3. Transit gateway by default only allows VPCs from the same AWS account to be attached. For our cross-account scenario, we’ll have to use another AWS service called the Resource Access Manager (RAM).

## Lambda calling outside

use NAT gateway

or setup VPC endpoint https://docs.aws.amazon.com/vpc/latest/privatelink/vpc-endpoints.html

https://docs.aws.amazon.com/vpc/latest/privatelink/endpoint-service.html


# IAM

## EC2 instance access

https://docs.aws.amazon.com/IAM/latest/UserGuide/id_roles_use_switch-role-ec2.html

When you launch an EC2 instance, you specify an IAM role to associate with the instance. Applications that run on the instance can then use the role-supplied temporary credentials to sign API requests.

## EC2 instance connect

https://aws.amazon.com/blogs/compute/new-using-amazon-ec2-instance-connect-for-ssh-access-to-your-ec2-instances/


IAM user can upload public ssh key

## ec2 ssh

https://github.com/widdix/aws-ec2-ssh

## Session manager

https://docs.aws.amazon.com/systems-manager/latest/userguide/session-manager-working-with-install-plugin.html

 If an instance profile that contains the AWS managed policy AmazonSSMManagedInstanceCore is already attached to your instances, the required permissions for Session Manager are already provided.
https://docs.aws.amazon.com/systems-manager/latest/userguide/session-manager-getting-started-instance-profile.html

## ECS instance access

https://docs.aws.amazon.com/AmazonECS/latest/developerguide/instance_IAM_role.html

https://docs.aws.amazon.com/AmazonECS/latest/developerguide/task-iam-roles.html

For ECS clusters, there are two IAM roles to consider:
1. The IAM role assigned to the cluster. When you set up an ECS cluster you select an IAM role for the cluster.
1. The IAM role assigned to the Task Definition.

## Using session manager

https://www.ernestchiang.com/en/posts/2021/using-amazon-ecs-exec/


# Certificate manager

ACM certificates are domain validated. That is, the subject field of an ACM certificate identifies a domain name and nothing more. W

# KMS

used inside Secrets Manager

# Systems Manager

https://aws.amazon.com/systems-manager/features/

Parameter Store IAM Policies

## Session Manager (vs Bastion)

https://armedia.com/blog/bastion-we-dont-need-no-stinkin-bastion/


The users who will be using ECS Exec to connect to their ECS containers will require the following permissions on the user or role they use to access the resources. Note that ECS Exec is currently only available via the AWS CLI. AWS reports that it will be available in the AWS Management Console at a later time.

ecs:ExecuteCommand

ecs:DescribeTasks

https://workshop.aws-management.tools/ssm/use-case-labs/sessionmanager/

# Secrets Manager

each secret has a ARN

When you send HTTP requests to AWS, you must sign the requests so AWS can identify the sender. You sign requests with your AWS access key, which consists of an access key ID and a secret access key.


## PutResourcePolicy

Attaches the contents of the specified resource-based permission policy to a secret. A resource-based policy is optional. Alternatively, you can use IAM identity-based policies that specify the secret's Amazon Resource Name (ARN) in the policy statement's Resources element. You can also use a combination of both identity-based and resource-based policies

https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access_identity-based-policies.html


https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access_resource-access.html


https://docs.aws.amazon.com/IAM/latest/UserGuide/introduction_attribute-based-access-control.html


# STS

AWS Security Token Service (AWS STS) is a web service that enables you to request temporary, limited-privilege credentials for AWS Identity and Access Management (IAM) users or for users that you authenticate (federated user

https://docs.aws.amazon.com/STS/latest/APIReference/API_AssumeRole.html

The temporary security credentials created by AssumeRole can be used to make API calls to any AWS service with the following exceptio

https://docs.aws.amazon.com/STS/latest/APIReference/welcome.html

https://docs.aws.amazon.com/IAM/latest/UserGuide/id_credentials_temp_request.html


# AWS Vault

https://github.com/99designs/aws-vault


# exam


https://d1.awsstatic.com/training-and-certification/docs-security-spec/AWS-Certified-Security-Speciality_Sample-Questions.pdf

https://d1.awsstatic.com/training-and-certification/docs-security-spec/AWS-Certified-Security-Specialty_Exam-Guide.pdf

