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

## applications

TrustJS, a framework that enables trustworthy execution of security-sensitive JavaScript inside commodity browsers.
https://dl.acm.org/doi/10.1145/3065913.3065917

SGXCrypter
https://ieeexplore.ieee.org/document/7858348

1. Process private data without being able to see it yourself, to enhance your user's privacy.
1. Create a hardware-backed form of zero knowledge proofs: make trustworthy 'statements' that a particular computation was done on some data, without the data itself needing to be revealed.
1. Outsource some kinds of computations to an untrusted cloud.
1. Improve the security of a server by restricting access to a whitelist of client enclaves, blocking attempts to send malformed packets and messages that might come from hackers.
1. Make your service auditable only by users who want high assurance - those who don't care can simply ignore the infrastructure entirely.

https://docs.conclave.net/enclaves.html

## research papers

https://software.intel.com/content/www/us/en/develop/topics/software-guard-extensions/academic-research.html

## Intel SGX explained - Costan, Devdas

https://eprint.iacr.org/2016/086.pdf

SGX1 = 

SGX2 = EDMM, DCAP FLC

## security

Alexander Nilsson, et al. A Survey of Published Attacks on Intel SGX https://arxiv.org/abs/2006.13598

## Attestation

DCAP

https://download.01.org/intel-sgx/dcap-1.0.1/docs/Intel_SGX_DCAP_ECDSA_Orientation.pdf

https://community.intel.com/t5/Intel-Software-Guard-Extensions/Thirdparty-Launch-control-in-SGX/td-p/1142713

## Linux patches

https://patchwork.kernel.org/project/platform-driver-x86/patch/20171010143258.21623-6-jarkko.sakkinen@linux.intel.com/

## Linux external driver

https://github.com/intel/linux-sgx-driver

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

## KVM SGX

https://lore.kernel.org/linux-sgx/20190727055214.9282-1-sean.j.christopherson@intel.com/

KVM SGX provides only the mechanisms to virtualize SGX

### Add Config param X86_SGX_KVM

Launch control

X86_FEATURE_SGX_LC

Documentation/x86/sgx/2.Kernel-internals.rst

### Initialize 

init_ia32_feat_ctl : check if CPU has SGX feature using CPUID

ENCLS_FAULT_FLAG

### enclave creation

arch/x86/kvm/vmx/sgx.c

MMU virtualization  (guest to host) using EPT/NPT

* GPA : guest physical address
* GVA : guest virtual address
* HPA : host physical address
* HVA : host virtual address 

18 instructions added

ECREATE, EINIT

### new virtual device sgx_vepc

A handle to a newly created virtual EPC section is returned as a file descriptor, which can in turn be used to mmap() EPC and assigned to a guest

sgx_vepc_fault

sgx_vepc_mmap

### Pub key hash MSR

LE = launch enclave

rdmsrl

read hash from MSR (model specific register)

https://man7.org/linux/man-pages/man4/msr.4.html

https://patchwork.kernel.org/project/platform-driver-x86/patch/20171010143258.21623-6-jarkko.sakkinen@linux.intel.com/

### Run ECREATE and EINIT on behalf of guest

sgx_virt_ecreate

sgx_virt_einit

sgx_encls_function

### nested virtualization

kvm/vmx/nested.c

handle enclaves

## QEMU SGX 

exposes SGX to userspace VM 

https://github.com/intel/qemu-sgx/blob/c9cb41bea6992634faa43e6ff33b677812e83ada/backends/hostmem-epc.c

add msr hash

https://github.com/intel/qemu-sgx/blob/c9cb41bea6992634faa43e6ff33b677812e83ada/target/i386/kvm.c#L3355-L3359

https://github.com/intel/qemu-sgx/blob/c9cb41bea6992634faa43e6ff33b677812e83ada/hw/i386/sgx-epc.c

# SGX in Docker

using out-of-kernel Intel SGX driver and Intel SDK into the Docker image

https://github.com/sebva/docker-sgx

https://github.com/aminueza/sgx-docker

https://github.com/tozd/docker-sgx

Scone https://www.usenix.org/conference/osdi16/technical-sessions/presentation/arnautov

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

https://www.usenix.org/sites/default/files/conference/protected-files/osdi16_slides_knauth.pdf

https://www.usenix.org/conference/osdi16/technical-sessions/presentation/arnautov

# Panoply


# hardware support

https://github.com/ayeks/SGX-hardware
