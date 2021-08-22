# Multiple paths in lambda

Use lambdarest

or enable proxy integration in API gateway

```
Amazon API Gateway Lambda proxy integration is a simple, powerful, and nimble mechanism to build an API with a setup of a single API method

With this integration type, API Gateway applies a default mapping template to send the entire request to the Lambda 
function and transforms the output from the Lambda function to HTTP responses.

```

https://docs.aws.amazon.com/apigateway/latest/developerguide/set-up-lambda-proxy-integrations.html

# AWS Lambda

1. ec2 has full hardware virtualization
1. lambda has lightweight virtualization

firecracker launches microvm
1. no BIOS; just copies the kernel into memory
1. only Linux supported
1. multi-tenant
1. faster cold-start
1. better security without full hypervisor
1. snapshot support
1. EFS runs in guest kernel
1. provisioned concurrency

container support and faster cold start
1. since same base images are used, you can download them once; 
1. flatten layers; 
1. compress; 
1. use "convergent encryption"; 
1. placed in low-level filesystem; 
1. does not download everything - this improves cold start time

firecracker written in Rust

Firecracker’s process-per-VM model  
also means that it doesn’t offer VM orchestration, packaging,  
management or other features — it replaces QEMU, rather  
than Docker or Kubernetes, in the container stack.  

HOW LAMBDA WORKS - COLD STARTS? FIRECRACKER? CONTAINER SUPPORT?
https://www.youtube.com/watch?v=OOGV81YbuEo

https://github.com/firecracker-microvm/firecracker

https://assets.amazon.science/96/c6/302e527240a3b1f86c86c3e8fc3d/firecracker-lightweight-virtualization-for-serverless-applications.pdf

# Lambda internals

Control plane : management API, integration with AWS
Data plane : invoke API

container image : The encryption method allows Lambda to securely deduplicate encrypted chunks.

execution environment:
1. Workers are bare metal Nitro instances which are launched in a seperate inaccessible AWS account. 
1. These workers have hardware-virtualized MVMs (Micro Virtual Machines) created by Firecracker (Linux's Kernel-based Virtual Machine). 
1. Workers have a lease lifetime of 14 hours, when a worker approaches this maximum, no further invocations are forwarded to the worker and the worker is terminated. 
1. Each worker has the ability to host one concurrent invocation, but is being reused if multiple invocations of the same function occur. 

## Placement Service 

places sandboxes on Workers to maximize packing density without impacting cold-path latency.
1. use statistical multiplexing to create uncorrelated workloads
1. copying very different kind of workloads onto the same server opposed to copying the same workload on the server

## Firecracker 

1. VMM tailored for containers; 
1. better than earlier approach of allocating per-customer EC2 instance for security
1. its job is to configure the KVM, it uses the KVM API to create and manage MVMs
1. provides REST API to manage MVM (micro virtual machine)

https://github.com/firecracker-microvm/firecracker/blob/main/src/api_server/swagger/firecracker.yaml

## Worker Manager 

downloads Lambda code

Lambda runtimes are prebuilt .NET Core, python, NodeJS

## Worker Machine 

Nitro + Host OS + KVM + Guest OS(MVM) + Sandbox + Lambda runtime 

## Synchronous Path

ALB -> Frontend worker -> Worker Manager -> Placement Service -> Worker

## Asynchronous Path

ALB -> Frontend worker -> SQS -> Poller -> Frontend worker -> Placement Service -> Worker

Kinesis and DynamoDB goes thru Poller







https://www.bschaatsbergen.com/behind-the-scenes-lambda

https://www.youtube.com/watch?v=QdzV04T_kec

https://www.youtube.com/watch?v=xmacMfbrG28

https://brooker.co.za/blog/2020/02/19/firecracker.html

https://docs.aws.amazon.com/whitepapers/latest/security-overview-aws-lambda/lambda-executions.html
# Gigabytes in milliseconds

https://www.youtube.com/watch?v=A-7j0QlGwFk

Gigabytes in milliseconds: Bringing container support to AWS Lambda without adding latency

Marc Brooker

Frontend API (Invoke) -> Stateful load balancer -> workers

Containers are Big and Sparse : number of reads required to start a container is small compared to actual container

just move around the bits that are required to start a container

Sparse filesystem : takes virtio read, figures out chunk, checks local cache, goes to shared local cache,

containers have lot of common data but encryption makes it difficult to share cache
(Harter, Fast distribution with Lazy Docker containers, FAST 16)

encryption makes dedupe hard

Convergent encryption : unique per-chunk key which is same for every identical plaintext (see references)

(storer, Secure Data deduplication, StorageSS 08)
https://www.ssrc.ucsc.edu/pub/storer-storagess08.html

(Douceur Reclaiming space from duplicate files
https://ieeexplore.ieee.org/abstract/document/1022312

Distributed cache fleet - erasure code

erasure codes help get better tail latency


