
1. dynamic translation of instructions
1. paravirtual
1. hardware virtualization

kvm type 1 (baremetal)

1. loadable kernel module, kvm.ko, 
2. processor specific module, kvm-intel.ko or kvm-amd.ko.

Every KVM is just one separate Linux process, whose safety is ensured using SELinux/sVirt, 
and resources are allocated using CGroups.

https://mkdev.me/en/posts/virtualization-basics-and-an-introduction-to-kvm

## nested virtualization


## libvirt


## source code

page fault handler
https://github.com/torvalds/linux/blob/master/virt/kvm/async_pf.c

coalesced mmio

dirty ring

irq

vfio

main 


## ARM

https://github.com/torvalds/linux/tree/master/arch/arm64/kvm

## x86

https://github.com/torvalds/linux/tree/master/arch/x86/kvm

## overview

ioctl on device /dev/kvm
1. Creation of a new virtual machine.
1. Allocation of memory to a virtual machine.
1. Reading and writing virtual cpu registers.
1. Injecting an interrupt into a virtual cpu.
1. Running a virtual cpu.

SMP support (IPI)   


Kivity kvm: the Linux Virtual Machine Monitor
https://www.kernel.org/doc/ols/2007/ols2007v1-pages-225-230.pdf


## vcpu to cpu

kernel was earlier not aware that vcpu is different from regular thread

there is higher costs of moving a virtual cpu from one CPU core to another,

## mmu

gfn = guest frame number
pfn = page frame number

1. when guest paging is disabled, we translate guest physical addresses to host physical addresses (gpa->hpa)
1. when guest paging is enabled, we translate guest virtual addresses, to guest physical addresses, to host physical addresses (gva->gpa->hpa)
1. when the guest launches a guest of its own, we translate nested guest virtual addresses, to nested guest physical addresses, to guest physical addresses, to host physical addresses (ngva->ngpa->gpa->hpa)

https://www.kernel.org/doc/html/latest/virt/kvm/mmu.html

## interrupt

vgic = virtual generic interrupt controller

https://www.kernel.org/doc/html/latest/virt/kvm/devices/arm-vgic.html

## live migration

kvm provides a dirty page log facility, which provides userspace with a
bitmap of modified pages since the last call.

https://www.kernel.org/doc/ols/2007/ols2007v1-pages-225-230.pdf
