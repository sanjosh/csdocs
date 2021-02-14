assume host is untrusted

protect data throughout its lifecycle
1. at rest,
2. in transit
3. in use.

# Intel SGX 

1. code is trusted
2. Data encrypted in RAM

Restrictions
1. Limited RAM for EPC (128 MB) - can be swapped
2. Only ring-3 - no VT
3. No system calls - need libOS

Three parts to SGX
1. CPU/platform hardware features: the new instruction set, new microarchitecture with the PRM (EPC) memory region and some new MSRs and some new logic in the MMU and so on;
2. the SGX Remote Attestation infrastructure, online services provided by Intel and/or third parties (see DCAP);
3. SDK and assorted software.

How does it work
1. RAM encryption engine
2. in-CPU logic
3. BIOS reserves an enclave page cache (EPC) on boot.  Max size 128 MB, but only 93 MB usable by applications
3. driver to manage enclave creation and mem management

How is enclave initialized
1. ECREATE to create Enclave control structure (SECS) 
2. EADD to copy code and data pages
3. crypto measurement of mem contents using EEXTEND
4. Verify enclave measurement against signature and activate using EINIT

* EENTER to enter enclave
* exit using EEXIT (followed by EENTER) or AEX (async exit, followed by ERESUME)

Enclave memory can be swapped to normal memory (after encryption by CPU)

SGX is separate execution mode in CPU rings

SDK
1. ecall from untrusted to enclave
2. ocall from enclave to untrusted

## Intel SGX explained - Costan, Devdas

https://eprint.iacr.org/2016/086.pdf

## security

Alexander Nilsson, et al. A Survey of Published Attacks on Intel SGX https://arxiv.org/abs/2006.13598

# SGX in VM

Hypervisors can expose SGX support to VM by unmasking CPUID flags

Hypervisor allocates section of EPC to VM.  EPC can be oversubscribed

Intel provides two hypervisor implementations using KVM and Xen

1. https://github.com/intel/kvm-sgx
1. https://github.com/intel/qemu-sgx
1. https://github.com/intel/xen-sgx.git

https://software.intel.com/content/www/us/en/develop/articles/virtualizing-intel-software-guard-extensions-with-kvm-and-qemu.html

Guest OS : Utilizing SGX in the guest requires a kernel/OS with SGX support,

VM Migration : EPC memory is encrypted with an ephemeral key that is tied to the underlying hardware, migrating a VM will result in the loss of EPC data, similar to loss of EPC data on system suspend.

Qemu memory backend is set to EPC

# SGX in Docker

## performance of SGX

### Everything You Should Know about Intel SGX Performance on Virtualized Systems

Dinh Ngoc Tu,  SIGMetrics 2019

https://github.com/sgxbench/sgxbench/releases

https://hal.archives-ouvertes.fr/hal-02947792/document


# Awesome

https://github.com/Liaojinghui/awesome-sgx

https://github.com/Maxul/Awesome-SGX-Open-Source

# Intel Protected File System Library


# Graphene LibOS

Graphene is a lightweight guest OS, designed to run a single Linux application with minimal host requirements.

part of OS as library

Graphene has
1. GCC patches
2. PAL for different backend (SGX, BSD)

https://github.com/oscarlab/graphene


## Graphene-SGX is port to SGX

intercept syscall and call SGX PAL and do RPCs to host OS

Tsai, Graphene-SGX: A Practical Library OS for Unmodified Applications on SGX
http://www.cs.unc.edu/~porter/pubs/graphene-sgx.pdf

## Graphene-SGX containers 

Docker container can use Graphene LibOS and SGX PAL


# Google Asylo

# Google - AMD SEV

GCP shielded VM

# Microsoft Open Enclave

# Microsoft Azure - SGX

create confidential computing VM

# VMWare

vSphere7 supports

# AWS Nitro

https://aws.amazon.com/ec2/nitro/nitro-enclaves/

https://www.allthingsdistributed.com/2020/09/reinventing-virtualization-with-aws-nitro.html

# Fortanix

# Anjuna

# Scone

# Panoply


# hardware support

https://github.com/ayeks/SGX-hardware
