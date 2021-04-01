
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

