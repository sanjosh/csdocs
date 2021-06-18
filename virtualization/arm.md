

# KVM/ARM: The Design and Implementation of the Linux ARM Hypervisor

## ARM 

Hyp mode

Memory virtualization

Interrupt virtualization (GIC)

Timer virtualization

## ARM vs Intel

| ARM  | Intel |
|--- | --- |
| Hyp mode | root and non-root
| software based storage of guest state | hardware support for saving VM control block |

## modifications

cannot run linux kernel in Hyp mode; So do split-mode virtualization (lowvisor and highvisor)

lowvisor

highvisor

mmap to share data between lowvisor and highvisor

## correctness

## benchmark

## code

virt/kvm/arm

https://git.kernel.org/pub/scm/linux/kernel/git/kvmarm/kvmarm.git/tree/virt/kvm/arm?id=57bdb436ce869a45881d8aa4bc5dac8e072dd2b6

http://www.virtualopensystems.com/en/solutions/guides/kvm-on-arm/

https://lists.cs.columbia.edu/pipermail/kvmarm/

https://github.com/aws/aws-graviton-getting-started

https://community.arm.com/developer/tools-software/oss-platforms/w/docs/510/spawn-a-linux-virtual-machine-on-arm-using-qemu-kvm

https://gcc.gnu.org/onlinedocs/gcc/ARM-Options.html

https://lwn.net/Articles/557132/

## references

https://systems.cs.columbia.edu/projects/kvm-arm/

Dall, 2014
http://www1.cs.columbia.edu/~nieh/pubs/asplos2014_kvmarm.pdf

https://www.linaro.org/blog/on-the-performance-of-arm-virtualization/
